#include "Jogo.h"
#include "Menu.h"
using namespace Entidades;
using namespace Personagens;
using namespace Fases; 
Menu::Menu():Ente(), posicaoMenu(0), emMenu(true) {
	pJog = NULL;
	//menu = pGG->criaJanela("Menu", 500, 500);
	exitMenu = new sf::RectangleShape();
 	fonte = new sf::Font();
	//cameraDefault = pGG->getJanela()->getDefaultView();
	//pFigura bg = new sf::Sprite();
	//figura = new sf::Texture();
	atribuir();
	
	atribuirFigura();	

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
	float telaAntigaX = 1360.0;
	float telaAntigaY = 768.0;
	sf::Vector2u telaAtual = pGG->getJanela()->getSize();
	float escalaX = static_cast<float>(telaAtual.x) / telaAntigaX;
	float escalaY = static_cast<float>(telaAtual.y) / telaAntigaY;	
	posicaoMouse = {0,0};
	coordMouse = {0.0, 0.0};	
	posicaoMenu = 0;

	pressionado = selecionado = false;
	fonte->loadFromFile("./assets/tropifonte.ttf");	

	setFile("./assets/menu.png");
	

	//pFigura->setScale(escalaX, escalaY);
			
	opcoes = {"Continuar", "Fase 1", "Fase 2","Salvar jogada","Rank","Salvar pontuacao"};
	coords = {{450 * escalaX, 140 * escalaY},{520 * escalaX, 240 * escalaY},{520 * escalaX , 318 * escalaY}, {520 * escalaX, 396 * escalaY},{520 * escalaX, 474 * escalaY},{520 * escalaX, 552 * escalaY} };
	tam = {40, 20,20,20,20,20};
	textos.resize(6);
        for(size_t i = 0; i < textos.size(); i++) {
		textos[i].setFont(*fonte);
		textos[i].setString(opcoes[i]);
		textos[i].setCharacterSize(tam[i]);
		//textos[i].setOutlineColor(sf::Color::Red);
	
		textos[i].setPosition(coords[i]);
	}
	pFigura->setPosition( 290 * escalaX, 140 * escalaY);
	pFigura->setScale(0.7680 * escalaX, 0.500 * escalaY);
}
void Menu::Executar() {
	executar();
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
void Menu::loopEventos() {
        sf::Event evento;     
	selecionado = false;
	while (pGG->getJanela()->pollEvent(evento))
        {
                if (evento.type == sf::Event::Closed) {
                    pGG->getJanela()->close();
                }


	if(evento.type == sf::Event::KeyPressed) {
        int pos = getPosicaoMenu();

        std::vector<sf::Text> *bucket = getTextos();
        if((evento.key.code == sf::Keyboard::Down) && !getPressionado()) {
                if(pos < 6 && pos >=0 ) {
                        setPressionado(true);
                        setPosicaoMenu(++pos);
                        (*bucket)[getPosicaoMenu()].setOutlineThickness(4);
                        (*bucket)[getPosicaoMenu() - 1].setOutlineThickness(0);
                        //setPressionado(false);
                        std::cout << "pos: " <<  getPosicaoMenu() << std::endl;

                }

        }
        if((evento.key.code == sf::Keyboard::Up) && ! getPressionado()) {
                if(pos >= 0 && pos < 6) {
                         setPressionado(true);
                         setPosicaoMenu(--pos);
                        (*bucket)[ getPosicaoMenu()].setOutlineThickness(4);
                        (*bucket)[ getPosicaoMenu() + 1].setOutlineThickness(0);
                         //setPressionado(false);
        std::cout << "pos: " <<  getPosicaoMenu() << std::endl;
                }
        }
                if( getPosicaoMenu() <= -1) {
                        (*bucket)[5].setOutlineThickness(4);
                        (*bucket)[0].setOutlineThickness(0);
                        setPosicaoMenu(5);
                }
                if( getPosicaoMenu() >= 6) {
                        (*bucket)[0].setOutlineThickness(4);
                        (*bucket)[5].setOutlineThickness(0);
                         setPosicaoMenu(0);
                }

     		if((evento.key.code == sf::Keyboard::Enter) && !selecionado) {
	 		selecionado = true;
     		}
		setPressionado(false);	
     }
   }
}
void Menu::executar(){
    if(emMenu == true) {		
	while(pGG->getJanela()->isOpen() && emMenu){
	
		 	loopEventos();
                        //desenharEnte(pE);
                        (pGG->getJanela())->clear();
                        atualizar(); //switch case e atualizar() {  jogo.atualizar(menu->jogo); }  
 			pGG->getJanela()->setView(pGG->getCameraDefault());
			Desenhar();

			for(int i = 0; i < textos.size(); i++) {
				pGG->getJanela()->draw(textos[i]);
			}	
                        //atualizar(); //switch case e atualizar() {  jogo.atualizar(menu->jogo); }  
                        // desenhar();
                        pGG->getJanela()->display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        			emMenu = false;  // para o jogo saber que o jogador saiu do menu
    			}
        }
    }	
}
void Menu::set_emMenu(bool v) {
	emMenu = v;
}
bool Menu::get_emMenu()const {
	return  emMenu;
}
void Menu::atualizar() {
	// //pJog->Executar();
	
	//pJog->Atualiza();	
	if(selecionado) {
		switch (getPosicaoMenu()) {
			case 0: {
				pGG->getJanela()->close();		
			}
				
			break;
			case 1: {  
					Fase_1 *f = new Fase_1();
					Jogador *j = new Jogador();
					pJog->setJogador(j);				
					f->Setar_Jogadores_Colisoes(j, nullptr);
					pJog->incluirEntes(static_cast<Ente*>(f));
					pJog->incluirEntes(static_cast<Ente*>(j));
					
			}
			break;
			case 2: {
						
				/*	TorreFogo *t = new TorreFogo();
					Jogador *j = new Jogador();
					pJog->setJogador(j);				
					t->Setar_Jogadores_Colisoes(j, nullptr);
					pJog->incluirEntes(static_cast<Ente*>(t));
					pJog->incluirEntes(static_cast<Ente*>(j));
				 */	
			}
			break;
			case 3: {
			
			}
			break;
			case 4: {
			
			}
			break;
			case 5: {

			}
			break;
			default: { 
				
			}
		}







	}

}
