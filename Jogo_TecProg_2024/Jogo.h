#pragma once

#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Fase_1.h"
#include "Menu.h"

enum class Estado { MENU, FASE_1 };

class Jogo
{
	private:
		Gerenciadores::Gerenciador_Grafico* GG;
		Entidades::Personagens::Jogador pJog1;
		Entidades::Personagens::Jogador pJog2;
		Fases::Fase_1 fase1;
		//sf::Clock tempo_principal;
		Menu *menu;
       // estado do jogo: inicia no menu e pode mudar para JOGANDO
       	Estado estado;

	public:
		Jogo();
		~Jogo();
		void setEstado(Estado novoEstado);
		Estado getEstado() const;
		void set_pJog2_Dois_Jogadores(bool valor);
		void Executar();
		void atualiza_Camera();
		void Atualiza();
};