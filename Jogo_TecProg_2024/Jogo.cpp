#include "Jogo.h"

using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo()
{

    jogador_2.setar_Dois_Jogadores(false);


    Ger_Graf = Gerenciador_Grafico::getInstance();

	//mudar para a fase que for ser utilizada, a principio o menu é para alternar essas boleanas e chamar a função setar_Fase();
    fase_1_ativa = false;
    fase_2_ativa = true;

    setar_Fase();
}

Jogo::~Jogo()
{
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
    }
}

void Jogo::Atualiza() {

    //fase1.Executar();

    if (!acabou) {
        if (fase_1_ativa) {
            //fase_1.executar();
        }
        else if (fase_2_ativa) {
            fase2.Executar();
        }


        jogador_1.Executar();

        if (jogador_2.get_Dois_Jogadores()) {
            jogador_2.Executar();
        }

        verifica_Fim_De_Jogo();

        atualiza_Camera();
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
