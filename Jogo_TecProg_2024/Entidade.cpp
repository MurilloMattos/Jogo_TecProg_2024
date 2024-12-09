#include "Entidade.h"

using namespace Entidades;

Entidade::Entidade() : Ente()
{
	x = 0;
	y = 0;
	gravidade = 9.807f;
}

Entidade::~Entidade(){

}

float Entidade::get_Gravidade() const{
	return gravidade;
}

void Entidades::Entidade::setar_Gravidade(int grav){
	gravidade = grav;
}

//irá funcionar?
void Entidades::Entidade::executar_Gravidade(){
	y -= gravidade;
	//pFigura->setPosition(x, y);
}


void Entidade::setar_Pos(float pos_x, float pos_y)
{
	x = pos_x;
	y = pos_y;

	pFigura->setPosition(x, y);
}
