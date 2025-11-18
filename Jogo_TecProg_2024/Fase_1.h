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
			
			virtual void Executar();
			virtual void Cria_Piso();
			virtual void Cria_Plataforma();
			virtual void Criar_Inimigos();
			virtual void Criar_Obstaculos();
	};

}