/*****************************************************************
* File: power-mgmt-defs.h
*
* Copyright (C) 2006 Avocent Corporation
*
* www.avocent.com
*
* Description:
*     This file has general PMD-NG definitions.
*
* Date: 05/31/2006
* Author: Helio Fujimoto <helio.fujimoto@avocent.com>
* Date: 06/30/2006
* Author: Daniel Belz <daniel.belz@avocent.com>
* 	Adding configuration, shared memory and core definitions
*
*****************************************************************/
#ifndef _pmdefs
#define _pmdefs

#define COMMANDSIZE		128
#define USERNAMESIZE		32
#define PASSWORDSIZE		32
#define OUTLETNAMESIZE		32
#define OUTLETSYSNAMESIZE	7
#define IPDUIDSIZE		32
#define VERSIONSIZE		32
#define MODELSIZE		16
#define DEVICENAMESIZE		32
#define PHASENAMESIZE	32
#define PHASESYSNAMESIZE	3
#define CIRCNAMESIZE	32
#define CIRCSYSNAMESIZE	4
#define ENVMONNAMESIZE      35
#define ENVMONSYSNAMESIZE   4

#define DEFAULT_POLLTIME 	20
#define SERVERTECH_KEEP_ALIVE_TIME 	50

#define MAX_PREFIX_LENGTH 	16
#define MAX_NAME_LENGTH   	32
#define MAX_ANAME_LENGTH   	33

#define INIT_READY 		0x80

//#define SHM_ID 		0xFACBADEC
#define SHM_ID 		0xAAAA4567
#define MAXOutletsPS    129
#define MAX_PMC_MENU    512
#define PMC_CMDSIZE     64
#define PMC_OUTLETS     128
#define MAX_CHAINS      256
#define MAXPHASES	3
#define MAXCIRCUITS	6

#define SHM_PERM 	0666

#define ARGSIZE 	512
#define MAXACCESS    	100
#define MAX_SLOTS    	5
#define PMC_ARGSIZE	128
#define OLIST_SIZE 	255
#define ENVMONLIST_SIZE		64

#ifdef HAVE_OUTLET_GROUPS
#define MAXGROUPS	255
#endif

#define MAXMSGSIZE 1024

#define PMD_SID	"pmd_ng"

#define BANK_MAX_CURRENT       20      //20A
#define OUTLET_MAX_CURRENT     20      //20A

enum {
	SLOT_IDLE=0,
	WAITING_ANSWER,
	ANSWER_RECEIVED,
	BACKGROUND
};

enum {
	IPDU_TYPE_AUTO=0,
	IPDU_TYPE_CYCLADES,
	IPDU_TYPE_SPC,
	IPDU_TYPE_SERVERTECH
};

enum {
	PINOUT_CYCLADES=0,
	PINOUT_CISCO
};

enum {
	NOT_IN_USE=0,
	IN_USE,
	COREACK,
	COREANS
};

enum {
	TYPE_SHM_STRING=0,
	TYPE_SHM_PMINFO,
	TYPE_SHM_IPDUINFO,
	TYPE_SHM_OUTLINFO,
	TYPE_SHM_IPDUBUF,
	TYPE_SHM_PMC,
	TYPE_SHM_ACL,
	TYPE_SHM_OGROUP,
	TYPE_SHM_OLIST,
	TYPE_SHM_ENVMONLIST,
	TYPE_SHM_PHEADER,
	TYPE_SHM_PACKET,
	TYPE_SHM_ANSBUF,
};

enum {
	FLOW__NONE=0, 
	FLOW__HARD,
	FLOW__SOFT,
	FLOW__RXON,
	FLOW__TXON
};

enum {
	PARITY_NONE=0,
	PARITY_ODD,
	PARITY_EVEN
};

enum {
    TempScaleF,
    TempScaleC,
    TempScaleK,
};

#define UPTIME_AFU	1	//Undefine it to switch to m/s and ft/s instead of afu

#ifdef UPTIME_AFU
enum {
    AirFlowScaleAFU,
};
#else
enum {
    AirFlowScaleFeet,
    AirFlowScaleMeters,
};
#endif //UPTIME_AFU

#define OUTL_DIRTY 	0xfe
#define ENVML_DIRTY 0xfe

#define PARAMLISTSIZE	16
#define MAXOUTLETS 	45
#define DEFAULT_PREFIX  "o"
#define DEFAULT_IPDU_PREFIX  "i"

#define USER_ROOT	"root"

#define SRVTECH_CFG_FILE 	"/etc/.servertech"
#define SRVTECH_TEMP	 	"/tmp/svt"
#ifdef PMDGSP
#define DSVIEW_CERTIFICATE 	"/etc/adsap2/remote_x509.pem"
#define APPLIANCE_PRIVATE_KEY 	"/etc/adsap2/local_key.pem"
#else // ACS Classic
#define DSVIEW_CERTIFICATE      "/root/.ssh/dsview.pem"
#define APPLIANCE_PRIVATE_KEY   "/etc/CA/server.pem"
#endif
#define PMDPIDFILE	"/var/run/pmdng.pid"
#define AUTO_STR	"auto"
#define CYCLADES_STR 	"cyclades"
#define SPC_STR		"spc"
#define SERVERTECH_STR	"servertech"
#define STRNONE 	"none"
#define STRALL 		"all"
#define AUTO_SIZE   	4
#define CYCLADES_SIZE   8
#define SPC_SIZE 	3
#define SERVERTECH_SIZE 10
#define ALL_SIZE 	3
#define NONE_SIZE 	4

#ifdef PMDGSP
#else
#define PMDCONFFILE	"/etc/pmd.conf"
#define PMDUSERFILE	"/etc/pmd.users"
#define PMDOUTGROUPSFILE "/etc/pmdgrp.conf"
#define PMDCONFFILE	"/etc/pmd.conf"

#endif

/// ACL config flag values
#define IPDU_NUMBER 		0x01
#define OUTLET_NUMBER 		0x02
#define FULL_IPDU_ACCESS 	0x04
#define FULL_ACCESS 		0x08
#define NONE_ACCESS 		0x10
#define NONE_IPDU_ACCESS 	0x20
#define SPECIFIC_ACCESS		0x80

#define STATUS 		0
#define IPC_MODE		0666		/* O_RDWR for owner and group members */
#define IPC_CREATE_FLAG	IPC_CREAT | IPC_EXCL | IPC_MODE
#define IPC_OPEN_FLAG	IPC_MODE | IPC_CREAT

#define TRIM(x) while(*x && isspace(*x)) x++

#define GOTO_LAST(p, n) \
	while (n) { \
		p = n;\
		n = n->next; \
	}

#define GOTO_NEXT(p, n) { \
		p = n;\
		n = n->next; \
	}

#define FREE_LIST(p, n) \
	do { \
		n = p->next; \
		free(p); \
		p = n; \
	} while (n); 

#define FREE_SLIST(p, n) \
	do { \
		n = p->next; \
		pmshm_free_str((char *)p); \
		p = n; \
	} while (n); 

#define MAX_OUTLET_LIST 128
#define OUTLIST_LEN             100
struct outlet_list {
        int outx;
        int port;
        int pdu;
        int outlet;
        char input[OUTLIST_LEN+1];
};

#endif //_pmdefs
