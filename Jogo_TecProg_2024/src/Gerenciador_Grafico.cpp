#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include "Jogo.h"
#include "Menu.h"
using namespace Gerenciadores;

Gerenciador_Grafico* Gerenciador_Grafico::GenGraf = NULL;

Gerenciador_Grafico::Gerenciador_Grafico() {

}

Gerenciador_Grafico::~Gerenciador_Grafico(){
	//delete janela;
}
sf::RenderWindow* Gerenciador_Grafico::criaJanela(const char *name, int xx, int yy) {
	sf::RenderWindow *w = new sf::RenderWindow();
	w->create(sf::VideoMode(xx,yy), name);
	return w;
}
/*sf::RenderWindow* Gerenciador_Grafico::getJanela(){	
	return janela;
}*/
void Gerenciador_Grafico::loopEventos(Menu *m) {
	sf::Event evento;
	while((getJanela())->pollEvent(evento)) {
		if(evento.type == sf::Event::Closed){
			getJanela()->close();
		}
	}
}
void Gerenciador_Grafico::executar(Menu *m){
		while((getJanela())->isOpen()) {
			loopEventos(m);
			//desenharEnte(pE);
			(getJanela())->clear();
			m->atualizar(); //switch case e atualizar() { m->jogo.atualizar(menu->jogo); }  
			m->desenhar();
			getJanela()->display();

		}
}
void Gerenciador_Grafico::setJanela(sf::RenderWindow *janela) {
	if(janela) { j = janela; } 
}
sf::RenderWindow *Gerenciador_Grafico::getJanela() {
	return j;
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
