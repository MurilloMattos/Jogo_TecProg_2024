#include "Obstaculo_Dificil.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

Obstaculo_Dificil::Obstaculo_Dificil(): Obstaculo() {
	setFile("./assets/chama.png");
	atribuirFigura();
	//setar_Pos(230.0, 159.0);
	pFigura->setOrigin(pFigura->getGlobalBounds().width/2.0f, pFigura->getGlobalBounds().height/2.0f);
	agressivo = true;
	pFigura->setScale(0.5f, 0.5f);	
}
Obstaculo_Dificil::~Obstaculo_Dificil() {

}
void Obstaculo_Dificil::Salvar()
{

}

void Obstaculo_Dificil::Executar() {
	srand(time(NULL));
	float random;
	random = rand() %(500-250+1) + 250;	
	sf::Vector2f anter;
	anter.x = x;
	anter.y = y;
	if((x + random) < (x + 500.0f)) { 
        	setar_Pos(x + random, y);
	}else if((x - random) > (x - 500.0f)) {
		setar_Pos(x - random, y);
	}
	Desenhar();
	setar_Pos(anter.x, anter.y);

}

void Obstaculo_Dificil::obstacular(Jogador* p) {
	if(agressivo) {
		p->diminuir_Vitalidade(10);
	}
}

