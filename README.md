🌱 Protótipo de Irrigação Automatizada Baseado em IoT para o Fortalecimento da Agricultura Familiar.
-----------------------------------------------------------------------------------------------------
- O projeto realiza:

- leitura de dados de umidade;
- envio de informações via MQTT;
- processamento no Node-RED;
- acionamento de um servo motor simulando uma válvula/bomba.<br>
-----------------------------------------------------------------------------------------------------
📌 Tecnologias Utilizadas:<br>
- ESP32
- MQTT
- Node-RED
- HiveMQ Broker
- DHT22
- Servo Motor
- OpenWeather API
- Wokwi<br>
-----------------------------------------------------------------------------------------------------
🧠 Funcionamento do Projeto<br>
- O sistema funciona em 3 partes:

📡 Publisher ESP32<br>
- Responsável por:
- ler os dados do sensor DHT22;
- enviar os dados para o broker MQTT.

🔄 Node-RED<br>
- Responsável por:
- receber os dados MQTT;
- consultar a API OpenWeather;
- processar os dados;
- exibir as informações.

⚙️ Atuador ESP32<br>
- Responsável por:
- receber comandos MQTT;
- controlar o servo motor;
- simular abertura e fechamento de uma válvula.<br>
-----------------------------------------------------------------------------------------------------

🚀  Passos para replicar o projeto:<br>

Para reproduzir este projeto corretamente, siga o passo a passo abaixo.<br>

🌐 1️⃣ Criando a Conta no Wokwi<br>

Primeiramente, acesse o simulador online Wokwi:<br>

Wokwi Simulator<br>

Após acessar:<br>
- Crie sua conta;
- Faça login na plataforma;
- Clique em:
- New Project
- Selecione a placa:
- ESP32 Arduino<br>

📡 2️⃣ Montando o Circuito do Sensor<br>

Após criar o projeto:<br>

- monte a estrutura exatamente igual à imagem disponível na pasta:
- Imagens/Sensor.png
- A estrutura utiliza:
- ESP32
- Sensor DHT22<br>

💻 3️⃣ Adicionando o Código Fonte do Sensor<br>
Após montar o circuito:<br>
- Abra o arquivo:
- Código Fonte Sensor/Sensor.C++
- Copie todo o conteúdo do arquivo;
- Cole no editor principal do Wokwi;
- Execute a simulação clicando em:
- Start Simulation<br>

📶 4️⃣ Funcionamento do Sensor<br>
O ESP32 Publisher será responsável por:<br>

- conectar ao Wi-Fi;
- conectar ao broker MQTT;
- ler os dados do sensor DHT22;
- publicar os dados MQTT no tópico:
- sistemaAgricola/umidade<br>

Os dados enviados possuem formato JSON:<br>

{<br>
  "umidade": 45.30<br>
}<br>
⚙️ 5️⃣ Configurando o Atuador<br>
Crie um novo projeto ESP32 no Wokwi.<br>
Depois:<br>
- monte o circuito conforme a imagem:
- Imagens/Atuador.png
- A estrutura utiliza:
- ESP32
- Servo Motor<br>

🤖 6️⃣ Adicionando o Código Fonte do Atuador<br>
Abra o arquivo:<br>
- Código Fonte Atuador/Atuador.C++
- Copie todo o conteúdo e cole no editor do Wokwi.
- Após isso:
- execute a simulação;
- o atuador ficará aguardando comandos MQTT.<br>

🔄 7️⃣ Funcionamento do Atuador<br>
- O atuador escuta o tópico:
- sitemaAgricola/bomba
- Os comandos disponíveis são:
- Comando	Função
- ON	Abre válvula
- OFF	Fecha válvula
- O servo motor simula o acionamento da bomba/válvula automaticamente.<br>

🌐 8️⃣ Configurando o Node-RED<br>

Instale o Node-RED através do site oficial:<br>

- Node-RED Oficial

Após instalar:<br>

- Abra o Node-RED;
- Clique no menu ☰;
- Clique em:
- Import
- Selecione o arquivo:
- Código Fonte Fluxo Node-red/Node-Red.json
- Clique em:
- Import
  <br>
🧠 9️⃣ Funcionamento do Fluxo Node-RED<br>

O fluxo realiza:<br>

- leitura dos dados MQTT;
- consulta da API OpenWeather;
- processamento das informações;
- tomada de decisão inteligente;
- acionamento automático do atuador;
- armazenamento de dados no InfluxDB.<br>

☁️ 🔐 Configuração da API OpenWeather<br>

O projeto utiliza a API OpenWeather.<br>

Site oficial:<br>

OpenWeather API<br>

No arquivo do Node-RED existe o campo:<br>

- APPID=SUA_API_KEY

Para utilizar corretamente:<br>

- Crie uma conta no OpenWeather;
- Gere sua API Key;
- Substitua:
- SUA_API_KEY, pela sua chave pessoal.<br>


🗄️ 🔐 Configuração do InfluxDB<br>

O projeto utiliza o InfluxDB para armazenamento de dados.<br>

Caso deseje utilizar:<br>

- Crie uma conta no InfluxDB;
- Gere seu token;
- Configure o token localmente no nó do Node-RED.<br>

🗄️ 🔐 Configuração do Grafana:<br>
- Crie uma conta no Grafana;
- Conecte o seu banco de dados do InfluxDB;<br>

Conectando o InfluxDB ao Grafana:<br>

No Grafana:<br>

Vá em:<br>
- Connections → Data Sources
- Clique em:
- Add Data Source
- Selecione:
- InfluxDB
- Configure:
- URL do InfluxDB;
- Organization;
- Bucket;
- Token de acesso.<br>

📈 Criando o Dashboard<br>
Após conectar:<br>
Clique em:
- Create Dashboard
- Adicione um novo painel;
- Selecione os dados do bucket;<br>

Crie gráficos para:<br>
- umidade;
- temperatura;
- status da bomba;
- clima.<br>



▶️ Executando o Projeto<br>

Para executar o sistema completo:<br>

- Inicie o Publisher;
- Inicie o Atuador;
- Execute o fluxo no Node-RED;
- Verifique os logs no Serial Monitor;
- Observe o acionamento automático do servo motor.

🎥 Vídeo Demonstrativo<br>
O vídeo demonstrativo do funcionamento encontra-se em:<br>

https://youtu.be/JcLJaScRvEA<br>


👨‍💻 Autores<br>
- Lucas Arenda Silveira - 10436971
- Leonardo Buzzoni Jaime - 10443802<br>
Universidade Presbiteriana Mackenzie
