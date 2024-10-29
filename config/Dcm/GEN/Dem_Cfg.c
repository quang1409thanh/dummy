/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "Dem_Priv.h"
#include "NvM_Cfg.h"
#ifdef USE_SHELL
#include "shell.h"
#endif
/* ================================ [ MACROS    ] ============================================== */
#define DEM_FFD_Battery 0
#define DEM_FFD_VehileSpeed 1
#define DEM_FFD_EngineSpeed 2
#define DEM_FFD_Time 3

#define DEM_EXTD_FaultOccuranceCounter 0
#define DEM_EXTD_AgingCounter 1
#define DEM_EXTD_AgedCounter 2

#define DEM_EXTD_FaultOccuranceCounter_NUMBER 0x1
#define DEM_EXTD_AgingCounter_NUMBER 0x2
#define DEM_EXTD_AgedCounter_NUMBER 0x3
#define DEM_MEMORY_ID_Primary 0
#define DEM_MEMORY_ID_Mirror 1
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
Std_ReturnType Dem_FFD_GetBattery(Dem_DtcIdType EventId, uint8_t *data, Dem_DTCOriginType DTCOrigin);
#ifdef USE_SHELL
static void Dem_FFD_PrintBattery(uint8_t* data) {
  {
    uint16_t *itsValue = (uint16_t*)(data+0);
    printf("  Battery = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
}
#endif
Std_ReturnType Dem_FFD_GetVehileSpeed(Dem_DtcIdType EventId, uint8_t *data, Dem_DTCOriginType DTCOrigin);
#ifdef USE_SHELL
static void Dem_FFD_PrintVehileSpeed(uint8_t* data) {
  {
    uint16_t *itsValue = (uint16_t*)(data+0);
    printf("  VehileSpeed = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
}
#endif
Std_ReturnType Dem_FFD_GetEngineSpeed(Dem_DtcIdType EventId, uint8_t *data, Dem_DTCOriginType DTCOrigin);
#ifdef USE_SHELL
static void Dem_FFD_PrintEngineSpeed(uint8_t* data) {
  {
    uint16_t *itsValue = (uint16_t*)(data+0);
    printf("  EngineSpeed = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
}
#endif
Std_ReturnType Dem_FFD_GetTime(Dem_DtcIdType EventId, uint8_t *data, Dem_DTCOriginType DTCOrigin);
#ifdef USE_SHELL
static void Dem_FFD_PrintTime(uint8_t* data) {
  {
    uint8_t *itsValue = (uint8_t*)(data+0);
    printf("  year = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
  {
    uint8_t *itsValue = (uint8_t*)(data+1);
    printf("  month = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
  {
    uint8_t *itsValue = (uint8_t*)(data+2);
    printf("  day = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
  {
    uint8_t *itsValue = (uint8_t*)(data+3);
    printf("  hour = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
  {
    uint8_t *itsValue = (uint8_t*)(data+4);
    printf("  minute = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
  {
    uint8_t *itsValue = (uint8_t*)(data+5);
    printf("  second = %u (0x%x)\n", (uint32_t)*itsValue, (uint32_t)*itsValue);
  }
}
#endif

Std_ReturnType Dem_EXTD_GetFaultOccuranceCounter(Dem_DtcIdType EventId, uint8_t *data, Dem_DTCOriginType DTCOrigin);
Std_ReturnType Dem_EXTD_GetAgingCounter(Dem_DtcIdType EventId, uint8_t *data, Dem_DTCOriginType DTCOrigin);
Std_ReturnType Dem_EXTD_GetAgedCounter(Dem_DtcIdType EventId, uint8_t *data, Dem_DTCOriginType DTCOrigin);

extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord0_Ram; /* DTC0 */
extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord1_Ram; /* DTC1 */
extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord2_Ram; /* DTC2 */
extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord3_Ram; /* DTC3 */
extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord4_Ram; /* DTC4 */
extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord5_Ram; /* DTC_COMB0_EVENT0 */
extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord6_Ram; /* DTC_COMB0_EVENT1 */
extern Dem_EventStatusRecordType Dem_NvmEventStatusRecord7_Ram; /* DTC_COMB0_EVENT2 */
extern Dem_DtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord0_Ram; /* DTC0 */
extern Dem_DtcStatusRecordType Dem_NvmMirrorDtcStatusRecord0_Ram; /* DTC0 */
extern Dem_DtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord1_Ram; /* DTC1 */
extern Dem_DtcStatusRecordType Dem_NvmMirrorDtcStatusRecord1_Ram; /* DTC1 */
extern Dem_DtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord2_Ram; /* DTC2 */
extern Dem_DtcStatusRecordType Dem_NvmMirrorDtcStatusRecord2_Ram; /* DTC2 */
extern Dem_DtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord3_Ram; /* DTC3 */
extern Dem_DtcStatusRecordType Dem_NvmMirrorDtcStatusRecord3_Ram; /* DTC3 */
extern Dem_DtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord4_Ram; /* DTC4 */
extern Dem_DtcStatusRecordType Dem_NvmMirrorDtcStatusRecord4_Ram; /* DTC4 */
extern Dem_DtcStatusRecordType Dem_NvmPrimaryDtcStatusRecord5_Ram; /* DTC_COMB0 */
extern Dem_DtcStatusRecordType Dem_NvmMirrorDtcStatusRecord5_Ram; /* DTC_COMB0 */
#if DEM_MAX_FREEZE_FRAME_RECORD > 0
extern Dem_FreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord0_Ram;
extern Dem_FreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord0_Ram;
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 1
extern Dem_FreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord1_Ram;
extern Dem_FreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord1_Ram;
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 2
extern Dem_FreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord2_Ram;
extern Dem_FreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord2_Ram;
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 3
extern Dem_FreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord3_Ram;
extern Dem_FreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord3_Ram;
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 4
extern Dem_FreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord4_Ram;
extern Dem_FreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord4_Ram;
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 5
extern Dem_FreezeFrameRecordType Dem_NvmPrimaryFreezeFrameRecord5_Ram;
extern Dem_FreezeFrameRecordType Dem_NvmMirrorFreezeFrameRecord5_Ram;
#endif
#if (DEM_MAX_EXTENDED_DATA_RECORD > 0) && defined(DEM_USE_NVM_EXTENDED_DATA)
extern Dem_ExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord0_Ram;
extern Dem_ExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord0_Ram;
#endif
#if (DEM_MAX_EXTENDED_DATA_RECORD > 1) && defined(DEM_USE_NVM_EXTENDED_DATA)
extern Dem_ExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord1_Ram;
extern Dem_ExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord1_Ram;
#endif
#if (DEM_MAX_EXTENDED_DATA_RECORD > 2) && defined(DEM_USE_NVM_EXTENDED_DATA)
extern Dem_ExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord2_Ram;
extern Dem_ExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord2_Ram;
#endif
#if (DEM_MAX_EXTENDED_DATA_RECORD > 3) && defined(DEM_USE_NVM_EXTENDED_DATA)
extern Dem_ExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord3_Ram;
extern Dem_ExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord3_Ram;
#endif
#if (DEM_MAX_EXTENDED_DATA_RECORD > 4) && defined(DEM_USE_NVM_EXTENDED_DATA)
extern Dem_ExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord4_Ram;
extern Dem_ExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord4_Ram;
#endif
#if (DEM_MAX_EXTENDED_DATA_RECORD > 5) && defined(DEM_USE_NVM_EXTENDED_DATA)
extern Dem_ExtendedDataRecordType Dem_NvmPrimaryExtendedDataRecord5_Ram;
extern Dem_ExtendedDataRecordType Dem_NvmMirrorExtendedDataRecord5_Ram;
#endif
/* ================================ [ DATAS     ] ============================================== */
static Dem_EventStatusRecordType* const Dem_NvmEventStatusRecords[] = {
  &Dem_NvmEventStatusRecord0_Ram, /* DTC0 */
  &Dem_NvmEventStatusRecord1_Ram, /* DTC1 */
  &Dem_NvmEventStatusRecord2_Ram, /* DTC2 */
  &Dem_NvmEventStatusRecord3_Ram, /* DTC3 */
  &Dem_NvmEventStatusRecord4_Ram, /* DTC4 */
  &Dem_NvmEventStatusRecord5_Ram, /* DTC_COMB0_EVENT0 */
  &Dem_NvmEventStatusRecord6_Ram, /* DTC_COMB0_EVENT1 */
  &Dem_NvmEventStatusRecord7_Ram, /* DTC_COMB0_EVENT2 */
};

static const uint16_t Dem_NvmEventStatusRecordNvmBlockIds[] = {
  NVM_BLOCKID_Dem_NvmEventStatusRecord0, /* DTC0 */
  NVM_BLOCKID_Dem_NvmEventStatusRecord1, /* DTC1 */
  NVM_BLOCKID_Dem_NvmEventStatusRecord2, /* DTC2 */
  NVM_BLOCKID_Dem_NvmEventStatusRecord3, /* DTC3 */
  NVM_BLOCKID_Dem_NvmEventStatusRecord4, /* DTC4 */
  NVM_BLOCKID_Dem_NvmEventStatusRecord5, /* DTC_COMB0_EVENT0 */
  NVM_BLOCKID_Dem_NvmEventStatusRecord6, /* DTC_COMB0_EVENT1 */
  NVM_BLOCKID_Dem_NvmEventStatusRecord7, /* DTC_COMB0_EVENT2 */
};

static Dem_DtcStatusRecordType* const Dem_NvmPrimaryDtcStatusRecord[] = {
  &Dem_NvmPrimaryDtcStatusRecord0_Ram,
  &Dem_NvmPrimaryDtcStatusRecord1_Ram,
  &Dem_NvmPrimaryDtcStatusRecord2_Ram,
  &Dem_NvmPrimaryDtcStatusRecord3_Ram,
  &Dem_NvmPrimaryDtcStatusRecord4_Ram,
  &Dem_NvmPrimaryDtcStatusRecord5_Ram,
};

#ifdef DEM_USE_NVM
static const uint16_t Dem_NvmPrimaryDtcStatusRecordNvmBlockIds[] = {
  NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord0,
  NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord1,
  NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord2,
  NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord3,
  NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord4,
  NVM_BLOCKID_Dem_NvmPrimaryDtcStatusRecord5,
};
#endif

static Dem_DtcStatusRecordType* const Dem_NvmMirrorDtcStatusRecord[] = {
  &Dem_NvmMirrorDtcStatusRecord0_Ram,
  &Dem_NvmMirrorDtcStatusRecord1_Ram,
  &Dem_NvmMirrorDtcStatusRecord2_Ram,
  &Dem_NvmMirrorDtcStatusRecord3_Ram,
  &Dem_NvmMirrorDtcStatusRecord4_Ram,
  &Dem_NvmMirrorDtcStatusRecord5_Ram,
};

#ifdef DEM_USE_NVM
static const uint16_t Dem_NvmMirrorDtcStatusRecordNvmBlockIds[] = {
  NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord0,
  NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord1,
  NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord2,
  NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord3,
  NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord4,
  NVM_BLOCKID_Dem_NvmMirrorDtcStatusRecord5,
};
#endif

static Dem_FreezeFrameRecordType* const Dem_NvmPrimaryFreezeFrameRecord[] = {
#if DEM_MAX_FREEZE_FRAME_RECORD > 0
  &Dem_NvmPrimaryFreezeFrameRecord0_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 1
  &Dem_NvmPrimaryFreezeFrameRecord1_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 2
  &Dem_NvmPrimaryFreezeFrameRecord2_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 3
  &Dem_NvmPrimaryFreezeFrameRecord3_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 4
  &Dem_NvmPrimaryFreezeFrameRecord4_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 5
  &Dem_NvmPrimaryFreezeFrameRecord5_Ram,
#endif
};

#ifdef DEM_USE_NVM
static const uint16_t Dem_NvmPrimaryFreezeFrameNvmBlockIds[] = {
#if DEM_MAX_FREEZE_FRAME_RECORD > 0
  NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord0,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 1
  NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord1,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 2
  NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord2,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 3
  NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord3,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 4
  NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord4,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 5
  NVM_BLOCKID_Dem_NvmPrimaryFreezeFrameRecord5,
#endif
};
#endif

static Dem_FreezeFrameRecordType* const Dem_NvmMirrorFreezeFrameRecord[] = {
#if DEM_MAX_FREEZE_FRAME_RECORD > 0
  &Dem_NvmMirrorFreezeFrameRecord0_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 1
  &Dem_NvmMirrorFreezeFrameRecord1_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 2
  &Dem_NvmMirrorFreezeFrameRecord2_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 3
  &Dem_NvmMirrorFreezeFrameRecord3_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 4
  &Dem_NvmMirrorFreezeFrameRecord4_Ram,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 5
  &Dem_NvmMirrorFreezeFrameRecord5_Ram,
#endif
};

#ifdef DEM_USE_NVM
static const uint16_t Dem_NvmMirrorFreezeFrameNvmBlockIds[] = {
#if DEM_MAX_FREEZE_FRAME_RECORD > 0
  NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord0,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 1
  NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord1,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 2
  NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord2,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 3
  NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord3,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 4
  NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord4,
#endif
#if DEM_MAX_FREEZE_FRAME_RECORD > 5
  NVM_BLOCKID_Dem_NvmMirrorFreezeFrameRecord5,
#endif
};
#endif

#ifdef DEM_USE_NVM_EXTENDED_DATA
static Dem_ExtendedDataRecordType* const Dem_NvmPrimaryExtendedDataRecord[] = {
#if DEM_MAX_EXTENDED_DATA_RECORD > 0
  &Dem_NvmPrimaryExtendedDataRecord0_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 1
  &Dem_NvmPrimaryExtendedDataRecord1_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 2
  &Dem_NvmPrimaryExtendedDataRecord2_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 3
  &Dem_NvmPrimaryExtendedDataRecord3_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 4
  &Dem_NvmPrimaryExtendedDataRecord4_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 5
  &Dem_NvmPrimaryExtendedDataRecord5_Ram,
#endif
};
#ifdef DEM_USE_NVM
static const uint16_t Dem_NvmPrimaryExtendedDataNvmBlockIds[] = {
#if DEM_MAX_EXTENDED_DATA_RECORD > 0
  NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord0,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 1
  NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord1,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 2
  NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord2,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 3
  NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord3,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 4
  NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord4,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 5
  NVM_BLOCKID_Dem_NvmPrimaryExtendedDataRecord5,
#endif
};
#endif
#endif

#ifdef DEM_USE_NVM_EXTENDED_DATA
static Dem_ExtendedDataRecordType* const Dem_NvmMirrorExtendedDataRecord[] = {
#if DEM_MAX_EXTENDED_DATA_RECORD > 0
  &Dem_NvmMirrorExtendedDataRecord0_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 1
  &Dem_NvmMirrorExtendedDataRecord1_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 2
  &Dem_NvmMirrorExtendedDataRecord2_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 3
  &Dem_NvmMirrorExtendedDataRecord3_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 4
  &Dem_NvmMirrorExtendedDataRecord4_Ram,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 5
  &Dem_NvmMirrorExtendedDataRecord5_Ram,
#endif
};
#ifdef DEM_USE_NVM
static const uint16_t Dem_NvmMirrorExtendedDataNvmBlockIds[] = {
#if DEM_MAX_EXTENDED_DATA_RECORD > 0
  NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord0,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 1
  NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord1,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 2
  NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord2,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 3
  NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord3,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 4
  NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord4,
#endif
#if DEM_MAX_EXTENDED_DATA_RECORD > 5
  NVM_BLOCKID_Dem_NvmMirrorExtendedDataRecord5,
#endif
};
#endif
#endif

#ifndef DEM_USE_NVM
static uint8_t Dem_NvmPrimaryDtcStatusRecordDirty[(ARRAY_SIZE(Dem_NvmPrimaryDtcStatusRecord)+7)/8];
static uint8_t Dem_NvmPrimaryFreezeFrameRecordDirty[(ARRAY_SIZE(Dem_NvmPrimaryFreezeFrameRecord)+7)/8];
#ifdef DEM_USE_NVM_EXTENDED_DATA
static uint8_t Dem_NvmPrimaryExtendedDataDirty[(ARRAY_SIZE(Dem_NvmPrimaryExtendedDataRecord)+7)/8];
#endif
static uint8_t Dem_NvmMirrorDtcStatusRecordDirty[(ARRAY_SIZE(Dem_NvmMirrorDtcStatusRecord)+7)/8];
static uint8_t Dem_NvmMirrorFreezeFrameRecordDirty[(ARRAY_SIZE(Dem_NvmMirrorFreezeFrameRecord)+7)/8];
#ifdef DEM_USE_NVM_EXTENDED_DATA
static uint8_t Dem_NvmMirrorExtendedDataDirty[(ARRAY_SIZE(Dem_NvmMirrorExtendedDataRecord)+7)/8];
#endif
#endif

static const Dem_MemoryDestinationType Dem_MemoryDestination[] = {
  {
    Dem_NvmPrimaryDtcStatusRecord,
    Dem_NvmPrimaryFreezeFrameRecord,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    Dem_NvmPrimaryExtendedDataRecord,
    #endif
    #ifndef DEM_USE_NVM
    Dem_NvmPrimaryDtcStatusRecordDirty,
    Dem_NvmPrimaryFreezeFrameRecordDirty,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    Dem_NvmPrimaryExtendedDataDirty,
    #endif
    #else
    Dem_NvmPrimaryDtcStatusRecordNvmBlockIds,
    Dem_NvmPrimaryFreezeFrameNvmBlockIds,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    Dem_NvmPrimaryExtendedDataNvmBlockIds,
    #endif
    #endif
    ARRAY_SIZE(Dem_NvmPrimaryDtcStatusRecord),
    ARRAY_SIZE(Dem_NvmPrimaryFreezeFrameRecord),
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    ARRAY_SIZE(Dem_NvmPrimaryExtendedDataRecord),
    #endif
    0x0001/* DTCOrigin */
  },
  {
    Dem_NvmMirrorDtcStatusRecord,
    Dem_NvmMirrorFreezeFrameRecord,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    Dem_NvmMirrorExtendedDataRecord,
    #endif
    #ifndef DEM_USE_NVM
    Dem_NvmMirrorDtcStatusRecordDirty,
    Dem_NvmMirrorFreezeFrameRecordDirty,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    Dem_NvmMirrorExtendedDataDirty,
    #endif
    #else
    Dem_NvmMirrorDtcStatusRecordNvmBlockIds,
    Dem_NvmMirrorFreezeFrameNvmBlockIds,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    Dem_NvmMirrorExtendedDataNvmBlockIds,
    #endif
    #endif
    ARRAY_SIZE(Dem_NvmMirrorDtcStatusRecord),
    ARRAY_SIZE(Dem_NvmMirrorFreezeFrameRecord),
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    ARRAY_SIZE(Dem_NvmMirrorExtendedDataRecord),
    #endif
    0x0002/* DTCOrigin */
  },
};

static const Dem_MemoryDestinationType* const Dem_Dtc0MemoryDestinations[]= {
  &Dem_MemoryDestination[DEM_MEMORY_ID_Primary],
  &Dem_MemoryDestination[DEM_MEMORY_ID_Mirror],
};

static const Dem_MemoryDestinationType* const Dem_Dtc1MemoryDestinations[]= {
  &Dem_MemoryDestination[DEM_MEMORY_ID_Primary],
  &Dem_MemoryDestination[DEM_MEMORY_ID_Mirror],
};

static const Dem_MemoryDestinationType* const Dem_Dtc2MemoryDestinations[]= {
  &Dem_MemoryDestination[DEM_MEMORY_ID_Primary],
  &Dem_MemoryDestination[DEM_MEMORY_ID_Mirror],
};

static const Dem_MemoryDestinationType* const Dem_Dtc3MemoryDestinations[]= {
  &Dem_MemoryDestination[DEM_MEMORY_ID_Primary],
  &Dem_MemoryDestination[DEM_MEMORY_ID_Mirror],
};

static const Dem_MemoryDestinationType* const Dem_Dtc4MemoryDestinations[]= {
  &Dem_MemoryDestination[DEM_MEMORY_ID_Primary],
  &Dem_MemoryDestination[DEM_MEMORY_ID_Mirror],
};

static const Dem_MemoryDestinationType* const Dem_Dtc5MemoryDestinations[]= {
  &Dem_MemoryDestination[DEM_MEMORY_ID_Primary],
  &Dem_MemoryDestination[DEM_MEMORY_ID_Mirror],
};

static const Dem_FreeFrameDataConfigType FreeFrameDataConfigs[] = {
  {
    Dem_FFD_GetBattery,
    0x1001,
    2,
#ifdef USE_SHELL
    Dem_FFD_PrintBattery,
#endif
  },
  {
    Dem_FFD_GetVehileSpeed,
    0x1002,
    2,
#ifdef USE_SHELL
    Dem_FFD_PrintVehileSpeed,
#endif
  },
  {
    Dem_FFD_GetEngineSpeed,
    0x1003,
    2,
#ifdef USE_SHELL
    Dem_FFD_PrintEngineSpeed,
#endif
  },
  {
    Dem_FFD_GetTime,
    0x1004,
    6,
#ifdef USE_SHELL
    Dem_FFD_PrintTime,
#endif
  },
};

static const Dem_ExtendedDataConfigType ExtendedDataConfigs[] = {
  {Dem_EXTD_GetFaultOccuranceCounter, DEM_EXTD_FaultOccuranceCounter_NUMBER, 1},
  {Dem_EXTD_GetAgingCounter, DEM_EXTD_AgingCounter_NUMBER, 1},
  {Dem_EXTD_GetAgedCounter, DEM_EXTD_AgedCounter_NUMBER, 1},
};

static const Dem_DebounceCounterBasedConfigType Dem_DebounceCounterBasedDefault = {
  DEM_DEBOUNCE_FREEZE,
  /* DebounceCounterDecrementStepSize */ 2,
  /* DebounceCounterFailedThreshold */ 10,
  /* DebounceCounterIncrementStepSize */ 1,
  /* DebounceCounterJumpDown */ FALSE,
  /* DebounceCounterJumpDownValue */ 0,
  /* DebounceCounterJumpUp */ TRUE,
  /* DebounceCounterJumpUpValue */ 0,
  /* DebounceCounterPassedThreshold */ -10,
};

/* each Event can have different environment data that cares about */
static const uint16_t Dem_FreezeFrameDataIndexDefault[] = {
  DEM_FFD_Battery,
  DEM_FFD_VehileSpeed,
  DEM_FFD_EngineSpeed,
  DEM_FFD_Time,
};

/* each Event can have different extended data that cares about*/
static const uint8_t Dem_ExtendedDataNumberIndexDefault[] = {
  DEM_EXTD_FaultOccuranceCounter,
  DEM_EXTD_AgingCounter,
  DEM_EXTD_AgedCounter,
};

static const Dem_FreezeFrameRecordClassType Dem_FreezeFrameRecordClassDefault = {
  Dem_FreezeFrameDataIndexDefault,
  ARRAY_SIZE(Dem_FreezeFrameDataIndexDefault),
};

static const Dem_ExtendedDataRecordClassType Dem_ExtendedDataRecordClassDefault = {
  Dem_ExtendedDataNumberIndexDefault,
  ARRAY_SIZE(Dem_ExtendedDataNumberIndexDefault),
  /* ExtendedDataRecordNumber */ 1,
};

static const Dem_ExtendedDataRecordClassType* const Dem_ExtendedDataRecordClassRefsDefault[] = {
  &Dem_ExtendedDataRecordClassDefault,
};

static const Dem_ExtendedDataClassType Dem_ExtendedDataClassDefault = {
  Dem_ExtendedDataRecordClassRefsDefault,
  ARRAY_SIZE(Dem_ExtendedDataRecordClassRefsDefault),
};

static const uint8_t Dem_FreezeFrameRecNumsForDTC0[] = {1, 2};
static const uint8_t Dem_FreezeFrameRecNumsForDTC1[] = {3, 4};
static const uint8_t Dem_FreezeFrameRecNumsForDTC2[] = {5, 6};
static const uint8_t Dem_FreezeFrameRecNumsForDTC3[] = {7, 8};
static const uint8_t Dem_FreezeFrameRecNumsForDTC4[] = {9, 10};
static const uint8_t Dem_FreezeFrameRecNumsForDTC_COMB0[] = {11, 12};
static const Dem_FreezeFrameRecNumClassType Dem_FreezeFrameRecNumClass[] = {
  {
    Dem_FreezeFrameRecNumsForDTC0,
    ARRAY_SIZE(Dem_FreezeFrameRecNumsForDTC0),
  },
  {
    Dem_FreezeFrameRecNumsForDTC1,
    ARRAY_SIZE(Dem_FreezeFrameRecNumsForDTC1),
  },
  {
    Dem_FreezeFrameRecNumsForDTC2,
    ARRAY_SIZE(Dem_FreezeFrameRecNumsForDTC2),
  },
  {
    Dem_FreezeFrameRecNumsForDTC3,
    ARRAY_SIZE(Dem_FreezeFrameRecNumsForDTC3),
  },
  {
    Dem_FreezeFrameRecNumsForDTC4,
    ARRAY_SIZE(Dem_FreezeFrameRecNumsForDTC4),
  },
  {
    Dem_FreezeFrameRecNumsForDTC_COMB0,
    ARRAY_SIZE(Dem_FreezeFrameRecNumsForDTC_COMB0),
  },
};

static const Dem_DTCAttributesType Dem_DTCAttributes[] = {
  {
    &Dem_ExtendedDataClassDefault,
    &Dem_FreezeFrameRecordClassDefault,
    &Dem_FreezeFrameRecNumClass[0],
    Dem_Dtc0MemoryDestinations,
    ARRAY_SIZE(Dem_Dtc0MemoryDestinations),
    /* Priority */ 0,
    /* AgingAllowed */ TRUE,
    /* AgingCycleCounterThreshold */ 2,
    /* OccurrenceCounterProcessing */ DEM_PROCESS_OCCCTR_TF,
    /* FreezeFrameRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    /* ExtendedDataRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #endif
    /* DebounceAlgorithmClass */ DEM_DEBOUNCE_COUNTER_BASED,
    /* EnvironmentDataCapture */ DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING,
  },
  {
    &Dem_ExtendedDataClassDefault,
    &Dem_FreezeFrameRecordClassDefault,
    &Dem_FreezeFrameRecNumClass[1],
    Dem_Dtc1MemoryDestinations,
    ARRAY_SIZE(Dem_Dtc1MemoryDestinations),
    /* Priority */ 1,
    /* AgingAllowed */ TRUE,
    /* AgingCycleCounterThreshold */ 2,
    /* OccurrenceCounterProcessing */ DEM_PROCESS_OCCCTR_TF,
    /* FreezeFrameRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    /* ExtendedDataRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #endif
    /* DebounceAlgorithmClass */ DEM_DEBOUNCE_COUNTER_BASED,
    /* EnvironmentDataCapture */ DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING,
  },
  {
    &Dem_ExtendedDataClassDefault,
    &Dem_FreezeFrameRecordClassDefault,
    &Dem_FreezeFrameRecNumClass[2],
    Dem_Dtc2MemoryDestinations,
    ARRAY_SIZE(Dem_Dtc2MemoryDestinations),
    /* Priority */ 2,
    /* AgingAllowed */ TRUE,
    /* AgingCycleCounterThreshold */ 2,
    /* OccurrenceCounterProcessing */ DEM_PROCESS_OCCCTR_TF,
    /* FreezeFrameRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    /* ExtendedDataRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #endif
    /* DebounceAlgorithmClass */ DEM_DEBOUNCE_COUNTER_BASED,
    /* EnvironmentDataCapture */ DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING,
  },
  {
    &Dem_ExtendedDataClassDefault,
    &Dem_FreezeFrameRecordClassDefault,
    &Dem_FreezeFrameRecNumClass[3],
    Dem_Dtc3MemoryDestinations,
    ARRAY_SIZE(Dem_Dtc3MemoryDestinations),
    /* Priority */ 3,
    /* AgingAllowed */ TRUE,
    /* AgingCycleCounterThreshold */ 2,
    /* OccurrenceCounterProcessing */ DEM_PROCESS_OCCCTR_TF,
    /* FreezeFrameRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    /* ExtendedDataRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #endif
    /* DebounceAlgorithmClass */ DEM_DEBOUNCE_COUNTER_BASED,
    /* EnvironmentDataCapture */ DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING,
  },
  {
    &Dem_ExtendedDataClassDefault,
    &Dem_FreezeFrameRecordClassDefault,
    &Dem_FreezeFrameRecNumClass[4],
    Dem_Dtc4MemoryDestinations,
    ARRAY_SIZE(Dem_Dtc4MemoryDestinations),
    /* Priority */ 4,
    /* AgingAllowed */ TRUE,
    /* AgingCycleCounterThreshold */ 2,
    /* OccurrenceCounterProcessing */ DEM_PROCESS_OCCCTR_TF,
    /* FreezeFrameRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    /* ExtendedDataRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #endif
    /* DebounceAlgorithmClass */ DEM_DEBOUNCE_COUNTER_BASED,
    /* EnvironmentDataCapture */ DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING,
  },
  {
    &Dem_ExtendedDataClassDefault,
    &Dem_FreezeFrameRecordClassDefault,
    &Dem_FreezeFrameRecNumClass[5],
    Dem_Dtc5MemoryDestinations,
    ARRAY_SIZE(Dem_Dtc5MemoryDestinations),
    /* Priority */ 5,
    /* AgingAllowed */ TRUE,
    /* AgingCycleCounterThreshold */ 2,
    /* OccurrenceCounterProcessing */ DEM_PROCESS_OCCCTR_TF,
    /* FreezeFrameRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #ifdef DEM_USE_NVM_EXTENDED_DATA
    /* ExtendedDataRecordTrigger */ DEM_TRIGGER_ON_TEST_FAILED,
    #endif
    /* DebounceAlgorithmClass */ DEM_DEBOUNCE_COUNTER_BASED,
    /* EnvironmentDataCapture */ DEM_CAPTURE_SYNCHRONOUS_TO_REPORTING,
  },
};

static const Dem_EventIdType Dem_Dtc0EventRefs[] = {
  DEM_EVENT_ID_DTC0,
};

static const Dem_EventIdType Dem_Dtc1EventRefs[] = {
  DEM_EVENT_ID_DTC1,
};

static const Dem_EventIdType Dem_Dtc2EventRefs[] = {
  DEM_EVENT_ID_DTC2,
};

static const Dem_EventIdType Dem_Dtc3EventRefs[] = {
  DEM_EVENT_ID_DTC3,
};

static const Dem_EventIdType Dem_Dtc4EventRefs[] = {
  DEM_EVENT_ID_DTC4,
};

static const Dem_EventIdType Dem_Dtc5EventRefs[] = {
  DEM_EVENT_ID_DTC_COMB0_EVENT0,
  DEM_EVENT_ID_DTC_COMB0_EVENT1,
  DEM_EVENT_ID_DTC_COMB0_EVENT2,
};


static const Dem_DTCType Dem_Dtcs[] = {
  {
    &Dem_DTCAttributes[0],
    Dem_Dtc0EventRefs,
    0x112200,
    0, /* DtcId */
    ARRAY_SIZE(Dem_Dtc0EventRefs),
    #if 0
    0, /* FunctionalUnit */
    DEM_SEVERITY_NO_SEVERITY, /* Severity */
    DEM_NV_STORE_IMMEDIATE_AT_FIRST_OCCURRENCE, /* NvStorageStrategy */
    #endif
  },
  {
    &Dem_DTCAttributes[1],
    Dem_Dtc1EventRefs,
    0x112201,
    1, /* DtcId */
    ARRAY_SIZE(Dem_Dtc1EventRefs),
    #if 0
    0, /* FunctionalUnit */
    DEM_SEVERITY_NO_SEVERITY, /* Severity */
    DEM_NV_STORE_IMMEDIATE_AT_FIRST_OCCURRENCE, /* NvStorageStrategy */
    #endif
  },
  {
    &Dem_DTCAttributes[2],
    Dem_Dtc2EventRefs,
    0x112202,
    2, /* DtcId */
    ARRAY_SIZE(Dem_Dtc2EventRefs),
    #if 0
    0, /* FunctionalUnit */
    DEM_SEVERITY_NO_SEVERITY, /* Severity */
    DEM_NV_STORE_IMMEDIATE_AT_FIRST_OCCURRENCE, /* NvStorageStrategy */
    #endif
  },
  {
    &Dem_DTCAttributes[3],
    Dem_Dtc3EventRefs,
    0x112203,
    3, /* DtcId */
    ARRAY_SIZE(Dem_Dtc3EventRefs),
    #if 0
    0, /* FunctionalUnit */
    DEM_SEVERITY_NO_SEVERITY, /* Severity */
    DEM_NV_STORE_IMMEDIATE_AT_FIRST_OCCURRENCE, /* NvStorageStrategy */
    #endif
  },
  {
    &Dem_DTCAttributes[4],
    Dem_Dtc4EventRefs,
    0x112204,
    4, /* DtcId */
    ARRAY_SIZE(Dem_Dtc4EventRefs),
    #if 0
    0, /* FunctionalUnit */
    DEM_SEVERITY_NO_SEVERITY, /* Severity */
    DEM_NV_STORE_IMMEDIATE_AT_FIRST_OCCURRENCE, /* NvStorageStrategy */
    #endif
  },
  {
    &Dem_DTCAttributes[5],
    Dem_Dtc5EventRefs,
    0x112205,
    5, /* DtcId */
    ARRAY_SIZE(Dem_Dtc5EventRefs),
    #if 0
    0, /* FunctionalUnit */
    DEM_SEVERITY_NO_SEVERITY, /* Severity */
    DEM_NV_STORE_IMMEDIATE_AT_FIRST_OCCURRENCE, /* NvStorageStrategy */
    #endif
  },
};

static const Dem_EventConfigType Dem_EventConfigs[DTC_ENVENT_NUM] = {
  {
    &Dem_Dtcs[0],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0|DEM_CONTIDION_BATTERY_NORMAL,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
  {
    &Dem_Dtcs[1],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
  {
    &Dem_Dtcs[2],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
  {
    &Dem_Dtcs[3],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
  {
    &Dem_Dtcs[4],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
  {
    &Dem_Dtcs[5],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
  {
    &Dem_Dtcs[5],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
  {
    &Dem_Dtcs[5],
    /* DemCallbackInitMForE */ NULL,
    &Dem_DebounceCounterBasedDefault,
    #ifdef DEM_USE_ENABLE_CONDITION
    0,
    #endif
    /* ConfirmationThreshold */ 1,
    /* OperationCycleRef */ DEM_OPERATION_CYCLE_IGNITION,
    /* RecoverableInSameOperationCycle */ FALSE,
  },
};

#ifndef DEM_USE_NVM
static uint8_t Dem_EventStatusDirty[(ARRAY_SIZE(Dem_EventConfigs)+7)/8];
#endif
static Dem_EventContextType Dem_EventContexts[DTC_ENVENT_NUM];
static Dem_OperationCycleStateType Dem_OperationCycleStates[2];
const Dem_ConfigType Dem_Config = {
  FreeFrameDataConfigs,
  ExtendedDataConfigs,
  Dem_EventConfigs,
  Dem_EventContexts,
  Dem_NvmEventStatusRecords,
#ifdef DEM_USE_NVM
  Dem_NvmEventStatusRecordNvmBlockIds,
#else
  Dem_EventStatusDirty,
#endif
  Dem_Dtcs,
  Dem_MemoryDestination,
  Dem_OperationCycleStates,
  ARRAY_SIZE(FreeFrameDataConfigs),
  ARRAY_SIZE(Dem_EventConfigs),
  ARRAY_SIZE(Dem_Dtcs),
  ARRAY_SIZE(Dem_MemoryDestination),
  ARRAY_SIZE(ExtendedDataConfigs),
  ARRAY_SIZE(Dem_OperationCycleStates),
  /* TypeOfFreezeFrameRecordNumeration */ DEM_FF_RECNUM_CONFIGURED,
};
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
