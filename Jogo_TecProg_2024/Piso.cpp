#include "Piso.h"

using namespace Obstaculos;

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
	
	tamanho.x = larg;
	tamanho.y = alt;
	pFigura->setFillColor(sf::Color::Green);
	pFigura->setSize(tamanho);
	pFigura->setPosition(-50.f, 200.f);

}

void Piso::Salvar()
{
}



void Piso::Executar() {
	Desenhar();
}