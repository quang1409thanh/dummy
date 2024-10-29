/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
#ifndef __STD_TRACE_APP_CFG_H
#define __STD_TRACE_APP_CFG_H
/* ================================ [ INCLUDES  ] ============================================== */
#include "Std_Timer.h"
#include "Std_Trace.h"
/* ================================ [ MACROS    ] ============================================== */
#ifndef TRE_APP_TIMER
#define TRE_APP_TIMER Std_GetTime()
#endif

#define TRE_APP_FLS_AC_ERASE 0
#define TRE_APP_FLS_AC_WRITE 1
#define TRE_APP_MAIN_TASK_10MS_B 2
#define TRE_APP_MAIN_TASK_10MS_E 3
#define TRE_APP_MAIN_TASK_FAST_B 4
#define TRE_APP_MAIN_TASK_FAST_E 5
#define TRE_APP_MEMORY_TASK_B 6
#define TRE_APP_MEMORY_TASK_E 7
#define TRE_APP_FEE_BACKUP_B 8
#define TRE_APP_FEE_BACKUP_E 9
#define TRE_APP_MAX 10

#define TRE_APP_ID_BITS 4
#define TRE_APP_TS_BITS 28
#define TRE_APP_TS_MASK 0xfffffff

#ifdef USE_TRACE_APP
#define STD_TRACE_APP(ev) STD_TRACE_EVENT( &Std_TraceArea_APP, ( TRE_APP_##ev << TRE_APP_TS_BITS ) | ( TRE_APP_TIMER & TRE_APP_TS_MASK ) )

#define STD_TRACE_APP_MAIN() STD_TRACE_MAIN( &Std_TraceArea_APP )
#else
#define STD_TRACE_APP(ev)
#define STD_TRACE_APP_MAIN()
#endif
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
extern const Std_TraceAreaType Std_TraceArea_APP;
/* ================================ [ DATAS     ] ============================================== */
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#endif /*__STD_TRACE_APP_CFG_H */
