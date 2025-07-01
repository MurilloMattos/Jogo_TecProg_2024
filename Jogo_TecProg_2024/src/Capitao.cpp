#include "Capitao.h"
#include "Fase.h"
#include "Gerenciador_Colisoes.h"
#include  <ctime>
using namespace Entidades;
using namespace Personagens;

Capitao::Capitao():Inimigo(), p(), it(){
	atacar = false;
	p.clear();
	it = p.begin();
	num_vitalidade = 200;
	dano = 20;
	
	tamanho.x = 35.0;
	tamanho.y = 65.0;

	pos_inicial.x = 50.f;
	pos_inicial.y = 159.f;

	pos_final = pos_inicial;

	velocidade.x = 2.0f;

	//pFigura->setFillColor(sf::Color::Magenta);

	//pFigura->setSize(tamanho);
		
        setFile("./assets/ladrao_centered.png");
        atribuirFigura();
	pFigura->setScale(0.3f, 0.3f);	
	pFigura->setPosition(pos_inicial.x, pos_inicial.y);
}

Capitao::~Capitao(){
	
}

void Capitao::Executar() {
	Ente::Desenhar();
	
	if(get_Atacar()) {
		Atualizar();
	}
	if(!p.empty()) {
		get_Inicio();
		while(obtem_Fim() != true) {
			if(*it != NULL) {
				(*it)->setar_Pos(get_X()+3, get_Y());
			}
			operator++();	
		}
	}
	Gerenciadores::Gerenciador_colisoes *pG = fase->get_Gerenciador();
	while(obtem_Fim() != true) {
		if(retorna_Atual()) {
			Listas::Lista_Entidades *lE = fase->get_Lista();
			lE->Incluir(static_cast<Entidade*>(retorna_Atual()));
			pG->Incluir_Projetil(retorna_Atual());
		}
	operator++();
	}
	pG->limpar_Projeteis();
	limpar_VetorProjeteis();
	srand(time(NULL));
	if(rand()%2) {
		setar_Pos(get_X() + velocidade.x, get_Y());
	}else{
		setar_Pos(get_X() - velocidade.x, get_Y());
	}
	
	set_Atacar(false);	
}
void Capitao::Salvar() {
	
}
void Capitao::Atualizar() {
		Projetil *fogo = new Projetil;
		fogo->setar_Pos(get_X(), get_Y());
		if(fogo) { 
			p.push_back(fogo);
		}else {
			std::cout << "Ponteiro nao alocado" << std::endl;
		}
}
bool Capitao::obtem_Fim() {
	if(it == p.end()){
		return true;
	}
	return false;
}
Projetil *Capitao::retorna_Atual() {
	if(*it) {
		return (*it);
	}else {
		std::cout << "iterador de projeteis vazio" << std::endl;
	}
	return NULL;
}
void Capitao::operator++() {
	if(*it) {
    		it++;
	}
}
void Capitao::get_Inicio() {
	it = p.begin();
}
void Capitao::limpar_VetorProjeteis() {
	if(p.size() >= 10) {
		get_Inicio();
		while(obtem_Fim() != true) {
			if(*it) {
			   delete *it;
		   	   it = p.erase(it);	   
			}else {
			    p.erase(it);	
			}
			operator++();
		}
	}	
}
