#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;

Gerenciador_Grafico* Gerenciador_Grafico::GenGraf = NULL;

Gerenciador_Grafico::Gerenciador_Grafico(){
	janela = new sf::RenderWindow(sf::VideoMode(500,500),"Jogo");
	evento = new sf::Event();
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
	delete janela;
	delete evento;
}

sf::RenderWindow* Gerenciador_Grafico::getJanela(){
	return janela;
}

sf::Event* Gerenciador_Grafico::getEvent() const {
	return evento;
}
