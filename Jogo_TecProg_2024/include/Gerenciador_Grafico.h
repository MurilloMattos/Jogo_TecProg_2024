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

			sf::RenderWindow* janela;
			sf::Event* evento;
			sf::View *camera;
			sf::View cameraDefault;

			static Gerenciador_Grafico* GenGraf;
		
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

			void setJanela(sf::RenderWindow *j);
			sf::RenderWindow *getJanela();
			sf::Event* getEvent() const;
			sf::View *getCamera() const;

			void desenharEnte(Ente *pE);
			const sf::View getCameraDefault();

	};
}

