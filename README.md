🌱 Protótipo de Irrigação Automatizada Baseado em IoT para o Fortalecimento da Agricultura Familiar.
-----------------------------------------------------------------------------------------------------
-O projeto realiza:

-leitura de dados de umidade;
-envio de informações via MQTT;
-processamento no Node-RED;
-acionamento de um servo motor simulando uma válvula/bomba.
-----------------------------------------------------------------------------------------------------
📌 Tecnologias Utilizadas
ESP32
MQTT
Node-RED
HiveMQ Broker
DHT22
Servo Motor
OpenWeather API
Wokwi
-----------------------------------------------------------------------------------------------------
🧠 Funcionamento do Projeto
-O sistema funciona em 3 partes:

📡 Publisher ESP32
-Responsável por:
-ler os dados do sensor DHT22;
-enviar os dados para o broker MQTT.

🔄 Node-RED
-Responsável por:
-receber os dados MQTT;
-consultar a API OpenWeather;
-processar os dados;
-exibir as informações.

⚙️ Atuador ESP32
-Responsável por:
-receber comandos MQTT;
-controlar o servo motor;
-simular abertura e fechamento de uma válvula.
-----------------------------------------------------------------------------------------------------

🚀  Passos para replicar o projeto:

Para reproduzir este projeto corretamente, siga o passo a passo abaixo.

🌐 1️⃣ Criando a Conta no Wokwi

Primeiramente, acesse o simulador online Wokwi:<br>

-Wokwi Simulator

-Após acessar:
-Crie sua conta;
-Faça login na plataforma;
-Clique em:
-New Project
-Selecione a placa:
-ESP32 Arduino

📡 2️⃣ Montando o Circuito do Sensor
Após criar o projeto:
monte a estrutura exatamente igual à imagem disponível na pasta:
Imagens/Sensor.png
A estrutura utiliza:
ESP32
Sensor DHT22

💻 3️⃣ Adicionando o Código Fonte do Sensor
Após montar o circuito:
Abra o arquivo:
Código Fonte Sensor/Sensor.C++
Copie todo o conteúdo do arquivo;
Cole no editor principal do Wokwi;
Execute a simulação clicando em:
Start Simulation

📶 4️⃣ Funcionamento do Sensor
O ESP32 Publisher será responsável por:

conectar ao Wi-Fi;
conectar ao broker MQTT;
ler os dados do sensor DHT22;
publicar os dados MQTT no tópico:
sistemaAgricola/umidade

Os dados enviados possuem formato JSON:

{
  "umidade": 45.30
}

⚙️ 5️⃣ Configurando o Atuador
Crie um novo projeto ESP32 no Wokwi.
Depois:
monte o circuito conforme a imagem:
Imagens/Atuador.png
A estrutura utiliza:
ESP32
Servo Motor

🤖 6️⃣ Adicionando o Código Fonte do Atuador
Abra o arquivo:
Código Fonte Atuador/Atuador.C++
Copie todo o conteúdo e cole no editor do Wokwi.
Após isso:
execute a simulação;
o atuador ficará aguardando comandos MQTT.

🔄 7️⃣ Funcionamento do Atuador
O atuador escuta o tópico:
sitemaAgricola/bomba
Os comandos disponíveis são:
Comando	Função
ON	Abre válvula
OFF	Fecha válvula
O servo motor simula o acionamento da bomba/válvula automaticamente.

🌐 8️⃣ Configurando o Node-RED

Instale o Node-RED através do site oficial:

Node-RED Oficial

Após instalar:

Abra o Node-RED;
Clique no menu ☰;
Clique em:
Import
Selecione o arquivo:
Código Fonte Fluxo Node-red/Node-Red.json
Clique em:
Import
🧠 9️⃣ Funcionamento do Fluxo Node-RED

O fluxo realiza:

leitura dos dados MQTT;
consulta da API OpenWeather;
processamento das informações;
tomada de decisão inteligente;
acionamento automático do atuador;
armazenamento de dados no InfluxDB.
☁️ 🔐 Configuração da API OpenWeather

O projeto utiliza a API OpenWeather.

Site oficial:

OpenWeather API

No arquivo do Node-RED existe o campo:

APPID=SUA_API_KEY

Para utilizar corretamente:

Crie uma conta no OpenWeather;
Gere sua API Key;
Substitua:
SUA_API_KEY

pela sua chave pessoal.


🗄️ 🔐 Configuração do InfluxDB

O projeto utiliza o InfluxDB Cloud para armazenamento de dados.

Caso deseje utilizar:

Crie uma conta no InfluxDB;
Gere seu token;
Configure o token localmente no Node-RED.

🗄️ 🔐 Configuração do Grafana:
Crie uma conta no Grafana;
Conecte o seu banco de dados do InfluxDB;

Conectando o InfluxDB ao Grafana:

No Grafana:

Vá em:
Connections → Data Sources
Clique em:
Add Data Source
Selecione:
InfluxDB
Configure:
URL do InfluxDB;
Organization;
Bucket;
Token de acesso.

📈 Criando o Dashboard
Após conectar:
Clique em:
Create Dashboard
Adicione um novo painel;
Selecione os dados do bucket;

Crie gráficos para:
umidade;
temperatura;
status da bomba;
clima.



▶️ Executando o Projeto

Para executar o sistema completo:

Inicie o Publisher;
Inicie o Atuador;
Execute o fluxo no Node-RED;
Verifique os logs no Serial Monitor;
Observe o acionamento automático do servo motor.

🎥 Vídeo Demonstrativo
O vídeo demonstrativo do funcionamento encontra-se em:

https://youtu.be/JcLJaScRvEA


👨‍💻 Autores
Lucas Arenda Silveira - 10436971
Leonardo Buzzoni Jaime - 10443802
Universidade Presbiteriana Mackenzie
