#include "Jogo.h"
#include "Menu.h"

Menu::Menu(Jogo *pJogo) : Ente(){
	// armazena a referência para o jogo para que possamos mudar o estado
	this->pJogo = pJogo;
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

	if (!fonte->loadFromFile("../assets/menu_principal/Jersey25-Regular.ttf")) {
		std::cerr << "[ERRO] Nao foi possivel encontrar ou carregar a fonte '../assets/menu_principal/Jersey25-Regular.ttf'" << std::endl;
	}
	
	if (imagem->loadFromFile("../assets/menu_principal/menuPrincipal.png")) { 
		// imagem carregada
		// Aplica a textura ao RectangleShape e reseta o rect para mapear corretamente
		pFigura->setTexture(imagem, true);
		// Também configura o sprite de fundo (bg) com a mesma textura e escala para a janela
		bg->setTexture(*imagem);
		// Garantir que o SFML não aplique smoothing que pode alterar a aparência
		imagem->setSmooth(false);
		// Garantir que o sprite não seja tinturado
		bg->setColor(sf::Color::White);
		sf::Vector2u texSize = imagem->getSize();
		// Escala o sprite para preencher a janela
		if (pGG && pGG->getJanela()) {
			sf::Vector2u winSize = pGG->getJanela()->getSize();
			if (texSize.x > 0 && texSize.y > 0) {
				bg->setScale(
					static_cast<float>(winSize.x) / static_cast<float>(texSize.x),
					static_cast<float>(winSize.y) / static_cast<float>(texSize.y)
				);
				bg->setPosition(0.0f, 0.0f);
			}
		}
	}
	else {
		std::cerr << "[ERRO] Nao foi possivel encontrar ou carregar a imagem '../assets/menu_principal/menuPrincipal.png'" << std::endl;
		// sf::Sprite não possui setFillColor/setSize — use setColor e setScale como fallback.
		bg->setColor(sf::Color::Magenta); // Magenta é uma cor feia que chama a atenção
		// Sem textura, setScale não define um tamanho absoluto; manter escala padrão como fallback.
		bg->setScale(1.0f, 1.0f);
	}


	// Define um tamanho absoluto para o retângulo que exibirá a textura.
	// Antes usávamos setScale em um RectangleShape sem size definido (0,0),
	// o que resulta em nada sendo desenhado. Agora usamos setSize.
	pFigura->setSize(sf::Vector2f(500.0f, 500.0f));//tamanho do menu na janela
	// Posiciona o fundo no canto superior esquerdo para ocupar a janela
	pFigura->setPosition(0.0f, 0.0f);//posicao do menu na janela
	
	opcoes = {"1 Jogador","2 Jogadores", "Configuracoes", "Sair"};
	coordsOpcoes = {{200, 250},{200, 300},{200, 350},{200, 400}};
	// Aumenta os tamanhos das opções principais para melhor legibilidade
	tam = {36, 36, 36, 36};
	textos.resize(4);
    for(std::size_t i{}; i < textos.size(); i++) {
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize((tam[i]));
		// Tornar textos visíveis mesmo em fundo claro: preenchimento preto + contorno vermelho
		textos[i].setFillColor(sf::Color::Black);
		textos[i].setOutlineColor(sf::Color::Red);
		textos[i].setOutlineThickness(2.f);
		textos[i].setPosition(coordsOpcoes[i]);
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

			if(pressionado) {
				//ação para cada opção do menu
				switch(posicaoMenu) {
					case 0://1 Jogador
						std::cout << "Opção '1 Jogador' selecionada." << std::endl;
						pJogo->setEstado(Estado::FASE_1);
						break;
					case 1://2 Jogadores
						std::cout << "Opção '2 Jogadores' selecionada." << std::endl;
						pJogo->set_pJog2_Dois_Jogadores(true);
						pJogo->setEstado(Estado::FASE_1);
						break;
					case 2://Sair
						std::cout << "Opção 'Sair' selecionada. Fechando o jogo..." << std::endl;
						pGG->getJanela()->close();
						break;
					default:
						std::cerr << "[ERRO] Opção de menu inválida selecionada." << std::endl;
						break;
				}
			}

		}	
		else{
				// Usar preto como cor padrão quando não selecionado para garantir contraste
				textos[i].setFillColor(sf::Color::Black);
				if(!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					pressionado = false;
					selecionado = false;    
				}                
			}    
	}	
}	
void Menu::desenhar() {//desenha o menu
	// Desenha o fundo e os textos. O loop principal controla clear()/display().
	if (bg && bg->getTexture()) {
		pGG->getJanela()->draw(*bg);
	} else if (pFigura) {
		pGG->getJanela()->draw(*pFigura);
	}

	for (size_t i = 0; i < textos.size(); i++) {
		pGG->getJanela()->draw(textos[i]);
	}

	// Fim do desenho do menu (fundo + textos)
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
	return valor;
}
bool Menu::getFase_1() {
	// Retorna se a Fase 1 deve ser iniciada
	// Implementação simples para exemplo
	return (posicaoMenu == 1 && pressionado);
}
Jogo* Menu::get_pJog() {
return pJogo;
}
