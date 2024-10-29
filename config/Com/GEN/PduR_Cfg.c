/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "PduR.h"
#include "PduR_Cfg.h"
#include "PduR_Priv.h"
#include "CanTp.h"
#include "CanTp_Cfg.h"
#include "Dcm.h"
#include "Com.h"
#include "Com_Cfg.h"
#include "CanIf.h"
#include "CanIf_Cfg.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
const PduR_ApiType PduR_DcmApi = {
  Dcm_StartOfReception,
  Dcm_CopyRxData,
  { (void_ptr_t)Dcm_TpRxIndication },
  NULL,
  Dcm_CopyTxData,
  Dcm_TpTxConfirmation,
};

const PduR_ApiType PduR_ComApi = {
  NULL,
  NULL,
  { (void*)Com_RxIndication },
  NULL,
  NULL,
  Com_TxConfirmation,
};

const PduR_ApiType PduR_CanTpApi = {
  NULL,
  NULL,
  { NULL },
  CanTp_Transmit,
  NULL,
  NULL,
};

const PduR_ApiType PduR_CanIfApi = {
  NULL,
  NULL,
  { NULL },
  CanIf_Transmit,
  NULL,
  NULL,
};

static const PduR_PduType PduR_SrcPdu_CanTp_Dcm_P2P_RX = {
  PDUR_MODULE_CANTP,
  CANTP_P2P_RX,
  &PduR_CanTpApi,
};

static const PduR_PduType PduR_DstPdu_CanTp_Dcm_P2P_RX[]={
  {
    PDUR_MODULE_DCM,
    DCM_P2P_RX,
    &PduR_DcmApi,
  },
};

static const PduR_PduType PduR_SrcPdu_Dcm_CanTp_P2P_TX = {
  PDUR_MODULE_DCM,
  DCM_P2P_TX,
  &PduR_DcmApi,
};

static const PduR_PduType PduR_DstPdu_Dcm_CanTp_P2P_TX[]={
  {
    PDUR_MODULE_CANTP,
    CANTP_P2P_TX,
    &PduR_CanTpApi,
  },
};

static const PduR_PduType PduR_SrcPdu_CanTp_Dcm_P2A_RX = {
  PDUR_MODULE_CANTP,
  CANTP_P2A_RX,
  &PduR_CanTpApi,
};

static const PduR_PduType PduR_DstPdu_CanTp_Dcm_P2A_RX[]={
  {
    PDUR_MODULE_DCM,
    DCM_P2A_RX,
    &PduR_DcmApi,
  },
};

static const PduR_PduType PduR_SrcPdu_Dcm_CanTp_P2A_TX = {
  PDUR_MODULE_DCM,
  DCM_P2A_TX,
  &PduR_DcmApi,
};

static const PduR_PduType PduR_DstPdu_Dcm_CanTp_P2A_TX[]={
  {
    PDUR_MODULE_CANTP,
    CANTP_P2A_TX,
    &PduR_CanTpApi,
  },
};

static const PduR_PduType PduR_SrcPdu_Com_CanIf_CAN0_TX_MSG_TIME = {
  PDUR_MODULE_COM,
  COM_CAN0_TX_MSG_TIME,
  &PduR_ComApi,
};

static const PduR_PduType PduR_DstPdu_Com_CanIf_CAN0_TX_MSG_TIME[]={
  {
    PDUR_MODULE_CANIF,
    CANIF_CAN0_TX_MSG_TIME,
    &PduR_CanIfApi,
  },
};

static const PduR_PduType PduR_SrcPdu_CanIf_Com_CAN0_RX_MSG_ABS_INFO = {
  PDUR_MODULE_CANIF,
  CANIF_CAN0_RX_MSG_ABS_INFO,
  &PduR_CanIfApi,
};

static const PduR_PduType PduR_DstPdu_CanIf_Com_CAN0_RX_MSG_ABS_INFO[]={
  {
    PDUR_MODULE_COM,
    COM_CAN0_RX_MSG_ABS_INFO,
    &PduR_ComApi,
  },
};

static const PduR_RoutingPathType PduR_RoutingPaths[] = {
  { /* 0: PDU P2P_RX from CanTp to Dcm P2P_RX */
    &PduR_SrcPdu_CanTp_Dcm_P2P_RX,
    PduR_DstPdu_CanTp_Dcm_P2P_RX,
    ARRAY_SIZE(PduR_DstPdu_CanTp_Dcm_P2P_RX),
    NULL,
  },
  { /* 1: PDU P2A_RX from CanTp to Dcm P2A_RX */
    &PduR_SrcPdu_CanTp_Dcm_P2A_RX,
    PduR_DstPdu_CanTp_Dcm_P2A_RX,
    ARRAY_SIZE(PduR_DstPdu_CanTp_Dcm_P2A_RX),
    NULL,
  },
  { /* 2: PDU P2P_TX from Dcm to CanTp P2P_TX */
    &PduR_SrcPdu_Dcm_CanTp_P2P_TX,
    PduR_DstPdu_Dcm_CanTp_P2P_TX,
    ARRAY_SIZE(PduR_DstPdu_Dcm_CanTp_P2P_TX),
    NULL,
  },
  { /* 3: PDU P2A_TX from Dcm to CanTp P2A_TX */
    &PduR_SrcPdu_Dcm_CanTp_P2A_TX,
    PduR_DstPdu_Dcm_CanTp_P2A_TX,
    ARRAY_SIZE(PduR_DstPdu_Dcm_CanTp_P2A_TX),
    NULL,
  },
  { /* 4: PDU CAN0_TX_MSG_TIME from Com to CanIf CAN0_TX_MSG_TIME */
    &PduR_SrcPdu_Com_CanIf_CAN0_TX_MSG_TIME,
    PduR_DstPdu_Com_CanIf_CAN0_TX_MSG_TIME,
    ARRAY_SIZE(PduR_DstPdu_Com_CanIf_CAN0_TX_MSG_TIME),
    NULL,
  },
  { /* 5: PDU CAN0_RX_MSG_ABS_INFO from CanIf to Com CAN0_RX_MSG_ABS_INFO */
    &PduR_SrcPdu_CanIf_Com_CAN0_RX_MSG_ABS_INFO,
    PduR_DstPdu_CanIf_Com_CAN0_RX_MSG_ABS_INFO,
    ARRAY_SIZE(PduR_DstPdu_CanIf_Com_CAN0_RX_MSG_ABS_INFO),
    NULL,
  },
};

const PduR_ConfigType PduR_Config = {
#if defined(PDUR_USE_MEMPOOL)
  NULL,
#endif
  PduR_RoutingPaths,
  ARRAY_SIZE(PduR_RoutingPaths),
  PDUR_DCM_TX_BASE_ID,
  PDUR_DOIP_RX_BASE_ID,
  PDUR_DOIP_TX_BASE_ID,
  PDUR_CANTP_RX_BASE_ID,
  PDUR_CANTP_TX_BASE_ID,
  PDUR_LINTP_RX_BASE_ID,
  PDUR_LINTP_TX_BASE_ID,
};
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
