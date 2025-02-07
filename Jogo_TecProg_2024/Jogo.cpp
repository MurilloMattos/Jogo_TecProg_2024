#include "Jogo.h"

using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo()
{

    //jogador_2.setar_Dois_Jogadores(true);

    Ger_Graf = Gerenciador_Grafico::getInstance();
    fase1.Setar_Jogadores_Colisoes(&jogador_1, nullptr);


    //Ger_Graf->getJanela()->setView(Ger_Graf->getCamera());
    //fase1.Setar_Jogadores_Colisoes(&jogador_1, &jogador_2);
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{

    while (Ger_Graf->getJanela()->isOpen())
    {
        sf::Event evento;

        Ger_Graf->getJanela()->setFramerateLimit(60);

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

    

    fase1.Executar();
    jogador_1.Executar();
    atualiza_Camera();

    //descomentar essa execu��o caso n�o achar interessante a movimenta��o da camera ao colidir.
    //fase1.Executar();
    
    //Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());
    //Ger_Graf->getCamera()->move(jogador_1.get_Centro());

    //jogador_2.Executar();

}

void Jogo::atualiza_Camera() {
    Ger_Graf->getJanela()->setView(*Ger_Graf->getCamera());
    Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());

}
