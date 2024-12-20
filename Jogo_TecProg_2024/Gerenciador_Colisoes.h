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

		// contador setado, pra evitar ser criado varias vezes durante a execu�ao do programa.
		int i;

	public:
		void Incluir_Obstaculo(Entidades::Obstaculos::Obstaculo* p_Obstaculo);
		void Incluir_Inimigo(Entidades::Personagens::Inimigo* p_Inimigo);
		void Incluir_Projetil(Entidades::Projetil* p_Projetil);
		void Setar_Jogador(Entidades::Personagens::Jogador* p_Jogador1, Entidades::Personagens::Jogador* p_Jogador2);


		void Tratar_Colisoes_Inimigos();
		void Tratar_Colisoes_Obstaculo();
		void Tratar_Colisoes_Jogadores();

		void Executar();


	};
}

