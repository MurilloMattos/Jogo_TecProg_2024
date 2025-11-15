#include "Fase_1.h"

using namespace Entidades;
using namespace Personagens;

Fases::Fase_1::Fase_1():num_max_Capitoes(1), i(0){

	lista_cap.clear();
	Cria_Inimigos();
	
}

Fases::Fase_1::~Fase_1(){

	lista_cap.clear();
}


void Fases::Fase_1::Executar(){

	verifica_Projetil_Destroido();

	verifica_Inimigos_Neutralizados();

	gerenciador_colisoes.Executar();

	lista_Entidades.Percorrer();


	for (i = 0; i < lista_cap.size(); i++) {

		if (lista_cap[i]->get_Disparou()) {
			lista_cap[i]->incluir_Projetil(Cria_Projetil());
		}
	}

}


void Fases::Fase_1::Cria_Inimigos(){

	//Cria_Inimigos_Piratas();
	Cria_Inimigos_Capitao();
}

void Fases::Fase_1::Cria_Inimigos_Capitao(){

	Capitao* capitao;
	capitao = new Capitao;

	capitao->setar_Pos(600.f, 159.f);
	gerenciador_colisoes.Incluir_Inimigo(capitao);
	lista_Entidades.Incluir(static_cast<Entidade*>(capitao));
	lista_cap.push_back(capitao);

}

Projetil* Fases::Fase_1::Cria_Projetil()
{

	Projetil* proj;
	proj = new Projetil;
	lista_Entidades.Incluir(proj);
	gerenciador_colisoes.Incluir_Projetil(proj);

	return proj;
}

void Fases::Fase_1::verifica_Projetil_Destroido()
{
	Projetil* proj_destruido;
	proj_destruido = gerenciador_colisoes.projetil_Destruido();
	if (proj_destruido != nullptr) {
		lista_Entidades.Remover(static_cast<Entidade*>(proj_destruido));
		
		for (i = 0; i < lista_cap.size(); i++) {
			//remover da lista de projeteis do capitao

			lista_cap[i]->remover_Projetil(static_cast<Projetil*>(proj_destruido));
		}
	}
}
