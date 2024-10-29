/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef DEM_CFG_H
#define DEM_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
/* ================================ [ MACROS    ] ============================================== */
#define DEM_USE_NVM
#define DEM_MAX_FREEZE_FRAME_NUMBER 2
#define DEM_MAX_FREEZE_FRAME_DATA_SIZE 13
#define DEM_MAX_EXTENDED_DATA_SIZE 4
#define DEM_EVENT_ID_DTC0 0
#define DEM_EVENT_ID_DTC1 1
#define DEM_EVENT_ID_DTC2 2
#define DEM_EVENT_ID_DTC3 3
#define DEM_EVENT_ID_DTC4 4
#define DEM_EVENT_ID_DTC_COMB0_EVENT0 5
#define DEM_EVENT_ID_DTC_COMB0_EVENT1 6
#define DEM_EVENT_ID_DTC_COMB0_EVENT2 7
#define DTC_ENVENT_NUM 8
#ifndef DEM_MAX_FREEZE_FRAME_RECORD
#define DEM_MAX_FREEZE_FRAME_RECORD DTC_ENVENT_NUM
#endif
#ifndef DEM_MAX_EXTENDED_DATA_RECORD
#define DEM_MAX_EXTENDED_DATA_RECORD DTC_ENVENT_NUM
#endif

#define DEM_USE_ENABLE_CONDITION
#define DEM_NUM_OF_ENABLE_CONDITION 1

#define DEM_CONTIDION_BATTERY_NORMAL (1<<0)

/* #define DEM_STATUS_BIT_STORAGE_TEST_FAILED */

#define DEM_RESET_CONFIRMED_BIT_ON_OVERFLOW

#define DEM_STATUS_BIT_HANDLING_TEST_FAILED_SINCE_LAST_CLEAR DEM_STATUS_BIT_AGING_AND_DISPLACEMENT

#define DEM_USE_NVM_EXTENDED_DATA

/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /* DEM_CFG_H */
