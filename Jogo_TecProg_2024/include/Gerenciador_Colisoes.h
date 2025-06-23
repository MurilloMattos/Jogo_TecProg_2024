#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include <iostream>
#include <vector>
#include <list>
#include <set>


namespace Gerenciadores {
	class Gerenciador_colisoes
	{
	private:
		std::vector<Entidades::Personagens::Inimigo*> lista_Inimigos;
		std::list<Entidades::Obstaculos::Obstaculo*> lista_Obstaculos;
		std::set<Entidades::Projetil*> lista_Projeteis;
		Entidades::Personagens::Jogador* pJogador1;
		Entidades::Personagens::Jogador* pJogador2;

		float empurrao;
		//sf::Time 

		// contador setado, pra evitar ser criado varias vezes durante a execuçao do programa.
		const int cima, baixo, esquerda, direita;

	public:

		Gerenciador_colisoes();
		~Gerenciador_colisoes();

		void Incluir_Obstaculo(Entidades::Obstaculos::Obstaculo* p_Obstaculo);
		void Incluir_Inimigo(Entidades::Personagens::Inimigo* p_Inimigo);
		void Incluir_Projetil(Entidades::Projetil* p_Projetil);
		void Setar_Jogador(Entidades::Personagens::Jogador* p_Jogador1, Entidades::Personagens::Jogador* p_Jogador2);

		Entidades::Entidade* projetil_Destruido();
		Entidades::Entidade* Inimigo_neutralizado();
		bool verifica_Lista_Inimigos_Vazia();

		void tratar_Fisica_Jogadores();
		void tratar_Fisica_Obstaculos();
		void tratar_Fisica_Inimigos();
		void tratar_Fisica_Projeteis();

		void tratar_Colisoes_Inimigos();
		void tratar_Colisoes_Obstaculo(Entidades::Entidade* pEntidadeRef);
		void tratar_Colisoes_Projeteis();
		void tratar_Colisoes_Jogador_Inimigos(Entidades::Personagens::Jogador* p_Jogador, Entidades::Personagens::Inimigo* pInimigo);
		void tratar_Colisoes_Jogador_Obstaculo(Entidades::Personagens::Jogador* p_Jogador);
		bool tratar_Colisoes_Jogador_Projeteis(Entidades::Personagens::Jogador* p_Jogador);

		const int verifica_Tipo_De_Colisao(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);
		const bool verifica_Mesma_Pos(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);
		const bool verifica_Colisao_Cima(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2 );
		const bool verifica_Colisao_Esquerda(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);
		const bool verifica_Colisao_Baixo(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);
		const bool verifica_Colisao_Direita(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);

		void Executar();
		Entidades::Personagens::Jogador* get_Jogador1();
		Entidades::Personagens::Jogador* get_Jogador2();

	};
}

