#pragma once
#include "Ente.h"
#include "Lista_Entidades.h"
#include "Piso.h"
#include "Inimigo_Medio.h"
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

			Entidades::Obstaculos::Piso* piso;
			Entidades::Obstaculos::Piso* plataforma;
			


			sf::Vector2f tam_Piso_Fase;
			sf::Vector2f pos_Piso;

			int num_plataformas;

			sf::Vector2f tam_plataforma;

			sf::Vector2f pos_original;


		public:
			Fase();
			~Fase();

			/*
			//int get_Num_Plataformas();
			Gerenciadores::Gerenciador_colisoes* get_Gerenciador_Colisoes();
			Listas::Lista_Entidades* get_Lista_Entidades();
			*/


			void Setar_Jogadores_Colisoes(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			virtual void Executar();

			//piso � inerente as fases e a plataforma � obst�culo nas 2 fases.
			void Cria_Piso();
			void Cria_Plataforma();

			//inimigos f�ceis
			void Cria_Inimigos_Piratas();
			//void Cria_Inimigos_Capitao();

			bool get_Ganhou();

			virtual void Cria_Inimigos() = 0;
			virtual void Cria_Obstaculos() = 0;
			void criar_cenario();
			void verifica_Inimigos_Neutralizados();

			//void executa_Colisoes();

	};
}