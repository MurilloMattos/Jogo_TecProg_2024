#pragma once
#include "Fase.h"
#include "Obstaculo_Esteira.h"
#include "Capitao.h"
#include "Projetil.h"

namespace Fases{

	class Fase_2 : public Fase
	{
	private:
		int num_max_Capitoes;
		int i,j;

		Entidades::Obstaculos::Esteira* esteira;

		std::vector<Entidades::Personagens::Inimigo_Capitao*> lista_cap;

	public:

		Fase_2();
		~Fase_2();


		void Cria_Obstaculos();
		void Cria_Esteira();
		void Cria_Inimigos();
		void Cria_Capitao(float x, float y);
		void Executar();
		Entidades::Projetil* Cria_Projetil();
		void verifica_Projeteis_Destroidos();

	};
}