#pragma once

#include "Entidades/Ente.h"
#include "Listas/Lista_Entidades.h"
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Obstaculos/Plataforma.h"
#include "Entidades/Personagens/Inimigos/Inimigo_Pirata.h"
#include "Entidades/Personagens/Jogador.h"
#include "Gerenciadores/Gerenciador_Colisoes.h"
#include <list>

namespace Fases {
	class Fase : public Ente
	{
		protected:

			//tem como a lista_Entidades passar parametros a classe que n�o necess�riamente entidades?
			bool ganhou;
			bool perdeu;
			Listas::Lista_Entidades lista_Entidades;
			Entidades::Obstaculos::Plataforma* piso;
			Entidades::Obstaculos::Plataforma* plataforma;
			Gerenciadores::Gerenciador_colisoes gerenciador_colisoes;
			std::list<int> lista_id_inimigos;
			

			sf::Vector2f tam_Piso_Fase;
			sf::Vector2f pos_Piso;

			int num_plataformas_totais;
			int num_inimigos;

			sf::Vector2f tam_plataforma;

			sf::Vector2f pos_original;


		public:
			Fase();
			virtual ~Fase();

			void Setar_Jogadores(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			void Setar_Jogadores_Colisoes(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			void Setar_Jogadores_Inimigos(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);

			void Cria_Inimigo_Pirata(float x, float y);

			bool get_Ganhou();

			virtual void Executar();
			virtual void Cria_Piso() = 0;
			virtual void Cria_Plataforma() = 0;
			virtual void Cria_Inimigos() = 0;	
			virtual void Cria_Obstaculos() = 0;

			virtual void atualiza_Camera_Fase(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2) = 0;
			virtual void setar_Camera_Fase() = 0;

			void criar_cenario();
			void verifica_Inimigos_Neutralizados();

	};
}