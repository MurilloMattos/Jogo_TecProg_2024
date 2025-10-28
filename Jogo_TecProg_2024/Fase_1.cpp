#include "Fase_1.h"

using namespace Entidades;
using namespace Personagens;




Fases::Fase_1::Fase_1(): maxChefoes(1), n_Inimigos(rand() % 5 + 3) {

	Cria_Inimigos();
	lista_Entidades.imprimir_Ids();
}

Fases::Fase_1::~Fase_1(){


}


void Fases::Fase_1::Cria_Obstaculos()
{

}

void Fases::Fase_1::Executar(){

	verifica_Inimigos_Neutralizados();

	gerenciador_colisoes.Executar();
	lista_Entidades.Percorrer();
}


void Fases::Fase_1::Cria_Inimigos(){

	int i;
	float pos_inicial_x, pos_inicial_y;

	pos_inicial_x = 290.f;
	pos_inicial_y = 100.f;

	for (i = 0; i < n_Inimigos; i++) {

		Cria_Inimigos_Piratas(pos_inicial_x+(100*i), pos_inicial_y);
	}



	Cria_Inimigos_Capitao();
}

void Fases::Fase_1::Cria_Inimigos_Capitao(){

	Capitao* capitao;
	capitao = new Capitao;

	capitao->setar_Pos(600.f, 159.f);
	gerenciador_colisoes.Incluir_Inimigo(capitao);
	lista_Entidades.Incluir(static_cast<Entidade*>(capitao));
}
