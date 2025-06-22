#include "Ente.h"
int Ente::id_contador = 0;
Gerenciadores::Gerenciador_Grafico*::Ente::pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
Ente::Ente() {
			//pGG = Gerenciadores::Gerenciador_Grafico::getInstance();
        id_contador++;

	id = id_contador;//id = NULL;

	pFigura = new sf::Sprite;
	figura = new sf::Texture();
}
Ente::~Ente() { delete pFigura; delete figura; id_contador--;}
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
void Ente::setId(int semente) { id += semente; }
int Ente::getId() const { return id; }
void Ente::setpGG(Gerenciadores::Gerenciador_Grafico *G){
	if(G) { pGG = G; }
}
Gerenciadores::Gerenciador_Grafico * Ente::getpGG() {
	return pGG; 
}
//sf::Texture//
sf::Sprite* Ente::getFigura() { //return pFigura;
	return pFigura;
}
void Ente::setFile(const char* f) {
	if(f) { strcpy(file, f); }
}
const char* Ente::getFile() const {
	return file;
}
void Ente::atribuirFigura() {
	figura->loadFromFile(file);	
	pFigura->setTexture(*figura);

	sf::Vector2u tamanhoJanela = pGG->getJanela()->getSize();
	sf::Vector2u tamanhoTextura = figura->getSize();
	
	sf::Image img;
	img.loadFromFile(file);

	unsigned int minX = img.getSize().x, maxX = 0;
	unsigned int minY = img.getSize().y, maxY = 0;

	for (unsigned int x = 0; x < img.getSize().x; ++x) {
    		for (unsigned int y = 0; y < img.getSize().y; ++y) {
        		sf::Color pixel = img.getPixel(x, y);
        			if (pixel.a > 0) {
            				if (x < minX) minX = x;
           				 if (x > maxX) maxX = x;
            				if (y < minY) minY = y;
            				if (y > maxY) maxY = y;
        			 }
    		}
	}

	unsigned int largura = maxX - minX + 1;
	unsigned int altura = maxY - minY + 1;
		
	pFigura->setTextureRect(sf::IntRect(minX, minY, largura, altura));	
	//pFigura->setOrigin(largura/2.0f, altura/2.0f);

	float X = static_cast<float>(tamanhoJanela.x * 0.3f) / (tamanhoTextura.x);
	float Y = static_cast<float>(tamanhoJanela.y * 0.3f) / (tamanhoTextura.y);
	//pFigura->setScale(X,Y);
	//pFigura->setOrigin(largura, altura);
}
sf::Vector2f Ente:: get_Centro()
{
	sf::Vector2f centro;		
	centro.x = pFigura->getPosition().x + (pFigura->getGlobalBounds().width / 2);
	centro.y = pFigura->getPosition().y + (pFigura->getGlobalBounds().height / 2);

	return sf::Vector2f(centro);
}
