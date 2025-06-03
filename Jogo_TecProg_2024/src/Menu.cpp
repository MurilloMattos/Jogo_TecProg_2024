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
}
sf::RenderWindow * Menu::getJanelaMenu() {
	return menu;
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
