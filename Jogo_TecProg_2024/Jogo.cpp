#include "Jogo.h"

using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo()
{
    pMenu = nullptr;
    pFase_Atual = nullptr;
    pFase1 = nullptr;
    pJogador1 = nullptr;
    pJogador2 = nullptr;

    pGer_Graf = Gerenciador_Grafico::getInstance();
    //pfase1->Setar_Jogadores_Colisoes(&jogador_1, nullptr);

    //Ger_Graf->getJanela()->setView(Ger_Graf->getCamera());
    estado_atual = EstadoJogo::MENU_PRINCIPAL;

    pMenu = new Menu();

    pMenu->set_pJog(this);
}

Jogo::~Jogo()
{
    delete pMenu;
}

void Jogo::Executar()
{
    //int i = 0;
    //tempo_principal.restart();
    //tempo.getElapsedTime().asSeconds();

    while (pGer_Graf->getJanela()->isOpen())
    {
        sf::Event evento;

        pGer_Graf->getJanela()->setFramerateLimit(60);

        //tempo.restart();

        while (pGer_Graf->getJanela()->pollEvent(evento))//trata eventos
        {
                if (evento.type == sf::Event::Closed) {//se o evento for fechar a janela
                    pGer_Graf->getJanela()->close();
                }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))//se a tecla ESC for pressionada
        {
            // deve ser modificado para encaixar o menu de pause.
            pGer_Graf->getJanela()->close();
        }

        pGer_Graf->getJanela()->clear();

        //std::cout << i << std::endl;
        //i++;
        //std::cout << tempo_principal.getElapsedTime().asSeconds(); //<< std::endl;
        //tempo.restart();
        
        switch (estado_atual) {
            case EstadoJogo::MENU_PRINCIPAL:{
                if(pMenu){
                    pMenu->Executar();
                }
                break;
            }
            case EstadoJogo::JOGANDO:{
                Atualiza();
                break;
            }
            case EstadoJogo::FIM_DE_JOGO:{
                pGer_Graf->getJanela()->close();
                break;
            }
        }

        pGer_Graf->getJanela()->display();

        if (pFase1->get_Ganhou()) {
            pGer_Graf->getJanela()->close();
        }
    }
}

void Jogo::Atualiza() {

    if (pFase_Atual) {
        pFase_Atual->Executar();
    }
    if (pJogador1) {
        pJogador1->Executar();
    }
    if (pJogador2->get_Dois_Jogadores()) {

        pJogador2->Executar();
    }
    
    atualiza_Camera();

    //descomentar essa execu��o caso n�o achar interessante a movimenta��o da camera ao colidir.
    //fase1.Executar();
    
    //Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());
    //Ger_Graf->getCamera()->move(jogador_1.get_Centro());

    

}

void Jogo::atualiza_Camera() {
    pGer_Graf->getJanela()->setView(*pGer_Graf->getCamera());
    pGer_Graf->getCamera()->setCenter(pJogador1->get_Centro());

}
