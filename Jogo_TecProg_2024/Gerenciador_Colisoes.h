#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include <iostream>
#include <vector>
#include <list>


namespace Gerenciadores {
	class Gerenciador_colisoes
	{
	private:
		std::vector<Entidades::Personagens::Inimigo*> lista_Inimigos;
		std::list<Entidades::Obstaculos::Obstaculo*> lista_Obstaculos;
		Entidades::Personagens::Jogador* pJogador1;
		Entidades::Personagens::Jogador* pJogador2;

		// contador setado, pra evitar ser criado varias vezes durante a execuçao do programa.
		bool cima, baixo, esquerda, direita;

	public:

		Gerenciador_colisoes();
		~Gerenciador_colisoes();

		void Incluir_Obstaculo(Entidades::Obstaculos::Obstaculo* p_Obstaculo);
		void Incluir_Inimigo(Entidades::Personagens::Inimigo* p_Inimigo);
		void Incluir_Projetil(Entidades::Projetil* p_Projetil);
		void Setar_Jogador(Entidades::Personagens::Jogador* p_Jogador1, Entidades::Personagens::Jogador* p_Jogador2);

		void tratar_Fisica_Jogadores();
		void tratar_Fisica_Obstaculos();
		void tratar_Fisica_Inimigos();

		void tratar_Colisoes_Inimigos();
		void tratar_Colisoes_Obstaculo();
		void tratar_Colisoes_Jogador_Obstaculo();

		const bool mesma_Altura_Para_Colisao(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);
		const bool verifica_Colisao_Cima(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2 );
		const bool verifica_Colisao_Esquerda(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);
		const bool verifica_Colisao_Baixo(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);
		const bool verifica_Colisao_Direita(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2);

		void Executar();


	};
}

