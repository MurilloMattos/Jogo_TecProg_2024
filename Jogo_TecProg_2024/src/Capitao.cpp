#include "Capitao.h"

using namespace Entidades;
using namespace Personagens;

Capitao::Capitao():Inimigo(){

	num_vitalidade = 200;
	dano = 20;

	tamanho.x = 35.0;
	tamanho.y = 65.0;

	pos_inicial.x = 50.f;
	pos_inicial.y = 159.f;

	pos_final = pos_inicial;

	velocidade.x = 2.0f;

	//pFigura->setFillColor(sf::Color::Magenta);

	//pFigura->setSize(tamanho);
	
        setFile("./assets/ladrao_centered.png");
        atribuirFigura();
	pFigura->setScale(0.3f, 0.3f);	
	pFigura->setPosition(pos_inicial.x, pos_inicial.y);

}

Capitao::~Capitao(){

}

void Capitao::Executar() {

	Ente::Desenhar();
}

void Capitao::Salvar() {

}
