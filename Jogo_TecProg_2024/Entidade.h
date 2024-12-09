#pragma once
#include "Ente.h"

namespace Entidades 
{
	class Entidade : public Ente
	{
	protected:
		float x, y;
		float gravidade;

	public:
		Entidade();
		~Entidade();

		float get_Gravidade() const;
		void setar_Gravidade(int grav);
		void executar_Gravidade();

		void setar_Pos(float pos_x, float pos_y);

		virtual void Executar() = 0;
		virtual void Salvar() = 0;

	};

}