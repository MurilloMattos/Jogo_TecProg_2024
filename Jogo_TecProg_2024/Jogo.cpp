#include "Jogo.h"

using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo() :
Ger_Graf(),
jogador_1(),
jogador_2(),
fase1(),
menu(new Menu(this)),
estado(Estado::MENU)
{

    jogador_2.setar_Dois_Jogadores(false);


    Ger_Graf = Gerenciador_Grafico::getInstance();

	//mudar para a fase que for ser utilizada, a principio o menu � para alternar essas boleanas e chamar a fun��o setar_Fase();
    fase_1_ativa = false;
    fase_2_ativa = true;

    setar_Fase();

    setar_Fase();
}

Jogo::~Jogo()
{
    delete menu;
}

void Jogo::setEstado(Estado novoEstado) {
    estado = novoEstado;
}

Estado Jogo::getEstado() const {
    return estado;
}

void Jogo::Executar()
{

    setar_Fase();

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

        if (fase1.get_Ganhou()) {
            Ger_Graf->getJanela()->close();
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
        atualiza_Camera();
        jogador_1.Executar();
        if (jogador_2.get_Dois_Jogadores()) {
            jogador_2.Executar();
        }

        verifica_Fim_De_Jogo();

    }
    
    else {
		system("pause");
        //salvar o jogo ou mostrar a tela de fim de jogo
	}
}

void Jogo::verifica_Fim_De_Jogo()
{
    if(fase_1_ativa){
        //if (fase1.get_Ganhou() || (jogador_1.get_Eliminado() && jogador_2.get_Eliminado()))
        //{
        //    Ger_Graf->getJanela()->close();
        //    acabou = true;
        //}
    }
    else  if(fase_2_ativa){
        if (fase2.get_Ganhou() || (jogador_1.get_Eliminado() && jogador_2.get_Eliminado()))
        {
            Ger_Graf->getJanela()->close();
			acabou = true;
        }
	}
}

void Jogo::setar_Fase()
{

	//com a fase_1 implementada, pode descomentar esse bloco;
    if (fase_1_ativa) {
        //fase1.Setar_Jogadores(&jogador_1, &jogador_2);
	}
    else if (fase_2_ativa) {
        fase2.Setar_Jogadores(&jogador_1, &jogador_2);
	}
}

void Jogo::atualiza_Camera() {
    Ger_Graf->getJanela()->setView(*Ger_Graf->getCamera());
    Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());

}
