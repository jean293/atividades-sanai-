#ifndef LED_H
#define LED_H

#include <Arduino.h>


class  led //* class e uma descricao do objeto
{
  private: //* caracteristicas
      int pino;
      bool estadoLed;
      bool modoPiscar = false;
      unsigned long ultimaTroca = 0;
      unsigned long intervalo = 0;


  public://* acoes
     led(int pin); //* metodo consultor tem o mesmo nome da classe
     

     void ligar();
     void desligar();
     void inverter();

     void pisca(float frequencia);
     void update();

     int getpino();
     unsigned long getIntervalo();
};






#endif
