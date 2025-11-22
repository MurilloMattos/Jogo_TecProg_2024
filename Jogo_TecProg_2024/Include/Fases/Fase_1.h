#pragma once

#include "Fases/Fase.h"
#include "Entidades/Obstaculos/Obstaculo_Esteira.h"
#include "Entidades/Personagens/Inimigos/Capitao.h"
#include "Entidades/Projetil.h"

namespace Fases{

	class Fase_1 : public Fase
	{
	private:
		int num_max_Capitoes;
		int i,j;

		std::vector<Entidades::Personagens::Inimigo_Capitao*> lista_cap;

	public:

			void cria_Obstaculos_Dificeis();
			void cria_Inimigos_Medios();
			
			void Executar();
			//void Cria_Piso();
			//void Cria_Plataforma();
			void Cria_Inimigos();
			void Cria_Obstaculos();

	};
}