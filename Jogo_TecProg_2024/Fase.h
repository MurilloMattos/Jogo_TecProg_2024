#pragma once
#include "Ente.h"
#include "Lista_Entidades.h"
#include "Plataforma.h"
#include "Inimigo_Medio.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include <List>

namespace Fases {
	class Fase : public Ente
	{
		protected:

			//tem como a lista_Entidades passar parametros a classe que não necessáriamente entidades?
			bool ganhou;
			Listas::Lista_Entidades lista_Entidades;
			Entidades::Obstaculos::Plataforma* piso;
			Entidades::Obstaculos::Plataforma* plataforma;
			Gerenciadores::Gerenciador_colisoes gerenciador_colisoes;
			std::list<int> lista_id_inimigos;
			

			sf::Vector2f tam_Piso_Fase;
			sf::Vector2f pos_Piso;

			int num_plataformas;

			sf::Vector2f tam_plataforma;

			sf::Vector2f pos_original;


		public:
			Fase();
			~Fase();

			void Setar_Jogadores(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			void Setar_Jogadores_Colisoes(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			void Setar_Jogadores_Inimigos(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);


			virtual void Executar();
			virtual void Cria_Piso();
			virtual void Cria_Plataforma();
			virtual void Cria_Inimigos_Piratas();

			bool get_Ganhou();

			virtual void Cria_Inimigos();
			void verifica_Inimigos_Neutralizados();

	};
}