#pragma once
#include "Ente.h"

namespace Entidades 
{
	class Entidade : public Ente
	{
	protected:
		float x, y;

	public:
		Entidade();
		~Entidade();

		void setar_pos(float pos_x, float pos_y);

		virtual void Executar() = 0;
		virtual void Salvar() = 0;

	};

}