#pragma once

#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;

class Ente
{
	protected:
		int id;

		//acesso a biblioteca graf (eveitar includes redundantes)
		Gerenciador_Grafico* pGG;

		//todo Ente possu� uma figura retangular
		sf::RectangleShape* pFigura;

	public:
		Ente() {
			pGG = Gerenciador_Grafico::getInstance();

			id = NULL;
			pFigura = new sf::RectangleShape;

		}

		~Ente() { delete pFigura; }

		//virtual void executar() = 0;
		virtual void Executar(){}
		void Desenhar() { pGG->getJanela()->draw(*pFigura); }
		
		//todo ente deve ter um id distinto
		void setId(int semente) { id = semente; }
		int getId() const { return id; }


};