#include "Jogo.h"

using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo()
{

    jogador_2.setar_Dois_Jogadores(true);

    Ger_Graf = Gerenciador_Grafico::getInstance();
    //fase1.Setar_Jogadores_Colisoes(&jogador_1, nullptr);


    //Ger_Graf->getJanela()->setView(Ger_Graf->getCamera());
    fase1.Setar_Jogadores_Colisoes(&jogador_1, &jogador_2);
}

Jogo::~Jogo()
{
}

void Jogo::Executar()
{
    //int i = 0;
    //tempo_principal.restart();
    //tempo.getElapsedTime().asSeconds();

    while (Ger_Graf->getJanela()->isOpen())
    {
        

        sf::Event evento;

        Ger_Graf->getJanela()->setFramerateLimit(60);

        //tempo.restart();

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

        //std::cout << i << std::endl;
        //i++;
        //std::cout << tempo_principal.getElapsedTime().asSeconds(); //<< std::endl;
        //tempo.restart();

        Atualiza();

        Ger_Graf->getJanela()->display();

        if (fase1.get_Ganhou()) {
            Ger_Graf->getJanela()->close();
        }
    }
}

void Jogo::Atualiza() {




    fase1.Executar();
    jogador_1.Executar();

    if (jogador_2.get_Dois_Jogadores()) {
        
        jogador_2.Executar();
    }
    
    atualiza_Camera();

    //descomentar essa execução caso não achar interessante a movimentação da camera ao colidir.
    //fase1.Executar();
    
    //Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());
    //Ger_Graf->getCamera()->move(jogador_1.get_Centro());

    

}

void Jogo::atualiza_Camera() {
    Ger_Graf->getJanela()->setView(*Ger_Graf->getCamera());
    Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());

}
