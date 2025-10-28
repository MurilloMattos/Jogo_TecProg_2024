#pragma once

#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Fase_1.h"
#include "Fase_2.h"
#include "Menu.h"

enum class Estado { MENU, FASE_1 };

class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* Ger_Graf;

		Entidades::Personagens::Jogador jogador_1;
		Entidades::Personagens::Jogador jogador_2;
		Menu *menu;
		Estado estado;

		Fases::Fase_1 fase1;
		Fases::Fase_2 fase2;

		bool fase_1_ativa;
		bool fase_2_ativa;
		

	public:
		Jogo();
		~Jogo();

		void Executar();

		void setEstado(Estado novoEstado);
		Estado getEstado() const;
		void set_pJog2_Dois_Jogadores(bool valor);
		bool get_pJog2_Dois_Jogadores() const;
		void setar_Fase();
		void atualiza_Camera();
		void Atualiza();

};