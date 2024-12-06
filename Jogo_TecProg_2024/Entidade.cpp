#include "Entidade.h"

using namespace Entidades;

Entidade::Entidade() : Ente()
{
	x = 0;
	y = 0;
}

Entidade::~Entidade(){

}

void Entidades::Entidade::setar_pos(float pos_x, float pos_y)
{
	x = pos_x;
	y = pos_y;

	pFigura->setPosition(x, y);
}
