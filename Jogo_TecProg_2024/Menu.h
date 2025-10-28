#pragma once
#include "Ente.h"
#include "Jogo.h"
#include "SFML/Graphics.hpp"

class Jogo;
class Menu : public Ente {
	private:
		int posicaoMenu;
		bool pressionado, selecionado;

		Jogo *pJogo;
		
		sf::RectangleShape *exitMenu;
		sf::Font *fonte;
		//sf::Text *texto;
		sf::Texture *imagem;
		sf::Sprite *bg;
		sf::Vector2i posicaoMouse;
		sf::Vector2f coordMouse;

		std::vector<const char*> opcoes;
		std::vector<sf::Vector2f> coordsOpcoes;
		std::vector<sf::Text> textos;
		std::vector<std::size_t> tam;	


		
				
	public:
		Menu(Jogo *pJogo);
		~Menu();
		void atribuir();
		void Executar();
		void Atualizar();
		void desenhar();
		sf::RenderWindow * getJanelaMenu();
		bool getPressionado();
		void setPressionado(bool valor);
		void setSelecionado(bool valor);
		bool getSelecionado();
		sf::Vector2i getPosicaoMouse();
		void setPosicaoMouse(sf::Vector2i pos);
		sf::Vector2f getCoordsMouse();
		void setCoordsMouse(sf::Vector2f coords);
		void setPosicaoMenu(int pos);
		int getPosicaoMenu();
		std::vector<sf::Text>* getTextos();
		bool setFase_1(bool valor);
		bool getFase_1();
		Jogo* get_pJogo(); 
};
