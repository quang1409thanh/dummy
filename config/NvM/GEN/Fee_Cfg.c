/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "Fee.h"
#include "Fee_Cfg.h"
#include "Fee_Priv.h"
/* ================================ [ MACROS    ] ============================================== */
#ifndef FLS_BASE_ADDRESS
#define FLS_BASE_ADDRESS 0
#endif

#ifndef FEE_MAX_JOB_RETRY
#define FEE_MAX_JOB_RETRY 0xFF
#endif

#ifndef FEE_MAX_ERASED_NUMBER
#define FEE_MAX_ERASED_NUMBER 1000000
#endif

#ifndef FEE_WORKING_AREA_SIZE
#define FEE_WORKING_AREA_SIZE 128
#endif
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
void NvM_JobEndNotification(void);
void NvM_JobErrorNotification(void);
/* ================================ [ DATAS     ] ============================================== */
#define Dem_NvmEventStatusRecord1_Rom Dem_NvmEventStatusRecord0_Rom
#define Dem_NvmEventStatusRecord2_Rom Dem_NvmEventStatusRecord0_Rom
#define Dem_NvmEventStatusRecord3_Rom Dem_NvmEventStatusRecord0_Rom
#define Dem_NvmEventStatusRecord4_Rom Dem_NvmEventStatusRecord0_Rom
#define Dem_NvmEventStatusRecord5_Rom Dem_NvmEventStatusRecord0_Rom
#define Dem_NvmEventStatusRecord6_Rom Dem_NvmEventStatusRecord0_Rom
#define Dem_NvmEventStatusRecord7_Rom Dem_NvmEventStatusRecord0_Rom
static const Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord0_Rom = { 80, 0, };

#define Dem_NvmPrimaryDtcStatusRecord1_Rom Dem_NvmPrimaryDtcStatusRecord0_Rom
#define Dem_NvmPrimaryDtcStatusRecord2_Rom Dem_NvmPrimaryDtcStatusRecord0_Rom
#define Dem_NvmPrimaryDtcStatusRecord3_Rom Dem_NvmPrimaryDtcStatusRecord0_Rom
#define Dem_NvmPrimaryDtcStatusRecord4_Rom Dem_NvmPrimaryDtcStatusRecord0_Rom
#define Dem_NvmPrimaryDtcStatusRecord5_Rom Dem_NvmPrimaryDtcStatusRecord0_Rom
static const Dem_NvmPrimaryDtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord0_Rom = { 80, 0, 0, 0, };

#define Dem_NvmPrimaryFreezeFrameRecord1_Rom Dem_NvmPrimaryFreezeFrameRecord0_Rom
#define Dem_NvmPrimaryFreezeFrameRecord2_Rom Dem_NvmPrimaryFreezeFrameRecord0_Rom
#define Dem_NvmPrimaryFreezeFrameRecord3_Rom Dem_NvmPrimaryFreezeFrameRecord0_Rom
#define Dem_NvmPrimaryFreezeFrameRecord4_Rom Dem_NvmPrimaryFreezeFrameRecord0_Rom
#define Dem_NvmPrimaryFreezeFrameRecord5_Rom Dem_NvmPrimaryFreezeFrameRecord0_Rom
static const Dem_NvmPrimaryFreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord0_Rom = { 65535, {{255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}, {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}}, };

#define Dem_NvmPrimaryExtendedDataRecord1_Rom Dem_NvmPrimaryExtendedDataRecord0_Rom
#define Dem_NvmPrimaryExtendedDataRecord2_Rom Dem_NvmPrimaryExtendedDataRecord0_Rom
#define Dem_NvmPrimaryExtendedDataRecord3_Rom Dem_NvmPrimaryExtendedDataRecord0_Rom
#define Dem_NvmPrimaryExtendedDataRecord4_Rom Dem_NvmPrimaryExtendedDataRecord0_Rom
#define Dem_NvmPrimaryExtendedDataRecord5_Rom Dem_NvmPrimaryExtendedDataRecord0_Rom
static const Dem_NvmPrimaryExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord0_Rom = { 65535, {255, 255, 255, 255}, };

#define Dem_NvmMirrorDtcStatusRecord1_Rom Dem_NvmMirrorDtcStatusRecord0_Rom
#define Dem_NvmMirrorDtcStatusRecord2_Rom Dem_NvmMirrorDtcStatusRecord0_Rom
#define Dem_NvmMirrorDtcStatusRecord3_Rom Dem_NvmMirrorDtcStatusRecord0_Rom
#define Dem_NvmMirrorDtcStatusRecord4_Rom Dem_NvmMirrorDtcStatusRecord0_Rom
#define Dem_NvmMirrorDtcStatusRecord5_Rom Dem_NvmMirrorDtcStatusRecord0_Rom
static const Dem_NvmMirrorDtcStatusRecordType Dem_NvmMirrorDtcStatusRecord0_Rom = { 80, 0, 0, 0, };

#define Dem_NvmMirrorFreezeFrameRecord1_Rom Dem_NvmMirrorFreezeFrameRecord0_Rom
#define Dem_NvmMirrorFreezeFrameRecord2_Rom Dem_NvmMirrorFreezeFrameRecord0_Rom
#define Dem_NvmMirrorFreezeFrameRecord3_Rom Dem_NvmMirrorFreezeFrameRecord0_Rom
#define Dem_NvmMirrorFreezeFrameRecord4_Rom Dem_NvmMirrorFreezeFrameRecord0_Rom
#define Dem_NvmMirrorFreezeFrameRecord5_Rom Dem_NvmMirrorFreezeFrameRecord0_Rom
static const Dem_NvmMirrorFreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord0_Rom = { 65535, {{255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}, {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255}}, };

#define Dem_NvmMirrorExtendedDataRecord1_Rom Dem_NvmMirrorExtendedDataRecord0_Rom
#define Dem_NvmMirrorExtendedDataRecord2_Rom Dem_NvmMirrorExtendedDataRecord0_Rom
#define Dem_NvmMirrorExtendedDataRecord3_Rom Dem_NvmMirrorExtendedDataRecord0_Rom
#define Dem_NvmMirrorExtendedDataRecord4_Rom Dem_NvmMirrorExtendedDataRecord0_Rom
#define Dem_NvmMirrorExtendedDataRecord5_Rom Dem_NvmMirrorExtendedDataRecord0_Rom
static const Dem_NvmMirrorExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord0_Rom = { 65535, {255, 255, 255, 255}, };

static const Dcm_NvmSecurityAccessType Dcm_NvmSecurityAccess_Rom = { 0, };

static const Fee_BlockConfigType Fee_BlockConfigs[] = {
  { FEE_NUMBER_Dem_NvmEventStatusRecord0, 2, 10000000, &Dem_NvmEventStatusRecord0_Rom },
  { FEE_NUMBER_Dem_NvmEventStatusRecord1, 2, 10000000, &Dem_NvmEventStatusRecord1_Rom },
  { FEE_NUMBER_Dem_NvmEventStatusRecord2, 2, 10000000, &Dem_NvmEventStatusRecord2_Rom },
  { FEE_NUMBER_Dem_NvmEventStatusRecord3, 2, 10000000, &Dem_NvmEventStatusRecord3_Rom },
  { FEE_NUMBER_Dem_NvmEventStatusRecord4, 2, 10000000, &Dem_NvmEventStatusRecord4_Rom },
  { FEE_NUMBER_Dem_NvmEventStatusRecord5, 2, 10000000, &Dem_NvmEventStatusRecord5_Rom },
  { FEE_NUMBER_Dem_NvmEventStatusRecord6, 2, 10000000, &Dem_NvmEventStatusRecord6_Rom },
  { FEE_NUMBER_Dem_NvmEventStatusRecord7, 2, 10000000, &Dem_NvmEventStatusRecord7_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord0, 4, 10000000, &Dem_NvmPrimaryDtcStatusRecord0_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord1, 4, 10000000, &Dem_NvmPrimaryDtcStatusRecord1_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord2, 4, 10000000, &Dem_NvmPrimaryDtcStatusRecord2_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord3, 4, 10000000, &Dem_NvmPrimaryDtcStatusRecord3_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord4, 4, 10000000, &Dem_NvmPrimaryDtcStatusRecord4_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord5, 4, 10000000, &Dem_NvmPrimaryDtcStatusRecord5_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord0, 28, 10000000, &Dem_NvmPrimaryFreezeFrameRecord0_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord1, 28, 10000000, &Dem_NvmPrimaryFreezeFrameRecord1_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord2, 28, 10000000, &Dem_NvmPrimaryFreezeFrameRecord2_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord3, 28, 10000000, &Dem_NvmPrimaryFreezeFrameRecord3_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord4, 28, 10000000, &Dem_NvmPrimaryFreezeFrameRecord4_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord5, 28, 10000000, &Dem_NvmPrimaryFreezeFrameRecord5_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord0, 6, 10000000, &Dem_NvmPrimaryExtendedDataRecord0_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord1, 6, 10000000, &Dem_NvmPrimaryExtendedDataRecord1_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord2, 6, 10000000, &Dem_NvmPrimaryExtendedDataRecord2_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord3, 6, 10000000, &Dem_NvmPrimaryExtendedDataRecord3_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord4, 6, 10000000, &Dem_NvmPrimaryExtendedDataRecord4_Rom },
  { FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord5, 6, 10000000, &Dem_NvmPrimaryExtendedDataRecord5_Rom },
  { FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord0, 4, 10000000, &Dem_NvmMirrorDtcStatusRecord0_Rom },
  { FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord1, 4, 10000000, &Dem_NvmMirrorDtcStatusRecord1_Rom },
  { FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord2, 4, 10000000, &Dem_NvmMirrorDtcStatusRecord2_Rom },
  { FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord3, 4, 10000000, &Dem_NvmMirrorDtcStatusRecord3_Rom },
  { FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord4, 4, 10000000, &Dem_NvmMirrorDtcStatusRecord4_Rom },
  { FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord5, 4, 10000000, &Dem_NvmMirrorDtcStatusRecord5_Rom },
  { FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord0, 28, 10000000, &Dem_NvmMirrorFreezeFrameRecord0_Rom },
  { FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord1, 28, 10000000, &Dem_NvmMirrorFreezeFrameRecord1_Rom },
  { FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord2, 28, 10000000, &Dem_NvmMirrorFreezeFrameRecord2_Rom },
  { FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord3, 28, 10000000, &Dem_NvmMirrorFreezeFrameRecord3_Rom },
  { FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord4, 28, 10000000, &Dem_NvmMirrorFreezeFrameRecord4_Rom },
  { FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord5, 28, 10000000, &Dem_NvmMirrorFreezeFrameRecord5_Rom },
  { FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord0, 6, 10000000, &Dem_NvmMirrorExtendedDataRecord0_Rom },
  { FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord1, 6, 10000000, &Dem_NvmMirrorExtendedDataRecord1_Rom },
  { FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord2, 6, 10000000, &Dem_NvmMirrorExtendedDataRecord2_Rom },
  { FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord3, 6, 10000000, &Dem_NvmMirrorExtendedDataRecord3_Rom },
  { FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord4, 6, 10000000, &Dem_NvmMirrorExtendedDataRecord4_Rom },
  { FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord5, 6, 10000000, &Dem_NvmMirrorExtendedDataRecord5_Rom },
  { FEE_NUMBER_Dcm_NvmSecurityAccess, 1, 10000000, &Dcm_NvmSecurityAccess_Rom },
};

static uint32_t Fee_BlockDataAddress[45];
static const Fee_BankType Fee_Banks[] = {
  {FLS_BASE_ADDRESS, FLS_BASE_ADDRESS + 64 * 1024},
  {FLS_BASE_ADDRESS + 64 * 1024, FLS_BASE_ADDRESS + 128 * 1024},
};

static uint32_t Fee_WorkingArea[FEE_WORKING_AREA_SIZE/sizeof(uint32_t)];
const Fee_ConfigType Fee_Config = {
  NvM_JobEndNotification,
  NvM_JobErrorNotification,
  Fee_BlockDataAddress,
  Fee_BlockConfigs,
  ARRAY_SIZE(Fee_BlockConfigs),
  Fee_Banks,
  ARRAY_SIZE(Fee_Banks),
  (uint8_t*)Fee_WorkingArea,
  sizeof(Fee_WorkingArea),
  FEE_MAX_JOB_RETRY,
  FEE_MAX_DATA_SIZE,
  FEE_MAX_ERASED_NUMBER,
};
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
