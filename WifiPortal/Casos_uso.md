Claro! Aqui estão os casos de uso atualizados e os novos casos de uso adicionais:

### Caso de Uso 1: Configuração Inicial de Conexão Wi-Fi

**Título:** Configuração Inicial de Conexão Wi-Fi

**Ator Principal:** Usuário

**Atores Secundários:** Desenvolvedor

**Descrição:** Este caso de uso descreve como um usuário configura a conexão Wi-Fi inicial de seu dispositivo IoT usando o WifiPortal.

**Pré-condições:**
- O dispositivo IoT está ligado.
- O dispositivo IoT não está conectado a nenhuma rede Wi-Fi.

**Pós-condições:**
- O dispositivo IoT está conectado à rede Wi-Fi configurada pelo usuário.
- O dispositivo IoT está vinculado à conta de e-mail do usuário.

**Fluxo Principal:**
1. O usuário liga o dispositivo IoT.
2. O dispositivo IoT inicia o WifiPortal e abre um captive portal e um Access Point.
3. O usuário conecta seu dispositivo móvel ao Access Point criado pelo dispositivo IoT.
4. O usuário é redirecionado para a página de configuração do WifiPortal.
5. O usuário insere seu e-mail de conta para vincular o dispositivo.
6. O usuário seleciona a rede Wi-Fi desejada e insere o SSID e a senha da rede.
7. O WifiPortal armazena as credenciais da rede em memória SPIFFS.
8. O dispositivo IoT tenta conectar à rede Wi-Fi configurada.
9. O dispositivo IoT confirma a conexão bem-sucedida e notifica o usuário.

**Fluxo Alternativo:**
- **Fluxo Alternativo 1:** Se o dispositivo IoT não conseguir se conectar à rede Wi-Fi configurada, ele retorna ao passo 2 e solicita ao usuário que tente novamente.

### Caso de Uso 2: Mudança de Rede Wi-Fi

**Título:** Mudança de Rede Wi-Fi

**Ator Principal:** Usuário

**Atores Secundários:** Desenvolvedor

**Descrição:** Este caso de uso descreve como um usuário muda a rede Wi-Fi à qual o dispositivo IoT está conectado usando o WifiPortal.

**Pré-condições:**
- O dispositivo IoT está conectado a uma rede Wi-Fi existente.
- O usuário deseja mudar para uma nova rede Wi-Fi.

**Pós-condições:**
- O dispositivo IoT está conectado à nova rede Wi-Fi configurada pelo usuário.

**Fluxo Principal:**
1. O usuário pressiona o botão físico no dispositivo IoT para entrar no modo de configuração.
2. O dispositivo IoT apaga os dados de SSID e senha armazenados.
3. O dispositivo IoT inicia o WifiPortal e abre um captive portal e um Access Point.
4. O usuário conecta seu dispositivo móvel ao Access Point criado pelo dispositivo IoT.
5. O usuário é redirecionado para a página de configuração do WifiPortal.
6. O usuário insere seu e-mail de conta para vincular o dispositivo.
7. O usuário seleciona a nova rede Wi-Fi desejada e insere o SSID e a senha da nova rede.
8. O WifiPortal armazena as novas credenciais da rede em memória SPIFFS.
9. O dispositivo IoT tenta conectar à nova rede Wi-Fi configurada.
10. O dispositivo IoT confirma a conexão bem-sucedida e notifica o usuário.

**Fluxo Alternativo:**
- **Fluxo Alternativo 1:** Se o dispositivo IoT não conseguir se conectar à nova rede Wi-Fi configurada, ele retorna ao passo 2 e solicita ao usuário que tente novamente.

### Caso de Uso 3: Reconexão Automática à Rede Wi-Fi

**Título:** Reconexão Automática à Rede Wi-Fi

**Ator Principal:** Dispositivo IoT

**Atores Secundários:** Usuário, Desenvolvedor

**Descrição:** Este caso de uso descreve como o dispositivo IoT usa o WifiPortal para reconectar automaticamente à rede Wi-Fi configurada após uma perda de conexão.

**Pré-condições:**
- O dispositivo IoT está configurado com credenciais válidas de uma rede Wi-Fi.
- O dispositivo IoT perdeu a conexão com a rede Wi-Fi.

**Pós-condições:**
- O dispositivo IoT está reconectado à rede Wi-Fi configurada.

**Fluxo Principal:**
1. O dispositivo IoT detecta que a conexão Wi-Fi foi perdida.
2. O dispositivo IoT usa o WifiPortal para tentar reconectar à rede Wi-Fi configurada.
3. O dispositivo IoT verifica a intensidade do sinal (RSSI) e a disponibilidade da rede.
4. O dispositivo IoT tenta reconectar usando as credenciais armazenadas em memória SPIFFS.
5. O dispositivo IoT confirma a reconexão bem-sucedida.

**Fluxo Alternativo:**
- **Fluxo Alternativo 1:** Se o dispositivo IoT não conseguir se reconectar à rede Wi-Fi, ele continua tentando periodicamente até que a reconexão seja bem-sucedida ou até que um usuário intervenha para reconfigurar a rede.

### Caso de Uso 4: Monitoramento da Intensidade do Sinal Wi-Fi (RSSI)

**Título:** Monitoramento da Intensidade do Sinal Wi-Fi (RSSI)

**Ator Principal:** Desenvolvedor

**Atores Secundários:** Usuário

**Descrição:** Este caso de uso descreve como o desenvolvedor pode usar o WifiPortal para monitorar a intensidade do sinal Wi-Fi (RSSI) do dispositivo IoT.

**Pré-condições:**
- O dispositivo IoT está conectado a uma rede Wi-Fi.

**Pós-condições:**
- O desenvolvedor tem acesso aos dados de intensidade do sinal (RSSI) do dispositivo IoT.

**Fluxo Principal:**
1. O dispositivo IoT está conectado à rede Wi-Fi.
2. O WifiPortal monitora a intensidade do sinal (RSSI) periodicamente.
3. Os dados de RSSI são armazenados em memória SPIFFS e disponibilizados através da serial do ESP32 e/ou API, dependendo de uma intervenção do desenvolvedor para a implementação.
4. O desenvolvedor pode acessar os dados de RSSI para análise e ajuste da posição do dispositivo IoT.

**Fluxo Alternativo:**
- **Fluxo Alternativo 1:** Se a intensidade do sinal (RSSI) cair abaixo de um determinado limiar, o dispositivo IoT pode notificar o desenvolvedor.
