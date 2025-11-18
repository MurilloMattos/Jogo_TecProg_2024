#include "Ente.h"

Ente::Ente()
{
	pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

	operator++();

	id = id_contador;
	pFigura = new sf::RectangleShape;
}

Ente::~Ente(){

	operator--();
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

void Ente::operator++() {
	id_contador++;
}

void Ente::operator--() {
	id_contador--;
}

int Ente::id_contador = 0;