#pragma once
#include "Ente.h"
#include "Lista_Entidades.h"
#include "Piso.h"
#include "Inimigo_Esmagador.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"

namespace Fases {
	class Fase : public Ente
	{
		protected:

			//tem como a lista_Entidades passar parametros a classe que n�o necess�riamente entidades?
			bool ganhou;
			bool perdeu;
			Listas::Lista_Entidades lista_Entidades;
			Gerenciadores::Gerenciador_colisoes gerenciador_colisoes;

		public:
			Fase();
			~Fase();

			/*
			//int get_Num_Plataformas();
			Gerenciadores::Gerenciador_colisoes* get_Gerenciador_Colisoes();
			Listas::Lista_Entidades* get_Lista_Entidades();
			*/

			void Setar_Jogadores_Colisoes(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			
			bool get_Ganhou();
			
			//virtual void criar_cenario() = 0;
			virtual void Cria_Piso() = 0;
			virtual void Cria_Plataforma() = 0;
			virtual void Cria_Inimigos() = 0;
			void verifica_Inimigos_Neutralizados();
			
			virtual void Executar() = 0;
			//void executa_Colisoes();

	};
};