/*****************************************************************
* File: power-mgmt-codes.h
*
* Copyright (C) 2006 Avocent Corporation
*
* www.avocent.com
*
* Description:
*     This file has the PM protocol definitions.
*
* Date: 05/31/2006
* Author: Helio Fujimoto <helio.fujimoto@avocent.com>
*
*****************************************************************/
#ifndef _pmcodes
#define _pmcodes

/*****************************************************************
 * List of element codes 
 *****************************************************************/
#define PROTO_ELEMENT_COMMAND				0x01
#define PROTO_ELEMENT_MESSAGE_ID			0x02
#define PROTO_ELEMENT_USERNAME				0x03
#define PROTO_ELEMENT_PASSWORD				0x04

#define PROTO_ELEMENT_CHAIN_POLL_RATE			0x06
#define PROTO_ELEMENT_CHAIN_NUMBER			0x07
			
#define PROTO_ELEMENT_IPDU_CAPABILITIES			0x10
#define PROTO_ELEMENT_IPDU_NUMBER			0x11
#define PROTO_ELEMENT_IPDU_ID				0x12
#define PROTO_ELEMENT_IPDU_MODEL			0x13
#define PROTO_ELEMENT_IPDU_VERSION			0x14
#define PROTO_ELEMENT_IPDU_MAXCURRENT			0x15
#define PROTO_ELEMENT_IPDU_INLET_TYPE			0x16 //Nazca/Stonehenge cable type
#define PROTO_ELEMENT_IPDU_TOPOLOGY			0x17
#define PROTO_ELEMENT_IPDU_SERIAL			0x18 //Nazca/SH serial 115200/hard

#define PROTO_ELEMENT_NUMBER_IPDUS			0x20
#define PROTO_ELEMENT_NUMBER_OUTLETS			0x21
#define PROTO_ELEMENT_NUMBER_INLETS			0x22
#define PROTO_ELEMENT_NUMBER_PHASES			0x24
#define PROTO_ELEMENT_NUMBER_CIRCUITS			0x25
#define PROTO_ELEMENT_NUMBER_ENVMONS			0x26

#define PROTO_ELEMENT_OUTLET_CAPABILITIES		0x30
#define PROTO_ELEMENT_OUTLET_NUMBER			0x31
#define PROTO_ELEMENT_OUTLET_NAME			0x32
#define PROTO_ELEMENT_OUTLET_CONTROL_ID			0x33
#define PROTO_ELEMENT_OUTLET_MINIMUM_ON_TIME		0x34
#define PROTO_ELEMENT_OUTLET_MINIMUM_OFF_TIME		0x35
#define PROTO_ELEMENT_OUTLET_POST_ON_INTERVAL		0x36
#define PROTO_ELEMENT_OUTLET_POST_OFF_INTERVAL		0x37
#define PROTO_ELEMENT_OUTLET_WAKEUP			0x38
#define PROTO_ELEMENT_OUTLET_MODULE_STATUS		0x39
#define PROTO_ELEMENT_OUTLET_SYSNAME			0x3A
#define PROTO_ELEMENT_OUTLET_RELAY_STATUS		0x3B
#define PROTO_ELEMENT_OUTLET_CONTROL_STATUS		0x3C
#define PROTO_ELEMENT_OUTLET_OPERATION_STATUS	0x3D

#define PROTO_ELEMENT_CIRCUIT_CAPABILITIES		0x40
#define PROTO_ELEMENT_CIRCUIT_NUMBER			0x41
#define PROTO_ELEMENT_CIRCUIT_NAME			0x42
#define PROTO_ELEMENT_CIRCUIT_SYSNAME			0x43
#define PROTO_ELEMENT_CIRCUIT_CONTROL_ID		0x44

#define PROTO_ELEMENT_PHASE_CAPABILITIES		0x50
#define PROTO_ELEMENT_PHASE_NUMBER			0x51
#define PROTO_ELEMENT_PHASE_NAME			0x52
#define PROTO_ELEMENT_PHASE_SYSNAME			0x53
#define PROTO_ELEMENT_PHASE_TYPE			0x54 //not used in ipdulib

#define PROTO_ELEMENT_IPDU_THRESHOLD			0x60 //not used in ipdulib
#define PROTO_ELEMENT_IPDU_SYSLOG			0x61
#define PROTO_ELEMENT_IPDU_BUZZER			0x62
#define PROTO_ELEMENT_IPDU_OVERCURRENT			0x63
#define PROTO_ELEMENT_IPDU_DISPLAY			0x64
#define PROTO_ELEMENT_IPDU_CONFIG_RESET_BUTTON		0x65
#define PROTO_ELEMENT_IPDU_COLDBOOT_ALERT		0x66
#define PROTO_ELEMENT_IPDU_REBOOT_DELAY			0x67
#define PROTO_ELEMENT_IPDU_SEQ_INTERVAL			0x68
#define PROTO_ELEMENT_IPDU_COLDSTART_DELAY		0x69

#define PROTO_ELEMENT_ELECMON_CAPABILITIES		0x70
#define PROTO_ELEMENT_ELECMON_CUR_CRIT_THRES	0x71
#define PROTO_ELEMENT_ELECMON_CUR_WARN_THRES	0x72
#define PROTO_ELEMENT_ELECMON_CUR_LOW_THRES		0x73
#define PROTO_ELEMENT_ELECMON_CUR_LOWCRIT_THRES	0x74
#define PROTO_ELEMENT_ELECMON_CURRENT			0x75
#define PROTO_ELEMENT_ELECMON_MIN_CURRENT		0x76
#define PROTO_ELEMENT_ELECMON_MAX_CURRENT		0x77
#define PROTO_ELEMENT_ELECMON_AVG_CURRENT		0x78
#define PROTO_ELEMENT_ELECMON_RESET_CURRENT		0x79
#define PROTO_ELEMENT_ELECMON_VOLTAGE			0x7A
#define PROTO_ELEMENT_ELECMON_MIN_VOLTAGE		0x7B
#define PROTO_ELEMENT_ELECMON_MAX_VOLTAGE		0x7C
#define PROTO_ELEMENT_ELECMON_AVG_VOLTAGE		0x7D
#define PROTO_ELEMENT_ELECMON_RESET_VOLTAGE		0x7E
#define PROTO_ELEMENT_ELECMON_VOLTAGE_TYPE		0x7F
#define PROTO_ELEMENT_ELECMON_POWER				0x80
#define PROTO_ELEMENT_ELECMON_MIN_POWER			0x81
#define PROTO_ELEMENT_ELECMON_MAX_POWER			0x82
#define	PROTO_ELEMENT_ELECMON_AVG_POWER			0x83
#define	PROTO_ELEMENT_ELECMON_RESET_POWER		0x84
#define PROTO_ELEMENT_ELECMON_POWER_TYPE		0x85
#define PROTO_ELEMENT_ELECMON_POWER_FACTOR		0x86
#define PROTO_ELEMENT_ELECMON_POWER_FACTOR_TYPE		0x87
#define PROTO_ELEMENT_ELECMON_MIN_POWER_FACTOR		0x88
#define PROTO_ELEMENT_ELECMON_MAX_POWER_FACTOR		0x89
#define PROTO_ELEMENT_ELECMON_AVG_POWER_FACTOR		0x8A
#define PROTO_ELEMENT_ELECMON_RESET_POWER_FACTOR	0x8B
#define PROTO_ELEMENT_ELECMON_ENERGY				0x8C
#define PROTO_ELEMENT_ELECMON_RESET_ENERGY			0x8D
#define PROTO_ELEMENT_ELECMON_ENERGY_START_TIME		0x8E
#define PROTO_ELEMENT_ELECMON_THRES_STATUS			0x8F
#define PROTO_ELEMENT_ELECMON_HWOCP					0x90
#define PROTO_ELEMENT_ELECMON_BLOWNFUSE				0x91

#define PROTO_ELEMENT_ENVMON_CAPABILITIES			0x95
#define PROTO_ELEMENT_ENVMON_NUMBER					0x96
#define PROTO_ELEMENT_ENVMON_NAME					0x97
#define PROTO_ELEMENT_ENVMON_SYSNAME				0x98
#define PROTO_ELEMENT_ENVMON_CRIT_THRESHOLD			0x99
#define PROTO_ELEMENT_ENVMON_CRIT_WARN_THRESHOLD	0x9A
#define PROTO_ELEMENT_ENVMON_LOW_WARN_THRESHOLD		0x9B
#define PROTO_ELEMENT_ENVMON_LOW_THRESHOLD			0x9C
#define PROTO_ELEMENT_ENVMON_VALUE					0x9D
#define PROTO_ELEMENT_ENVMON_MIN_VALUE				0x9E
#define PROTO_ELEMENT_ENVMON_MAX_VALUE				0x9F
#define PROTO_ELEMENT_ENVMON_AVG_VALUE				0xA0
#define PROTO_ELEMENT_ENVMON_RESET_VALUE			0xA1
#define PROTO_ELEMENT_ENVMON_SENSOR_TYPE			0xA2
#define PROTO_ELEMENT_ENVMON_UNIT					0xA3

#define PROTO_ELEMENT_SYSLOG				0xB0
#define PROTO_ELEMENT_XMODEM				0xB1

#define PROTO_ELEMENT_UPGRADE_IPDUS			0xC0
#define PROTO_ELEMENT_UPGRADE_PROGRESS		0xC1


/*****************************************************************
 * List of command codes
 *****************************************************************/
#define COMMAND_OUTLET_OPERATION	1
#define COMMAND_OUTLET_INFORMATION	2
#define COMMAND_OUTLET_NAME		3
#define COMMAND_USER_ADD		4
#define COMMAND_USER_DELETE		5
#define COMMAND_USER_PASSWORD		6
#define COMMAND_USER_ASSIGN		7
#define COMMAND_USER_UNASSIGN		8
#define COMMAND_USER_INFO		9
#define COMMAND_IPDU_OPERATION		10
#define COMMAND_IPDU_INFORMATION	11
#define COMMAND_IPDU_ID			12
#define COMMAND_RESTORE			13
#define COMMAND_SAVE			14
#define COMMAND_DEFAULTS		15
#define COMMAND_REBOOT			16
#define COMMAND_UPGRADE			17
#define COMMAND_UPGRADE_FN		18
#define COMMAND_CHAIN_INFORMATION	19
#define COMMAND_CHAIN_OPERATION		20
#define COMMAND_CHAIN_NAME		21
#define COMMAND_PHASE_OPERATION		22
#define COMMAND_PHASE_INFORMATION	23
#define COMMAND_PHASE_NAME		24
#define COMMAND_CIRCUIT_OPERATION	25
#define COMMAND_CIRCUIT_INFORMATION	26
#define COMMAND_CIRCUIT_NAME		27
#define COMMAND_ENVMON_OPERATION	28
#define COMMAND_ENVMON_INFORMATION	29
#define COMMAND_ENVMON_NAME		30

/*****************************************************************
 * Possible values for outlet control
 *****************************************************************/
#define OUTLET_CONTROL_OFF		1
#define OUTLET_CONTROL_ON		2
#define OUTLET_CONTROL_CYCLE	3
#define OUTLET_CONTROL_LOCK		4
#define OUTLET_CONTROL_UNLOCK	5
#define OUTLET_CONTROL_IOFF		6
#define OUTLET_CONTROL_ION		7

/*****************************************************************
 * Possible values for circuit control
 *****************************************************************/
#define CIRCUIT_CONTROL_OFF		1
#define CIRCUIT_CONTROL_ON		2
#define CIRCUIT_CONTROL_CYCLE	3

/*****************************************************************
 * Possible values for outlet status
 *****************************************************************/
#define OUTLET_STATUS_OFF			1
#define OUTLET_STATUS_ON			2
#define OUTLET_STATUS_LOCK_OFF		3
#define OUTLET_STATUS_LOCK_ON		4
#define OUTLET_STATUS_CYCLE			5
//FIXME: core_info test status%2 to decide if status changed, 
// thus all OFFs must be odd numbers and ONs even numbers.
// Note that CYCLE/PEND_CYCLE, OFF/PEND_ON, ON/PEND_OFF follows the rule above  
// Changing this may impact configuration which saves the status code
// istead of parsing/deparsing a string. For now it seems OK since
// it saves only codes 1,2,3,4. 
#define OUTLET_STATUS_PEND_CYCLE	6
#define OUTLET_STATUS_PEND_ON		7
#define OUTLET_STATUS_PEND_OFF		8
#define OUTLET_STATUS_IDLE_OFF		9
#define OUTLET_STATUS_IDLE_ON		10
#define OUTLET_STATUS_WAKE_OFF		11
#define OUTLET_STATUS_WAKE_ON		12
#define OUTLET_STATUS_NOT_SET		13
#define OUTLET_STATUS_FIXED_ON		14
#define OUTLET_STATUS_SHUTDOWN		15

#define OUTLET_MODSTATUS_OFF		1
#define OUTLET_MODSTATUS_ON			2
#define OUTLET_MODSTATUS_OFF_ERR	3
#define OUTLET_MODSTATUS_ON_ERR		4
#define OUTLET_MODSTATUS_OFF_WAIT	5
#define OUTLET_MODSTATUS_ON_WAIT	6
#define OUTLET_MODSTATUS_OFF_FUSE	7
#define OUTLET_MODSTATUS_ON_FUSE	8
#define OUTLET_MODSTATUS_OCP_OFF	9
#define OUTLET_MODSTATUS_READING	10
#define OUTLET_MODSTATUS_COMM_ERR	11

#define OUTLET_RELSTATUS_OFF		1
#define OUTLET_RELSTATUS_ON			2

/*****************************************************************
 * List of error codes
 *****************************************************************/
#define ERROR_IDLE_TIMEOUT		1
#define ERROR_NOT_LOGGED		2
#define ERROR_ACCESS_DENIED		3
#define ERROR_INVALID_IPDU_NUMBER	4
#define ERROR_INVALID_IPDU_ID		5
#define ERROR_DUPLICATED_IPDU_ID	6
#define ERROR_INVALID_OUTLET_NUMBER	7
#define ERROR_INVALID_OUTLET_NAME	8
#define ERROR_DUPLICATED_OUTLETNAME	9
#define ERROR_OUTLET_LOCKED		10
#define ERROR_OVERCURRENT		11
#define ERROR_OUTLET_NOT_ON		12
#define ERROR_OUTLET_NOT_OFF		13
#define ERROR_INVALID_THRESHOLD		14	
#define ERROR_QUEUE_FULL		15	
#define ERROR_QUEUE_EMPTY		16	
#define ERROR_RESTORE_FAILED		17
#define ERROR_SAVE_DONE			18
#define ERROR_SAVE_FAILED		19
#define ERROR_DEFAULT_DONE		20
#define ERROR_IPDU_NOT_READY		21
#define ERROR_IPDU_BUSY			22
#define ERROR_CONNECTION_LOST		23
#define ERROR_IPDU_RESTARTED		24
#define ERROR_TIMEOUT			25
#define ERROR_UNSUPPORTED_COMMAND	26
#define ERROR_RESTORE_DONE		27
#define ERROR_INVALID_INTERVAL		28
#define ERROR_HWOCP_RESET		29
#define ERROR_COMMAND_NOT_EXECUTED	30
#define ERROR_REBOOT_DONE		31
#define ERROR_UPGRADE_TIMEOUT		32
#define ERROR_UPGRADE_ERROR		33
#define ERROR_UPGRADE_DONE		34
#define ERROR_CURRENT_OVER		35
#define ERROR_CURRENT_BACK		36
#define ERROR_PASSWD_ERROR		37
#define ERROR_PASSWD_DONE		38
#define ERROR_INVALID_WAKEUP		39
#define ERROR_INVALID_POWER_FACTOR	40
#define ERROR_OUTLET_FIXED_ON		41
#define ERROR_INVALID_ENVMON_NAME	42

/****************************************************************************
 * List of IPDU capabilities
 ***************************************************************************/
#define IPDU_CAPABILITIES_LENGHT	4	// IPDU capabilities fits in 4 bytes

#define IPDU_CAP_ID				0x00000001
#define IPDU_CAP_VERSION		0x00000002
#define IPDU_CAP_MODEL			0x00000004
#define IPDU_CAP_MAXCURRENT		0x00000008
#define IPDU_CAP_BUZZER			0x00000010
#define IPDU_CAP_SYSLOG			0x00000020
#define IPDU_CAP_OVERCURRENT	0x00000040
#define IPDU_CAP_DISPLAY		0x00000080
#define IPDU_CAP_CONFIGRESET	0x00000100
#define IPDU_CAP_COLDBOOTALERT	0x00000200
#define IPDU_CAP_REBOOTDELAY	0x00000400
#define IPDU_CAP_NOT_SWITCHABLE	0x00000800
#define IPDU_CAP_SEQINTERVAL	0x00001000
#define IPDU_CAP_OUTLETS		0x00002000
#define IPDU_CAP_INLETS			0x00004000
#define IPDU_CAP_INLET_TYPE		0x00008000 //Nazca/Stonehenge cable type
#define IPDU_CAP_DISPLAY_CYCLE	0x00010000
#define IPDU_CAP_PHASE			0x00020000
#define IPDU_CAP_CIRCUIT		0x00040000
#define IPDU_CAP_ELECMON		0x00080000
#define IPDU_CAP_ENVMON			0x00100000
#define IPDU_CAP_COLDSTARTDELAY	0x00200000
#define IPDU_CAP_TOPOLOGY		0x00400000
#define IPDU_CAP_FPGA			0x00800000 /* fpga version */
#define IPDU_CAP_SPEEDFLOW		0x01000000 /* allow HW flow control & 115200 */

/*****************************************************************
 * List of phase capabilities
 *****************************************************************/
#define PHASE_CAP_NAME			0x01 //not used in ipdulib
#define PHASE_CAP_SYSNAME		0x02
#define PHASE_CAP_TYPE			0x04 //not used in ipdulib
#define PHASE_CAP_ELECMON		0x08
#define PHASE_CAP_NOT_PRESENT   0x10

/*****************************************************************
 * List of circuit capabilities
 *****************************************************************/
#define CIRCUIT_CAP_NAME		0x01 //not used in ipdulib
#define CIRCUIT_CAP_SYSNAME		0x02
#define CIRCUIT_CAP_OUTLETS 		0x04
#define CIRCUIT_CAP_ELECMON		0x08
#define CIRCUIT_CAP_NOT_PRESENT   0x20

/*****************************************************************
 * List of outlet capabilities
 *****************************************************************/
#define OUTLET_CAPABILITIES_LENGHT	2	// Outlet capabilities fits in 2 bytes

#define OUTLET_CAP_NAME			0x0001
#define OUTLET_CAP_STATUS		0x0002
#define OUTLET_CAP_MINIMUMON		0x0004
#define OUTLET_CAP_MINIMUMOFF		0x0008
#define OUTLET_CAP_POSTPOWERON		0x0010
#define OUTLET_CAP_POSTPOWEROFF		0x0020
#define OUTLET_CAP_WAKEUP		0x0040
#define OUTLET_CAP_MODSTATUS		0x0080
#define OUTLET_CAP_SYSNAME		0x0100
#define OUTLET_CAP_RELSTATUS		0x0200
#define OUTLET_CAP_ELECMON		0x0400

/****************************************************************
 * List of Port Capabilities
 ****************************************************************/
#define PORT_CAP_POLLING_RATE		0x1
/****************************************************************************
 * List of ElecMon capabilities
 ***************************************************************************/
#define ELECMON_CAPABILITIES_LENGHT	4	// Elecmon capabilities fits in 4 bytes

#define ELECMON_CAP_CUR_CRIT_THRES		0x00000001
#define ELECMON_CAP_CUR_WARN_THRES		0x00000002
#define ELECMON_CAP_CUR_LOW_THRES		0x00000004
#define ELECMON_CAP_CUR_LOWCRIT_THRES	0x00000008
#define ELECMON_CAP_CURRENT				0x00000010
#define ELECMON_CAP_MIN_CURRENT			0x00000020
#define ELECMON_CAP_MAX_CURRENT			0x00000040
#define ELECMON_CAP_AVG_CURRENT			0x00000080
#define ELECMON_CAP_VOLTAGE				0x00000100
#define ELECMON_CAP_MIN_VOLTAGE			0x00000200
#define ELECMON_CAP_MAX_VOLTAGE			0x00000400
#define ELECMON_CAP_AVG_VOLTAGE			0x00000800
#define ELECMON_CAP_VOLTAGE_TYPE		0x00001000
#define ELECMON_CAP_POWER				0x00002000
#define ELECMON_CAP_MIN_POWER			0x00004000
#define ELECMON_CAP_MAX_POWER			0x00008000
#define ELECMON_CAP_AVG_POWER			0x00010000
#define ELECMON_CAP_POWER_TYPE			0x00020000
#define ELECMON_CAP_POWER_FACTOR		0x00040000
#define ELECMON_CAP_MIN_POWER_FACTOR	0x00080000
#define ELECMON_CAP_MAX_POWER_FACTOR	0x00100000
#define ELECMON_CAP_AVG_POWER_FACTOR	0x00200000
#define ELECMON_CAP_POWER_FACTOR_TYPE	0x00400000
#define ELECMON_CAP_ENERGY				0x00800000
#define ELECMON_CAP_ENERGY_START_TIME	0x01000000
#define ELECMON_CAP_THRES_STATUS		0x02000000
#define ELECMON_CAP_HWOCP				0x04000000
#define ELECMON_CAP_BLOWNFUSE			0x08000000

/****************************************************************************
 * List of EnvMon capabilities
 ***************************************************************************/
#define ENVMON_CAPABILITIES_LENGHT	2	// Envmon capabilities fits in 2 bytes

#define ENVMON_CAP_NAME			0x0001
#define ENVMON_CAP_SYSNAME		0x0002
#define ENVMON_CAP_VALUE		0x0004
#define ENVMON_CAP_MIN_VALUE		0x0008
#define ENVMON_CAP_MAX_VALUE		0x0010
#define ENVMON_CAP_AVG_VALUE		0x0020
#define ENVMON_CAP_CRIT_THRES		0x0040
#define ENVMON_CAP_CRIT_WARN_THRES	0x0080
#define ENVMON_CAP_LOW_WARN_THRES	0x0100
#define ENVMON_CAP_LOW_THRES		0x0200
#define ENVMON_CAP_THRES_STATUS		0x0400
#define ENVMON_CAP_SENSOR_TYPE		0x0800
#define ENVMON_CAP_UNIT				0x1000
#define ENVMON_CAP_HYSTERESIS		0x2000
#define ENVMON_CAP_CALIBRATION		0x4000
#define ENVMON_CAP_NOT_PRESENT		0x8000

/****************************************************************************
 * List of environmental sensor types
 ***************************************************************************/
#define ENVMON_SENSOR_UNKNOWN                0
#define ENVMON_SENSOR_AVOCENT_TEMP_INTERNAL  1
#define ENVMON_SENSOR_AVOCENT_TEMP_EXTERNAL  2
#define ENVMON_SENSOR_AVOCENT_HUM_INTERNAL   3
#define ENVMON_SENSOR_AVOCENT_HUM_EXTERNAL   4
#define ENVMON_SENSOR_AVOCENT_DRY_CONTACT    5
#define ENVMON_SENSOR_AVOCENT_WATER_LEVEL    6
#define ENVMON_SENSOR_AVOCENT_MOTION         7
#define ENVMON_SENSOR_AVOCENT_SMOKE          8
#define ENVMON_SENSOR_AVOCENT_AIR_FLOW       9
#define ENVMON_SENSOR_AVOCENT_VOLTAGE       10
#define ENVMON_SENSOR_AVOCENT_CURRENT       11
#define ENVMON_SENSOR_AVOCENT_DRY_CONTACT_OPEN   12
#define ENVMON_SENSOR_AVOCENT_DRY_CONTACT_CLOSED 13
#define ENVMON_SENSOR_AVOCENT_RELAY     14
#define ENVMON_SENSOR_AVOCENT_SERIAL    15
#define ENVMON_SENSOR_TEMPERATURE       16
#define ENVMON_SENSOR_HUMIDITY          17
#define ENVMON_SENSOR_DRY_CONTACT       18
#define ENVMON_SENSOR_WATER_LEVEL       19
#define ENVMON_SENSOR_AD_CONVERTER      20
#define ENVMON_SENSOR_DIGITAL           21 //used in ACS Classic's pmclib to group
                                           //DRY_CONTACT/WATER_LEVEL/MOTION/SMOKE
#define ENVMON_SENSOR_UNDEFINED         22

/****************************************************************************
 * List of IPDU display modes
 ***************************************************************************/
#define IPDU_DISPLAY_NORMAL_CURRENT    0
#define IPDU_DISPLAY_INVERTED_CURRENT  1
#define IPDU_DISPLAY_NORMAL_VOLTAGE    2
#define IPDU_DISPLAY_INVERTED_VOLTAGE  3

/****************************************************************************
 * List of Topology Types
 ***************************************************************************/
#define IPDU_TOPOLOGY_UNDEFINED         0
#define IPDU_TOPOLOGY_MONOPHASE         1
#define IPDU_TOPOLOGY_MANUAL_MONOPHASE  2 //for ServerTech, protocol is older than v2.0f
#define IPDU_TOPOLOGY_3PHASE_Y          3
#define IPDU_TOPOLOGY_3PHASE_DELTA      4
#define IPDU_TOPOLOGY_3PHASE            5
#define IPDU_TOPOLOGY_MANUAL_3PHASE     6 //for ServerTech, protocol is older than v2.0f

/****************************************************************************
 * List of Wake up states
 ***************************************************************************/
#define WAKEUP_STATE_OFF		0
#define WAKEUP_STATE_ON			1
#define WAKEUP_STATE_LAST		2

/****************************************************************************
 * "Import" defined for blown fuses from kernel
 *     redefine them here for modules taht cannot include same kernel driver 
 ***************************************************************************/
#ifndef FUSE_NOT
#define FUSE_NOT            0
#endif
#ifndef FUSE_OK
#define FUSE_OK             1
#endif
#ifndef FUSE_BLOWN
#define FUSE_BLOWN          2
#endif


/****************************************************************************
 * List of PMHD models
 ***************************************************************************/

#define PM10_30AMPS             0x02
#define PM10_20AMPS             0x01
#define PM10_15AMPS             0x00
#define PM10I_10AMPS            0x03
#define PM10I_15AMPS            0x0B
#define PM10I_16AMPS            0x07
#define PM10I_20AMPS            0x0F
#define PM10I_30AMPS            0x06
#define PM10I_32AMPS            0x15
#define PM20_15AMPS             0x10
#define PM8I_10AMPS             0x11
#define PM20_20AMPS             0x12
#define PM20_30AMPS             0x13
#define PM8I_16AMPS             0x14
#define PM8IR_16AMPS            0x16
#define PM8_15AMPS              0x17
#define PM8_20AMPS              0x1F
#define PM20I_16AMPS            0x04
#define PM20I_20AMPS            0x05
#define PM20I_30AMPS            0x08
#define PM20I_32AMPS            0x09
#define PM10DC_10AMPS           0x18
#define PM45_30AMPS             0x40
#define PM42_30AMPS             0x41


//??? Should this match the AIDP number?
// Intentionally starting with bit 7 set, so we may use it to detect the model
#define PMHD_ini        0x80    // Initial ID for PMHD models.
#define PM1024          0x80
#define PM2003          0x81
#define PM2006          0x82
#define PM2024          0x83    // 3 boards
#define PM3003          0x84
#define PM3006          0x85
#define PM3024          0x86    // 3 boards
#define PM1010          0x87
#define PM2010          0x88
#define PM3010          0x89
#define PM1020          0x8a
#define PM2020          0x8b
#define PM3020          0x8c
#define PMHD_end        0x8f    // Last ID for PMHD models

#define isPMHD(m) ((m >= PMHD_ini) && (m <= PMHD_end))
#define isPMHDsw(m) ((m == PM3003) || (m == PM3006) || (m == PM3024) || (m == PM3010) || (m == PM3020))
#define isPMHDbasic(m) ((m == PM1024) || (m == PM1010) || (m == PM1020))
#define isPM42(m) (m == PM42_30AMPS)

#endif //_pmcodes
