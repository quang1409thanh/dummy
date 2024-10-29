/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#ifdef USE_CANIF
#include "CanIf_Cfg.h"
#endif
#include "CanTp_Cfg.h"
#include "CanTp.h"
#include "CanTp_Types.h"
/* ================================ [ MACROS    ] ============================================== */
#ifndef CANTP_CFG_N_As
#define CANTP_CFG_N_As 25
#endif
#ifndef CANTP_CFG_N_Bs
#define CANTP_CFG_N_Bs 1000
#endif
#ifndef CANTP_CFG_N_Cr
#define CANTP_CFG_N_Cr 1000
#endif

#ifndef CANTP_CFG_STMIN
#define CANTP_CFG_STMIN 0
#endif

#ifndef CANTP_CFG_BS
#define CANTP_CFG_BS 8
#endif

#ifndef CANTP_CFG_RX_WFT_MAX
#define CANTP_CFG_RX_WFT_MAX 8
#endif

#ifndef CANTP_LL_DL
#define CANTP_LL_DL 8
#endif

#ifndef CANTP_CFG_PADDING
#define CANTP_CFG_PADDING 0x55
#endif

#if defined(_WIN32) || defined(linux)
#define L_CONST
#else
#define L_CONST const
#endif
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static uint8_t u8P2PData[CANTP_LL_DL];
static uint8_t u8P2AData[CANTP_LL_DL];
static L_CONST CanTp_ChannelConfigType CanTpChannelConfigs[] = {
  {
    /* P2P */
    CANTP_STANDARD,
    CANIF_P2P_TX,
    0 /* PduR_RxPduId */,
    0 /* PduR_TxPduId */,
    CANTP_CONVERT_MS_TO_MAIN_CYCLES(CANTP_CFG_N_As),
    CANTP_CONVERT_MS_TO_MAIN_CYCLES(CANTP_CFG_N_Bs),
    CANTP_CONVERT_MS_TO_MAIN_CYCLES(CANTP_CFG_N_Cr),
    CANTP_CFG_STMIN,
    CANTP_CFG_BS,
    0 /* N_TA */,
    CANTP_CFG_RX_WFT_MAX,
    CANTP_LL_DL,
    CANTP_CFG_PADDING,
    u8P2PData,
  },
  {
    /* P2A */
    CANTP_STANDARD,
    CANIF_P2A_TX,
    1 /* PduR_RxPduId */,
    1 /* PduR_TxPduId */,
    CANTP_CONVERT_MS_TO_MAIN_CYCLES(CANTP_CFG_N_As),
    CANTP_CONVERT_MS_TO_MAIN_CYCLES(CANTP_CFG_N_Bs),
    CANTP_CONVERT_MS_TO_MAIN_CYCLES(CANTP_CFG_N_Cr),
    CANTP_CFG_STMIN,
    CANTP_CFG_BS,
    0 /* N_TA */,
    CANTP_CFG_RX_WFT_MAX,
    CANTP_LL_DL,
    CANTP_CFG_PADDING,
    u8P2AData,
  },
};

static CanTp_ChannelContextType CanTpChannelContexts[ARRAY_SIZE(CanTpChannelConfigs)];

const CanTp_ConfigType CanTp_Config = {
  CanTpChannelConfigs,
  CanTpChannelContexts,
  ARRAY_SIZE(CanTpChannelConfigs),
};
/* ================================ [ LOCALS    ] ============================================== */
#if defined(_WIN32) || defined(linux)
#include <stdlib.h>
static void __attribute__((constructor)) _ll_dl_init(void) {
  int i;
  char *llDlStr = getenv("LL_DL");
  if (llDlStr != NULL) {
    for( i = 0; i < ARRAY_SIZE(CanTpChannelConfigs); i++ ) {
      CanTpChannelConfigs[i].LL_DL = atoi(llDlStr);
    }
  }
}
#endif
/* ================================ [ FUNCTIONS ] ============================================== */
