/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "Std_Trace.h"
#ifdef USE_SHELL
#include "shell.h"
#endif
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
RB_DECLARE(TraceAreaApp, Std_TraceEventType, 1024);
const Std_TraceAreaType Std_TraceArea_APP = {
  &rb_TraceAreaApp,
};

/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
#ifdef USE_SHELL
static int Shell_TraceApp(int argc, const char *argv[]) {
  Std_TraceDump(&Std_TraceArea_APP);
  return 0;
}
SHELL_REGISTER(trace_app, "trace_app\n", Shell_TraceApp)
#endif
