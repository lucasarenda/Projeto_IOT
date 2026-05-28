#include <WiFi.h>
#include <PubSubClient.h>
#include <DHTesp.h>

char SSIDName[] = "Wokwi-GUEST";
char SSIDPass[] = "";

char BrokerURL[] = "broker.hivemq.com";
char MQTTClientName[] = "publisher-TESTE2026-Sensor";
int BrokerPort = 1883;

char Topico_Umidade[] = "sistemaAgricula/umidade";

WiFiClient espClient;
PubSubClient clienteMQTT(espClient);
DHTesp dhtSensor;

const int DHT_PIN = 15;

void mqttReconnect() {
  while (!clienteMQTT.connected()) {
    Serial.println("Conectando ao MQTT...");

    if (clienteMQTT.connect(MQTTClientName)) {
      Serial.println("Conectado com sucesso ao Broker MQTT!");
    } else {
      Serial.print("Falha na conexão. Status erro: ");
      Serial.print(clienteMQTT.state());
      Serial.println(" tente novamente em 5 segundos...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);

  WiFi.begin(SSIDName, SSIDPass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");

  clienteMQTT.setServer(BrokerURL, BrokerPort);

  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);
}

void loop() {

  if (!clienteMQTT.connected()) {
    mqttReconnect();
  }

  clienteMQTT.loop();

  TempAndHumidity dados = dhtSensor.getTempAndHumidity();


  char mensagem[50];

  sprintf(
    mensagem,
    "{\"umidade\": %.2f}",
    dados.humidity
  );

  clienteMQTT.publish(Topico_Umidade, mensagem);

  Serial.print("JSON enviado para o MQTT: ");
  Serial.println(mensagem);

  delay(5000);
}