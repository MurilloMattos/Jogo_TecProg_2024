#pragma once

#include "Gerenciador_Grafico.h"


class Ente
{
	protected:
		int id;

		//acesso a biblioteca graf (eveitar includes redundantes)
		Gerenciadores::Gerenciador_Grafico* pGG;

		//todo Ente possu� uma figura retangular
		//sf::RectangleShape* pFigura;
		sf::Sprite *pFigura;
		sf::Texture *figura;

	public:
		Ente();

		~Ente();
		virtual void Executar() = 0;
		void Desenhar();
		void desenhar();
		
		//todo ente deve ter um id distinto
		void setId(int semente);
		int getId() const;
		void setpGG(Gerenciadores::Gerenciador_Grafico *G);
		sf::Sprite *getFigura();

};
