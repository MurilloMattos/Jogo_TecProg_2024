#pragma once
#include "Ente.h"

namespace Entidades 
{
	class Entidade : public Ente
	{
	protected:
		float x, y;
		float gravidade;
		bool agressivo;
		//bool colisao;

	public:
		Entidade();
		~Entidade();

		float get_Gravidade() const;
		void setar_Gravidade(float grav);
		virtual void executar_Gravidade();


		// escolhi deixar o pFigura mais restrito.
		float get_Largura();
		float get_Altura();

		float get_Comprimento_A();
		float get_Comprimento_L();

		float get_X() const;
		float get_Y() const;
		void setar_Pos(float pos_x, float pos_y);

		virtual void Executar() = 0;
		virtual void Salvar() = 0;

	};

}