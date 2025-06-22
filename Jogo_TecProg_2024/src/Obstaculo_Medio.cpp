#include "Obstaculo_Medio.h"
#include <ctime>
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

Obstaculo_Medio::Obstaculo_Medio():Obstaculo() {
	setFile("./assets/lama.png");
	atribuirFigura();
	setar_Pos(230.0, 159.0);
}

Obstaculo_Medio::~Obstaculo_Medio() {

}

void Entidades::Obstaculos::Obstaculo_Medio::Salvar()
{	

}

void Obstaculo_Medio::Executar()
{
	Desenhar();
	srand(time(NULL));
	float random;
	random = rand()%5+1;
        setar_Pos(x - random, y);
}

void Obstaculo_Medio::obstacular(Entidades::Personagens::Jogador* p) {

}
