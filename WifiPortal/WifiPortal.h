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
#define PARAM_INPUT_3 "e"
#define ssidPath "/ssid.txt"
#define passPath "/pass.txt"
#define userPath "/user.txt"
#define reconectPath "/recon.txt"
#define html_home "/index.html"
#define timeout_conection_limit 5000 // Tempo máximo para conectar ao WiFi como STATION
#define get_email_user false

class WifiPortal {
    private:
        String criar_div_wifi(const char* nome_wifi, uint8_t potencia_porcentagem, const char* potencia_simbolo, uint8_t id, int16_t rssi);
        String criar_pagina_wifi(String divs_wifi);
        String criar_pagina_user();
        void config_server_ap();
        void abrir_portal();
        uint8_t converter_rssi_porcentagem(int16_t rssi);
        void montar_captive_wifi();
        bool connect_wifi_sta();
        byte scan_wifis();
        byte vrf_counter_reconect();
        void increment_counter_reconect();

        uint16_t time_ms_callback_config = 300;
        void (*_callback)(void) = nullptr;

    public:
        WifiPortal(); 
        ~WifiPortal();
        void connect();
        void reset_data();
        void set_config_callback(void (*name_callback)(void), uint16_t ms_interval_call = 100);
        bool vrf_conexao();
        #if get_email_user ==true
            String get_email();
        #endif
};

#endif // WIFIPORTAL_H
