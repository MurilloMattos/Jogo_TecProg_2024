#include "Inimigo_Medio.h"

using namespace Entidades;
using namespace Personagens;

Inimigo_Medio::Inimigo_Medio() {

	sf::Vector2f boo(25.f, 45.f);

	velocidade = 2.0f;

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
	setar_Pos(x, y);

	if ((pos_final.x != x) && (pos_final.y != y)) {

		if (pos_final.x > x) {
			x += velocidade;
		}
		else if (pos_final.x < x) {
			x -= velocidade;
		}
		/*
		if (pos_final.y > y) {
			y += velocidade;
		}
		else if (pos_final.y < y) {
			y -= velocidade;
		}
		*/
	}
}


void Inimigo_Medio::Danificar(){

}

void Inimigo_Medio::andar_ate(float em_x, float em_y){

	pos_final.x = em_x;
	pos_final.y = em_y;
}

void Inimigo_Medio::Salvar() {

}