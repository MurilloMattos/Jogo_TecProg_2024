#include "Ente.h"
Ente::Ente() {
			pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

			id = -1;//id = NULL;
			pFigura = new sf::Sprite;
			figura = new sf::Texture();

}
Ente::~Ente() { delete pFigura; delete figura; }
void Ente::Desenhar() { 
		//
		//pGG->getJanela()->draw(*pFigura);	
		desenhar();
}
void Ente::desenhar() {
			if(pGG == NULL) {
				return;
			}
			pGG->desenharEnte(this);
}
		//todo ente deve ter um id distint
//executar() { pGG->executar(this); }
void Ente::setId(int semente) { id = semente; }
int Ente::getId() const { return id; }
void Ente::setpGG(Gerenciadores::Gerenciador_Grafico *G) {
	if(G) { pGG = G; }
}
//sf::Texture//
sf::Sprite* Ente::getFigura() { //return pFigura;
	return pFigura;
}
