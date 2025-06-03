#include "Jogador.h"

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador() {

	segundo_jogador = false;

	x = 50.0;
	y = 100.0;

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
	if (!segundo_jogador) {
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
		
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			y += velocidade;
		}
		
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			x += velocidade;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			x -= velocidade;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			y -= velocidade;
		}
	}
	setar_Pos(x, y);
	desenhar();
}

void Jogador::setar_Dois_Jogadores(bool jogador_dois) {
	segundo_jogador = jogador_dois;
	pFigura->setColor(sf::Color::Magenta);
	setar_Pos(x + 25,y);
}

void Jogador::Salvar(){

}

// adicionar em classes primordiais? tais como Ente ou Entidades?
void Jogador::setar_Figura() {

	sf::Vector2f boo(20.f, 40.f);

	//pFigura->setSize(boo);
	//pFigura->setColor(sf::Color::Blue);
	pFigura->setScale(0.1 , 0.01);
	figura->loadFromFile("./assets/sprite.png");
	pFigura->setTexture(*figura);
}

/*
void Jogador::setar_Pos(float x, float y) {

	pFigura->setPosition(x, y);
}
*/
