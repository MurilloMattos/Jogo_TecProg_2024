#include "Jogo.h"

Jogo::Jogo()
{
    Ger_Graf = Gerenciador_Grafico::getInstance();

}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{

    while (Ger_Graf->getJanela()->isOpen())
    {
        sf::Event evento;

        while (Ger_Graf->getJanela()->pollEvent(evento))
        {
                if (evento.type == sf::Event::Closed) {
                    Ger_Graf->getJanela()->close();
                }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // deve ser modificado para encaixar o menu de pause.
            Ger_Graf->getJanela()->close();
        }

        Ger_Graf->getJanela()->clear();

        Atualiza();

        Ger_Graf->getJanela()->display();

    }
}

void Jogo::Atualiza() {

    jogador_1.Executar();
    fase1.Executar();

}

void Jogo::Atualiza_cam() {
    //Ger_Graf->getJanela()->
}