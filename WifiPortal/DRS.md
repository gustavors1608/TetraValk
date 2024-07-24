# Documento de Requisitos do Software (DRS)

## 1. Introdução

### 1.1 Propósito
Este documento tem como objetivo descrever os requisitos do software da lib WifiPortal. Ele fornece uma visão detalhada das funcionalidades, restrições e especificações técnicas necessárias para o desenvolvimento da lib.

### 1.2 Escopo
O WifiPortal é destinado a possibilitar o usuario do sistema configurar a conexão wifi que seu device Iot irá se conectar bem como vincular o device ao user. Este documento abrange todos os requisitos funcionais e não funcionais necessários para a implementação do sistema.

### 1.3 Definições, Acrônimos e Abreviações
- **Lib**: biblioteca para o ESP32.
- **ESP32**: Um microcontrolador de baixo custo e baixo consumo de energia com Wi-Fi e Bluetooth integrado.

### 1.4 Referências
- [Readme do projeto principal](https://github.com/gustavors1608/TetraValk)

### 1.5 Visão Geral
Este documento está estruturado da seguinte forma:
1. Introdução
2. Descrição Geral
3. Requisitos Funcionais
4. Requisitos Não Funcionais
5. Restrições
6. Critérios de Aceitação

## 2. Descrição Geral

### 2.1 Perspectiva do Produto
O WifiPortal será desenvolvido para possibilitar a conexão wifi e atribuicao de usuario de maneira simples e intuitiva. Ele será utilizado por desenvolvedores de produtos iot que desejam facilitar o desenvolvimento de seus produtos com uma soluçao robusta, rápida e intuitiva para os usuarios terem pouca fricção ao usar e conectar o device iot na rede wifi.

### 2.2 Funções do Produto
O software oferecerá as seguintes funcionalidades principais:
- verificar conexão a internet
- abrir um captive portal e um AP (acess point) para pertitir o usuario buscar sua rede wifi e inserir ssid e senha da mesma.
- registrar esses dados de ssid e senha da rede em memoria flash ou eeprom.
- ir para modo configuração (captive portal e AP) ao apertar um botão (para trocar de rede wifi quando ja estive conectado, trocar de usuario etc)
- reconexão automática ao wifi já configurado.
- gerenciar conexao wifi de modo geral
- monitorar rssi
- gerar relatorios sobre a conexão
- possibilitar a relização de teste ping

### 2.3 Características do Usuário
Os usuários do sistema são categorizados em:
- **Desenvolvedores**: Terão acesso ao codigo e implementarão o mesmo em seus produtos e projetos.
- **Usuários**: Terão acesso a interface grafica somente e usarão o sistema feito pelos desenvolvedores.

### 2.4 Restrições
- O sistema deve ser compatível com o ESP32.
- O sistema deve ser capaz de ser operado em qualquer dispositivo movel

### 2.5 Suposições e Dependências
- Suponha que todos os usuários tenham acesso a uma conexão de internet estável.
- Memoria SPIFFS disponivel para armazenamento das credenciais e user.

## 3. Requisitos Funcionais

### 3.1 Módulo de Armazenamento de Dados
- **RF001**: O sistema deve permitir o armazenamento de dados no ESP32 utilizando SPIFFS.

### 3.2 Módulo de Gestão de Redes wifi
- **RF002**: O sistema deve ser capaz de realizar buscas de redes avaliando rssi das mesmas.
- **RF003**: O sistema deve ser capaz de disponiblizar um captive portal e acess point mostrando uma pagina com as redes e suas intensidades de maneira intuitiva.
- **RF004**: O sistema deve ser capaz se reconectar a uma rede caso perca o sinal ou esta muito fraco.
- **RF005**: Toda a lib deve ser personalizavel, podendo mudar facimente o estilo da pagina de configuração, nome da rede do Acess Point entre outros.
- **RF006**: A atribuição de usuario ao device deve ser opcional no memento de integraçao da lib, podendo assim o desenvolvedor optar por nao implementar esta funcionalidade.
- **RF007**: O sistema deve disponibilizar um meio de iniciar o modo configuraçõa atravez de um botao ou função especifica, chamado "on_demand()"
  

## 4. Requisitos Não Funcionais

### 4.1 Desempenho
- **RNF001**: O sistema deve abrir o portal de configuração em menos de 10 segundos, após o inicio do sistema pela primeira vez.

### 4.2 Usabilidade
- **RNF003**: A interface do usuário deve ser intuitiva e fácil de navegar para garantir uma experiência agradável.

## 5. Restrições
- **R001**: O sistema deve ser desenvolvido utilizando a linguagem de programação C++ e Arduino.

## 6. Critérios de Aceitação
- O sistema será considerado aceito quando:
  - Todos os requisitos funcionais e não funcionais forem implementados e testados com sucesso.
  - O sistema passar por testes de usabilidade e for aprovado por 5 usuários de teste.
