#include "Fases/Fase_1.h"

using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Fases::Fase_1::Fase_1():num_max_Capitoes(1), i(0){

	i = 0;
	j = 0;

	lista_cap.clear();

	Cria_Jogador(50.f, 100.f);
	Cria_Inimigos();
	Cria_Obstaculos();
	setar_Camera_Fase();
}

Fases::Fase_1::~Fase_1(){


}


void Fases::Fase_1::Cria_Obstaculos()
{
	Cria_Plataforma();
}

void Fases::Fase_1::Executar(){

	verifica_Inimigos_Neutralizados();

	if (!ganhou) {
		verifica_Projeteis_Destroidos();
		gerenciador_colisoes.Executar();
		lista_Entidades.Percorrer();

		for (i = 0; i < lista_cap.size(); i++) {

			if (lista_cap[i]->get_Disparou()) {

				lista_cap[i]->incluir_Projetil(Cria_Projetil());
			}
		}
	}

}

void Fase_1::Executar() {

}

void Fase_1::Cria_Piso() {

}

void Fase_1::Cria_Plataforma() {

}

void Fase_1::Cria_Inimigos() {
}

void Fase_1::Cria_Obstaculos() {

}


void Fases::Fase_1::atualiza_Camera_Fase(Jogador* p_jogador1, Jogador* p_jogador2)
{
	//centraliza a camera no jogador 1
	pGG->getCamera()->setCenter(p_jogador1->get_Centro());

}