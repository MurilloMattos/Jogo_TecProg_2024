#include "Piso.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Piso::Piso()
{
	boo = 0;

	tamanho.x = 0.0;
	tamanho.y = 0.0;
}

Piso::~Piso(){

}

void Piso::seta_Piso(float alt, float larg, float origem_x, float origem_y)
{

	tamanho.x = larg;
	tamanho.y = alt;

	pFigura->setFillColor(sf::Color::Green);
	pFigura->setSize(tamanho);
	this->setar_Pos(origem_x, origem_y);
}

void Piso::Salvar(){

}



void Piso::Executar() {
	Desenhar();
}

void Piso::obstacular(Jogador* p) {

}
