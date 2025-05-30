#ifndef BOTAO_H
#define  BOTAO_H

#include <Arduino.h>


class Botao {


    private:
        uint8_t pino;
        bool estadoAtual = HIGH;
        bool estadoAnterior = HIGH;
        bool estadoConfirmado = HIGH;
        bool flagAlteracao = false;
        bool flagpressionado = false;
        bool flagSolto = false;

        unsigned long tempoInicioEstado = 0;
        unsigned long tempoFiltro = 50;
        unsigned long tempoUltimaMudanca = 0;
        unsigned long duracaoEstado = 0;



    public:
        Botao(uint8_t p); //* contrutor
        
        void begin();
        void update();

        bool pressionado();
        bool Solto();
        bool alteracaoEstado();
        unsigned long duracaoUltimatoEstado();


     void configuraFiltro(unsigned long tempo);
 

};










#endif