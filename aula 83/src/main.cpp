#include <Arduino.h>
#include "temporizador.h"
#include "led.h"
#include "botao.h"

temporizador tempo_10s(10000);
led  led_placa(2);
Botao btn_boot(0);

void setup()
{
  btn_boot.begin();
}
void loop()
{
  btn_boot.update();
  led_placa.update();

  if (btn_boot.pressionado())
  {
    if (!tempo_10s.estaAtivo())
      tempo_10s.inicia();

    else
      tempo_10s.reiniciar();

    led_placa.pisca(3);
  }

  if (tempo_10s.estaPronto());  
  {
    tempo_10s.desliga();
    tempo_10s.parar();
  }
}
