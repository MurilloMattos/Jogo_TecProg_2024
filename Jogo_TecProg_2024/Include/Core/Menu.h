#pragma once
#include "Entidades/Ente.h"
#include "Core/Jogo.h"
#include "SFML/Graphics.hpp"

class Jogo;
class Menu : public Ente {

	private:

		enum class Selecao { ESCOLHE_JOGADOR, ESCOLHE_FASE };

		Selecao selecaoAtual;
		int posicaoMenu;
		bool pressionado, selecionado;
		bool fase_1_selecionado;
		bool fase_2_selecionado;
		bool jogador_2_selecionado;

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
		void Inicializar();
		void Executar();
		void EscolheJogador();
		void EscolheFase();
		void desenhar();
		sf::Vector2i getPosicaoMouse();
		void setPosicaoMouse(sf::Vector2i pos);
		sf::Vector2f getCoordsMouse();
		void setCoordsMouse(sf::Vector2f coords);
		void setPosicaoMenu(int pos);
		int getPosicaoMenu();
		bool getJogador2Selecionado();
		bool getFase1Selecionado();
		bool getFase2Selecionado();
		std::vector<sf::Text>* getTextos();
		Jogo* get_pJogo(); 
};
