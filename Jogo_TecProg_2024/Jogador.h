#pragma once
#include "Personagem.h"

namespace Entidades{
	namespace Personagens {


		class Jogador : public Personagem
		{
			private:
				int pontos;
				bool segundo_jogador;
				void setar_Figura();

			public:
				Jogador();
				~Jogador();

				void setar_Dois_Jogadores(bool jogador_dois);


				void Executar();
				void Salvar();
		};
	}
}

