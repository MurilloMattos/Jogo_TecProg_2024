#include "Jogo.h"
//#include "Jogador.h"
//#include "Fase.h"
#include "Menu.h"
using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Jogo::Jogo()
{
    //jogador_2.setar_Dois_Jogadores(true);

    Ger_Graf = Gerenciador_Grafico::getInstance();
    janelaJogo = Ger_Graf->criaJanela("Jogo", 1360, 768);
    Ger_Graf->setJanela(this->janelaJogo);

    fase1.Setar_Jogadores_Colisoes(&jogador_1, nullptr);
    m = new Menu();
    m->setpGG(Ger_Graf);
    m->set_pJog(this);

    incluirEntes((Ente*)m);
    //m->Executar(); 
    //fase1.Setar_Jogadores_Colisoes(&jogador_1, &jogador_2);
}
Jogo::~Jogo()
{
}
void Jogo::setJanelaJogo(sf::RenderWindow *j) {  janelaJogo = j; }
sf::RenderWindow * Jogo::getJanela() {	return janelaJogo;	}
void Jogo::Executar()
{
    entes[0]->Executar();     	
}

void Jogo::Atualiza()
{
    
    jogador_1.Executar();
    jogador_2.Executar();
    fase1.Executar();

}

void Jogo::Atualiza_cam() {
    //Ger_Graf->getJanela()->
}
void Jogo::incluirEntes(Ente *ente) {
	if(ente) {
		entes.push_back(ente);
	}
}
