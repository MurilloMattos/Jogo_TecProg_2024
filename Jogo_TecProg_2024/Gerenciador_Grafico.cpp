#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;

Gerenciador_Grafico* Gerenciador_Grafico::GenGraf = NULL;

Gerenciador_Grafico::Gerenciador_Grafico(){

	janela = new sf::RenderWindow(sf::VideoMode(1024,1024),"Jogo");
	evento = new sf::Event();
	camera = new sf::View();

	//camera->setSize(700.f, 700.f);
	//janela->setView(*camera);
	//
	camera->setSize(static_cast<float>(janela->getSize().x), static_cast<float>(janela->getSize().y));
}

Gerenciador_Grafico::~Gerenciador_Grafico(){
	delete janela;
	delete evento;
	delete camera;
}

sf::RenderWindow* Gerenciador_Grafico::getJanela(){
	return janela;
}

sf::Event* Gerenciador_Grafico::getEvent() const {
	return evento;
}

sf::View* Gerenciador_Grafico::getCamera() const {
	return camera;
}