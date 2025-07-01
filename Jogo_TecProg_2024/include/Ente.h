#pragma once
#include <cstring>
#include "Gerenciador_Grafico.h"


class Ente
{
	protected:
		int id;
		static int id_contador;

		//acesso a biblioteca graf (eveitar includes redundantes)
		static  Gerenciadores::Gerenciador_Grafico* pGG;

		//todo Ente possu� uma figura retangular
		//sf::RectangleShape* pFigura;
		sf::Sprite *pFigura;
		sf::Texture *figura;

		char file[50];

	public:
		Ente();

		~Ente();
		virtual void Executar() = 0;
		void Desenhar();
		void desenhar();
		
		//todo ente deve ter um id distinto
		void setId(int semente);
		int getId() const;
		static void setpGG(Gerenciadores::Gerenciador_Grafico *G);
		static Gerenciadores::Gerenciador_Grafico * getpGG();
		sf::Sprite *getFigura();
		void setFile(const char* f);
		const char* getFile() const;
		void atribuirFigura();
		sf::Vector2f get_Centro();
		sf::Texture* get_Textura(); 
	
};
