// ...existing code...
#include "Jogo.h"
#include "Menu.h"

// adiciona texturas/sprite estáticos para o menu (vivem pelo tempo do programa)

Menu::Menu():Ente(), posicaoMenu(0) {
    pJog = NULL;
    //menu = pGG->criaJanela("Menu", 500, 500);
    exitMenu = new sf::RectangleShape();
     fonte = new sf::Font();
	menuTexture = nullptr;
	menuSprite = nullptr;
    atribuir();	
}
Menu::~Menu() {
    pJog = NULL;
    //delete menu;
    delete exitMenu;
    delete fonte;
    // não delete menuTexture/menuSprite aqui (são estáticos e podem ser reutilizados)
}
void Menu::atribuir() {	
    
    posicaoMouse = {0,0};
    coordMouse = {0.0, 0.0};	
    posicaoMenu = 0;

    pressionado = selecionado = false;
    fonte->loadFromFile("./assets/tropifonte.ttf");

    // inicializa textura/sprite do menu apenas uma vez
    if (!menuTexture) {
        menuTexture = new sf::Texture();
        if (!menuTexture->loadFromFile("./assets/menu.png")) {
            std::cerr << "Erro ao carregar ./assets/menu.png\n";
        }
        menuSprite = new sf::Sprite();
        menuSprite->setTexture(*menuTexture);
        menuSprite->setScale(0.7680f, 0.500f);
        menuSprite->setPosition(290.f,140.f);
    }

    opcoes = {"Menu","Continuar","Fases","Salvar jogada","Rank","Salvar pontuacao"};
    coords = {{600,150},{520, 240},{520, 318},{520, 396},{520, 474},{520,552} };
    tam = {44, 20,20,20,20,20};
    textos.resize(6);
    for(size_t i = 0; i < textos.size(); i++) {
        textos[i].setFont(*fonte);
        textos[i].setString(opcoes[i]);
        textos[i].setCharacterSize(tam[i]);
        textos[i].setPosition(coords[i]);
    }
}
void Menu::Executar() {
    executar();
}
void Menu::executar() {
    // atualiza estado e prepara desenho do menu
    atualizar();
}
void Menu::atualizar() {
    // atualiza lógica do jogo via ponteiro (se existir)
    if (pJog) pJog->Atualiza();

    // desenha fundo do menu usando o gerenciador gráfico (pGG fornecido por Ente)
    if (menuSprite && pGG && pGG->getJanela()) {
        pGG->getJanela()->draw(*menuSprite);
    }

    // desenha textos do menu na janela do gerenciador gráfico
    for (size_t i = 0; i < textos.size(); ++i) {
        if (pGG && pGG->getJanela()) pGG->getJanela()->draw(textos[i]);
    }
}
// ...existing code continues...
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
