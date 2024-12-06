#pragma once

#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Fase.h"

class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* Ger_Graf;
		Entidades::Personagens::Jogador jogador_1;
		Fases::Fase fase1;

	public:
		Jogo();
		~Jogo();
		void Executar();
		void Atualiza_cam();
		void Atualiza();

};