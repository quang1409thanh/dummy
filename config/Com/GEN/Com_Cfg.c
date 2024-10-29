/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "Com_Cfg.h"
#include "Com.h"
#include "Com_Priv.h"
#ifdef USE_PDUR
#include "PduR_Cfg.h"
#endif
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static const uint16_t year_InitialValue = 0;
static const uint8_t month_InitialValue = 0;
static const uint8_t day_InitialValue = 0;
static const uint8_t hour_InitialValue = 0;
static const uint8_t minute_InitialValue = 0;
static const uint8_t second_InitialValue = 0;
static const uint16_t VehicleSpeed_InitialValue = 0;
static const uint16_t TachoSpeed_InitialValue = 0;
static const uint8_t Led1Sts_InitialValue = 0;
static const uint8_t Led2Sts_InitialValue = 0;
static const uint8_t Led3Sts_InitialValue = 0;

static uint8_t Com_PduData_TxMsgTime[8];
static uint8_t Com_GrpsData_SystemTime[7];
static uint8_t Com_PduData_RxMsgAbsInfo[8];

static Com_IPduTxContextType Com_IPduTxContext_TxMsgTime;
static Com_IPduRxContextType Com_IPduRxContext_RxMsgAbsInfo;

#ifdef COM_USE_SIGNAL_CONFIG
static const Com_SignalTxConfigType Com_SignalTxConfig_SystemTime = {
  NULL, /* ErrorNotification */
  NULL, /* TxNotification */
};

static Com_SignalRxContextType Com_SignalRxContext_VehicleSpeed;
static const Com_SignalRxConfigType Com_SignalRxConfig_VehicleSpeed = {
  &Com_SignalRxContext_VehicleSpeed,
  NULL, /* InvalidNotification */
  NULL, /* RxNotification */
  NULL, /* RxTOut */
  NULL, /* TimeoutSubstitutionValue */
  0, /* FirstTimeout */
  0, /* Timeout */
  COM_ACTION_NOTIFY, /* DataInvalidAction */
  COM_ACTION_NONE, /* RxDataTimeoutAction */
};

static Com_SignalRxContextType Com_SignalRxContext_TachoSpeed;
static const Com_SignalRxConfigType Com_SignalRxConfig_TachoSpeed = {
  &Com_SignalRxContext_TachoSpeed,
  NULL, /* InvalidNotification */
  NULL, /* RxNotification */
  NULL, /* RxTOut */
  NULL, /* TimeoutSubstitutionValue */
  0, /* FirstTimeout */
  0, /* Timeout */
  COM_ACTION_NOTIFY, /* DataInvalidAction */
  COM_ACTION_NONE, /* RxDataTimeoutAction */
};

static Com_SignalRxContextType Com_SignalRxContext_Led1Sts;
static const Com_SignalRxConfigType Com_SignalRxConfig_Led1Sts = {
  &Com_SignalRxContext_Led1Sts,
  NULL, /* InvalidNotification */
  NULL, /* RxNotification */
  NULL, /* RxTOut */
  NULL, /* TimeoutSubstitutionValue */
  0, /* FirstTimeout */
  0, /* Timeout */
  COM_ACTION_NOTIFY, /* DataInvalidAction */
  COM_ACTION_NONE, /* RxDataTimeoutAction */
};

static Com_SignalRxContextType Com_SignalRxContext_Led2Sts;
static const Com_SignalRxConfigType Com_SignalRxConfig_Led2Sts = {
  &Com_SignalRxContext_Led2Sts,
  NULL, /* InvalidNotification */
  NULL, /* RxNotification */
  NULL, /* RxTOut */
  NULL, /* TimeoutSubstitutionValue */
  0, /* FirstTimeout */
  0, /* Timeout */
  COM_ACTION_NOTIFY, /* DataInvalidAction */
  COM_ACTION_NONE, /* RxDataTimeoutAction */
};

static Com_SignalRxContextType Com_SignalRxContext_Led3Sts;
static const Com_SignalRxConfigType Com_SignalRxConfig_Led3Sts = {
  &Com_SignalRxContext_Led3Sts,
  NULL, /* InvalidNotification */
  NULL, /* RxNotification */
  NULL, /* RxTOut */
  NULL, /* TimeoutSubstitutionValue */
  0, /* FirstTimeout */
  0, /* Timeout */
  COM_ACTION_NOTIFY, /* DataInvalidAction */
  COM_ACTION_NONE, /* RxDataTimeoutAction */
};

#endif /* COM_USE_SIGNAL_CONFIG */
static const Com_SignalConfigType Com_SignalConfigs[] = {
  {
#ifdef USE_SHELL
    "year",
#endif
    &Com_GrpsData_SystemTime[0], /* ptr */
    &year_InitialValue, /* initPtr */
    COM_UINT16, /* type */
    COM_SID_year, /* HandleId */
    COM_CAN0_TX_MSG_TIME, /* PduId */
    7, /* BitPosition */
    16, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    NULL, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "month",
#endif
    &Com_GrpsData_SystemTime[2], /* ptr */
    &month_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_month, /* HandleId */
    COM_CAN0_TX_MSG_TIME, /* PduId */
    7, /* BitPosition */
    8, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    NULL, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "day",
#endif
    &Com_GrpsData_SystemTime[3], /* ptr */
    &day_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_day, /* HandleId */
    COM_CAN0_TX_MSG_TIME, /* PduId */
    7, /* BitPosition */
    8, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    NULL, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "hour",
#endif
    &Com_GrpsData_SystemTime[4], /* ptr */
    &hour_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_hour, /* HandleId */
    COM_CAN0_TX_MSG_TIME, /* PduId */
    7, /* BitPosition */
    8, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    NULL, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "minute",
#endif
    &Com_GrpsData_SystemTime[5], /* ptr */
    &minute_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_minute, /* HandleId */
    COM_CAN0_TX_MSG_TIME, /* PduId */
    7, /* BitPosition */
    8, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    NULL, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "second",
#endif
    &Com_GrpsData_SystemTime[6], /* ptr */
    &second_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_second, /* HandleId */
    COM_CAN0_TX_MSG_TIME, /* PduId */
    7, /* BitPosition */
    8, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    NULL, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "SystemTime",
#endif
    &Com_PduData_TxMsgTime[0], /* ptr */
    Com_GrpsData_SystemTime, /* shadowPtr */
    COM_UINT8N, /* type */
    COM_GID_SystemTime, /* HandleId */
    COM_CAN0_TX_MSG_TIME, /* PduId */
    7, /* BitPosition */
    56, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    NULL, /* rxConfig */
    &Com_SignalTxConfig_SystemTime, /* txConfig */
#endif
    TRUE,
  },
  {
#ifdef USE_SHELL
    "VehicleSpeed",
#endif
    &Com_PduData_RxMsgAbsInfo[0], /* ptr */
    &VehicleSpeed_InitialValue, /* initPtr */
    COM_UINT16, /* type */
    COM_SID_VehicleSpeed, /* HandleId */
    COM_CAN0_RX_MSG_ABS_INFO, /* PduId */
    7, /* BitPosition */
    16, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    &Com_SignalRxConfig_VehicleSpeed, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "TachoSpeed",
#endif
    &Com_PduData_RxMsgAbsInfo[2], /* ptr */
    &TachoSpeed_InitialValue, /* initPtr */
    COM_UINT16, /* type */
    COM_SID_TachoSpeed, /* HandleId */
    COM_CAN0_RX_MSG_ABS_INFO, /* PduId */
    7, /* BitPosition */
    16, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    &Com_SignalRxConfig_TachoSpeed, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "Led1Sts",
#endif
    &Com_PduData_RxMsgAbsInfo[4], /* ptr */
    &Led1Sts_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_Led1Sts, /* HandleId */
    COM_CAN0_RX_MSG_ABS_INFO, /* PduId */
    7, /* BitPosition */
    2, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    &Com_SignalRxConfig_Led1Sts, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "Led2Sts",
#endif
    &Com_PduData_RxMsgAbsInfo[4], /* ptr */
    &Led2Sts_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_Led2Sts, /* HandleId */
    COM_CAN0_RX_MSG_ABS_INFO, /* PduId */
    5, /* BitPosition */
    2, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    &Com_SignalRxConfig_Led2Sts, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
  {
#ifdef USE_SHELL
    "Led3Sts",
#endif
    &Com_PduData_RxMsgAbsInfo[4], /* ptr */
    &Led3Sts_InitialValue, /* initPtr */
    COM_UINT8, /* type */
    COM_SID_Led3Sts, /* HandleId */
    COM_CAN0_RX_MSG_ABS_INFO, /* PduId */
    3, /* BitPosition */
    2, /* BitSize */
#ifdef COM_USE_SIGNAL_UPDATE_BIT
    COM_UPDATE_BIT_NOT_USED, /* UpdateBit */
#endif
    BIG, /* Endianness */
#ifdef COM_USE_SIGNAL_CONFIG
    &Com_SignalRxConfig_Led3Sts, /* rxConfig */
    NULL, /* txConfig */
#endif
    FALSE,
  },
};

static const Com_SignalConfigType* Com_IPduSignals_TxMsgTime[] = {
  &Com_SignalConfigs[COM_SID_year],
  &Com_SignalConfigs[COM_SID_month],
  &Com_SignalConfigs[COM_SID_day],
  &Com_SignalConfigs[COM_SID_hour],
  &Com_SignalConfigs[COM_SID_minute],
  &Com_SignalConfigs[COM_SID_second],
  &Com_SignalConfigs[COM_GID_SystemTime],
};

static const Com_SignalConfigType* Com_IPduSignals_RxMsgAbsInfo[] = {
  &Com_SignalConfigs[COM_SID_VehicleSpeed],
  &Com_SignalConfigs[COM_SID_TachoSpeed],
  &Com_SignalConfigs[COM_SID_Led1Sts],
  &Com_SignalConfigs[COM_SID_Led2Sts],
  &Com_SignalConfigs[COM_SID_Led3Sts],
};

static const Com_IPduTxConfigType Com_IPduTxConfig_TxMsgTime = {
  &Com_IPduTxContext_TxMsgTime,
  NULL, /* ErrorNotification */
  NULL, /* TxNotification */
  NULL, /* TxIpduCallout */
  COM_CONVERT_MS_TO_MAIN_CYCLES(0), /* FirstTime */
  COM_CONVERT_MS_TO_MAIN_CYCLES(1000), /* CycleTime */
#ifdef USE_PDUR
  PDUR_CAN0_TX_MSG_TIME,
#else
  COM_ECUC_PDUID_OFFSET + COM_CAN0_TX_MSG_TIME,
#endif
};

static const Com_IPduRxConfigType Com_IPduRxConfig_RxMsgAbsInfo = {
  &Com_IPduRxContext_RxMsgAbsInfo,
  NULL, /* RxNotification */
  NULL, /* RxTOut */
  COM_CONVERT_MS_TO_MAIN_CYCLES(0), /* FirstTimeout */
  COM_CONVERT_MS_TO_MAIN_CYCLES(0), /* Timeout */
};

static const Com_IPduConfigType Com_IPduConfigs[] = {
  {
#ifdef USE_SHELL
    "TxMsgTime",
#endif
    Com_PduData_TxMsgTime, /* ptr */
    NULL, /* dynLen */
    Com_IPduSignals_TxMsgTime, /* signals */
    NULL, /* rxConfig */
    &Com_IPduTxConfig_TxMsgTime, /* txConfig */
    Com_IPduTxMsgTime_GroupRefMask,
    sizeof(Com_PduData_TxMsgTime), /* length */
    ARRAY_SIZE(Com_IPduSignals_TxMsgTime), /* numOfSignals */
  },
  {
#ifdef USE_SHELL
    "RxMsgAbsInfo",
#endif
    Com_PduData_RxMsgAbsInfo, /* ptr */
    NULL, /* dynLen */
    Com_IPduSignals_RxMsgAbsInfo, /* signals */
    &Com_IPduRxConfig_RxMsgAbsInfo, /* rxConfig */
    NULL, /* txConfig */
    Com_IPduRxMsgAbsInfo_GroupRefMask,
    sizeof(Com_PduData_RxMsgAbsInfo), /* length */
    ARRAY_SIZE(Com_IPduSignals_RxMsgAbsInfo), /* numOfSignals */
  },
};

static Com_GlobalContextType Com_GlobalContext;
const Com_ConfigType Com_Config = {
  Com_IPduConfigs,
  Com_SignalConfigs,
  &Com_GlobalContext,
  ARRAY_SIZE(Com_IPduConfigs),
  ARRAY_SIZE(Com_SignalConfigs),
  1 /* numOfGroups */,
};

/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
