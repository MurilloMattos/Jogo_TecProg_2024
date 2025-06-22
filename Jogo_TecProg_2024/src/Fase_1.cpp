#include "Fase_1.h"

using namespace Entidades;
using namespace Personagens;

Fases::Fase_1::Fase_1(): Fase(){

	Cria_Inimigos();
	setFile("./assets/faselama.png");
	atribuirFigura();
	pFigura->setPosition(0.0f, 0.0f);

        //sf::Vector2u tamanhoJanela = pGG->getJanela()->getSize();
        //sf::Vector2u tamanhoTextura = figura->getSize();

	//float X = static_cast<float>(tamanhoJanela.x) / (tamanhoTextura.x);
        //float Y = static_cast<float>(tamanhoJanela.y) / (tamanhoTextura.y);
        //pFigura->setScale(X, Y);
	

}

Fases::Fase_1::~Fase_1(){

}
void Fases::Fase_1::Executar(){
	pGG->getJanela()->setView(pGG->getCameraDefault());
	Desenhar();
	pGG->getJanela()->setView(*pGG->getCamera());
	verifica_Inimigos_Neutralizados();
	gerenciador_colisoes.Executar();
	lista_Entidades.Percorrer();
}


void Fases::Fase_1::Cria_Inimigos(){

	Cria_Inimigos_Piratas();
	Cria_Inimigos_Capitao();
}

void Fases::Fase_1::Cria_Inimigos_Capitao(){

	Capitao* capitao;
	capitao = new Capitao;

	capitao->setar_Pos(950.f, 159.f);
	gerenciador_colisoes.Incluir_Inimigo(capitao);
	lista_Entidades.Incluir(static_cast<Entidade*>(capitao));
}
