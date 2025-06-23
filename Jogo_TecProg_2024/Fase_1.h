#pragma once
#include "Fase.h"
#include "Capitao.h"

namespace Fases{

	class Fase_1 : public Fase
	{
	private:

		const int maxChefoes;

	public:

		Fase_1();
		~Fase_1();


		void Cria_Obstaculos();
		void Executar();
		void Cria_Inimigos();
		void Cria_Inimigos_Capitao();

	};
}
