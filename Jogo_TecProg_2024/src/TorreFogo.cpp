#include "TorreFogo.h"
#include "Gerenciador_Colisoes.h"
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
Fases::TorreFogo::TorreFogo(): Fase() {
	Cria_Inimigos_Piratas();
	Cria_Inimigo_Dificeis();
	Cria_Obstaculos_Medios();
	
	setFile("./assets/fasefogo.png");
	atribuirFigura();
	pFigura->setPosition(0.0f, 0.0f);
}
Fases::TorreFogo::~TorreFogo() {

}
void Fases::TorreFogo::Cria_Inimigo_Dificeis() {
	Capitao *capitao;

	srand(static_cast<unsigned int>(time(0)));
	int aux = ((rand()%(12 - 3 + 1))+ 3);
	float espaco = 0.0f;
	for(int i = 0; i < aux; i++) {
		capitao = new Capitao;
		sf::Texture *t = capitao->get_Textura();
		t->loadFromFile("./assets/chefao.png");
		capitao->getFigura()->setTexture(*t);		
		capitao->setar_Pos(950.f + espaco*2 , 159.f);
		espaco += capitao->getFigura()->getGlobalBounds().width;
		associa_Inimigo(static_cast<Inimigo*>(capitao));
		
		gerenciador_colisoes->Incluir_Inimigo(capitao);
		lista_Entidades.Incluir(static_cast<Entidade*>(capitao));

	}			
}
void Fases::TorreFogo::Cria_Obstaculos_Medios() { // obstaculos considerados Dificeis por estarem na fase2
	srand(time(NULL));
	int random = ((rand()%(8 - 3)) + 3);
	std::cout << "random " << random << std::endl;
	int dist = ((rand()%(350 - 100)) + 100);
	int diff = dist;	
	for(int i = 0; i < random; i++) {
		Obstaculo_Dificil *fogo = new Obstaculo_Dificil;
		fogo->setar_Pos(pos_original.x + diff, 250.0f);
		dist  = ((rand()%(350 - 100)) + 100);
		diff += ((fogo->getFigura()->getGlobalBounds().width) + dist);
		gerenciador_colisoes->Incluir_Obstaculo(fogo);
		lista_Entidades.Incluir(static_cast<Entidade*>(fogo));
	}
}
void Fases::TorreFogo::Executar() {
	pGG->getJanela()->setView(pGG->getCameraDefault());
	Desenhar();
	pGG->getJanela()->setView(*pGG->getCamera());
	verifica_Inimigos_Neutralizados();
	gerenciador_colisoes->Executar();
	lista_Entidades.Percorrer();
	
	if(gerenciador_colisoes->get_Jogador1()->get_Vitalidade() <= 0) {
		std::cout << "#############JOGADOR LOOSER!!!!############" << std::endl;
	}
}
