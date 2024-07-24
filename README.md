# TetraValk

![Versão](https://img.shields.io/badge/version-0.0.0-yellow) ![Status](https://img.shields.io/badge/Status-Project-brightgreen)

TetraValk é um projeto modular para soluções IoT, baseado em quatro pilares, com bibliotecas dedicadas para ESP32 e servidor:

- Conexão API: Envio e recepção de dados entre servidor e ESP32.
- Conexão a internet: Captive portal para conexão a internet e primeiro acesso do ESP#@ no server.
- Armazenamento de Dados: Banco de dados padronizado no servidor.
- Gestão de Usuários: Gestão de usuários e atribuição de dados.

Simplifique seu desenvolvimento IoT com TetraValk!

## Objetivos

- Desenvolver um projeto que posso servir para desenvolver de maneira padronizada produtos iot, onde atraves desse projeto seja possivel fazer grande parte do produto iot, composto por conexao ao servidor, armazenamento de dados, gestao de usuarios e conexão a internet.
- Ter baixa fricção no uso, possuindo comandos familiares e simplificados para o usuario (Desenvolvedor).
- Possuir um tamanho reduzido e boa performance.
- Ser seguro e estavel para uso em produção.

## Requisitos funcionais

**1. Conexão API**
- **tipo:** Servidor deve funcionar como MicroService e no Esp32 como lib

1.1. O sistema deve permitir o envio de dados do ESP32 para o servidor.
- **Descrição:** O ESP32 deve ser capaz de enviar dados para o servidor de forma padronizada ou seja possuindo o mesmo json idependende da aplicação.
- **Prioridade:** Alta

1.2. O sistema deve permitir a recepção de dados do servidor pelo ESP32.
- **Descrição:** O ESP32 deve ser capaz de receber comandos e sinais do servidor.
- **Prioridade:** Alta

**2. Conexão à Internet**
- **tipo:** Servidor deve funcionar como MicroService(atribuição de user/emai em um device) e no Esp32 como lib
  
2.1. O sistema deve oferecer um captive portal para conexão inicial à internet.
- **Descrição:** O ESP32 deve disponibilizar um captive portal para que o usuário possa configurar a conexão à internet na primeira utilização.
- **Prioridade:** Alta

2.2. O sistema deve permitir a configuração conta/username.
- **Descrição:** O usuário deve ser capaz de configurar um email para atrelar o device a sua conta .
- **Prioridade:** Média

**3. Armazenamento de Dados**
- **tipo:** Servidor deve funcionar como MicroService (sendo acessado inclusive pelos outros 3 serviços quando precisar armazenar dados de user, dados do esp32 etc).
  
3.1. O sistema deve utilizar um banco de dados padronizado no servidor.
- **Descrição:** Os dados enviados devem ser armazenados em um banco de dados relacional ou não relacional no servidor.
- **Prioridade:** Alta

**4. Gestão de Usuários**
- **tipo:** Servidor deve funcionar como MicroService.
  
4.1. O sistema deve permitir a criação e gerenciamento de usuários.
- **Descrição:** Deve ser possível criar, editar e excluir usuários no sistema bem como seu login.
- **Prioridade:** Alta

4.2. O sistema deve permitir a atribuição de dados específicos a usuários.
- **Descrição:** Os dados coletados devem ser atribuídos a usuários específicos, permitindo um controle especifico dos dados.
- **Prioridade:** Alta

**5. Segurança e Estabilidade**

5.1. O sistema deve implementar medidas de segurança para a comunicação entre o ESP32 e o servidor.
- **Descrição:** Deve-se utilizar protocolos seguros, como HTTPS, para garantir a integridade e confidencialidade dos dados transmitidos.
- **Prioridade:** Alta

5.2. O sistema deve garantir a estabilidade e robustez das bibliotecas desenvolvidas.
- **Descrição:** As bibliotecas devem ser testadas extensivamente para assegurar seu funcionamento estável em ambientes de produção.
- **Prioridade:** Alta

---

## Requisitos Não Funcionais

**Desempenho:**
- As operações de envio e recepção de dados devem ser executadas com baixa latência.
- O sistema deve ser otimizado para uso com memória e recursos limitados do ESP32.

**Usabilidade:**
- A interface do captive portal deve ser intuitiva e fácil de usar.
- A documentação das bibliotecas deve ser clara e acessível para desenvolvedores de diferentes níveis de experiência.

**Compatibilidade:**
- As bibliotecas devem ser compatíveis com diferentes versões do ESP32.
- O sistema deve ser compatível com os principais sistemas operacionais de servidores (Linux, Windows).

**Escalabilidade:**
- O sistema deve ser capaz de suportar um grande número de dispositivos ESP32 conectados simultaneamente.
- O banco de dados deve ser escalável para lidar com um volume crescente de dados.

**Manutenibilidade:**
- O código das bibliotecas deve ser modular e bem documentado para facilitar a manutenção e a atualização.

## Requisitos de Hardware e Software

### Hardware
- Esp32
    - memoria livre:
    - flash minima:
 
### Software
- Python
- FastApi
- MySql

## Análise de risco
#### 1. Riscos Técnicos

**1.1. Falhas de Conexão entre ESP32 e Servidor**
- **Descrição:** A instabilidade na conexão pode impedir a comunicação entre os dispositivos ESP32 e o servidor.
- **Mitigação:** Implementar mecanismos de reconexão automática e monitoramento contínuo da conexão. Utilizar protocolos robustos e testar em diferentes ambientes de rede.

**1.2. Segurança de Dados**
- **Descrição:** Riscos relacionados à interceptação de dados durante a transmissão.
- **Mitigação:** Implementar criptografia HTTPS/TLS para garantir a segurança dos dados transmitidos. Realizar auditorias de segurança periódicas.

**1.3. Incompatibilidade de Versões**
- **Descrição:** Atualizações de firmware ou software podem causar incompatibilidade entre o ESP32 e o servidor.
- **Mitigação:** Manter uma documentação detalhada das versões compatíveis e realizar testes extensivos de regressão antes de implementar atualizações.

#### 2. Riscos de Projeto

**2.1. Escopo Mal Definido**
- **Descrição:** Mudanças frequentes ou mal definidas no escopo podem causar atrasos e aumento de custos.
- **Mitigação:** Definir claramente os requisitos desde o início e estabelecer um processo de controle de mudanças rigoroso.

**2.2. Prazos Irrealistas**
- **Descrição:** Prazos apertados podem levar a compromissos na qualidade.
- **Mitigação:** Realizar uma estimativa realista do tempo necessário para cada fase do projeto e incluir margens de segurança.

#### 3. Riscos Operacionais

**3.1. Dependência de Terceiros**
- **Descrição:** Dependência de fornecedores ou serviços de terceiros pode causar atrasos.
- **Mitigação:** Identificar fornecedores alternativos e estabelecer contratos claros com penalidades por não conformidade.
  
#### 4. Riscos de Segurança

**4.1. Vulnerabilidades de Segurança**
- **Descrição:** Vulnerabilidades no código ou na infraestrutura podem ser exploradas por atacantes.
- **Mitigação:** Realizar revisões de segurança periódicas e implementar boas práticas de codificação segura.

**4.2. Gestão de Acessos**
- **Descrição:** A má gestão de acessos pode levar a acessos não autorizados.
- **Mitigação:** Implementar controles de acesso rigorosos e revisar regularmente as permissões de acesso.

---


## Etapas do projeto
- [X] Estabelecer os principais objetivos do TetraValk.
- [X] Requisitos funcionais: Definir as funcionalidades principais de cada biblioteca.
- [X] Requisitos não funcionais: Desempenho, escalabilidade, segurança, usabilidade.
- [X] Requisitos de hardware e software: Especificar o hardware (ESP32) e as tecnologias a serem usadas (FastAPI, bancos de dados, etc.).
- [X] Análise de risco: Identificar possíveis riscos e planejar mitigação.
- [ ] Documento de Requisitos do Software (DRS).
- [ ] Especificação de Caso de Uso.
- [ ] Arquitetura do Sistema
- [ ] Definir a arquitetura do sistema (cliente-servidor).
- [ ] Diagramas de arquitetura (UML).
- [ ] Detalhamento dos componentes de cada pilar (biblioteca) do projeto.
- [ ] Diagramas de sequência, diagramas de classes, diagramas de componentes.
- [ ] Definição dos endpoints da API.
- [ ] Especificação de formatos de dados e autenticação.
- [ ] Configuração do Ambiente de Desenvolvimento e padronização.
- [ ] Setup de ambientes de desenvolvimento para ESP32 e servidor.
- [ ] Desenvolvimento das Bibliotecas
- [ ] Testes unitários para cada biblioteca.
