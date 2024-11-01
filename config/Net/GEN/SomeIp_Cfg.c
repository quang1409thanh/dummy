/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "SomeIp.h"
#include "SomeIp_Cfg.h"
#include "SomeIp_Priv.h"
#include "SoAd_Cfg.h"
#include "Sd_Cfg.h"
#include "SS_server0.h"
#include "CS_client0.h"
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
/* ================================ [ DATAS     ] ============================================== */
static const SomeIp_ServerMethodType someIpServerMethods_server0[] = {
  {
    0x421, /* Method ID */
    0, /* interface version */
    SomeIp_server0_method1_OnRequest,
    SomeIp_server0_method1_OnFireForgot,
    SomeIp_server0_method1_OnAsyncRequest,
    SomeIp_server0_method1_OnTpCopyRxData,
    SomeIp_server0_method1_OnTpCopyTxData,
    1396 /* resMaxLen */
  },
};

static const SomeIp_ServerEventType someIpServerEvents_server0[] = {
  {
    SD_EVENT_HANDLER_SERVER_0_EVENT_GROUP_1, /* SD EventGroup Handle ID */
    0xbeef, /* Event ID */
    0, /* interface version */
    SomeIp_server0_event_group1_event0_OnTpCopyTxData,
  },
};

static const SomeIp_ClientMethodType someIpClientMethods_client0[] = {
  {
    0x424, /* Method ID */
    0, /* interface version */
    SomeIp_client0_method2_OnResponse,
    SomeIp_client0_method2_OnError,
    SomeIp_client0_method2_OnTpCopyRxData,
    SomeIp_client0_method2_OnTpCopyTxData,
  },
};

static const SomeIp_ClientEventType someIpClientEvents_client0[] = {
  {
    0xabcd, /* Event ID */
    0, /* interface version */
    SomeIp_client0_event_group2_event0_OnNotification,
    SomeIp_client0_event_group2_event0_OnTpCopyRxData,
  },
};

static SomeIp_ServerContextType someIpServerContext_server0;

static SomeIp_ServerConnectionContextType someIpServerConnectionContext_server0[1];

static const SomeIp_ServerConnectionType someIpServerServiceConnections_server0[1] = {
  {
    &someIpServerConnectionContext_server0[0],
    SOAD_TX_PID_SOMEIP_SERVER_0,
    SOAD_SOCKID_SOMEIP_SERVER_0,
    NULL
  },
};

static const SomeIp_ServerServiceType someIpServerService_server0 = {
  0x1234, /* serviceId */
  0x4444, /* clientId */
  someIpServerMethods_server0,
  ARRAY_SIZE(someIpServerMethods_server0),
  someIpServerEvents_server0,
  ARRAY_SIZE(someIpServerEvents_server0),
  someIpServerServiceConnections_server0,
  ARRAY_SIZE(someIpServerServiceConnections_server0),
  TCPIP_IPPROTO_UDP,
  &someIpServerContext_server0,
  SOMEIP_CONVERT_MS_TO_MAIN_CYCLES(10),
  SomeIp_server0_OnConnect,
};

static SomeIp_ClientServiceContextType someIpClientServiceContext_client0;
static const SomeIp_ClientServiceType someIpClientService_client0 = {
  0xabcd, /* serviceId */
  0x5555, /* clientId */
  SD_CLIENT_SERVICE_HANDLE_ID_CLIENT_0, /* sdHandleID */
  someIpClientMethods_client0,
  ARRAY_SIZE(someIpClientMethods_client0),
  someIpClientEvents_client0,
  ARRAY_SIZE(someIpClientEvents_client0),
  &someIpClientServiceContext_client0,
  SOAD_TX_PID_SOMEIP_CLIENT_0,
  SomeIp_client0_OnAvailability,
  NULL,
  SOMEIP_CONVERT_MS_TO_MAIN_CYCLES(10),
  SOMEIP_CONVERT_MS_TO_MAIN_CYCLES(1000),
};

static const SomeIp_ServiceType SomeIp_Services[] = {
  {
    TRUE,
    SOAD_SOCKID_SOMEIP_SERVER_0,
    &someIpServerService_server0,
  },
  {
    FALSE,
    SOAD_SOCKID_SOMEIP_CLIENT_0,
    &someIpClientService_client0,
  },
};

static const uint16_t Sd_PID2ServiceMap[] = {
  SOMEIP_SSID_SERVER_0,
  SOMEIP_CSID_CLIENT_0,
};

static const uint16_t Sd_PID2ServiceConnectionMap[] = {
  0,
  0,
};

static const uint16_t Sd_TxMethod2ServiceMap[] = {
  SOMEIP_CSID_CLIENT_0,/* method2 */
  -1
};

static const uint16_t Sd_TxMethod2PerServiceMap[] = {
  0, /* method2 */
  -1
};

static const uint16_t Sd_TxEvent2ServiceMap[] = {
  SOMEIP_SSID_SERVER_0, /* event_group1 event0 */
  -1
};

static const uint16_t Sd_TxEvent2PerServiceMap[] = {
  0, /* event_group1 event0 */
  -1
};

const SomeIp_ConfigType SomeIp_Config = {
  SOMEIP_CONVERT_MS_TO_MAIN_CYCLES(200),
  SomeIp_Services,
  ARRAY_SIZE(SomeIp_Services),
  Sd_PID2ServiceMap,
  Sd_PID2ServiceConnectionMap,
  ARRAY_SIZE(Sd_PID2ServiceMap),
  Sd_TxMethod2ServiceMap,
  Sd_TxMethod2PerServiceMap,
  ARRAY_SIZE(Sd_TxMethod2ServiceMap)-1,
  Sd_TxEvent2ServiceMap,
  Sd_TxEvent2PerServiceMap,
  ARRAY_SIZE(Sd_TxEvent2ServiceMap)-1,
};

/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
