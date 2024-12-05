#include "Jogador.h"

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador() {
	setar_Vitalidade(100);
	setar_Figura();
	setar_Pos(50.f,159.f);

	pontos = 0;

}

Jogador::~Jogador() {

}

void Jogador::Executar() {
	Desenhar();
}

void Jogador::Salvar(){

}

// adicionar em classes primordiais? tais como Ente ou Entidades?
void Jogador::setar_Figura() {

	sf::Vector2f boo(20.f, 40.f);

	pFigura->setSize(boo);
	pFigura->setFillColor(sf::Color::Blue);

}

void Jogador::setar_Pos(float x, float y) {

	pFigura->setPosition(x, y);
}