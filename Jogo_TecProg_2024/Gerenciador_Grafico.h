#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

namespace Gerenciadores
{
	//singleton, só existe UM gerenciador grafico, em resumo, serve para que tenha apenas uma janela executável do jogo
	class Gerenciador_Grafico
	{
		private:
			sf::RenderWindow* janela;
			sf::Event* evento;

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

			sf::RenderWindow* getJanela();
			sf::Event* getEvent() const;

			//talvez?
			//void Desenhar();
	};

}

