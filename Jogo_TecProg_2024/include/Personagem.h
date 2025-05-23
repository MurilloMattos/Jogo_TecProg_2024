#pragma once
#include "Entidade.h"

namespace Entidades {

	namespace Personagens {

		class Personagem : public Entidade
		{
		protected:
			int num_vitalidade;
			float velocidade;

		public:
			Personagem();
			~Personagem();

			void setar_Vitalidade(int vida);
			void diminuir_Vitalidade(int dano);

			virtual void Salvar() = 0;
			virtual void Executar() = 0;
		};
	}
}
