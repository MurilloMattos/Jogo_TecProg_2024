#pragma once

#include "Fases/Fase.h"
#include "Entidades/Obstaculos/Esteira.h"
#include "Entidades/Personagens/Inimigos/Capitao.h"
#include "Entidades/Personagens/Inimigos/Esmagador.h"
#include "Entidades/Projetil.h"

namespace Fases{

	class Fase_1 : public Fase
	{
	private:
	
		int i,j;
		float zoom_camera;
		
		std::vector<Entidades::Obstaculos::Plataforma*> lista_plat;
		
		Entidades::Obstaculos::Esteira* esteira;

	public:

		Fase_1();
		~Fase_1();
			
		void Executar();

		void Cria_Obstaculos();
		void Cria_Inimigos();

		void Cria_Piso();
		void Cria_Plataforma();
		void Cria_Esteira();

		void Cria_Esmagador(float x, float y);

		void atualiza_Camera_Fase(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
		void setar_Camera_Fase();

		Entidades::Projetil* Cria_Projetil();
		void verifica_Projeteis_Destroidos();

	};
}