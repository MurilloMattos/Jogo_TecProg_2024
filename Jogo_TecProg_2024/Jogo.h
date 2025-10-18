#pragma once

#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Fase.h"
#include "Fase_1.h"
#include "Menu.h"

enum class EstadoJogo{
	MENU_PRINCIPAL,
	JOGANDO,
	PAUSADO,
	FIM_DE_JOGO
};
class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* pGer_Graf;
		Entidades::Personagens::Jogador pJog1;
		Entidades::Personagens::Jogador pJog2;
		Fases::Fase_1* pFase1;
		//sf::Clock tempo_principal;
		EstadoJogo estado_atual;
		Menu* pMenu;
		Fases::Fase* pFase_Atual;

	public:
		Jogo();
		~Jogo();
		void Executar();
		void atualiza_Camera();
		void Atualiza();

};