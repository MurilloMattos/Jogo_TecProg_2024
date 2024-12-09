#pragma once
#include "Personagem.h"

namespace Entidades{
	namespace Personagens {


		class Jogador : public Personagem
		{
			private:
				int pontos;
				void setar_Figura();

			public:
				Jogador();
				~Jogador();

				void Executar();
				void Salvar();
		};
	}
}

