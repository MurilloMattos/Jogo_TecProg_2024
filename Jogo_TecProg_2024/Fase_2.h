#pragma once
#include "Fase.h"
#include "Capitao.h"
#include "Projetil.h"

namespace Fases{

	class Fase_2 : public Fase
	{
	private:

		std::vector<Entidades::Personagens::Capitao*> lista_cap;
		int num_max_Capitoes;
		int i,j;

	public:

		Fase_2();
		~Fase_2();


		void Cria_Obstaculos();
		void Executar();
		void Cria_Inimigos();
		void Cria_Inimigo_Capitao(float x, float y);
		Entidades::Projetil* Cria_Projetil();
		void verifica_Projeteis_Destroidos();

	};
}
