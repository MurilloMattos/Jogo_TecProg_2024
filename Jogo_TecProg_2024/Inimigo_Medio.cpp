#include "Inimigo_Medio.h"

using namespace Entidades;
using namespace Personagens;

Inimigo_Medio::Inimigo_Medio() {

	sf::Vector2f boo(20.f, 40.f);

	pFigura->setFillColor(sf::Color::Red);

	pFigura->setSize(boo);
	pFigura->setPosition(200.f, 159.f);

}

/*
Inimigo_Medio::Inimigo_Medio(float pos_x,float pos_y) {

	sf::Vector2f boo(20.f, 40.f);

	pFigura->setFillColor(sf::Color::Red);

	pFigura->setSize(boo);
	pFigura->setPosition(pos_x, pos_y);
}
*/

Inimigo_Medio::~Inimigo_Medio() {

}

void Inimigo_Medio::Executar() {
	Desenhar();
}

/*
void Inimigo_Medio::Danificar() {

}
*/

void Inimigo_Medio::Salvar() {

}