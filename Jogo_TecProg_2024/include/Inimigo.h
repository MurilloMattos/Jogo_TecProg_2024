#pragma once
#include "Personagem.h"

namespace Entidades {
	namespace Personagens {

		class Inimigo : public Personagem
		{
			protected:
				int nivel_raiva;
				int dano;

			public:
				Inimigo();
				~Inimigo();

				virtual void Salvar() = 0;
				//virtual void Danificiar() = 0;
				virtual void Executar() = 0;

		};
	}
}
