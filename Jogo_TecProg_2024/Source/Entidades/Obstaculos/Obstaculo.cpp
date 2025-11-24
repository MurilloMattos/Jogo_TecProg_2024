#include "Entidades/Obstaculos/Obstaculo.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

Obstaculo::Obstaculo() : semente_id_entidade(1000)
{
	agressivo = false;
	setId(semente_id_entidade);

	tamanho.x = 0.f;
	tamanho.y = 0.f;
	
}

Obstaculo::~Obstaculo() {

}

//n�o sei como executar a gravidade aplicada ao obstaculo.
void Obstaculo::executar_Gravidade(){
	y += gravidade;
	y -= gravidade;
}


