#pragma once

#include "Fases/Fase.h"
#include "Entidades/Obstaculos/Esteira.h"
#include "Entidades/Personagens/Inimigos/Capitao.h"
#include "Entidades/Projetil.h"

namespace Fases{

	class Fase_2 : public Fase
	{
	private:
		int num_capitoes;
		int num_piratas;
		int num_restante_piratas;
		int num_restante_capitoes;

		int i,j;

		float zoom_camera;
		float tamanho_da_tela_x;

		int num_max_andares;
		float espaco_vazio_x;
		int num_max_plataformas;

		std::vector<int> num_plataformas_por_andar;

		std::vector<Entidades::Personagens::Capitao*> lista_cap;

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
		virtual void cria_Inimigos_Nas_Plataformas(float ponta_esq_plataforma, float ponta_dir_plataforma, sf::Vector2f pos_plat);

	};
}