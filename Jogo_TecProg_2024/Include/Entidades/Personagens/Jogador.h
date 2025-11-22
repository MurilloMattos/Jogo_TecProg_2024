#pragma once
#include "Personagem.h"

namespace Entidades{
	namespace Personagens {


		class Jogador : public Personagem
		{
			private:
				int pontos;
				const int semente_id_entidade;

				bool eliminado;

				bool segundo_jogador;
				void setar_Figura();

				bool estado_pulando;
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
				void setar_Estado(bool estado);

				bool get_Eliminado() const;

				void diminuir_Vitalidade(int dano);
				void danificar(Personagem* pAtacado);

				void Executar();
				void Salvar();
		};
	}
}

