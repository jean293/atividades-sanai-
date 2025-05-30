#include "led.h"
/**
 * @return void
 * @brief liga o led
 */
led::led(int pin)
{
    pino = pin;
    estadoLed = false;
    pinMode(pino, OUTPUT);
    digitalWrite(pino, LOW);
}
void led::ligar()
{
    estadoLed = true;
    modoPiscar = false;
    digitalWrite(pino, HIGH);

}

/**
 * @brief desligar Led
 */
void led::desligar()
{
    estadoLed = false;
    modoPiscar = false;
    digitalWrite(pino, LOW);
}
/**
 * 
 * @brief inverte o estado Led
 */
void led::inverter()
{
    estadoLed = !estadoLed;
    digitalWrite(pino, estadoLed);
}

/**
 * @brief pisca Led
 * @param f frequencia em hz que o led devera piscar
 */
void led::pisca(float frequencia)
{
    if(frequencia == 0) return;
    intervalo = 1000.0/(frequencia * 2);
    ultimaTroca = millis();
    modoPiscar = true;
}

/**
 * @brief funcao que atualiza o estado do Led no modo piscar
 */
void led::update()
{
    if(!modoPiscar) return;

    unsigned long agora = millis();
    if(agora - ultimaTroca >= intervalo)
    {
        inverter();
        ultimaTroca = agora;
    }
}

int led::getpino()
   {
     return pino;
   }

unsigned long led::getIntervalo()
{
    return intervalo;
}