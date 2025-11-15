#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo
		{
		private:
			//int boo;
			//float altura;
			//float largura;

			sf::Vector2f tamanho;

		public:
			float boo;

			Plataforma();
			~Plataforma();

			void seta_Plataforma(float alt, float larg, float origem_x, float origem_y);
			void Executar();
			void obstacular(Entidades::Personagens::Jogador* p);
			void Salvar();

		};
	}
}
