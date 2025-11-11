#include "Jogo.h"
#include "Menu.h"

Menu::Menu(Jogo *pJogo):Ente(){
	posOpcao = -1;
	//menu = pGG->getJanela("Menu", 500, 500);
	exitMenu = new sf::RectangleShape();
 	fonte = new sf::Font();
	bg = new sf::Sprite();
	imagem = new sf::Texture();
	atribuir();	
}
Menu::~Menu() {
	pJogo = NULL;
	delete exitMenu;
	delete fonte;
	//delete pFigura;
	delete imagem;
}
void Menu::atribuir() {	
	
	posicaoMouse = {0,0};
	coordMouse = {0.0, 0.0};	
	posicaoMenu = 0;

	pressionado = selecionado = false;

	if (fonte->loadFromFile("./assets/Jersey25-Regular.ttf")) {
		std::cout << "[SUCESSO] Fonte 'Jersey25-Regular.ttf' carregada." << std::endl;
	}	
	else {
		std::cout << "[ERRO FATAL] Nao foi possivel encontrar ou carregar a fonte 'assets/Jersey25-Regular.ttf'" << std::endl;
	}	
	
	if (imagem->loadFromFile("./assets/menuPrincipal.png")) { 
		std::cout << "[SUCESSO] Imagem 'menuPrincipal.png' carregada." << std::endl;
		bg->setTexture(*imagem);
	}
	else {
		std::cout << "[ERRO FATAL] Nao foi possivel encontrar ou carregar a imagem 'assets/menuPrincipal.png'" << std::endl;
		// sf::Sprite não possui setFillColor/setSize — use setColor e setScale como fallback.
		bg->setColor(sf::Color::Magenta); // Magenta é uma cor feia que chama a atenção
		// Sem textura, setScale não define um tamanho absoluto; manter escala padrão como fallback.
		bg->setScale(1.0f, 1.0f);
	}
		

	pFigura->setScale(500.0f, 500.0f);//tamanho do menu na janela
	pFigura->setPosition(290.0f,140.0f);//posicao do menu na janela
	
	opcoes = {"Joguinho", "Jogar", "Configurações", "Sair"};
	coords = {{200,100},{200, 250},{200, 300},{200, 350}};
	tam = {44, 20,20,20};
	textos.resize(4);
    for(std::size_t i{}; i < textos.size(); i++) {
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize((tam[i]));
		textos[i].setOutlineColor(sf::Color::Red);
		textos[i].setPosition(coords[i]);
	}	
}	
void Menu::Executar() {
	Atualizar();
	desenhar();
}	
void Menu::Atualizar() {
	sf::Event evento;
	while(pGG->getJanela()->pollEvent(evento)){ //enquanto houver eventos
		if(evento.type == sf::Event::Closed){//se o evento for fechar a janela
			pGG->getJanela()->close();
		}	

		if(evento.type == sf::Event::MouseMoved){//se o evento for mover o mouse
			posicaoMouse = sf::Mouse::getPosition(*pGG->getJanela());//pega a posicao do mouse na janela
			coordMouse = pGG->getJanela()->mapPixelToCoords(posicaoMouse);//converte a posicao do mouse para coordenadas do mundo
		}	

		if(evento.type == sf::Event::MouseButtonPressed){//se o evento for pressionar o botão do mouse
			if(evento.mouseButton.button == sf::Mouse::Left){//se o botão pressionado for o esquerdo
				pressionado = true;
			}	

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
}	
void Menu::desenhar() {//desenha o menu
	pGG->getJanela()->draw(*pFigura);//desenha o fundo do menu
	for (size_t i = 0; i < textos.size(); i++) {//desenha cada texto do menu
        pGG->getJanela()->draw(textos[i]);
    }
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
bool Menu::setFase_1(bool valor) {
	// Define se o menu deve iniciar a Fase 1
	// Implementação simples para exemplo
	if(valor) {
		std::cout << "Iniciando Fase 1..." << std::endl;
	}
}
bool Menu::getFase_1() {
	// Retorna se a Fase 1 deve ser iniciada
	// Implementação simples para exemplo
	return (posicaoMenu == 1 && pressionado);
}
Jogo* Menu::get_pJog() {
return pJogo;
}
