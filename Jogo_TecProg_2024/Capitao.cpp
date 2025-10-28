#include "Capitao.h"

using namespace Entidades;
using namespace Personagens;

Capitao::Capitao(){

	num_vitalidade = 200;
	dano = 20;

	tamanho.x = 35.0;
	tamanho.y = 65.0;

	pos_inicial.x = 600.f;
	pos_inicial.y = 159.f;

	pos_final = pos_inicial;

	velocidade.x = 2.0f;

	pFigura->setFillColor(sf::Color::Magenta);

	pFigura->setSize(tamanho);
	pFigura->setPosition(pos_inicial);
}

Capitao::~Capitao(){

}

void Capitao::Executar() {

	Desenhar();
}

void Capitao::Salvar() {

}
