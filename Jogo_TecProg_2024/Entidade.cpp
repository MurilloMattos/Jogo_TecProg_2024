#include "Entidade.h"

using namespace Entidades;

Entidade::Entidade() : Ente()
{
	x = NULL;
	y = NULL;
}

Entidade::~Entidade()
{
}

void Entidades::Entidade::setar_pos(float pos_x, float pos_y)
{
	x = pos_x;
	y = pos_y;
}
