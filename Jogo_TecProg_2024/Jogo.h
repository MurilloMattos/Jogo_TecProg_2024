#pragma once

#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Fase_1.h"

enum class EstadoJogo{
	MENU_PRINCIPAL,
	JOGANDO,
	PAUSADO,
	FIM_DE_JOGO
};
class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* Ger_Graf;
		Entidades::Personagens::Jogador jogador_1;
		Entidades::Personagens::Jogador jogador_2;
		Fases::Fase_1 fase1;
		//sf::Clock tempo_principal;
		EstadoJogo estado_atual;

	public:
		Jogo();
		~Jogo();
		void Executar();
		void atualiza_Camera();
		void Atualiza();

};