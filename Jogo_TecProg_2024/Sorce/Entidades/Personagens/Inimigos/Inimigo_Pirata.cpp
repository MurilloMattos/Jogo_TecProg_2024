#include "Entidades/Personagens/Inimigos/Inimigo_Pirata.h"

using namespace Entidades;
using namespace Personagens;

Pirata::Pirata() {

	num_vitalidade = 100;
	dano = 20;

	tamanho.x = 25.0;
	tamanho.y = 55.0;

	pos_inicial.x = 200.f;
	pos_inicial.y = 159.f;

	pos_final = pos_inicial;

	velocidade.x = 2.0f;

	pFigura->setFillColor(sf::Color::Red);

	pFigura->setSize(tamanho);
	pFigura->setPosition(pos_inicial);

}

Pirata::~Pirata() {

}

void Pirata::Executar() {

	Desenhar();
	setar_Pos(x, y);

	if ((pos_final.x != x) && (pos_final.y != y)) {

		if (pos_final.x > x) {
			x += velocidade.x;
		}
		else if (pos_final.x < x) {
			x -= velocidade.x;
		}

	}
}


void Pirata::Danificar(){

}

void Pirata::andar_ate(float em_x, float em_y){

	pos_final.x = em_x;
	pos_final.y = em_y;
}

void Pirata::Salvar() {

}