/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef FEE_CFG_H
#define FEE_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
/* ================================ [ MACROS    ] ============================================== */
#define FEE_MAX_DATA_SIZE 28

#define FEE_NUMBER_Dem_NvmEventStatusRecord0 1
#define FEE_NUMBER_Dem_NvmEventStatusRecord1 2
#define FEE_NUMBER_Dem_NvmEventStatusRecord2 3
#define FEE_NUMBER_Dem_NvmEventStatusRecord3 4
#define FEE_NUMBER_Dem_NvmEventStatusRecord4 5
#define FEE_NUMBER_Dem_NvmEventStatusRecord5 6
#define FEE_NUMBER_Dem_NvmEventStatusRecord6 7
#define FEE_NUMBER_Dem_NvmEventStatusRecord7 8
#define FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord0 9
#define FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord1 10
#define FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord2 11
#define FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord3 12
#define FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord4 13
#define FEE_NUMBER_Dem_NvmPrimaryDtcStatusRecord5 14
#define FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord0 15
#define FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord1 16
#define FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord2 17
#define FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord3 18
#define FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord4 19
#define FEE_NUMBER_Dem_NvmPrimaryFreezeFrameRecord5 20
#define FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord0 21
#define FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord1 22
#define FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord2 23
#define FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord3 24
#define FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord4 25
#define FEE_NUMBER_Dem_NvmPrimaryExtendedDataRecord5 26
#define FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord0 27
#define FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord1 28
#define FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord2 29
#define FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord3 30
#define FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord4 31
#define FEE_NUMBER_Dem_NvmMirrorDtcStatusRecord5 32
#define FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord0 33
#define FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord1 34
#define FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord2 35
#define FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord3 36
#define FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord4 37
#define FEE_NUMBER_Dem_NvmMirrorFreezeFrameRecord5 38
#define FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord0 39
#define FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord1 40
#define FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord2 41
#define FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord3 42
#define FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord4 43
#define FEE_NUMBER_Dem_NvmMirrorExtendedDataRecord5 44
#define FEE_NUMBER_Dcm_NvmSecurityAccess 45
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
#endif /* FEE_CFG_H */
