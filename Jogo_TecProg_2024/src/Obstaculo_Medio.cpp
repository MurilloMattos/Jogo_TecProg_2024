#include "Obstaculo_Medio.h"
#include <ctime>
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

Obstaculo_Medio::Obstaculo_Medio():Obstaculo() {
	setFile("./assets/lama.png");
	atribuirFigura();
	//setar_Pos(230.0, 159.0);
	pFigura->setOrigin(pFigura->getGlobalBounds().width/2.0f, pFigura->getGlobalBounds().height/2.0f);
	agressivo = true;
}

Obstaculo_Medio::~Obstaculo_Medio() {

}

void Entidades::Obstaculos::Obstaculo_Medio::Salvar()
{	

}

void Obstaculo_Medio::Executar()
{
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

void Obstaculo_Medio::obstacular(Entidades::Personagens::Jogador* p) {
	if(agressivo) {
		p->diminuir_Vitalidade(10);
	}
}
