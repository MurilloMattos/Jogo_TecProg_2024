#include "Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Plataforma::Plataforma()
{

	tamanho.x = 0;
	tamanho.y = 0;
}

Plataforma::~Plataforma(){

}

void Plataforma::seta_Plataforma(float alt, float larg, float origem_x, float origem_y)
{

	tamanho.x = larg;
	tamanho.y = alt;

	pFigura->setFillColor(sf::Color::Green);
	pFigura->setSize(tamanho);
	this->setar_Pos(origem_x, origem_y);
}

void Plataforma::Salvar(){

}



void Plataforma::Executar() {

	Desenhar();
}

void Plataforma::obstacular(Jogador* p, int lado) {

	if(lado == baixo){
		p->setar_Estado(false);
	}
	
}
