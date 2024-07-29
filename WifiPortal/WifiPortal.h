#ifndef WIFIPORTAL_H
#define WIFIPORTAL_H

#include "Arduino.h"
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>
#include <DNSServer.h>
#include "site.h"

// Definições de parâmetros e caminhos
#define porcentagem_minima_sinal 15 // Sinal mínimo em porcentagem para aparecer na pesquisa de WiFis
#define PARAM_INPUT_1 "ssid"
#define PARAM_INPUT_2 "pass"
#define PARAM_INPUT_3 "user"
#define ssidPath "/ssid.txt"
#define passPath "/pass.txt"
#define userPath "/user.txt"
#define html_home "/captive_page.html"
#define html_user "/captive_user.html"
#define NOME_REDE_AP "WifiPortal ESP32"
#define timeout_conection_limit 5000 // Tempo máximo para conectar ao WiFi como STATION
#define timeout_reconect 10000 // Tempo de reconexão
#define get_email_user true

class WifiPortal {
    private:
        String criar_div_wifi(const char* nome_wifi, uint8_t potencia_porcentagem, const char* potencia_simbolo);
        String criar_pagina_wifi(String divs_wifi);
        String criar_pagina_user();
        void config_server_ap();
        void abrir_portal();
        uint8_t converter_rssi_porcentagem(int16_t rssi);
        void montar_captive_wifi();
        bool connect_wifi_sta(bool forcar_reconexao);
        byte scan_wifis();

        uint16_t time_ms_callback_config = 300;
        void (*_callback)(void) = nullptr;

    public:
        WifiPortal(); 
        ~WifiPortal();
        bool connect();
        void reset_data();
        void set_config_callback(void (*name_callback)(void), uint16_t ms_interval_call = 100);
        bool vrf_conexao();
};

#endif // WIFIPORTAL_H
