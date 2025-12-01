#include "Core/Jogo.h"

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
fase2(),
estado(Estado::MENU)

{

    jogador_2.setar_Dois_Jogadores(false);

    Ger_Graf = Gerenciador_Grafico::getInstance();

	//inicialação das fases corrigida, agora função Atualiza chama setar_Fase quando necessário
    fase_1_ativa = false;
    fase_2_ativa = false;

    fase1.Setar_Jogadores(&jogador_1, &jogador_2);
    fase2.Setar_Jogadores(&jogador_1, &jogador_2);


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

void Jogo::set_pJog2_Dois_Jogadores(bool valor) {

    jogador_2.setar_Dois_Jogadores(valor);
}

bool Jogo::get_pJog2_Dois_Jogadores() {
    return jogador_2.get_Dois_Jogadores();
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


        EstadoDoJogo();

        Ger_Graf->getJanela()->display();

        if(fase_1_ativa) {
            
            if (fase1.get_Ganhou()) {
                Ger_Graf->getJanela()->close();
            }
        }
        else if (fase_2_ativa) {

            if (fase2.get_Ganhou()) {
                Ger_Graf->getJanela()->close();
            }
        }

    }
}

void Jogo::EstadoDoJogo() {//executa o estado atual do jogo

    if(estado == Estado::MENU) {
        menu->Executar();
    }

    if(estado == Estado::FASE_1) {

        fase_1_ativa = true;
        atualiza_Camera();
        setar_Fase();

        verifica_Fim_De_Jogo();

    }

    if(estado == Estado::FASE_2) {

        fase_2_ativa = true;
        atualiza_Camera();
        setar_Fase();

        verifica_Fim_De_Jogo();

    }
    
    else {
		//system("pause");
        //salvar o jogo ou mostrar a tela de fim de jogo
	}
}

void Jogo::verifica_Fim_De_Jogo()
{
    if(fase_1_ativa){
        if (fase1.get_Ganhou() || (jogador_1.get_Eliminado() && jogador_2.get_Eliminado()))
        {
            
            std::cout << "pontuacao jogador 1:" << jogador_1.get_Pontuacao() << std::endl;
            std::cout << "pontuacao jogador 2:" << jogador_2.get_Pontuacao() << std::endl;

            Ger_Graf->getJanela()->close();
            acabou = true;
        }
    }
    else  if(fase_2_ativa){
        if (fase2.get_Ganhou() || (jogador_1.get_Eliminado() && jogador_2.get_Eliminado()))
        {
            std::cout << "pontuacao jogador 1:" << jogador_1.get_Pontuacao() << std::endl;
            std::cout << "pontuacao jogador 2:" << jogador_2.get_Pontuacao() << std::endl;

            Ger_Graf->getJanela()->close();
			acabou = true;
        }
	}
}

void Jogo::setar_Fase()
{
    //garante que os jogadores sejam setados
    jogador_1.Executar();
    if (jogador_2.get_Dois_Jogadores()) {
        jogador_2.Executar();
    }

    //seta os jogadores na fase ativa
    if (fase_1_ativa) {
       //fase1.Setar_Jogadores(&jogador_1, &jogador_2);
        fase1.Executar();

        if(fase1.verifica_Se_Caiu_No_Abismo(static_cast<Entidade*>(&jogador_1))){
            jogador_1.diminuir_Vitalidade(200);
        }
        if(fase1.verifica_Se_Caiu_No_Abismo(static_cast<Entidade*>(&jogador_2))){
            jogador_2.diminuir_Vitalidade(200);
        }
        
	}
    else if (fase_2_ativa) {
        //fase2.Setar_Jogadores(&jogador_1, &jogador_2);
        fase2.Executar();

        if(fase2.verifica_Se_Caiu_No_Abismo(static_cast<Entidade*>(&jogador_1))){
            jogador_1.diminuir_Vitalidade(200);
        }
        if(fase2.verifica_Se_Caiu_No_Abismo(static_cast<Entidade*>(&jogador_2))){
            jogador_2.diminuir_Vitalidade(200);
        }
	}
}

void Jogo::atualiza_Camera() {
    Ger_Graf->getJanela()->setView(*Ger_Graf->getCamera());

    if(fase_1_ativa){
        fase1.atualiza_Camera_Fase(&jogador_1, &jogador_2);
    }
    else if(fase_2_ativa){
        fase2.atualiza_Camera_Fase(&jogador_1, &jogador_2);
    }

    //isso deve ser passado para a fase, que deve ajustar a camera conforme o jogador se move pelo mapa.
    //Ger_Graf->getCamera()->setCenter(jogador_1.get_Centro());

}
