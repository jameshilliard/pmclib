/*****************************************************************
* File: shm-structs.h
*
* Copyright (C) 2006 Avocent Corporation
*
* www.avocent.com
*
* Description:
*     This file has general PMD definitions for GSP.
*
* Date: 06/30/2006
* Author: Daniel Belz <daniel.belz@avocent.com>
*
*****************************************************************/
#ifndef _sharedstructs
#define _sharedstructs

#include <sys/sem.h>
#include <power-mgmt-defs.h>
#include <power-mgmt-codes.h>
#include <pthread.h>

#ifdef USE_ACCOUNTING
#include <sys/time.h>
#include <sys/resource.h>
#endif

#define CUR_HYSTERESIS 10
#define TEMP_HYSTERESIS 5

//[RK]Sep/20/06 - fixed the address where the PM shared memory will be attached
// the PortSlave shared memory is attached in 0x3FF00000
#define PM_ADDR_SHM  0x3F000000

struct _ipduInfo;
struct _pmInfo; 

typedef struct _PM_SHM_STR {
	int  flag;
	int  count;
	int  size;
	struct _PM_SHM_STR *next;
} PM_SHM_STR;


typedef struct _answer {
	int size;
	unsigned char *buf;
	struct _answer *next;
} answer;

/// Structure to communicate between clients and core threads
typedef struct st_request {
	int status;
	int slot;
	unsigned char command_id;
	char username[USERNAMESIZE];
	unsigned int sequence;
	int argsize;
	unsigned char command_args[PMC_ARGSIZE];
	struct st_request *next;
	answer *answer_b;
} request;

/// Structure to synchronize between clients and core threads
typedef struct st_sema {
	int buf_sem_id;
	struct sembuf buf_ops[8];
} cmd_sema;

/// Structure to communicate between CORE and IPDU Threads
typedef struct st_cmdbuf_ds {
	int status;
	int buf_sem_id;
	struct sembuf buf_ops[7];
	unsigned char command_id;
	char username[USERNAMESIZE];
	int argsize;
	unsigned char command_args[PMC_ARGSIZE];
	struct st_cmdbuf_ds *next;
	answer *answer_b;
} COMMAND_S;

/* please keep alarm states in order of precedence */
typedef enum {
	ALARM_UNDEF,
	ALARM_NORMAL,
	ALARM_LOW,
	ALARM_LOWCRIT,
	ALARM_WARN,
	ALARM_CRIT,
} alarm_state_t;

typedef enum {
	UNDEFINED,
	ESTIMATED,
	MEASURED,
} value_type_t;

typedef struct _elecMonInfo {
	unsigned int cap;
	unsigned int flag;
	unsigned int sflag;
    int current;
    int min_current;
    int max_current;
    int avg_current;
	int nr_samples_current;
    int crit_threshold;		// Current High Critical Threshold
    int warn_threshold;		// Current High Warning Threshold
    int low_threshold;		// Current Low Warning Threshold
    int lowcrit_threshold;	// Current Low Critical Threshold
	alarm_state_t alarm_state;
    int voltage;			// Power type also defines the voltage nature
							// which can be either Measured or Nominal
    int min_voltage;
    int max_voltage;
    int avg_voltage;
	int nr_samples_voltage;
	value_type_t voltage_type; // Voltage Type: Measured or Estimated/Nominal
    int power;
    int min_power;
    int max_power;
    int avg_power;
	int nr_samples_power;
    value_type_t power_type;// Power Type: Measured or Estimated
    int power_fac;			// Power Factor
    int min_power_fac;
    int max_power_fac;
    int avg_power_fac;
	unsigned int nr_samples_power_fac;
	value_type_t power_fac_type;
	int last_cur_reading;   // Time of last current reading in secs since epoch
    int64_t energy;				// Cumulative Watt Hour
    int energy_start;		// Start time for accumulating energy
	unsigned char hwocp;
    unsigned char spclog;	// SPC log status (current threshold for SPC)
	//Blown fuse: from PMHD driver: FUSE_NOT, FUSE_OK, FUSE_BLOWN
	unsigned char blown_fuse;
} elecMonInfo;

typedef struct _envMonInfo {
	unsigned int cap;		// Capabilities
    unsigned int flag;		// Updated information
    unsigned int sflag;		// Updated information
    unsigned char number;	// Sensor number
	char name[ENVMONNAMESIZE+1];
	char sysname[ENVMONSYSNAMESIZE];	// System name
	int namehash;
	unsigned char sensor_type;	// type of sensor e.g. temperature, humidity
	int value;
	int unit;
    int min_value;
    int max_value;
    int avg_value;
	int nr_samples;
    int min_threshold;
	int min_warn_threshold;
	int max_warn_threshold;
    int max_threshold;
	alarm_state_t alarm_state;
	time_t last_update;
	int calibration;
	int hysteresis;
    struct _ipduInfo *ipdu;	// Pointer to the 'parent', the IPDU in the chain
} envMonInfo;

typedef struct _envMonList {
	unsigned char status;
	envMonInfo envMon[ENVMONLIST_SIZE]; 
	envMonInfo *envmon_ptr; /* access to the array above - needed because now we're reallocating memory as needed */
	pthread_mutex_t mutex;	/* required for multi port systems (ACS) - since this is shared with all */
	struct _envMonList *next;
} envMonList;

typedef struct _outletData {
	unsigned int cap;			// Capabilities
	unsigned int flag;			// Updated information
	unsigned int sflag;			// Information obtained
	unsigned char onumber;			// Outlet index in IPDU
	unsigned char defaultname;		// 1 if it uses a default name
	char name[OUTLETNAMESIZE+1];		// Unique outlet name, null terminated
	char sysname[OUTLETSYSNAMESIZE];	// System name
	unsigned long outnamehash;		// Outlet name hash
	unsigned char status;			// Outlet control status
	unsigned char mstatus;			// Outlet module status
	unsigned char rstatus;			// Outlet module status
	unsigned char pending;			// Operation Pending in queue.
	int minimum_on;				// Minimum on time
	int minimum_off;			// Minimum off time
	int post_power_on;			// Post-power on interval
	int post_power_off;			// Post-power off interval
	char wakeup;				// Wake-up outlet status
	int max_current;			// Max current
	elecMonInfo elecMon;			// electrical monitoring sensor
	struct _ipduInfo *ipdu;			// pointer to the IPDU on chain (num_ipdus)
} oData;

#ifdef HAVE_OUTLET_GROUPS
typedef struct _outletGroupMember {
	oData *outlet;
	struct _outletGroupMember *next;
} outletGroupMember;

typedef struct _outletGroup {
	char name[OUTLETNAMESIZE+1];
	unsigned long namehash;
	outletGroupMember *member;
	struct _outletGroup *next;
} outletGroup;
#endif

typedef struct _outletList {
	unsigned char status;
	oData outlets[OLIST_SIZE];
	struct _outletList *next;
} outletList;

typedef struct _phaseInfo {
	unsigned int cap;
	unsigned int flag;
	unsigned int sflag;
	unsigned char number;
	char name[PHASENAMESIZE+1];
	int namehash;
	unsigned char defaultname;
	char sysname[PHASESYSNAMESIZE+1];
	elecMonInfo elecMon;
	struct _ipduInfo *ipdu;
} phaseInfo;

typedef struct _circuitInfo {
	unsigned int cap;
	unsigned int flag;
	unsigned int sflag;
	unsigned char number;
	char name[CIRCNAMESIZE+1];
	int namehash;
	unsigned char defaultname;
	char sysname[CIRCSYSNAMESIZE+1];
	int max_current;			// Max current
	elecMonInfo elecMon;
	unsigned char num_outlets;
	struct _ipduInfo *ipdu;
} circuitInfo;

/* IPDU information structure */
typedef struct _ipduInfo {
	struct _pmInfo *pmInfo;			// pointer to the chain
	unsigned char number;			// IPDU index on chain
	char version[VERSIONSIZE];		// Sw Version
	char model[MODELSIZE];			// Model
	unsigned char model_nr;			// Model # from cyc_models.h
	unsigned char fpga;			// fpga version
	char ready;				// 1 if the IPDU is ready
	char defaultid;				// 1 if it uses a default ID
	unsigned char license;			// 1 if the IPDU is allowed to be managed
	unsigned int cap;			// Capabilities
	unsigned int flag;			// Update information
	unsigned int sflag;			// Information obtained
	char id[IPDUIDSIZE+1];			// IPDU name (ID)
	unsigned long idhash;			// IPDU ID hash 
	int max_current;			// Max current
	unsigned char num_inlets;		// number of inlets
	unsigned char inlet_type;
	unsigned char topology;			// Single, Delta, Wye, as defined in power-mgmt-codes.h
	unsigned char num_phases;
	phaseInfo phase[MAXPHASES];
	unsigned char num_circuits;
	circuitInfo circuit[MAXCIRCUITS];
	unsigned char num_outlets;		// number of outlets
	oData *outlet;
    elecMonInfo elecMon;
    unsigned char num_envMons;
    unsigned char num_local_envMons;
    envMonInfo *envMon;				// EnvMons are attached to the PDUs
	unsigned char overcurrent;
	unsigned char syslog;
	unsigned char buzzer;
	char display;
	char display_cycle;
	char config_reset_button;
	char cold_boot_alert;
	int cycledelay;
	int seqinterval;
	int coldstart_delay;
	unsigned char spclog;			// SPC log status
	struct _ipduInfo *next;			// Next IPDU on chain
} ipduInfo;

typedef struct ipduconfig {
	char username[USERNAMESIZE];
	char password[PASSWORDSIZE];
	int polltime;
} ipduconfig;

typedef struct _spcIpduConfig {
	unsigned long idhash;			// IPDU ID hash 
	int infeed;
	int polltime;
	int loadmax;
	int loadmin;
	struct _spcIpduConfig *next;
#ifndef PMDGSP
	int defvoltage;
	float pwrfactor;
	int numphases;
#endif

  
} spcipduconfig;

typedef struct _pmConfig {
	int ipdu_type;				// Device type (cyclades, spc)
	int speed;				// Port speed
	int datasize;				// Port data size
	int parity;				// Port parity
	int stop;				// Port Stop Bits
	int media;				// Port Media (rs232, sock, ssh, telnet)
	int flow;				// Port Flow control
	int pollrate;				// poll rate
	int pinout;				// pinout (Cyclades or Cisco)
	int speedad;				// speed auto detection
	int overcurrent;			// sw ocp 
	int syslog;				// syslog
	int buzzer;				// buzzer status
	int cycle_delay;			// cycle_delay
	unsigned int cap;			// capabilities of the chain
} pmConfig;

typedef	enum {
	TASK_ID_NOP,
	TASK_ID_OUTLETON,
	TASK_ID_OUTLETOFF,
} local_task_id;

typedef struct _local_task {
	local_task_id id;
	char number;
	int delay;
	struct _local_task *next;
} local_task;

typedef enum {
	ANSWER_IDLE, 				// No command to answer
	ANSWER_COMPLETE,			// Answer completed
	ANSWER_SLEEPING,			// Command sleeping, waiting for timeout
} local_answ_st;

typedef struct _local_board {
	char num_outlets;
	char num_phases;
	char num_singles;
	char num_banks;
} local_board;

typedef struct _local {
	int fd;					// File descriptor
	local_task *task;			// Task list
	local_answ_st answer_status;		// Command answer status
	time_t wake_task;				// Time to wake up the task
	time_t next_poll;			// Time for the next poll
	time_t conversion_timeout;		// Time Out for the conversion to finish
	char polltime;				// Polling time
	char conv_status;			// Conversion status
	time_t last_sample;			// time of the last sample
	char switched;				// type of PDU (switched=1, metered=0)
	char num_boards;			// number of outlet boards
	char buzzer;				// buzzer state
	local_board *board;			// mapping of board/outlet
} local;

/* chain information structure */
typedef struct _pmInfo {
	pthread_mutex_t mutex;
	unsigned char port;			// Logical port number (order in linked list)
	unsigned char number;			// Physical port number (n on ttySn)
	char device[DEVICENAMESIZE];		// Physical port string (ttySn)
	unsigned char got_num_ipdus;		// 1 if the number of IPDUs was  gotten from the library
	unsigned char console_msg_status;	// 1 if need to report status change to console (like PM legacy)
	unsigned char num_ipdus;		// Number of IPDUs on chain
	unsigned char status;			// IPDU STATUS
	unsigned char ipdu_type;
	unsigned char start;
	unsigned char pending;		// chain busy for outlet commands. 
	int fdpipe[2];				// pipe file descriptors. 1=write, 0=read
	ipduInfo *ipdu;				// IPDU RTS for each IPDU on chain (num_ipdus)
	pmConfig pmconf;			// Physical configuration for this IPDU/Port
	COMMAND_S cmdbuff;			// Each chain can handle one command at time
	pthread_t thread_id;
	struct _ti *td;
	struct _local *local;
	struct _pmInfo *next;			// Next IPDU
} pmInfo;

#ifdef USE_ACCOUNTING
typedef struct _acct {
	int inittime;
	int uptime;
	int lastHUPtime;
	unsigned int cmdRXfromCLI;
	unsigned int cmdTXtoIPDUth;
	struct rusage usage;
} accounting;
#endif

typedef struct _packet {
	unsigned char size;
	unsigned char type;
	unsigned char data[PMC_ARGSIZE];
	struct _packet *next;
} packet;

typedef struct _packetheader {
	unsigned char operation; 
	unsigned char element;
	unsigned char size;
	unsigned char code;
	unsigned char data[PMC_ARGSIZE];
	packet *pkt;
} packetheader;

typedef struct _srvtechpdu {
	unsigned char port;
	unsigned char ipdu;
} srvtechpdu;

/*  beginning here are typedefs for pmd-gsp on ACS Classic */
typedef struct acl {
	unsigned long userhash;
	unsigned long devicehash;
	unsigned long ipduhash;
	unsigned long outlethash;
	unsigned char outletnum;
} acl;

typedef struct groupmember {
	char ipduname[OUTLETNAMESIZE+1];
	char outlname[OUTLETNAMESIZE+1];
	int outletnum;
} groupmember;

typedef struct outletgroup {
	char groupname[OUTLETNAMESIZE+1];
	int numOfMembers;
	groupmember *groupmembers;
	struct outletgroup *next;
} outletgroup;

typedef struct usercfg {
	char *username;
	unsigned long userhash;
} userconfig;
/*  end of typedefs for pmd-gsp on ACS Classic */

typedef struct pmshm_control {
	pthread_mutex_t request_mutex;
	pthread_cond_t  got_request;
	pthread_cond_t  got_req_slot0;
	int num_requests;
	int num_req_outcmd;
	int total_delay_outcmd;
	int ShmId;
	int SemId;
	struct sembuf ops[5];			// Core/Client synchronization 
	unsigned char corestatus;		// Core status flag
	request *requests;
	request *req_outcmd;
	unsigned int sequence;
	unsigned int alarm_count;
	cmd_sema cmdbuff[MAX_SLOTS];
	pmInfo *pmInfo;
	char *alloc_str;
	char *free_str;
	char ignore_answer;
	srvtechpdu *license;
	ipduconfig cyclades, spc, servertech;
	spcipduconfig *spccfg;
	outletList *olist;
	envMonList *envmonlist;
#ifdef PMDGSP
#ifdef HAVE_OUTLET_GROUPS
	outletGroup *oGroup[MAXGROUPS];
#endif
#else
	outletgroup *oGroups;    //Outlet Groups for ACS Classic
#endif
	unsigned char *firmware;
	int fw_size;
	int fw_progress;
	int fw_lock;
	int fw_result;
	int ipduidx;
	packetheader *allList;
	int changepending;
	char prefix[8];
#ifdef USE_ACCOUNTING
	accounting acct;
#endif
#ifndef PMDGSP
	char *stports;
	acl *gacl;        //Access Control List for ACS Classic
#endif
	char strings[1];  //!!ATTENTION:THIS MEMBER MUST BE LAST!! New member variables must be added above this line
} SHARED_DATA;

typedef struct port {
	char *physicalport;
	ipduconfig *ipdu;
} port;

/** Semaphore Stuff */
#if defined(__GNU_LIBRARY__) && !defined(_SEM_SEMUN_UNDEFINED)
#else
#undef _SEM_SEMUN_UNDEFINED
union semun {				/* define union for semctl() */
  int              val;
  struct semid_ds *buf;
  unsigned short  *array;
};
#endif

#endif //_sharedstructs
