#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
//#include "Ente.h"
class Menu;
class Jogo;
class Ente;
namespace Gerenciadores
{
	//singleton, só existe UM gerenciador grafico, em resumo, serve para que tenha apenas uma janela executável do jogo
	class Gerenciador_Grafico
	{
		private:
			static Gerenciador_Grafico* GenGraf;
			sf::RenderWindow *j;
			Gerenciador_Grafico();

		public:

			~Gerenciador_Grafico();

			static Gerenciador_Grafico* getInstance() {
				if (GenGraf == NULL) {
					GenGraf = new Gerenciador_Grafico();
				}
				return GenGraf;
			}
			sf::RenderWindow* criaJanela(const char *name, int xx, int yy);	
			void loopEventos(Menu *m);
			void executar(Menu *m);
			void setJanela(sf::RenderWindow *janela);
			sf::RenderWindow *getJanela();
			//talvez?
			void desenharEnte(Ente *pE);

	};
}

