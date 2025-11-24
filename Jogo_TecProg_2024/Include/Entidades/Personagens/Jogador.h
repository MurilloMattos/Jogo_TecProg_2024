#pragma once
#include "Personagem.h"

namespace Entidades{
	namespace Personagens {


		class Jogador : public Personagem
		{
			private:
				int pontos;
				const int semente_id_entidade;

				bool segundo_jogador;
				void setar_Figura();

				bool estado_pulando;
				bool no_ar;
				bool estado_caindo;

				bool acelerando;
				
				float forca_de_impulso;
				float gravidade;
				//float altura_de_pulo;

				//sf::Clock tempo;

			public:
				Jogador();
				~Jogador();

				void setar_Dois_Jogadores(bool jogador_dois);
				bool get_Dois_Jogadores();
				void executando_Pulo();
				void executar_Gravidade();

				void setar_No_Ar(bool no_meio_do_ar);
				void setar_Estado_Pulando(bool estado_pulando);
				void setar_Caindo(bool caindo);
				void setar_Bateu_A_Cabeca();

				bool get_Eliminado() const;
				int get_Pontuacao() const;

				void diminuir_Vitalidade(int dano);
				void danificar(Personagem* pAtacado);

				void aumentar_Pontuacao(int pontos_a_adicionar);

				void Executar();
				void Salvar();
		};
	}
}

