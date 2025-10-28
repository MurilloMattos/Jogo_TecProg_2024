#pragma once
#include "Fase.h"

namespace Fases {
	class Fase_2 : public Fase
	{
		private:
			const int max_inimigos_medios;

		public:

			Fase_2();
			~Fase_2();


			void cria_Obstaculos_Dificeis();
			void cria_Inimigos_Medios();
			void Executar();
			void Criar_Inimigos();
			void Criar_Obstaculos();
	};

}