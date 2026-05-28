#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32Servo.h> 

char SSIDName[] = "Wokwi-GUEST";
char SSIDPass[] = "";

char BrokerURL[] = "broker.hivemq.com";

char MQTTClientName[] = "subscriber-TESTE2026-SERVO"; 
int BrokerPort = 1883;


char Topico_Bomba[] = "sistemaAgricola/bomba";


const int PIN_SERVO = 18; 
Servo meuServo;

WiFiClient espClient;
PubSubClient clienteMQTT(espClient);


void callback(char* topic, byte* payload, unsigned int length) {
  String comando = "";
  for (int i = 0; i < length; i++) {
    comando += (char)payload[i];
  }
  
  Serial.print("Comando recebido para a Válvula: ");
  Serial.println(comando);

  
  if (comando == "ON") {
    meuServo.write(90);
    Serial.println(">>> ATUADOR: Válvula ABERTA (90°) <<<");
  } else if (comando == "OFF") {
    meuServo.write(0);  
    Serial.println(">>> ATUADOR: Válvula FECHADA (0°) <<<");
  }
}

void mqttReconnect() {
  while (!clienteMQTT.connected()) {
    Serial.println("Conectando Atuador ao Broker...");
    if (clienteMQTT.connect(MQTTClientName)) {
      Serial.println("Atuador pronto e conectado!");
      clienteMQTT.subscribe(Topico_Bomba);
    } else {
      Serial.print("Falha. Status: ");
      Serial.print(clienteMQTT.state());
      Serial.println(" Retentando em 5 segundos...");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(9600);
  
  
  meuServo.attach(PIN_SERVO, 500, 2400);
  meuServo.write(0); 

  WiFi.begin(SSIDName, SSIDPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nWiFi do Atuador Conectado com sucesso!");

  clienteMQTT.setServer(BrokerURL, BrokerPort);
  clienteMQTT.setCallback(callback);
}

void loop() {
  if (!clienteMQTT.connected()) {
    mqttReconnect();
  }
  clienteMQTT.loop();
  delay(200);
}