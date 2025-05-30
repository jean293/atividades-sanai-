#include "botao.h"

/**
 * @brief contrutor da classe botao
 *
 * @param p Numero do pino deigital ao qual o botao esta conectado
 */
Botao::Botao(uint8_t p) : pino(p) {}

/**
 * @brief inicializa o botao
 *
 * configura o pino como entrada. o modo pull up padrao
 *
 */
void Botao::begin()
{
    pinMode(pino, INPUT_PULLUP);
    estadoAtual = digitalRead(pino);
    estadoAnterior = estadoAtual;
    estadoConfirmado = estadoAtual;
    tempoInicioEstado = millis();
}

/**
 * @brief define o tempo de filtro (debounce) para estabilizar as leituras do botao
 *
 * @param tempo tempo de debounce em milisegundos
 */
void Botao::configuraFiltro(unsigned long tempo)
{
    tempoFiltro = tempo;
}

/**
 * @brief atualiza o estado interno do botao
 *
 * deve ser chamado frequentimente dentro do lopp principal.
 * detecta mudancas de estado e aciona as flags internas de
 * eventos (pressionado, solto, mudanca, de estado)
 *
 */
void Botao::update()
{
    unsigned long agora = millis();
    estadoAtual = digitalRead(pino);
    flagAlteracao = false;
    flagpressionado = false;
    flagSolto = false;

    if (estadoAtual != estadoAnterior)

        if ((agora - tempoUltimaMudanca) > tempoFiltro)
        {
            if (estadoAtual != estadoConfirmado)
            {
                estadoConfirmado = estadoAtual;
                duracaoEstado = agora - tempoInicioEstado;
                tempoInicioEstado = agora;
                flagAlteracao = true;

                if (!estadoAtual) //*botao pressionado
                {
                    flagpressionado = true;
                }
                else
                {
                    flagSolto = true;
                }
            }
        }
    estadoAnterior = estadoAtual;
}


/**
 * @brief verifics se o botao acabou de ser pressionado
 * 
 * @return true se houve uma transicao para o estado solto na ultima atualiza
 */
bool Botao::pressionado()
{
    return flagpressionado;
}

/**
 * @brief verifics se o botao acabou de ser solto
 * 
 * @return true se houve uma transicao para o estado solto na ultima atualiza
 */
 bool Botao::Solto(){
    return flagSolto;
 }

/**
 * @brief verifica se houve uma mundanca  de estado no botao
 * 
 * @return true se o estado do botao mudou (pressionado ou solto)
 * na ultima atualizacao
 */
bool Botao::alteracaoEstado()
{
    return flagAlteracao;
}

/**
 * @brief retorna a duracao do ultimo estado mantido (pressionado ou solto)
 * 
 * @return tempo em millisegundos que o botao peramaneceu no ultimo estado
 */
unsigned long Botao::duracaoUltimatoEstado()
{
  return duracaoEstado;
}