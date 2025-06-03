#pragma once
#include "Ente.h"
#include "SFML/Graphics.hpp"
class Jogo;
class Menu : public Ente {
	private:
		Jogo *pJog;
		sf::RenderWindow *menu;
		sf::RectangleShape *exitMenu;
		sf::Font *fonte;
		//sf::Text *texto;
		sf::Vector2i posicaoMouse;
		sf::Vector2f coordMouse;
		int posicaoMenu;
		bool pressionado, selecionado;

		std::vector<const char*> opcoes;
		std::vector<sf::Vector2f> coords;
		std::vector<sf::Text> textos;
		std::vector<std::size_t> tam;	


		
				
	public:
		Menu();
		~Menu();
		void atribuir();
		void Executar();
		void executar();
		void atualizar();
		sf::RenderWindow * getJanelaMenu();
		void set_pJog(Jogo *pJ);
		Jogo* get_pJog(); 
};
