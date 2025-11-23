#pragma once

#include "Fases/Fase.h"
#include "Entidades/Obstaculos/Esteira.h"
#include "Entidades/Personagens/Inimigos/Capitao.h"
#include "Entidades/Projetil.h"

namespace Fases{

	class Fase_2 : public Fase
	{
	private:
		int num_max_Capitoes;
		int i,j;
		float zoom_camera;

		std::vector<Entidades::Personagens::Inimigo_Capitao*> lista_cap;

	public:

		Fase_2();
		~Fase_2();
		
		void Cria_Obstaculos();
		void Cria_Inimigos();
		void Cria_Capitao(float x, float y);

		void Executar();
		Entidades::Projetil* Cria_Projetil();
		void verifica_Projeteis_Destroidos();
		void Cria_Plataforma();
		void Cria_Piso();


		void atualiza_Camera_Fase(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
		void setar_Camera_Fase();

	};
}