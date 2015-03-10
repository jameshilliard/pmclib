/*****************************************************************
* File: shm-defs.h
*
* Copyright (C) 2006 Avocent Corporation
*
* www.avocent.com
*
* Description:
*     This file has general PMD-NG definitions.
*
* Date: 06/30/2006
* Author: Daniel Belz <daniel.belz@avocent.com>
*
*****************************************************************/
#ifndef _sharedmem
#define _sharedmem

#include <pthread.h>
#include <string.h>
#include <shm-structs.h>
#include <syslog.h>

/**
 * Power Management Configuration
 */
extern SHARED_DATA * shmp;
extern pthread_mutex_t shm_mtx;

struct timespec myreq;	/* timeout for semaphore 1. see WAIT_SYNC below and in processSlot in core.c */

/**
 *	Function prototypes for Shared Memory
 */
#ifdef SHM_FREE_STR
//mp: needs review: Should be removed by the end of the project (ACS Classic).
//    It was introduced just to allow -Werror in pmd-gsp/Makefile
#if !defined(READCFGCLASSIC) && !defined(SHAREDMEM_API_CLASSIC) || !defined(IPDULIBTEST)
static void pmshm_group_str(PM_SHM_STR *psh)
{
	PM_SHM_STR *pnext;

	if (psh->next == NULL) {
		return;
	}

	pnext = (PM_SHM_STR *)((char *)psh + psh->size);

	if (pnext == psh->next) {
		if (pnext->flag > TYPE_SHM_ANSBUF ||
			(pnext->next && (((int)pnext->next & PM_ADDR_SHM) != PM_ADDR_SHM || (int)pnext->next >= PM_ADDR_SHM+6*1024*1024))) {
			syslog(1, "%s: corrupted SHM s=%d t=%d addr=%x next=%x", __func__, pnext->size, pnext->flag, (int)pnext, (int)pnext->next);
			return;
		}
		psh->size += pnext->size;
		psh->next = pnext->next;
	}
}
#endif

#ifdef IPDULIBTEST
static void pmshm_free_str(char *p)
{
	free(p);
}
#else
static void pmshm_free_str(char *p)
{
	PM_SHM_STR *psh = (PM_SHM_STR *)(p - sizeof(PM_SHM_STR));
	PM_SHM_STR *plist, *pold;


	pthread_mutex_lock(&shm_mtx);
	
	pold = NULL;
	plist = (PM_SHM_STR *)shmp->alloc_str;

	if (--psh->count > 0) {
		pthread_mutex_unlock(&shm_mtx);
		return;
	}

	// remove from used list
	while (plist) {
		if (plist == psh) {
			if (pold == NULL) {
				shmp->alloc_str = (char *)plist->next;
			} else {
				pold->next = plist->next;
			}
			break;
		}
		pold = plist;
		plist = plist->next;
	}

	if (plist == NULL) {
		pthread_mutex_unlock(&shm_mtx);
		return;
	}

	// put into free list
	plist = (PM_SHM_STR *)shmp->free_str;
	pold = NULL;

	while (plist != NULL && plist < psh) {
		pold = plist;
		plist = plist->next;
	}

	// at the beginning
	if (pold == NULL) {
		psh->next = (PM_SHM_STR *)shmp->free_str;
		shmp->free_str = (char *)psh;
		pmshm_group_str(psh);
		pthread_mutex_unlock(&shm_mtx);
		return;
	}

	// In the middle

	psh->next = pold->next;
	pold->next = psh;
	pmshm_group_str(psh);
	pmshm_group_str(pold);
	pthread_mutex_unlock(&shm_mtx);
}
#endif
#endif

//mp: needs review: Should be removed by the end of the project (ACS Classic).
//    It was introduced just to allow -Werror in pmd-gsp/Makefile
#ifndef LIBTESTCLASSIC
#ifdef SHM_MALLOC
#ifdef IPDULIBTEST
static char *pmshm_malloc(int size, int flag)
{
	return malloc(size);
}
#else
static char *pmshm_malloc(int size, int flag)
{
	PM_SHM_STR *pmin = NULL, *pold = NULL, *pnew, *pant = NULL;
	PM_SHM_STR *psh;

	if (!size) ++size;

	pthread_mutex_lock(&shm_mtx);

	if ((psh = (PM_SHM_STR *)shmp->free_str) == NULL) {
		pthread_mutex_unlock(&shm_mtx);
		syslog(1, "%s: fail to alloc s=%d t=%d in PMSHM", __func__, size, flag);
		return(NULL);
	}

	size = (size - 1 + sizeof(PM_SHM_STR) * 2) & 0xfffffff0;

	while (psh) {
		if (psh->size >= size) {
			// save previous
			if (!pmin) {
				pant = pold;
				pmin = psh;
			} else {
				if (pmin->size > psh->size) {
					pant = pold;
					pmin = psh;
				}
			}
		}
		pold = psh;
		psh = psh->next;
	}

	if (pmin == NULL) {
		pthread_mutex_unlock(&shm_mtx);
		syslog(1, "%s: pmin-fail to alloc s=%d t=%d in PMSHM", __func__, size, flag);
		return(NULL);
	}
	// previous
	psh = pant;

	if (pmin->size <= (size + sizeof(PM_SHM_STR) + 8)) {
		// remove the entry from free list
		pnew = pmin;
		if (psh == NULL) {
			shmp->free_str = (char *)pmin->next;
		} else {
			psh->next = pmin->next;
		}
	} else {
		// allocate from the end 
		pnew = (PM_SHM_STR *)( (char *)pmin + (pmin->size - size) );
		pmin->size -= size;
		pnew->size = size;
	}

	// build used list
	pnew->next = (PM_SHM_STR *)shmp->alloc_str;
	shmp->alloc_str = (char *)pnew;

	// clean the memory allocated
	memset(((char *)pnew + sizeof(PM_SHM_STR)), 0, pnew->size - sizeof(PM_SHM_STR));

	pnew->flag = flag;
	pnew->count = 1;

	pthread_mutex_unlock(&shm_mtx);
	return(((char *)pnew + sizeof(PM_SHM_STR)));
}
#endif
#endif
#endif

#ifdef SHM_HASH
// SDBM Hash Function
static unsigned long Hash(unsigned char *str)
{
	unsigned long hash = 0;
	int c;

	while ( (c = *str++) ) {
		if (c >= 'A' && c <= 'Z') c += 'a' - 'A';
		// hash(i) = hash(i - 1) * 65599 + str[i]; 
		hash = c + (hash << 6) + (hash << 16) - hash;
	}

	return hash;
}
#endif


#define WAIT_SYNC(x)  semtimedop(shmp->cmdbuff[x].buf_sem_id, shmp->cmdbuff[x].buf_ops + 2, 1,&myreq)	/* wait for semaphore [1] */
#define POST_SYNC(x)  semop(shmp->cmdbuff[x].buf_sem_id, shmp->cmdbuff[x].buf_ops + 3, 1)	/* post to  semaphore [1] */
#define TRYLOCK_SYNC(x)  semop(shmp->cmdbuff[x].buf_sem_id, shmp->cmdbuff[x].buf_ops + 4, 1)	/* trylock to  semaphore [1] */
#define WAIT_THREAD(x)  semop(shmp->cmdbuff[x].buf_sem_id, shmp->cmdbuff[x].buf_ops + 5, 1)	/* wait for semaphore [2] */
#define POST_THREAD(x)  semop(shmp->cmdbuff[x].buf_sem_id, shmp->cmdbuff[x].buf_ops + 6, 1)	/* post to  semaphore [2] */
#define TRYLOCK_THREAD(x)  semop(shmp->cmdbuff[x].buf_sem_id, shmp->cmdbuff[x].buf_ops + 7, 1)	/* trylock to  semaphore [2] */

#define WAIT_SHM  	semop(shmp->SemId, shmp->ops,     1)					/* wait for semaphore [0] */
#define POST_SHM  	semop(shmp->SemId, shmp->ops + 1, 1)					/* post to  semaphore [0] */
#define WAIT_STA  	semop(shmp->SemId, shmp->ops + 2, 1)					/* wait for semaphore [1] */
#define POST_STA  	semop(shmp->SemId, shmp->ops + 3, 1)					/* post to  semaphore [1] */
#define TRYLOCK_SHM  	semop(shmp->SemId, shmp->ops + 4, 1)					/* trylock to  semaphore [0] */

#endif //_sharedmem
