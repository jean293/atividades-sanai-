#include <Arduino.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "temporizador.h"

const char *mqtt_server = "broker.hivemq.com";                 //* endereco do mqtt/servidor
const int mqtt_port = 1883;                                    //* porta que estamos usando para se comunicar
const char *mqtt_client_id = "esp32_jean";                  //* nome do dispositivo, no caso do esp
const char *mqtt_topic_sub = "senai134/mesa07/jean/espsub"; //*dispositivo que se inscreve
const char *mqtt_topic_pub = "senai134/mesa07/jean/esppub"; //*dispositivo que manda a mensagem


void callback(char *, byte *, unsigned int); //*funcao que vai ser executada quando uma mensagem for enviada no topico que for escrita
void conectaMQTT(void);                      //* funcao que garante que esta conectada, que esta funcionando

WiFiClient espClient;
PubSubClient client(espClient); //* vai fazer conexao com o broker

void setup() 
{
    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
}

void loop() 
{


}


void conectaMQTT()
{
    while (!client.connected())
    {
        Serial.print("Conectando ao MQTT...");
        if (client.connect(mqtt_client_id))
        {
            Serial.println("Conectado!");
            client.subscribe(mqtt_topic_sub);
        }

        else
        {
            Serial.print("Falha, rc= ");
            Serial.print(client.state());
            Serial.println(" tentando novamente em 5 seg");
            delay(5000);
        }
    }
}