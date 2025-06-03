#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
//class Jogador;
#include "Fase.h"
//class Fase;
class Jogo
{
	private:
		sf::RenderWindow *janelaJogo;
		Gerenciadores::Gerenciador_Grafico* Ger_Graf;
		Entidades::Personagens::Jogador jogador_1;
		Entidades::Personagens::Jogador jogador_2;
		Fases::Fase fase1;
		Menu *m;
		std::vector<Ente*> entes;
		sf::Event evento;
	public:
		Jogo();
		~Jogo();
		void setJanelaJogo(sf::RenderWindow *j);
		sf::RenderWindow *getJanela();
		void Executar();
		void Atualiza_cam();
		void Atualiza();
		void incluirEntes(Ente *ente);
};
