#include "Piso.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Piso::Piso(): Obstaculo()
{
	boo = 0;

	tamanho.x = 0;
	tamanho.y = 0;
	setFile("./assets/piso_centered.png");
	atribuirFigura();
}

Piso::~Piso(){

}

void Piso::seta_Piso(float alt, float larg, float origem_x, float origem_y)
{
	//boo = larg;
	//x = -500.f;
	//y = 400.f;
	pFigura->setScale(larg, alt);	
	this->setar_Pos(origem_x, origem_y);;
	//pFigura->setOrigin(largura/2.f, altura / 2.f);
	//sf::FloatRect global = pFigura->getGlobalBounds();
	//tamanho.x = global.width;
	//tamanho.y = global.height;

	//pFigura->setColor(sf::Color::Green);
	//pFigura->setSize(tamanho);
	//pFigura->setFillColor(sf::Color::Green);
	//pFigura->setSize(tamanho);
}
void Piso::Salvar(){

}



void Piso::Executar() {
	Ente::Desenhar();
}

void Piso::obstacular(Jogador* p) {

}
