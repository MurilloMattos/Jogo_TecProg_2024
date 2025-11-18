#include "Fase_1.h"

using namespace Entidades;
using namespace Personagens;

Fases::Fase_1::Fase_1() {

	num_plataformas = rand() % 7;

	ganhou = false;

	tam_Piso_Fase.x = 2500.f;
	tam_Piso_Fase.y = 100.f;
	pos_Piso.x = -100.f;
	pos_Piso.y = 200.f;

	tam_plataforma.x = 150.f;
	tam_plataforma.y = 30.f;

	pos_original.x = 10;
	pos_original.y = 80;
	
	Cria_Piso();
	Cria_Plataforma();
	Cria_Esteiras();
	Cria_Inimigos();

}

Fases::Fase_1::~Fase_1(){

}

void Fases::Fase_1::Cria_Plataforma(){
	plataforma = new Obstaculos::Piso;
	plataforma->seta_Piso(tam_plataforma.y, tam_plataforma.x, pos_original.x, pos_original.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(plataforma));
	lista_Entidades.Incluir(static_cast<Entidade*>(plataforma));
}

void Fases::Fase_1::Cria_Piso() {

	piso = new Obstaculos::Piso;
	piso->seta_Piso(tam_Piso_Fase.y, tam_Piso_Fase.x, pos_Piso.x, pos_Piso.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(piso));
	
}

void Fases::Fase_1::Cria_Esteiras() {

	esteira = new Obstaculos::Obstaculo_Esteira(2.f, sf::Vector2f(-1.f, 0.f));//velocidade e direc
	sf::Vector2f altura_esteira = esteira->get_Tamanho_Esteira();
	float altura_base = pos_Piso.y - (tam_Piso_Fase.y / 2);
	altura_esteira.y = altura_base - (altura_esteira.y / 2);
	esteira->setar_Pos(400.f, 200.f);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(esteira));
	lista_Entidades.Incluir(static_cast<Entidade*>(esteira));
}

void Fases::Fase_1::Cria_Inimigos(){

	Cria_Inimigos_Piratas();
	Cria_Inimigos_Esmagador();
	Cria_Inimigos_Capitao();

}

void Fases::Fase_1::Cria_Inimigos_Piratas(){

	int random = rand() % 3 + 3;// número aleatório de piratas entre 3 e 5
	float espacamento = 100.f;
	
	for(int i = 0; i < random; i++) {

		pirata = new Piratas;
		pirata->setar_Pos(290.f + i * espacamento, 100.f);

		gerenciador_colisoes.Incluir_Inimigo(pirata);
		lista_Entidades.Incluir(static_cast<Entidade*>(pirata));
	}
}

void Fases::Fase_1::Cria_Inimigos_Esmagador(){

	int random = rand() % 2 + 1;// número aleatório de esmagadores entre 1 e 2
	float espacamento = 100.f;

	for (int i = 0; i < random; i++) {

		Inimigo_Esmagador* esmagador = new Inimigo_Esmagador;
		esmagador->setar_Pos(500.f + i * espacamento, 100.f);

		gerenciador_colisoes.Incluir_Inimigo(esmagador);
		lista_Entidades.Incluir(static_cast<Entidade*>(esmagador));
	}
}



void Fases::Fase_1::Cria_Inimigos_Capitao(){

	capitao = new Capitao;

	capitao->setar_Pos(600.f, 159.f);
	gerenciador_colisoes.Incluir_Inimigo(capitao);
	lista_Entidades.Incluir(static_cast<Entidade*>(capitao));
}

void Fases::Fase_1::Executar(){
	
	verifica_Inimigos_Neutralizados();

	gerenciador_colisoes.Executar();
	lista_Entidades.Percorrer();
}
