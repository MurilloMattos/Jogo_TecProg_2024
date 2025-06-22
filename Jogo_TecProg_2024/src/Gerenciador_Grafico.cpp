#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include "Jogador.h"
using namespace Gerenciadores;

Gerenciador_Grafico* Gerenciador_Grafico::GenGraf = NULL;

Gerenciador_Grafico::Gerenciador_Grafico() {
	janela = new sf::RenderWindow(sf::VideoMode(500, 500),"Jogo");
        evento = new sf::Event();
        camera = new sf::View();
	cameraDefault = janela->getDefaultView(); 	
        //camera->setSize(700.f, 700.f);
        //janela->setView(*camera);
        //
       camera->setSize(static_cast<float>(janela->getSize().x), static_cast<float>(janela->getSize().y));

}

Gerenciador_Grafico::~Gerenciador_Grafico(){
	//delete janela;
        delete janela;
        delete evento;
        delete camera;
}
sf::RenderWindow* Gerenciador_Grafico::criaJanela(const char *name, int xx, int yy) {
	sf::RenderWindow *w = new sf::RenderWindow();
	w->create(sf::VideoMode(xx,yy), name);
	return w;
}
/*sf::RenderWindow* Gerenciador_Grafico::getJanela(){	
	return janela;
}*/

void Gerenciador_Grafico::setJanela(sf::RenderWindow *j) {
	if(j) { janela = j; } 
}
sf::RenderWindow *Gerenciador_Grafico::getJanela() {
	return janela;
}
sf::Event* Gerenciador_Grafico::getEvent() const {
        return evento;
}

sf::View *Gerenciador_Grafico::getCamera() const {
        return camera;
}
void Gerenciador_Grafico::desenharEnte(Ente *pE) {
				if(pE == NULL) {
					return;
				}
				//logica de desenhar entes 
				//renderiza textura criada
				//renderiza sprite criado
			//renderiza aqui draw(sprite) (textura);
			getJanela()->draw(*(pE->getFigura()));
}
const sf::View Gerenciador_Grafico::getCameraDefault() {
        return cameraDefault;
}				
