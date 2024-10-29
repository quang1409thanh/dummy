/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "NvM.h"
#include "NvM_Cfg.h"
#include "NvM_Priv.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord0_Ram;
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord1_Ram;
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord2_Ram;
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord3_Ram;
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord4_Ram;
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord5_Ram;
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord6_Ram;
Dem_NvmEventStatusRecordType Dem_NvmEventStatusRecord7_Ram;
Dem_NvmPrimaryDtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord0_Ram;
Dem_NvmPrimaryDtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord1_Ram;
Dem_NvmPrimaryDtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord2_Ram;
Dem_NvmPrimaryDtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord3_Ram;
Dem_NvmPrimaryDtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord4_Ram;
Dem_NvmPrimaryDtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord5_Ram;
Dem_NvmPrimaryFreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord0_Ram;
Dem_NvmPrimaryFreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord1_Ram;
Dem_NvmPrimaryFreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord2_Ram;
Dem_NvmPrimaryFreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord3_Ram;
Dem_NvmPrimaryFreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord4_Ram;
Dem_NvmPrimaryFreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord5_Ram;
Dem_NvmPrimaryExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord0_Ram;
Dem_NvmPrimaryExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord1_Ram;
Dem_NvmPrimaryExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord2_Ram;
Dem_NvmPrimaryExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord3_Ram;
Dem_NvmPrimaryExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord4_Ram;
Dem_NvmPrimaryExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord5_Ram;
Dem_NvmMirrorDtcStatusRecordType Dem_NvmMirrorDtcStatusRecord0_Ram;
Dem_NvmMirrorDtcStatusRecordType Dem_NvmMirrorDtcStatusRecord1_Ram;
Dem_NvmMirrorDtcStatusRecordType Dem_NvmMirrorDtcStatusRecord2_Ram;
Dem_NvmMirrorDtcStatusRecordType Dem_NvmMirrorDtcStatusRecord3_Ram;
Dem_NvmMirrorDtcStatusRecordType Dem_NvmMirrorDtcStatusRecord4_Ram;
Dem_NvmMirrorDtcStatusRecordType Dem_NvmMirrorDtcStatusRecord5_Ram;
Dem_NvmMirrorFreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord0_Ram;
Dem_NvmMirrorFreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord1_Ram;
Dem_NvmMirrorFreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord2_Ram;
Dem_NvmMirrorFreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord3_Ram;
Dem_NvmMirrorFreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord4_Ram;
Dem_NvmMirrorFreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord5_Ram;
Dem_NvmMirrorExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord0_Ram;
Dem_NvmMirrorExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord1_Ram;
Dem_NvmMirrorExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord2_Ram;
Dem_NvmMirrorExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord3_Ram;
Dem_NvmMirrorExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord4_Ram;
Dem_NvmMirrorExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord5_Ram;
Dcm_NvmSecurityAccessType Dcm_NvmSecurityAccess_Ram;
static const NvM_BlockDescriptorType NvM_BlockDescriptors[] = {
  { &Dem_NvmEventStatusRecord0_Ram, 1, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmEventStatusRecord1_Ram, 2, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmEventStatusRecord2_Ram, 3, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmEventStatusRecord3_Ram, 4, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmEventStatusRecord4_Ram, 5, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmEventStatusRecord5_Ram, 6, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmEventStatusRecord6_Ram, 7, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmEventStatusRecord7_Ram, 8, sizeof(Dem_NvmEventStatusRecordType) },
  { &Dem_NvmPrimaryDtcStatusRecord0_Ram, 9, sizeof(Dem_NvmPrimaryDtcStatusRecordType) },
  { &Dem_NvmPrimaryDtcStatusRecord1_Ram, 10, sizeof(Dem_NvmPrimaryDtcStatusRecordType) },
  { &Dem_NvmPrimaryDtcStatusRecord2_Ram, 11, sizeof(Dem_NvmPrimaryDtcStatusRecordType) },
  { &Dem_NvmPrimaryDtcStatusRecord3_Ram, 12, sizeof(Dem_NvmPrimaryDtcStatusRecordType) },
  { &Dem_NvmPrimaryDtcStatusRecord4_Ram, 13, sizeof(Dem_NvmPrimaryDtcStatusRecordType) },
  { &Dem_NvmPrimaryDtcStatusRecord5_Ram, 14, sizeof(Dem_NvmPrimaryDtcStatusRecordType) },
  { &Dem_NvmPrimaryFreezeFrameRecord0_Ram, 15, sizeof(Dem_NvmPrimaryFreezeFrameRecordType) },
  { &Dem_NvmPrimaryFreezeFrameRecord1_Ram, 16, sizeof(Dem_NvmPrimaryFreezeFrameRecordType) },
  { &Dem_NvmPrimaryFreezeFrameRecord2_Ram, 17, sizeof(Dem_NvmPrimaryFreezeFrameRecordType) },
  { &Dem_NvmPrimaryFreezeFrameRecord3_Ram, 18, sizeof(Dem_NvmPrimaryFreezeFrameRecordType) },
  { &Dem_NvmPrimaryFreezeFrameRecord4_Ram, 19, sizeof(Dem_NvmPrimaryFreezeFrameRecordType) },
  { &Dem_NvmPrimaryFreezeFrameRecord5_Ram, 20, sizeof(Dem_NvmPrimaryFreezeFrameRecordType) },
  { &Dem_NvmPrimaryExtendedDataRecord0_Ram, 21, sizeof(Dem_NvmPrimaryExtendedDataRecordType) },
  { &Dem_NvmPrimaryExtendedDataRecord1_Ram, 22, sizeof(Dem_NvmPrimaryExtendedDataRecordType) },
  { &Dem_NvmPrimaryExtendedDataRecord2_Ram, 23, sizeof(Dem_NvmPrimaryExtendedDataRecordType) },
  { &Dem_NvmPrimaryExtendedDataRecord3_Ram, 24, sizeof(Dem_NvmPrimaryExtendedDataRecordType) },
  { &Dem_NvmPrimaryExtendedDataRecord4_Ram, 25, sizeof(Dem_NvmPrimaryExtendedDataRecordType) },
  { &Dem_NvmPrimaryExtendedDataRecord5_Ram, 26, sizeof(Dem_NvmPrimaryExtendedDataRecordType) },
  { &Dem_NvmMirrorDtcStatusRecord0_Ram, 27, sizeof(Dem_NvmMirrorDtcStatusRecordType) },
  { &Dem_NvmMirrorDtcStatusRecord1_Ram, 28, sizeof(Dem_NvmMirrorDtcStatusRecordType) },
  { &Dem_NvmMirrorDtcStatusRecord2_Ram, 29, sizeof(Dem_NvmMirrorDtcStatusRecordType) },
  { &Dem_NvmMirrorDtcStatusRecord3_Ram, 30, sizeof(Dem_NvmMirrorDtcStatusRecordType) },
  { &Dem_NvmMirrorDtcStatusRecord4_Ram, 31, sizeof(Dem_NvmMirrorDtcStatusRecordType) },
  { &Dem_NvmMirrorDtcStatusRecord5_Ram, 32, sizeof(Dem_NvmMirrorDtcStatusRecordType) },
  { &Dem_NvmMirrorFreezeFrameRecord0_Ram, 33, sizeof(Dem_NvmMirrorFreezeFrameRecordType) },
  { &Dem_NvmMirrorFreezeFrameRecord1_Ram, 34, sizeof(Dem_NvmMirrorFreezeFrameRecordType) },
  { &Dem_NvmMirrorFreezeFrameRecord2_Ram, 35, sizeof(Dem_NvmMirrorFreezeFrameRecordType) },
  { &Dem_NvmMirrorFreezeFrameRecord3_Ram, 36, sizeof(Dem_NvmMirrorFreezeFrameRecordType) },
  { &Dem_NvmMirrorFreezeFrameRecord4_Ram, 37, sizeof(Dem_NvmMirrorFreezeFrameRecordType) },
  { &Dem_NvmMirrorFreezeFrameRecord5_Ram, 38, sizeof(Dem_NvmMirrorFreezeFrameRecordType) },
  { &Dem_NvmMirrorExtendedDataRecord0_Ram, 39, sizeof(Dem_NvmMirrorExtendedDataRecordType) },
  { &Dem_NvmMirrorExtendedDataRecord1_Ram, 40, sizeof(Dem_NvmMirrorExtendedDataRecordType) },
  { &Dem_NvmMirrorExtendedDataRecord2_Ram, 41, sizeof(Dem_NvmMirrorExtendedDataRecordType) },
  { &Dem_NvmMirrorExtendedDataRecord3_Ram, 42, sizeof(Dem_NvmMirrorExtendedDataRecordType) },
  { &Dem_NvmMirrorExtendedDataRecord4_Ram, 43, sizeof(Dem_NvmMirrorExtendedDataRecordType) },
  { &Dem_NvmMirrorExtendedDataRecord5_Ram, 44, sizeof(Dem_NvmMirrorExtendedDataRecordType) },
  { &Dcm_NvmSecurityAccess_Ram, 45, sizeof(Dcm_NvmSecurityAccessType) },
};

static uint16_t NvM_JobReadMasks[(NVM_BLOCK_NUMBER+15)/16];
static uint16_t NvM_JobWriteMasks[(NVM_BLOCK_NUMBER+15)/16];
const NvM_ConfigType NvM_Config = {
  NvM_BlockDescriptors,
  ARRAY_SIZE(NvM_BlockDescriptors),
  NvM_JobReadMasks,
  NvM_JobWriteMasks,
};
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
