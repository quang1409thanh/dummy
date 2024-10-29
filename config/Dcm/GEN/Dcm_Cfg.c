/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "Dcm.h"
#include "Dcm_Cfg.h"
#include "Dcm_Internal.h"
#include <string.h>
/* ================================ [ MACROS    ] ============================================== */
#define DCM_RDID_F15B_INDEX 0
#define DCM_RDID_AB01_INDEX 1
#define DCM_RDID_AB02_INDEX 2
#define DCM_RDID_F201_INDEX 3
#define DCM_RDID_F202_INDEX 4
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
Std_ReturnType App_GetSessionChangePermission(Dcm_SesCtrlType sesCtrlTypeActive,
                  Dcm_SesCtrlType sesCtrlTypeNew,
                  Dcm_NegativeResponseCodeType *nrc);

Std_ReturnType App_GetEcuResetPermission(Dcm_OpStatusType opStatus, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_ReadFingerPrint(Dcm_OpStatusType opStatus, uint8_t *data, uint16_t length,
                   Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_ReadAB01(Dcm_OpStatusType opStatus, uint8_t *data, uint16_t length,
                   Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_ReadAB02(Dcm_OpStatusType opStatus, uint8_t *data, uint16_t length,
                   Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_GetExtendedSessionSeed(uint8_t *seed, Dcm_NegativeResponseCodeType *errorCode);
Std_ReturnType App_CompareExtendedSessionKey(const uint8_t *key, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_GetProgramSessionSeed(uint8_t *seed, Dcm_NegativeResponseCodeType *errorCode);
Std_ReturnType App_CompareProgramSessionKey(const uint8_t *key, Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_GetPeriodicDID01(Dcm_OpStatusType opStatus, uint8_t *data, uint16_t length,
                   Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_GetPeriodicDID02(Dcm_OpStatusType opStatus, uint8_t *data, uint16_t length,
                   Dcm_NegativeResponseCodeType *errorCode);

Std_ReturnType App_IOCtl_FC01_ShortTermAdjustment(uint8_t *ControlRecord, uint16_t length,
                  uint8_t *resData, uint16_t *resDataLen,
                  uint8_t *nrc);

Std_ReturnType App_IOCtl_FC01_ReturnControlToEcuFnc(uint8_t *ControlRecord, uint16_t length,
                  uint8_t *resData, uint16_t *resDataLen,
                  uint8_t *nrc);

static Std_ReturnType Dcm_DspReadDDDID_0(Dcm_OpStatusType opStatus, uint8_t *data,
                                          uint16_t length,
                                          Dcm_NegativeResponseCodeType *errorCode);

static Std_ReturnType Dcm_DspReadDDDID_1(Dcm_OpStatusType opStatus, uint8_t *data,
                                          uint16_t length,
                                          Dcm_NegativeResponseCodeType *errorCode);

/* ================================ [ DATAS     ] ============================================== */
static uint8_t rxBuffer[514];
static uint8_t txBuffer[514];

#if defined(DCM_USE_SERVICE_READ_MEMORY_BY_ADDRESS) || defined(DCM_USE_SERVICE_WRITE_MEMORY_BY_ADDRESS)
static const Dcm_DspMemoryRangeInfoType Dcm_DspMemoryRangeInfos[] = {
  {
     0,
     0x100000,
     DCM_MEM_ATTR_READ|DCM_MEM_ATTR_WRITE,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
  {
     0x300000,
     0x400000,
     DCM_MEM_ATTR_READ,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
};

static const uint8_t Dcm_DspAddressAndLengthFormatIdentifiers[] = {
  0x44,
};

static const Dcm_DspMemoryConfigType Dcm_DspMemoryConfig = {
  Dcm_DspAddressAndLengthFormatIdentifiers,
  ARRAY_SIZE(Dcm_DspAddressAndLengthFormatIdentifiers),
  Dcm_DspMemoryRangeInfos,
  ARRAY_SIZE(Dcm_DspMemoryRangeInfos),
};

#endif

static Dcm_rDIDConfigType Dcm_rDDDIDConfigs[2];
static Dcm_DDDIDContextType Dcm_DDDIDContexts[2];
static const Dcm_DDDIDConfigType Dcm_DDDIDConfigs[] = {
  {
     &Dcm_rDDDIDConfigs[0],
     &Dcm_DDDIDContexts[0],
     Dcm_DspReadDDDID_0,
  },
  {
     &Dcm_rDDDIDConfigs[1],
     &Dcm_DDDIDContexts[1],
     Dcm_DspReadDDDID_1,
  },
};

static const Dcm_rDIDConfigType Dcm_rDIDConfigs[] = {
  {
    0xF15B,
    10,
    App_ReadFingerPrint,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
  {
    0xAB01,
    10,
    App_ReadAB01,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
  {
    0xAB02,
    10,
    App_ReadAB02,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
  {
    0xF201,
    10,
    App_GetPeriodicDID01,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
  {
    0xF202,
    32,
    App_GetPeriodicDID02,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
};

static const Dcm_SesCtrlType Dcm_SesCtrls[] = {
  DCM_DEFAULT_SESSION,
  DCM_PROGRAM_SESSION,
  DCM_EXTENDED_SESSION,
  DCM_FACTORY_SESSION,
};

static const Dcm_SessionControlConfigType Dcm_SessionControlConfig = {
  App_GetSessionChangePermission,
  Dcm_SesCtrls,
  ARRAY_SIZE(Dcm_SesCtrls),
};

static const Dcm_EcuResetConfigType Dcm_EcuResetConfig = {
  App_GetEcuResetPermission,
  DCM_CONVERT_MS_TO_MAIN_CYCLES(100),
};

#ifdef USE_DEM
static const Dcm_ReadDTCSubFunctionConfigType Dcm_ReadDTCSubFunctions[] = {
  {Dem_DspReportNumberOfDTCByStatusMask, 0x01},
  {Dem_DspReportDTCByStatusMask, 0x02},
  {Dem_DspReportDTCSnapshotIdentification, 0x03},
  {Dem_DspReportDTCSnapshotRecordByDTCNumber, 0x04},
  {Dem_DspReportDTCExtendedDataRecordByDTCNumber, 0x06},
  {Dem_DspReportMirrorMemoryDTCByStatusMask, 0x0F},
  {Dem_DspReportMirrorMemoryDTCExtendedDataRecordByDTCNumber, 0x10},
  {Dem_DspReportNumberOfMirrorMemoryDTCByStatusMask, 0x11},
};

static const Dcm_ReadDTCInfoConfigType Dcm_ReadDTCInformationConfig = {
  Dcm_ReadDTCSubFunctions,
  ARRAY_SIZE(Dcm_ReadDTCSubFunctions),
};
#endif

static Dcm_ReadDIDContextType Dcm_ReadDIDContexts[5];
static const Dcm_ReadDIDType Dcm_ReadDIDs[] = {
  {
    &Dcm_ReadDIDContexts[0],
    &Dcm_rDIDConfigs[DCM_RDID_F15B_INDEX],
  },
  {
    &Dcm_ReadDIDContexts[1],
    &Dcm_rDIDConfigs[DCM_RDID_AB01_INDEX],
  },
  {
    &Dcm_ReadDIDContexts[2],
    &Dcm_rDIDConfigs[DCM_RDID_AB02_INDEX],
  },
  {
    &Dcm_ReadDIDContexts[3],
    &Dcm_rDDDIDConfigs[0],
  },
  {
    &Dcm_ReadDIDContexts[4],
    &Dcm_rDDDIDConfigs[1],
  },
};

static const Dcm_ReadDIDConfigType Dcm_ReadDataByIdentifierConfig = {
  Dcm_ReadDIDs,
  ARRAY_SIZE(Dcm_ReadDIDs),
};

static const Dcm_SecLevelConfigType Dcm_SecLevelConfigs[] = {
  {
    App_GetExtendedSessionSeed,
    App_CompareExtendedSessionKey,
    DCM_SEC_LEVEL1,
    4,
    4,
    DCM_EXTENDED_MASK,
  },
  {
    App_GetProgramSessionSeed,
    App_CompareProgramSessionKey,
    DCM_SEC_LEVEL2,
    4,
    4,
    DCM_PROGRAM_MASK,
  },
};

static const Dcm_SecurityAccessConfigType Dcm_SecurityAccessConfig = {
  Dcm_SecLevelConfigs,
  ARRAY_SIZE(Dcm_SecLevelConfigs),
};

#ifdef USE_CRYPTO
static const Dcm_AuthenticationType Dcm_Authentications[] = {
  {
    0x00,
    Dcm_DspDeAuthentication,
  },
  {
    0x01,
    Dcm_DspVerifyCertificateUnidirectional,
  },
  {
    0x02,
    Dcm_DspVerifyCertificateBidirectional,
  },
  {
    0x03,
    Dcm_DspProofOfOwnership,
  },
  {
    0x04,
    Dcm_DspTransmitCertificate,
  },
  {
    0x05,
    Dcm_DspRequestChallengeForAuthentication,
  },
  {
    0x06,
    Dcm_DspVerifyProofOfOwnershipUnidirectional,
  },
  {
    0x07,
    Dcm_DspVerifyProofOfOwnershipBidirectional,
  },
  {
    0x08,
    Dcm_DspAuthenticationConfiguration,
  },
};

static const Dcm_AuthenticationConfigType Dcm_AuthenticationConfig = {
  Dcm_Authentications,
  ARRAY_SIZE(Dcm_Authentications),
};

#endif

static Dcm_ReadPeriodicDIDContextType Dcm_ReadPeriodicDIDContexts[4];
static const Dcm_ReadPeriodicDIDType Dcm_ReadPeriodicDIDs[] = {
  {
    &Dcm_ReadPeriodicDIDContexts[0],
    &Dcm_rDIDConfigs[DCM_RDID_F201_INDEX],
  },
  {
    &Dcm_ReadPeriodicDIDContexts[1],
    &Dcm_rDIDConfigs[DCM_RDID_F202_INDEX],
  },
  {
    &Dcm_ReadPeriodicDIDContexts[2],
    &Dcm_rDDDIDConfigs[0],
  },
  {
    &Dcm_ReadPeriodicDIDContexts[3],
    &Dcm_rDDDIDConfigs[1],
  },
};

static const Dcm_ReadPeriodicDIDConfigType Dcm_ReadDataByPeriodicIdentifierConfig = {
  Dcm_ReadPeriodicDIDs,
  ARRAY_SIZE(Dcm_ReadPeriodicDIDs),
};

static Dcm_IOControlContextType Dcm_IOCtrlContexts[1];
static const Dcm_IOControlType Dcm_IOCtrls[] = {
  {
    &Dcm_IOCtrlContexts[0],
    0xFC01,
    App_IOCtl_FC01_ReturnControlToEcuFnc, /* ReturnControlToEcu */
    NULL, /* ResetToDefault */
    NULL, /* FreezeCurrentState */
    App_IOCtl_FC01_ShortTermAdjustment, /* ShortTermAdjustment */
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
  },
};

static const Dcm_IOControlConfigType Dcm_IOControlByIdentifierConfig = {
  Dcm_IOCtrls,
  ARRAY_SIZE(Dcm_IOCtrls),
};

static const Dcm_ServiceType Dcm_UdsServices[] = {
  {
    SID_DIAGNOSTIC_SESSION_CONTROL,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_FUNCTIONAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspSessionControl,
    (const void *)&Dcm_SessionControlConfig,
  },
  {
    SID_ECU_RESET,
    {
      DCM_PROGRAM_MASK|DCM_EXTENDED_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_SEC_LEVEL2_MASK|DCM_SEC_LEVEL1_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_FUNCTIONAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspEcuReset,
    (const void *)&Dcm_EcuResetConfig,
  },
#ifdef USE_DEM
  {
    SID_CLEAR_DIAGNOSTIC_INFORMATION,
    {
      DCM_EXTENDED_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_FUNCTIONAL,
    },
    Dcm_DspClearDTC,
    NULL,
  },
#endif
#ifdef USE_DEM
  {
    SID_READ_DTC_INFORMATION,
    {
      DCM_EXTENDED_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_FUNCTIONAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspReadDTCInformation,
    (const void *)&Dcm_ReadDTCInformationConfig,
  },
#endif
  {
    SID_READ_DATA_BY_IDENTIFIER,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
    Dcm_DspReadDataByIdentifier,
    (const void *)&Dcm_ReadDataByIdentifierConfig,
  },
  {
    SID_SECURITY_ACCESS,
    {
      DCM_DEFAULT_MASK|DCM_PROGRAM_MASK|DCM_EXTENDED_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspSecurityAccess,
    (const void *)&Dcm_SecurityAccessConfig,
  },
#ifdef USE_CRYPTO
  {
    SID_AUTHENTICATION,
    {
      DCM_DEFAULT_MASK|DCM_EXTENDED_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspAuthentication,
    (const void *)&Dcm_AuthenticationConfig,
  },
#endif
  {
    SID_READ_DATA_BY_PERIODIC_IDENTIFIER,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
    Dcm_DspReadDataByPeriodicIdentifier,
    (const void *)&Dcm_ReadDataByPeriodicIdentifierConfig,
  },
  {
    SID_DYNAMICALLY_DEFINE_DATA_IDENTIFIER,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspDynamicallyDefineDataIdentifier,
    NULL,
  },
  {
    SID_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
    Dcm_DspIOControlByIdentifier,
    (const void *)&Dcm_IOControlByIdentifierConfig,
  },
  {
    SID_TESTER_PRESENT,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspTesterPresent,
    NULL,
  },
  {
    SID_READ_MEMORY_BY_ADDRESS,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
    Dcm_DspReadMemoryByAddress,
    NULL,
  },
  {
    SID_WRITE_MEMORY_BY_ADDRESS,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL,
    },
    Dcm_DspWriteMemoryByAddress,
    NULL,
  },
#ifdef USE_DEM
  {
    SID_CONTROL_DTC_SETTING,
    {
      DCM_ANY_SESSION_MASK,
#ifdef DCM_USE_SERVICE_SECURITY_ACCESS
      DCM_ANY_SECURITY_MASK,
#endif
      DCM_MISC_PHYSICAL|DCM_MISC_FUNCTIONAL|DCM_MISC_SUB_FUNCTION,
    },
    Dcm_DspControlDTCSetting,
    NULL,
  },
#endif
};

static const Dcm_ServiceTableType Dcm_UdsServiceTable = {
  Dcm_UdsServices,
  ARRAY_SIZE(Dcm_UdsServices),
};

static const Dcm_ServiceTableType *Dcm_ServiceTables[] = {
  &Dcm_UdsServiceTable,
};

static const Dcm_TimingConfigType Dcm_TimingConfig = {
  DCM_CONVERT_MS_TO_MAIN_CYCLES(5000),
  DCM_CONVERT_MS_TO_MAIN_CYCLES(450),
  DCM_CONVERT_MS_TO_MAIN_CYCLES(500),
};

static const Dcm_DslDiagRespConfigType Dcm_DslDiagRespConfig = {
  8,
};

const Dcm_ConfigType Dcm_Config = {
  rxBuffer,
  txBuffer,
  sizeof(rxBuffer),
  sizeof(txBuffer),
  Dcm_ServiceTables,
  ARRAY_SIZE(Dcm_ServiceTables),
  &Dcm_TimingConfig,
  &Dcm_DslDiagRespConfig,
  #ifdef DCM_USE_SERVICE_DYNAMICALLY_DEFINE_DATA_IDENTIFIER
  Dcm_DDDIDConfigs,
  ARRAY_SIZE(Dcm_DDDIDConfigs),
  Dcm_rDIDConfigs,
  ARRAY_SIZE(Dcm_rDIDConfigs),
  #endif
  #ifdef DCM_USE_SERVICE_READ_DATA_BY_PERIODIC_IDENTIFIER
  &Dcm_ReadDataByPeriodicIdentifierConfig,
  #endif
  #ifdef DCM_USE_SERVICE_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER
  &Dcm_IOControlByIdentifierConfig,
  #endif
  #if defined(DCM_USE_SERVICE_READ_MEMORY_BY_ADDRESS) || defined(DCM_USE_SERVICE_WRITE_MEMORY_BY_ADDRESS)
  &Dcm_DspMemoryConfig,
  #endif
  #ifdef DCM_USE_SERVICE_SECURITY_ACCESS
  3,
  DCM_CONVERT_MS_TO_MAIN_CYCLES(3000),
  #ifdef USE_NVM
  NVM_BLOCKID_Dcm_NvmSecurityAccess
  #endif
  #endif
};

/* ================================ [ LOCALS    ] ============================================== */
static Std_ReturnType Dcm_DspReadDDDID_0(Dcm_OpStatusType opStatus, uint8_t *data,
                                          uint16_t length,
                                          Dcm_NegativeResponseCodeType *errorCode) {
  return Dcm_DspReadDDDID(&Dcm_DDDIDConfigs[0], opStatus, data, length, errorCode);
}

static Std_ReturnType Dcm_DspReadDDDID_1(Dcm_OpStatusType opStatus, uint8_t *data,
                                          uint16_t length,
                                          Dcm_NegativeResponseCodeType *errorCode) {
  return Dcm_DspReadDDDID(&Dcm_DDDIDConfigs[1], opStatus, data, length, errorCode);
}

/* ================================ [ FUNCTIONS ] ============================================== */
Std_ReturnType Dcm_Transmit(const uint8_t *buffer, PduLengthType length, int functional) {
  Std_ReturnType r = E_NOT_OK;
  Dcm_ContextType *context = Dcm_GetContext();

  if ((DCM_BUFFER_IDLE == context->txBufferState) && (Dcm_Config.txBufferSize >= length)) {
    r = E_OK;
    if (functional) {
      context->curPduId = DCM_P2A_PDU;
    } else {
      context->curPduId = DCM_P2P_PDU;
    }
    memcpy(Dcm_Config.txBuffer, buffer, (size_t)length);
    context->TxTpSduLength = (PduLengthType)length;
    context->txBufferState = DCM_BUFFER_FULL;
  }

  return r;
}
