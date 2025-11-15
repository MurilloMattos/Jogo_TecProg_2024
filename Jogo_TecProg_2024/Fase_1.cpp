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

	Cria_Obstaculos();
	Cria_Piso();
	Cria_Plataforma();
	Cria_Inimigos();

}

Fases::Fase_1::~Fase_1(){

}


void Fases::Fase_1::Cria_Obstaculos()
{

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
void Fases::Fase_1::Cria_Inimigos(){

	Cria_Inimigos_Piratas();
	Cria_Inimigos_Capitao();

}

void Fases::Fase_1::Cria_Inimigos_Piratas(){
	Inimigo_Medio* pirata;

	pirata = new Inimigo_Medio;
	pirata->setar_Pos(290.f, 100.f);

	gerenciador_colisoes.Incluir_Inimigo(pirata);
	lista_Entidades.Incluir(static_cast<Entidade*>(pirata));
}


void Fases::Fase_1::Cria_Inimigos_Capitao(){

	Capitao* capitao;
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
	
