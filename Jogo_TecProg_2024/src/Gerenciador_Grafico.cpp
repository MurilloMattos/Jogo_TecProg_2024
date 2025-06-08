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

     if(evento.type == sf::Event::KeyPressed) {
	int pos = m->getPosicaoMenu();
	std::vector<sf::Text> *bucket = m->getTextos();
	if((evento.key.code == sf::Keyboard::Down) && !m->getPressionado()) {	
		if(pos < 6) {
			m->setPressionado(true);
			m->setPosicaoMenu(++pos);
			(*bucket)[m->getPosicaoMenu()].setOutlineThickness(4);
			(*bucket)[m->getPosicaoMenu() - 1].setOutlineThickness(0);
			m->setPressionado(false);
			std::cout << "pos: " << m->getPosicaoMenu() << std::endl;

		}

	}
	if((evento.key.code == sf::Keyboard::Up) && !m->getPressionado()) {	
		if(pos >= 0) {
			m->setPressionado(true);
			m->setPosicaoMenu(--pos);
			(*bucket)[m->getPosicaoMenu()].setOutlineThickness(4);
			(*bucket)[m->getPosicaoMenu() + 1].setOutlineThickness(0);
			m->setPressionado(false);
	std::cout << "pos: " << m->getPosicaoMenu() << std::endl;

		}
	}
		if(m->getPosicaoMenu() == -1) { 
			(*bucket)[5].setOutlineThickness(4);
			(*bucket)[0].setOutlineThickness(0);
			m->setPosicaoMenu(5);
 		}
		if(m->getPosicaoMenu() == 6) { 
			(*bucket)[0].setOutlineThickness(4);
			(*bucket)[5].setOutlineThickness(0);
			m->setPosicaoMenu(0);
		}
      }
}
void Gerenciador_Grafico::executar(Menu *m){
		while((getJanela())->isOpen()) {
			loopEventos(m);
			//desenharEnte(pE);
			(getJanela())->clear();
			m->desenhar();
			m->atualizar(); //switch case e atualizar() { m->jogo.atualizar(menu->jogo); }  
			//m->desenhar();
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
