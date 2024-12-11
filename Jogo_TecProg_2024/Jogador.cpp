#include "Jogador.h"

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador() {
	x = 50.0;
	y = 150.0;

	setar_Vitalidade(100);
	setar_Figura();
	setar_Pos(x,y);
	//setar_pos(0.0f, 0.0f);

	//std::cout << "X:" << pFigura->getPosition().x<< " Y:" << pFigura->getOrigin().y << std::endl;

	velocidade = 5.0;

	pontos = 0;

}

Jogador::~Jogador() {

}

void Jogador::Executar() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		x += velocidade;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		x -= velocidade;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		y -= velocidade;
	}

	setar_Pos(x, y);
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

/*
void Jogador::setar_Pos(float x, float y) {

	pFigura->setPosition(x, y);
}
*/