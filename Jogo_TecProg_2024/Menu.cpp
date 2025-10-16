#include "Jogo.h"
#include "Menu.h"
Menu::Menu():Ente(), posicaoMenu(0) {
	pJog = NULL;
	//menu = pGG->criaJanela("Menu", 500, 500);
	exitMenu = new sf::RectangleShape();
 	fonte = new sf::Font();
	//pFigura bg = new sf::Sprite();
	figura = new sf::Texture();
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

	// DENTRO DE Menu::atribuir()

	std::cout << "--- Iniciando o carregamento de assets do Menu ---" << std::endl;

	// ---- VERIFICANDO A FONTE ----
	if (fonte->loadFromFile("./assets/tropifonte.ttf")) {
		std::cout << "[SUCESSO] Fonte 'tropifonte.ttf' carregada." << std::endl;
	} else {
		std::cout << "[ERRO FATAL] Nao foi possivel encontrar ou carregar a fonte './assets/tropifonte.ttf'" << std::endl;
	}

	// ---- VERIFICANDO A IMAGEM ----
	if (figura->loadFromFile("./assets/menu.jpg")) { // <--- CONFIRME SE O NOME É .jpg ou .png
		std::cout << "[SUCESSO] Imagem 'menu.jpg' carregada." << std::endl;
		pFigura->setTexture(figura);
	}
	else {
		std::cout << "[ERRO FATAL] Nao foi possivel encontrar ou carregar a imagem './assets/menu.jpg'" << std::endl;
    // Se a imagem não carregar, vamos pelo menos pintar o fundo de uma cor para ver algo.
    pFigura->setFillColor(sf::Color::Magenta); // Magenta é uma cor feia que chama a atenção
    pFigura->setSize(sf::Vector2f(800.0f, 600.0f));
	}

	std::cout << "--- Fim do carregamento de assets ---" << std::endl;

	// O resto do código (configuração de textos, etc.) continua aqui...

	pFigura->setScale(0.7680f, 0.500f);
	pFigura->setPosition(290.0f,140.0f);
	
	opcoes = {"Menu","Continuar","Fases","Salvar jogada","Rank","Salvar pontuacao"};
	coords = {{600,150},{520, 240},{520, 318},{520, 396},{520, 474},{520,552} };
	tam = {44, 20,20,20,20,20};
	textos.resize(6);
        for(size_t i = 0; i < textos.size(); i++) {
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize(static_cast<unsigned int>(tam[i]));
		//textos[i].setOutlineColor(sf::Color::Red);
	
		textos[i].setPosition(coords[i]);
	}
}
void Menu::Executar() {
	sf::Event evento;
	while(pGG->getJanela()->pollEvent(evento)){ //enquanto houver eventos
		if(evento.type == sf::Event::Closed){//se o evento for fechar a janela
			pGG->getJanela()->close();
		}

		if(evento.type == sf::Event::MouseMoved){//se o evento for mover o mouse
			//ver depois
		}

		if(evento.type == sf::Event::MouseButtonPressed){//se o evento for pressionar o botão do mouse
			//ver depois
		}
	}

	sf::Vector2f mouse_pos = pGG->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGG->getJanela()));//pega a posição do mouse na janela

	//laco para verificar cada texto do menu
	for(int i = 0; i < textos.size(); i++) {
		if(textos[i].getGlobalBounds().contains(mouse_pos)) {//se o mouse estiver sobre o texto
			textos[i].setFillColor(sf::Color::Red);//muda a cor do texto para vermelho
			posicaoMenu = i;
			selecionado = true;
			if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {//se o botão esquerdo do mouse estiver pressionado
				pressionado = true;
				//std::cout << "opcao " << i << " selecionada" << std::endl;
			}
		}
		else{
			textos[i].setFillColor(sf::Color::White);//muda a cor do texto para branco
			if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				pressionado = false;
				selecionado = false;	
			}			
		}
	}
	desenhar();
}
void Menu::desenhar() {//desenha o menu
	pGG->getJanela()->draw(*pFigura);//desenha o fundo do menu
	for (size_t i = 0; i < textos.size(); i++) {//desenha cada texto do menu
        pGG->getJanela()->draw(textos[i]);
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
