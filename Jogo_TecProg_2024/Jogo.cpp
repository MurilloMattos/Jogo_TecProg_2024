#include "Jogo.h"

using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo():
GG(nullptr),
pJog1(),
pJog2(),
fase1(),
menu(nullptr)
{
    //inicializa o estado do jogo como MENU
    estado = Estado::MENU;

    pJog2.setar_Dois_Jogadores(false);

    GG = Gerenciador_Grafico::getInstance();
    //fase1.Setar_Jogadores_Colisoes(&pJog1, nullptr);

    menu = new Menu(this);

    //GG->getJanela()->setView(GG->getCamera());
    fase1.Setar_Jogadores_Colisoes(&pJog1, &pJog2);
}

Jogo::~Jogo()
{
    delete menu;
    menu = nullptr;
}

void Jogo::Executar()
{
    //int i = 0;
    //tempo_principal.restart();
    //tempo.getElapsedTime().asSeconds();

    while (GG->getJanela()->isOpen())
    {
        sf::Event evento;

        GG->getJanela()->setFramerateLimit(60);

        //tempo.restart();

        
        while (GG->getJanela()->pollEvent(evento))//trata eventos
        {
                if (evento.type == sf::Event::Closed) {//se o evento for fechar a janela
                    GG->getJanela()->close();
                }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//se a tecla ESC for pressionada
        {
            // deve ser modificado para encaixar o menu de pause.
            GG->getJanela()->close();
        }

        GG->getJanela()->clear();

        //std::cout << i << std::endl;
        //i++;
        //std::cout << tempo_principal.getElapsedTime().asSeconds(); //<< std::endl;
        //tempo.restart();
        
        Atualiza();

        GG->getJanela()->display();

        if (fase1.get_Ganhou()) {
            GG->getJanela()->close();
        }
    }
}

void Jogo::Atualiza() {

    if(estado == Estado::MENU) {
        menu->Executar();
        if (menu->getFase_1()) {
            estado = Estado::FASE_1;
        }
    }
    if(estado == Estado::FASE_1) {
        fase1.Executar();
    }
    
    pJog1.Executar();

    if (pJog2.get_Dois_Jogadores()) {
        pJog2.Executar();
    }
    
    atualiza_Camera();

    //descomentar essa execu��o caso n�o achar interessante a movimenta��o da camera ao colidir.
    //fase1.Executar();
    
    //Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());
    //Ger_Graf->getCamera()->move(jogador_1.get_Centro());

    

}

void Jogo::atualiza_Camera() {
    GG->getJanela()->setView(*GG->getCamera());
    GG->getCamera()->setCenter(pJog1.get_Centro());

}