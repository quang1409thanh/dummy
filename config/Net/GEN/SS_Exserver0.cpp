/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "usomeip/usomeip.hpp"
#include "usomeip/server.hpp"
extern "C" {
#include "SS_server0.h"
#include "SomeIp_Cfg.h"
#include "Sd_Cfg.h"
}
#include "plugin.h"
#include "Std_Timer.h"
using namespace as;
using namespace as::usomeip;
/* ================================ [ MACROS    ] ============================================== */
/* ================================ [ TYPES     ] ============================================== */
/* ================================ [ DECLARES  ] ============================================== */
class SS_server0;
/* ================================ [ DATAS     ] ============================================== */
static std::shared_ptr<SS_server0> SS_Instance = nullptr;
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
class SS_server0: public server::Server {
public:
  SS_server0() {
  }
  ~SS_server0() {
  }
  void start() {
    identity(SOMEIP_SSID_SERVER_0);
    offer(SD_SERVER_SERVICE_HANDLE_ID_SERVER_0);
    m_BufferPool.create("SS_server0", 5, 1024 * 1024);
    listen(SOMEIP_RX_METHOD_SERVER_0_METHOD_1, &m_BufferPool);
    provide(SD_EVENT_HANDLER_SERVER_0_EVENT_GROUP_1);
    // Std_TimerStart(&m_Timer);
  }

  void stop() {
    Std_TimerStop(&m_Timer);
  }

  void onRequest(std::shared_ptr<Message> msg) {
    usLOG(INFO, "server0: on request: %s\n", msg->str().c_str());
    msg->reply(E_OK, msg->payload);
  }

  void onFireForgot(std::shared_ptr<Message> msg) {
    usLOG(INFO, "server0: on fire forgot: %s\n", msg->str().c_str());
  }

  void onError(std::shared_ptr<Message> msg) {
  }

  void onSubscribe(uint16_t eventGroupId, bool isSubscribe) {
    usLOG(INFO, "server0: event group %d %s\n", eventGroupId, isSubscribe ? "subscribed" : "unsubscribed");
  }

  void run() {
    if (Std_GetTimerElapsedTime(&m_Timer) >= 1000000) {
      // Std_TimerStart(&m_Timer);
      uint32_t requestId =
        ((uint32_t)SOMEIP_TX_EVT_SERVER_0_EVENT_GROUP_1_EVENT_0 << 16) + (++m_SessionId);
      auto buffer = m_BufferPool.get();
      if (nullptr != buffer) {
        buffer->size = 8000;
        uint8_t *data = (uint8_t *)buffer->data;
        for (size_t i = 0; i < buffer->size; i++) {
          data[i] = m_SessionId + i;
        }
        notify(requestId, buffer);
      }
    }
  }

private:
  Std_TimerType m_Timer;
  BufferPool m_BufferPool;
  uint16_t m_SessionId = 0;
};

void SS_Exserver0_init(void) {
  SS_Instance = std::make_shared<SS_server0>();
  SS_Instance->start();
}

void SS_Exserver0_main(void) {
  SS_Instance->run();
}

void SS_Exserver0_deinit(void) {
  SS_Instance->stop();
}

REGISTER_PLUGIN(SS_Exserver0);
