#pragma once
#include "Gerenciador_Grafico.h"
#include "Jogador.h"

//class Jogador;
//#include "Fase.h"
//class Fase;

#include "Fase_1.h"
#include "TorreFogo.h"
class Jogo
{
	private:
		
		Gerenciadores::Gerenciador_Grafico* Ger_Graf;
		Entidades::Personagens::Jogador *jogador_1;
		Menu *m;
		std::vector<Ente*>::iterator it;
		std::vector<Ente*> entes;
		//Entidades::Personagens::Jogador jogador_2;
		Fases::Fase_1 *fase1;
		Fases::TorreFogo *t;
		//sf::Clock tempo_principal;
	public:
		Jogo();
		~Jogo();
		sf::RenderWindow *getJanela();
		void Executar();
		void Atualiza_Camera();
		void Atualiza();
		void incluirEntes(Ente *ente);
		Gerenciadores::Gerenciador_Grafico* getGerGraf();
		void percorreEntes();
		Entidades::Personagens::Jogador *getJogador();
		void setJogador(Entidades::Personagens::Jogador* j);
};
