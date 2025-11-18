#pragma once
#include "Entidade.h"

namespace Entidades {

	namespace Personagens {

		class Personagem : public Entidade
		{
		protected:
			int num_vitalidade;
			int dano;

			sf::Vector2f tamanho;

		public:
			Personagem();
			~Personagem();

			void setar_Vitalidade(int vida);
			virtual void diminuir_Vitalidade(int dano);
			int get_Vitalidade();
			int danificar();

			virtual void Salvar() = 0;
			virtual void Executar() = 0;
		};
	}
}
