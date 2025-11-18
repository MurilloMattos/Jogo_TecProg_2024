#pragma once

#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Fase_1.h"
#include "Fase_2.h"

class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* Ger_Graf;

		Entidades::Personagens::Jogador jogador_1;
		Entidades::Personagens::Jogador jogador_2;

		//Fases::Fase_1 fase1;
		Fases::Fase_2 fase2;

		bool fase_1_ativa;
		bool fase_2_ativa;
		

	public:
		Jogo();
		~Jogo();

		void Executar();

		void setar_Fase();
		void atualiza_Camera();
		void Atualiza();

};