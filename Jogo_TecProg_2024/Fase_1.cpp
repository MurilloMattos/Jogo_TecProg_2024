#include "Fase_1.h"

using namespace Entidades;
using namespace Personagens;

Fases::Fase_1::Fase_1():num_max_Capitoes(1), i(0){

	i = 0;
	j = 0;

	lista_cap.clear();
	Cria_Inimigos();
	
}

Fases::Fase_1::~Fase_1(){

	lista_cap.clear();
}


void Fases::Fase_1::Cria_Obstaculos()
{

}

void Fases::Fase_1::Executar(){

	verifica_Projeteis_Destroidos();

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

	//proj->setar_Ativo(true);

	
	lista_Entidades.Incluir(proj);
	gerenciador_colisoes.Incluir_Projetil(proj);

	return proj;
}

void Fases::Fase_1::verifica_Projeteis_Destroidos()
{
	
	Projetil* projetil_deletado;

	for(i=0;i<lista_cap.size(); i++) {

		for(j=0; j < lista_cap[i]->get_Vetor_De_Projetis().size(); j++) {

			if (!(lista_cap[i]->get_Vetor_De_Projetis()[j]->get_Ativo())) {

				projetil_deletado = lista_cap[i]->get_Vetor_De_Projetis()[j];

				
				if (projetil_deletado) {
					//remove da lista de colisões
					gerenciador_colisoes.projetil_Destruido(projetil_deletado);

				}
				else {
					std::cout << "Erro ao remover projetil (Gerenciador_colisoes)" << std::endl;
				}

				if (projetil_deletado) {
					//remove do capitão
					lista_cap[i]->remover_Projetil(projetil_deletado);
				}
				else {
					std::cout << "Erro ao remover projetil (Capitao)" << std::endl;
				}

				if (projetil_deletado) {
					//remove da lista de entidades
					lista_Entidades.Remover(static_cast<Entidade*>(projetil_deletado));
				}
				else {
					std::cout << "Erro ao remover projetil (Lista_Entidades)" << std::endl;
				}

				//system("pause");
			}
		}

		projetil_deletado = nullptr;
	}

	

}
