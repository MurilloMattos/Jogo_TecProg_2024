#include "Obstaculo.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

Obstaculo::Obstaculo()
{
	agressivo = false;
}

Obstaculo::~Obstaculo() {

}

//n�o sei como executar a gravidade aplicada ao obstaculo.
void Obstaculo::executar_Gravidade(){
	y += gravidade;
	y -= gravidade;
}
