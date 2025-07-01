#pragma once
#include "Ente.h"
#include "Lista_Entidades.h"
#include "Piso.h"
#include "Inimigo_Medio.h"
//class Inimigo_Medio;
#include "Jogador.h"
//#include "Gerenciador_Colisoes.h"
namespace Gerenciadores {
	class Gerenciador_colisoes;
}
namespace Fases {
	class Fase : public Ente
	{
		protected:

			//tem como a lista_Entidades passar parametros a classe que não necessáriamente entidades?
			bool ganhou;
			Listas::Lista_Entidades lista_Entidades;
			Entidades::Obstaculos::Piso* piso;
			Entidades::Obstaculos::Piso* plataforma;
			Gerenciadores::Gerenciador_colisoes *gerenciador_colisoes;
			sf::Vector2f tam_Piso_Fase;
			sf::Vector2f pos_Piso;

			int num_plataformas;

			sf::Vector2f tam_plataforma;

			sf::Vector2f pos_original;
			//Entidades::Personagens::Inimigo *inimigo;


		public:
			Fase();
			~Fase();

			/*
			//int get_Num_Plataformas();
			Gerenciadores::Gerenciador_colisoes* get_Gerenciador_Colisoes();
			*/
			Listas::Lista_Entidades* get_Lista_Entidades();
			void set_pJog(Jogo *pJ);

			void Setar_Jogadores_Colisoes(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			virtual void Executar();
			void Cria_Piso();
			void Cria_Plataforma();
			void Cria_Inimigos_Piratas();
			//void Cria_Inimigos_Capitao;

			bool get_Ganhou();

			virtual void Cria_Inimigos();
			void verifica_Inimigos_Neutralizados();

			//void executa_Colisões();
			Gerenciadores::Gerenciador_colisoes * get_Gerenciador();
			Listas::Lista_Entidades *get_Lista();
			void associa_Inimigo(Entidades::Personagens::Inimigo *i);
			void Cria_Plataforma_Baixo();
	};
}
