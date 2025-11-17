#pragma once
#include "Personagem.h"
#include "Jogador.h"

namespace Entidades {
	namespace Personagens {

		class Inimigo : public Personagem
		{
			protected:
				const int semente_id_entidade;
				//int dano;

				sf::Vector2f pos_inicial;
				sf::Vector2f pos_final;

			public:
				Inimigo();
				~Inimigo();

				//void setar_Jogador_No_Inimigo(Entidades::Personagens::Jogador* pJogador1, Entidades::Personagens::Jogador* pJogador2);

				virtual void andar_ate(float em_x, float em_y);
				virtual void Salvar() = 0;
				//virtual void Danificar() = 0;
				virtual void Executar();

		};
	}
}
