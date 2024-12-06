#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {
		class Piso : public Entidade
		{
		private:
			//int boo;
			//float altura;
			//float largura;

			sf::Vector2f tamanho;

		public:
			float boo;

			Piso();
			~Piso();

			void seta_Piso(float alt, float larg);
			void Executar();
			void Salvar();

		};
	}
}
