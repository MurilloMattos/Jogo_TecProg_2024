#pragma once
#include <vector>
#include "Fase.h"
#include "Capitao.h"
#include "Projetil.h"

namespace Fases{

	class Fase_1 : public Fase
	{
	private:

		std::vector<Entidades::Personagens::Capitao*> lista_cap;
		int num_max_Capitoes;
		int i,j;

	public:

		Fase_1();
		~Fase_1();


		void Cria_Obstaculos();
		void Executar();
		void Cria_Inimigos();
		void Cria_Inimigos_Capitao();
		Entidades::Projetil* Cria_Projetil();
		void verifica_Projeteis_Destroidos();

	};
}
