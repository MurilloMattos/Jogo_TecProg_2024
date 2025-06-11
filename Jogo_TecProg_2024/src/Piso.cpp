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
	x = -500.f;
	y = 400.f;
	
	tamanho.x = larg;
	tamanho.y = alt;
	//pFigura->setColor(sf::Color::Green);
	//pFigura->setSize(tamanho);
	pFigura->setPosition(x, y);
	pFigura->setScale(1.0, 0.5);
	figura->loadFromFile("./assets/piso.png");
	pFigura->setTexture(*figura);		

}

void Piso::Salvar()
{
}



void Piso::Executar() {
	//Desenhar();
	desenhar();
}

void Piso::obstacular(Jogador* p)
{
}
