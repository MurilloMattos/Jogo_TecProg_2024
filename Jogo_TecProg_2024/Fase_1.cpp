#include "Fase_1.h"

using namespace Entidades;
using namespace Personagens;

Fases::Fase_1::Fase_1(){

	Cria_Inimigos();
}

Fases::Fase_1::~Fase_1(){


}


void Fases::Fase_1::Executar(){

	verifica_Inimigos_Neutralizados();
	gerenciador_colisoes.Executar();
	lista_Entidades.Percorrer();
}


void Fases::Fase_1::Cria_Inimigos(){

	Cria_Inimigos_Piratas();
	Cria_Inimigos_Capitao();
}

void Fases::Fase_1::Cria_Inimigos_Capitao(){

	Capitao* capitao;
	capitao = new Capitao;

	capitao->setar_Pos(600.f, 159.f);
	gerenciador_colisoes.Incluir_Inimigo(capitao);
	lista_Entidades.Incluir(static_cast<Entidade*>(capitao));
}
