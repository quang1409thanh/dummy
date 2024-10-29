/**
 * SSAS - Simple Smart Automotive Software
 * Copyright (C) 2021-2024 Parai Wang <parai@foxmail.com>
 *
 * Generated at Tue Oct 29 15:59:27 2024
 */
/* ================================ [ INCLUDES  ] ============================================== */
#include "usomeip/usomeip.hpp"
#include "usomeip/client.hpp"
extern "C" {
#include "CS_client0.h"
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
class CS_client0;
/* ================================ [ DATAS     ] ============================================== */
static std::shared_ptr<CS_client0> CS_Instance = nullptr;
/* ================================ [ LOCALS    ] ============================================== */
/* ================================ [ FUNCTIONS ] ============================================== */
class CS_client0 : public client::Client {
public:
  CS_client0() {
  }

  ~CS_client0() {
  }

  void start() {
    identity(SOMEIP_CSID_CLIENT_0);
    require(SD_CLIENT_SERVICE_HANDLE_ID_CLIENT_0);
    m_BufferPool.create("CS_client0", 5, 1024 * 1024);
    bind(SOMEIP_TX_METHOD_CLIENT_0_METHOD_2, &m_BufferPool);
    subscribe(SD_CONSUMED_EVENT_GROUP_CLIENT_0_EVENT_GROUP_2);
    listen(SOMEIP_RX_EVT_CLIENT_0_EVENT_GROUP_2_EVENT_0, &m_BufferPool);
    // Std_TimerStart(&m_Timer);
  }

  void stop() {
    Std_TimerStop(&m_Timer);
  }

  void onResponse(std::shared_ptr<Message> msg) {
    usLOG(INFO, "client0: on response: %s\n", msg->str().c_str());
  }

  void onNotification(std::shared_ptr<Message> msg) {
    usLOG(INFO, "client0: on notification: %s\n", msg->str().c_str());
  }

  void onError(std::shared_ptr<Message> msg) {
    usLOG(INFO, "client0: on error: %s\n", msg->str().c_str());
  }

  void onAvailability(bool isAvailable) {
    usLOG(INFO, "client0: %s\n", isAvailable?"online":"offline");
  }

  void run() {
    if (Std_GetTimerElapsedTime(&m_Timer) >= 1000000) {
      // Std_TimerStart(&m_Timer);
      uint32_t requestId =
        ((uint32_t)SOMEIP_TX_METHOD_CLIENT_0_METHOD_2 << 16) + (++m_SessionId);
      auto buffer = m_BufferPool.get();
      if (nullptr != buffer) {
        buffer->size = 5000;
        uint8_t *data = (uint8_t *)buffer->data;
        for (size_t i = 0; i < buffer->size; i++) {
          data[i] = m_SessionId + i;
        }
        request(requestId, buffer);
      }
    }
  }

private:
  Std_TimerType m_Timer;
  BufferPool m_BufferPool;
  uint16_t m_SessionId = 0;
};

void CS_client0_init(void) {
  CS_Instance = std::make_shared<CS_client0>();
  CS_Instance->start();
}

void CS_client0_main(void) {
  CS_Instance->run();
}

void CS_client0_deinit(void) {
  CS_Instance->stop();
}

REGISTER_PLUGIN(CS_client0);
