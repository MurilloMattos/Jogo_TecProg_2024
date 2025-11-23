#pragma once
#include "Entidades/Personagens/Personagem.h"
#include "Entidades/Personagens/Jogador.h"

namespace Entidades {
	namespace Personagens {

		class Inimigo : public Personagem
		{
			protected:
				int nivel_maldade;
				const int semente_id_entidade;
				Jogador* ponteiro_jogador1;
				Jogador* ponteiro_jogador2;

				int direcao;
				int lado_fraco;


				//int dano

				sf::Vector2f pos_inicial;
				sf::Vector2f pos_final;

			public:
				Inimigo();
				~Inimigo();

				void setar_Jogador_No_Inimigo(Entidades::Personagens::Jogador* pJogador1, Entidades::Personagens::Jogador* pJogador2);
				void setar_direcao();

				virtual void andar_ate(float em_x, float em_y);
				virtual void Salvar() = 0;

				virtual void Executar();
				virtual void verifica_Acao_de_Colisao(int lado, Entidades::Personagens::Jogador* pJogador);
				
		};
	}
}
