#include "Jogo.h"
#include "Menu.h"
Menu::Menu():Ente() {
	pJog = NULL;
	//menu = pGG->criaJanela("Menu", 500, 500);
	exitMenu = new sf::RectangleShape();
 	fonte = new sf::Font();
	//pFigura bg = new sf::Sprite();
	//figura = new sf::Texture();
	atribuir();	
}
Menu::~Menu() {
	pJog = NULL;
	//delete menu;
	delete exitMenu;
	delete fonte;
	//delete pFigura;
	//delete figura;
}
void Menu::atribuir() {	
	
	posicaoMouse = {0,0};
	coordMouse = {0.0, 0.0};	
	posicaoMenu = 0;

	pressionado = selecionado = false;
	fonte->loadFromFile("./assets/tropifonte.ttf");
	figura->loadFromFile("./assets/menu.png");
	pFigura->setScale(0.7680, 0.500);
	pFigura->setTexture(*figura);
	pFigura->setPosition(290,140);
	
	opcoes = {"Menu","Continuar","Fases","Salvar jogada","Rank","Salvar pontuacao"};
	coords = {{600,150},{520, 240},{520, 318},{520, 396},{520, 474},{520,552} };
	tam = {44, 20,20,20,20,20};
	textos.resize(6);
        for(size_t i = 0; i < textos.size(); i++) {
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize(tam[i]);
		//textos[i].setOutlineColor(sf::Color::Red);
		textos[i].setPosition(coords[i]);
	}
}
void Menu::Executar() {
	executar();
}
void Menu::executar() {
//entra, atualiza, renderiza;
pGG->executar(this);
	//pJog->Executar();		
}
void Menu::atualizar() {
	//pJog->Executar();
	pJog->Atualiza();
	for(int i = 0; i < textos.size(); i++) {
		pJog->getJanela()->draw(textos[i]);
	}	
}
sf::RenderWindow * Menu::getJanelaMenu() {
	return menu;
}
bool Menu::getPressionado() {
	return pressionado;
}
void Menu::setPressionado(bool valor) {
	pressionado = valor;
}
void Menu::setSelecionado(bool valor) {
	selecionado = valor;	
}
bool Menu::getSelecionado() {
	return selecionado;
}
sf::Vector2i Menu::getPosicaoMouse() {
	return posicaoMouse;
}
void Menu::setPosicaoMouse(sf::Vector2i pos) {
	posicaoMouse = pos;
}
sf::Vector2f  Menu::getCoordsMouse() {
	return coordMouse;
}
void Menu::setCoordsMouse(sf::Vector2f coords) {
	coordMouse = coords;
}

void Menu::setPosicaoMenu(int pos) {
	posicaoMenu  = pos;
}
int Menu::getPosicaoMenu() {
	return posicaoMenu;
}
std::vector<sf::Text>* Menu::getTextos() {
	return &textos;
}
void Menu::set_pJog(Jogo *pJ) {
	if(pJ) {
		pJog = pJ;
	}else{
	  	std::cout << "tentando acessar ponteiro nullo" << std::endl;
	}	
}
Jogo* Menu::get_pJog() {
return pJog;
}
