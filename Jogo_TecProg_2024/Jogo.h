#pragma once

#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Fase.h"

class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* Ger_Graf;
		Entidades::Personagens::Jogador jogador_1;
		//Entidades::Personagens::Jogador jogador_2;
		Fases::Fase fase1;

	public:
		Jogo();
		~Jogo();
		void Executar();
		void atualiza_Camera();
		void Atualiza();

};