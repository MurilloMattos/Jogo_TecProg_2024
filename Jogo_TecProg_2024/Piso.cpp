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

void Piso::seta_Piso(float alt, float larg)
{
	//boo = larg;
	x = -50.f;
	y = 200.f;
	
	tamanho.x = larg;
	tamanho.y = alt;
	pFigura->setFillColor(sf::Color::Green);
	pFigura->setSize(tamanho);
	pFigura->setPosition(x, y);

}

void Piso::Salvar()
{
}



void Piso::Executar() {
	Desenhar();
}

void Piso::obstacular(Jogador* p)
{
}
