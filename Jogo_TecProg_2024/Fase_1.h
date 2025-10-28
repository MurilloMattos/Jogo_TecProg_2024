#pragma once
#include "Fase.h"

namespace Fases {
	class Fase_1 : public Fase
	{
		private:
			const int max_inimigos_medios;

		public:

			Fase_1();
			~Fase_1();

			void cria_Obstaculos_Dificeis();
			void cria_Inimigos_Medios();
			
			void Executar();
			void Cria_Piso();
			void Cria_Plataforma();
			void Cria_Inimigos();
			void Cria_Obstaculos();
	};

}