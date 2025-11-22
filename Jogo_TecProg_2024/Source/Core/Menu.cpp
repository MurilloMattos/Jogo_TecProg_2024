#include "Core/Jogo.h"
#include "Core/Menu.h"

Menu::Menu(Jogo *pJogo) : Ente(){

	selecaoAtual = Selecao::ESCOLHE_JOGADOR;

	fase_1_selecionado = false;
	fase_2_selecionado = false;
	jogador_2_selecionado = false;
	pressionado = selecionado = false;

	// armazena a referência para o jogo para que possamos mudar o estado
	this->pJogo = pJogo;

	exitMenu = new sf::RectangleShape();
	fonte = new sf::Font();
	bg = new sf::Sprite();
	imagem = new sf::Texture();
	
	Inicializar();	
	
}

Menu::~Menu() {

	pJogo = NULL;
	delete exitMenu;
	delete fonte;
	delete bg;
	delete imagem;

}

void Menu::Inicializar() {	
	
	posicaoMouse = {0,0};
	coordMouse = {0.0, 0.0};	
	posicaoMenu = 0;


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

		// Obtém o tamanho da textura para calcular a escala correta
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
			else {
				std::cerr << "[ERRO] Tamanho da textura inválido ao configurar o fundo do menu." << std::endl;
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

	// Posiciona o fundo no canto superior esquerdo para ocupar a janela
	pFigura->setPosition(0.0f, 0.0f);//posicao do menu na janela
	
}	

void Menu::Executar() {

	desenhar();

	// Lógica de navegação do menu
	if(selecaoAtual == Selecao::ESCOLHE_JOGADOR)
		EscolheJogador();
	else if(selecaoAtual == Selecao::ESCOLHE_FASE)
		EscolheFase();
	// Fim da lógica de navegação do menu

}

void Menu::EscolheJogador() {

	opcoes = {"1 Jogador","2 Jogadores", "Sair"};
	coordsOpcoes = {{200, 250},{200, 300},{200, 350}};
	tam = {36, 36, 36};// Aumenta os tamanhos das opções principais para melhor legibilidade
	textos.resize(3);

    for(std::size_t i{}; i < textos.size(); i++) {

		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize(static_cast<unsigned int>(tam[i]));
		// Tornar textos visíveis mesmo em fundo claro: preenchimento preto + contorno vermelho
		textos[i].setFillColor(sf::Color::Black);
		textos[i].setOutlineColor(sf::Color::Red);
		textos[i].setOutlineThickness(2.f);
		textos[i].setPosition(coordsOpcoes[i]);

	}

	sf::Event evento;

	while(pGG->getJanela()->pollEvent(evento)){ //enquanto houver eventos
		if(evento.type == sf::Event::Closed){//se o evento for fechar a janela
			pGG->getJanela()->close();
		}	

	}	

	sf::Vector2f mouse_pos = pGG->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGG->getJanela()));//pega a posição do mouse na janela
	bool mouse_clicado = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	//laco para verificar cada texto do menu
	for(int i = 0; i < textos.size(); i++) {
		if(textos[i].getGlobalBounds().contains(mouse_pos)) {//se o mouse estiver sobre o texto

			textos[i].setFillColor(sf::Color::Red);//muda a cor do texto para vermelho
			posicaoMenu = i;
			selecionado = true;

			if(mouse_clicado && !pressionado) {//se o botão esquerdo do mouse estiver pressionado
				pressionado = true;

				//ação para cada opção do menu
				switch(posicaoMenu) {

					case 0://1 Jogador
						std::cout << "Opção '1 Jogador' selecionada." << std::endl;
						jogador_2_selecionado = false;
						selecaoAtual = Selecao::ESCOLHE_FASE;
						break;

					case 1://2 Jogadores
						std::cout << "Opção '2 Jogadores' selecionada." << std::endl;
						jogador_2_selecionado = true;
						selecaoAtual = Selecao::ESCOLHE_FASE;
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

void Menu::EscolheFase() {

	opcoes = {"Fase 1","Fase 2", "Voltar"};
	coordsOpcoes = {{200, 250},{200, 300},{200, 350}};
	tam = {36, 36, 36};// Aumenta os tamanhos das opções principais para melhor legibilidade
	textos.resize(3);

    for(std::size_t i{}; i < textos.size(); i++) {

		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize(static_cast<unsigned int>(tam[i]));
		// Tornar textos visíveis mesmo em fundo claro: preenchimento preto + contorno vermelho
		textos[i].setFillColor(sf::Color::Black);
		textos[i].setOutlineColor(sf::Color::Red);
		textos[i].setOutlineThickness(2.f);
		textos[i].setPosition(coordsOpcoes[i]);

	}

	sf::Event evento;

	while(pGG->getJanela()->pollEvent(evento)){ //enquanto houver eventos
		if(evento.type == sf::Event::Closed){//se o evento for fechar a janela
			pGG->getJanela()->close();
		}	

	}

	sf::Vector2f mouse_pos = pGG->getJanela()->mapPixelToCoords(sf::Mouse::getPosition(*pGG->getJanela()));//pega a posição do mouse na janela
	bool mouse_clicado = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	//laco para verificar cada texto do menu
	for(int i = 0; i < textos.size(); i++) {
		if(textos[i].getGlobalBounds().contains(mouse_pos)) {//se o mouse estiver sobre o texto
			textos[i].setFillColor(sf::Color::Red);//muda a cor do texto para vermelho
			posicaoMenu = i;
			selecionado = true;

			if(mouse_clicado && !pressionado) {//se o botão esquerdo do mouse estiver pressionado
				pressionado = true;

				//ação para cada opção do menu
				switch(posicaoMenu) {

					case 0://Fase 1
						std::cout << "Opção 'Fase 1' selecionada." << std::endl;
						if(jogador_2_selecionado)
							pJogo->set_pJog2_Dois_Jogadores(true);
						pJogo->setEstado(Estado::FASE_1);
						fase_1_selecionado = true;
						break;

					case 1://Fase 2
						std::cout << "Opção 'Fase 2' selecionada." << std::endl;
						if(jogador_2_selecionado)
							pJogo->set_pJog2_Dois_Jogadores(true);
						pJogo->setEstado(Estado::FASE_2);
						fase_2_selecionado = true;
						break;

					case 2://Voltar
						std::cout << "Opção 'Voltar' selecionada. Retornando ao menu principal..." << std::endl;
						selecaoAtual = Selecao::ESCOLHE_JOGADOR;
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


Jogo* Menu::get_pJogo() {
return pJogo;
}
