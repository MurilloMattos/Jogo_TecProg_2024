#pragma once
#include "Entidades/Obstaculos/Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo
		{
		private:
			sf::Vector2f tamanho;

		public:

			Plataforma();
			~Plataforma();

			void seta_Plataforma(float alt, float larg, float origem_x, float origem_y);
			void Executar();
			void obstacular(Entidades::Personagens::Jogador* p);
			void Salvar();

		};
	}
}
