#pragma once

#include "Gerenciador_Grafico.h"


class Ente
{
protected:
	int id;
	static int id_contador;

	//acesso a biblioteca graf (eveitar includes redundantes)
	Gerenciadores::Gerenciador_Grafico* pGG;

	//todo Ente possuí uma figura retangular
	sf::RectangleShape* pFigura;

public:

	Ente();
	~Ente();
	virtual void Executar() = 0;
	void Desenhar();

	//virtual void set_Id_Contador() = 0;
	//todo ente deve ter um id distinto
	void setId(int semente);
	int getId() const;
	//sf::RectangleShape* getFigura();

	//sf::RectangleShape* getFigura() { return pFigura; };
	/*
	Ente() {
		pGG = Gerenciadores::Gerenciador_Grafico::getInstance();

		id_contador++;

		id = NULL;
		pFigura = new sf::RectangleShape;

	}

	~Ente() { delete pFigura; }

	virtual void Executar(){}
	void Desenhar() { pGG->getJanela()->draw(*pFigura); }

	//virtual void set_Id_Contador() = 0;
	//todo ente deve ter um id distinto
	void setId(int semente) { id = semente; }
	int getId() const { return id; }

	//sf::RectangleShape* getFigura() { return pFigura; };
	*/

};

//int Ente::id_contador = 0;