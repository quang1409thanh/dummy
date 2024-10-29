/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef DCM_CFG_H
#define DCM_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
#ifdef USE_NVM
#include "NvM_Cfg.h"
#endif
/* ================================ [ MACROS    ] ============================================== */
#ifndef DCM_DEFAULT_SESSION
#define DCM_DEFAULT_SESSION 0x1
#endif
#ifndef DCM_DEFAULT_MASK
#define DCM_DEFAULT_MASK 0x1
#endif
#ifndef DCM_PROGRAM_SESSION
#define DCM_PROGRAM_SESSION 0x2
#endif
#ifndef DCM_PROGRAM_MASK
#define DCM_PROGRAM_MASK 0x2
#endif
#ifndef DCM_EXTENDED_SESSION
#define DCM_EXTENDED_SESSION 0x3
#endif
#ifndef DCM_EXTENDED_MASK
#define DCM_EXTENDED_MASK 0x4
#endif
#ifndef DCM_FACTORY_SESSION
#define DCM_FACTORY_SESSION 0x50
#endif
#ifndef DCM_FACTORY_MASK
#define DCM_FACTORY_MASK 0x10
#endif

#define DCM_MAIN_FUNCTION_PERIOD 10
#define DCM_CONVERT_MS_TO_MAIN_CYCLES(x) \
  ((x + DCM_MAIN_FUNCTION_PERIOD - 1) / DCM_MAIN_FUNCTION_PERIOD)

#define Dcm_DslCustomerSession2Mask(mask, sesCtrl) \
  if (DCM_FACTORY_SESSION == sesCtrl) { \
    mask = DCM_FACTORY_MASK; \
  }\


#define DCM_USE_SERVICE_DIAGNOSTIC_SESSION_CONTROL
#define DCM_USE_SERVICE_ECU_RESET
#ifdef USE_DEM
#define DCM_USE_SERVICE_CLEAR_DIAGNOSTIC_INFORMATION
#endif
#ifdef USE_DEM
#define DCM_USE_SERVICE_READ_DTC_INFORMATION
#endif
#define DCM_USE_SERVICE_READ_DATA_BY_IDENTIFIER
#define DCM_USE_SERVICE_SECURITY_ACCESS
#ifdef USE_CRYPTO
#define DCM_USE_SERVICE_AUTHENTICATION
#endif
#define DCM_USE_SERVICE_READ_DATA_BY_PERIODIC_IDENTIFIER
#define DCM_USE_SERVICE_DYNAMICALLY_DEFINE_DATA_IDENTIFIER
#define DCM_USE_SERVICE_INPUT_OUTPUT_CONTROL_BY_IDENTIFIER
#define DCM_USE_SERVICE_TESTER_PRESENT
#define DCM_USE_SERVICE_READ_MEMORY_BY_ADDRESS
#define DCM_USE_SERVICE_WRITE_MEMORY_BY_ADDRESS
#ifdef USE_DEM
#define DCM_USE_SERVICE_CONTROL_DTC_SETTING
#endif
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /* DCM_CFG_H */
