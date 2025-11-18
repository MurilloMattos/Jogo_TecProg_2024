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
	virtual ~Ente();
	virtual void Executar() = 0;
	void Desenhar();
	void setId(int semente);
	int getId() const;
	void operator++();
	void operator--();

};
