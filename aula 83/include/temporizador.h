#ifndef TEMPORIZADOR_H
#define TEMPORIZADOR_H
 
#include <Arduino.h>


class temporizador {


    private:

        unsigned long intervalo;
        bool ativo;
        unsigned long inicio;



    public:
           
      temporizador(unsigned long tempo_ms = 1000);
        void inicia();
        void parar();
        void reiniciar();
        bool estaPronto();
        bool estaAtivo();
        void definirIntervalo(unsigned long tempo_ms);

};





#endif