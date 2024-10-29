/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef NVM_CFG_H
#define NVM_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
#include "Std_Types.h"
/* ================================ [ MACROS    ] ============================================== */
/* NVM target is FEE, CRC is not used */
#define MEMIF_ZERO_COST_FEE
#define NVM_BLOCKID_Dem_NvmEventStatusRecord0 2
#define NVM_BLOCKID_Dem_NvmEventStatusRecord1 3
#define NVM_BLOCKID_Dem_NvmEventStatusRecord2 4
#define NVM_BLOCKID_Dem_NvmEventStatusRecord3 5
#define NVM_BLOCKID_Dem_NvmEventStatusRecord4 6
#define NVM_BLOCKID_Dem_NvmEventStatusRecord5 7
#define NVM_BLOCKID_Dem_NvmEventStatusRecord6 8
#define NVM_BLOCKID_Dem_NvmEventStatusRecord7 9
#define NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord0 10
#define NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord1 11
#define NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord2 12
#define NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord3 13
#define NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord4 14
#define NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord5 15
#define NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord0 16
#define NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord1 17
#define NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord2 18
#define NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord3 19
#define NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord4 20
#define NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord5 21
#define NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord0 22
#define NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord1 23
#define NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord2 24
#define NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord3 25
#define NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord4 26
#define NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord5 27
#define NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord0 28
#define NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord1 29
#define NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord2 30
#define NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord3 31
#define NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord4 32
#define NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord5 33
#define NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord0 34
#define NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord1 35
#define NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord2 36
#define NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord3 37
#define NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord4 38
#define NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord5 39
#define NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord0 40
#define NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord1 41
#define NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord2 42
#define NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord3 43
#define NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord4 44
#define NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord5 45
#define NVM_BLOCKID_Dcm_NvmSecurityAccess 46
#define NVM_BLOCK_NUMBER 46
/* ================================ [ TYPES     ] ============================================== */
typedef struct {
  uint8_t status;
  uint8_t testFailedCounter;
} Dem_NvmEventStatusRecordType;

typedef struct {
  uint8_t status;
  uint8_t faultOccuranceCounter;
  uint8_t agingCounter;
  uint8_t agedCounter;
} Dem_NvmPrimaryDtcStatusRecordType;

typedef struct {
  uint16_t DtcId;
  uint8_t record[2][13];
} Dem_NvmPrimaryFreezeFrameRecordType;

typedef struct {
  uint16_t DtcId;
  uint8_t record[4];
} Dem_NvmPrimaryExtendedDataRecordType;

typedef struct {
  uint8_t status;
  uint8_t faultOccuranceCounter;
  uint8_t agingCounter;
  uint8_t agedCounter;
} Dem_NvmMirrorDtcStatusRecordType;

typedef struct {
  uint16_t DtcId;
  uint8_t record[2][13];
} Dem_NvmMirrorFreezeFrameRecordType;

typedef struct {
  uint16_t DtcId;
  uint8_t record[4];
} Dem_NvmMirrorExtendedDataRecordType;

typedef struct {
  uint8_t AttemptCounter;
} Dcm_NvmSecurityAccessType;

/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /* NVM_CFG_H */
