/*****************************************************************
* File: pm_debug.h
*
* Copyright (C) 2006 Avocent Corporation
*
* www.avocent.com
*
* Description:
*     This file describes the prototypes and definitions used 
*     for system debugging
*
* Date: 05/31/2006
* Author: Helio Fujimoto <helio.fujimoto@avocent.com>
* Date: 06/30/2006
* Author: Daniel Belz <daniel.belz@avocent.com>
* 	Importing the kvmd debug style
*
****************************************************************/

#ifndef __PM_DEBUG_H__
#define __PM_DEBUG_H__

#include <stdio.h>
#include <stdarg.h>
#ifdef PMDGSP
#include <dlog.h>
#else
#define DLOG_EMERGENCY 0
#define DLOG_ALERT     ( DLOG_EMERGENCY + 1 )
#define DLOG_CRITICAL  ( DLOG_EMERGENCY + 2 )
#define DLOG_ERROR     ( DLOG_EMERGENCY + 3 )
#define DLOG_WARNING   ( DLOG_EMERGENCY + 4 )
#define DLOG_NOTICE    ( DLOG_EMERGENCY + 5 )
#define DLOG_INFO      ( DLOG_EMERGENCY + 6 )
#define DLOG_DEBUG     ( DLOG_EMERGENCY + 7 )
#define DLOG_NONE      ( DLOG_EMERGENCY - 1 )

enum {
	CMSG = 0,
	READ_ACL = 1,
	READ_CONFIG,  	// 2
	PARSE_OUTLET,  	// 3
	MANAGE_ACL,  	// 4
	SHM_OPERATIONS,	// 5
	CORE,  		// 6
	IPDU_THREAD,  	// 7
	CORE_THREADS,  	// 8
	IPDULIB,  	// 9
	READ_OG,  	// 10
	SHM_DEBUG,  	// 11
	PMCLIB,		// 12 generic functions on pmclib.c
	PMCLIB_SHOW,	// 13 show functions on pmc_show.c
	PMCLIB_BUILD,	// 14 build functions on pmc_build.c
	PMCLIB_VALIDATE, // 15 validate functions on pmc_validate.c
	CMD_XCHANGE,     // 16 commands exchange between client, core and ipduthread
	TRACE		// 17
};

#endif //PMDGSP

#ifdef DEBUG
#ifdef PMDGSP
#define debug(level, fmt, P...) \
	if (debugFlag) { \
		printf("(%d)%s[%d] - " fmt "\n", (unsigned int)level, __FILE__, __LINE__, ##P); \
	} else { \
		dlog_printf(level, __FUNCTION__, "%s[%d] - " fmt "\n", __FILE__, __LINE__, ##P); \
	}
#else
#define debug(level, fmt, P...) \
	if (debugFlag) { \
		printf("(%d)%s[%d] - " fmt "\n", (unsigned int)level, __FILE__, __LINE__, ##P); \
	}
#endif //PMDGSP
#define dodebug(fmt, arg...) debugprintf(fmt, ##arg);
#define dotrace(hdr, name, buf, size) traceprintf(hdr, name, buf, size)
extern int traceEnable;
extern int debugFlag;
extern void debugprintf(const char *fmt, ...);
extern void traceprintf(const char *header, char *name, char *buf, int size);
#else
#define debug(level, fmt, P...)
#endif //DEBUG

#ifdef CONFIG_PMHD
extern void switch_driver_debug(void);
#endif

#endif

