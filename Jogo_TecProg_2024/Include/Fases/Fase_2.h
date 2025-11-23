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
		int num_max_andares;
		int i,j;
		float zoom_camera;
		float tamanho_da_tela_x;
		float espaco_vazio_x;
		int num_max_plataformas;

		std::vector<int> num_plataformas_por_andar;

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

		void seta_Tamanho_Plataformas(int n_plataformas);
		void seta_Num_Plataformas();
		void Cria_Plataforma();
		void Cria_Piso();


		void atualiza_Camera_Fase(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
		void setar_Camera_Fase();

	};
}