#pragma once

#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include <iostream>
#include <vector>
#include <list>

//using namespace std;
//using namespace Entidades;
//using namespace Personagens;
//using namespace Obstaculos;

class Gerenciador_colisoes
{
	private:
		std::vector<Entidades::Personagens::Inimigo*> Lista_Inimigos;
		std::list<Entidades::Obstaculos::Obstaculo*> Lista_Obstaculos;
		Entidades::Personagens::Jogador* pJogador1;
		Entidades::Personagens::Jogador* pJogador2;

	public:
		void Incluir_Obstaculo(Entidades::Obstaculos::Obstaculo* p_Obstaculo);
		void Incluir_Inimigo(Entidades::Personagens::Inimigo* p_Inimigo);
		void Incluir_Projetil(Entidades::Projetil* p_Projetil);
		void Setar_Jogador(Entidades::Personagens::Jogador* p_Jogador1, Entidades::Personagens::Jogador* p_Jogador2);


		void Tratar_Colisoes_Inimigos();
		void Tratar_Colisoes_Obstaculo();
		void Tratar_Colisoes_Jogadores();

		void executar();


};

