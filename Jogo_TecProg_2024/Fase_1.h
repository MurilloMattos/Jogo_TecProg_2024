#pragma once
#include "Fase.h"
#include "Capitao.h"
#include "Projetil.h"

namespace Fases{

	class Fase_1 : public Fase
	{
	private:

		std::vector<Entidades::Personagens::Capitao*> lista_cap;
		int num_max_Capitoes;
		int i;

	public:

		Fase_1();
		~Fase_1();

		void Executar();
		void Cria_Inimigos();
		void Cria_Inimigos_Capitao();
		Entidades::Projetil* Cria_Projetil();
		void verifica_Projetil_Destroido();

	};
}
