#include "Ente.h"

Ente::Ente()
{
	pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

	id_contador++;

	id = id_contador;
	pFigura = new sf::RectangleShape;
}

Ente::~Ente(){

	id_contador--;
	delete pFigura;
}

void Ente::Desenhar() { 
	pGG->getJanela()->draw(*pFigura); 
}

void Ente::setId(int semente) {
	id += semente;
}

int Ente::getId() const {
	return id;
}

/*
sf::RectangleShape* Ente::getFigura() {
	return pFigura;
}
*/

int Ente::id_contador = 0;