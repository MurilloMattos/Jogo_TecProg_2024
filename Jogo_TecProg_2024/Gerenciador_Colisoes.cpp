#include "Gerenciador_Colisoes.h"


using namespace Gerenciadores;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace std;


Gerenciador_colisoes::Gerenciador_colisoes()
{
	cima = false;
	baixo = false;
	esquerda = false;
	direita = false;


	lista_Inimigos.clear();
	lista_Obstaculos.clear();
	
	pJogador1 = nullptr;
	pJogador2 = nullptr;
}

Gerenciador_colisoes::~Gerenciador_colisoes(){

	lista_Inimigos.clear();
	lista_Obstaculos.clear();

	pJogador1 = nullptr;
	pJogador2 = nullptr;
}

void Gerenciador_colisoes::Incluir_Obstaculo(Obstaculo* p_Obstaculo){
	lista_Obstaculos.push_back(p_Obstaculo);
}

void Gerenciador_colisoes::Incluir_Inimigo(Inimigo* p_Inimigo){
	lista_Inimigos.push_back(p_Inimigo);
}

void Gerenciador_colisoes::Incluir_Projetil(Projetil* p_Projetil){

}

void Gerenciador_colisoes::Setar_Jogador(Jogador* p_Jogador1, Jogador* p_Jogador2){
	pJogador1 = p_Jogador1;
	pJogador2 = p_Jogador2;
}

//classe nova?
void Gerenciador_colisoes::tratar_Fisica_Inimigos(){

}

void Gerenciador_colisoes::tratar_Fisica_Jogadores() {
	if (pJogador1)
		pJogador1->executar_Gravidade();

	if (pJogador2)
		pJogador2->executar_Gravidade();
}

void Gerenciador_colisoes::tratar_Fisica_Obstaculos(){

	list<Obstaculo*>::iterator itr;

	itr = lista_Obstaculos.begin();

	while (itr != lista_Obstaculos.end()) {

		(*itr)->executar_Gravidade();

		itr++;
	}

}

void Gerenciador_colisoes::tratar_Colisoes_Inimigos(){

	int i;

	for (i = 0; i < lista_Inimigos.size(); i++) {
		
		lista_Inimigos[i]->get_X();

	}

}

void Gerenciador_colisoes::tratar_Colisoes_Obstaculo(){

}

void Gerenciador_colisoes::tratar_Colisoes_Jogador_Obstaculo(){

	list<Obstaculo*>::iterator itr;

	itr = lista_Obstaculos.begin();

	while (itr != lista_Obstaculos.end()) {

		if (verifica_Colisao_Cima(static_cast<Entidade*>(*itr), static_cast<Entidade*>(pJogador1))) {
			pJogador1->setar_Pos(pJogador1->get_X(), (*itr)->get_Y() - pJogador1->get_Altura());
		}

		itr++;
	}


}

const bool Gerenciador_colisoes::mesma_Altura_Para_Colisao(Entidades::Entidade* pEntidade_Ref, Entidades::Entidade* pEntidade2)
{
	// (y > y2 + a) ou (y + a < y2)
	if ((pEntidade_Ref->get_Y() > (pEntidade2->get_Y() + pEntidade2->get_Altura())) || 
		((pEntidade_Ref->get_Y() + pEntidade_Ref->get_Altura()) < pEntidade2->get_Y())) {
		return false;
	}

	return true;
}

const bool Gerenciador_colisoes::verifica_Colisao_Cima(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	cima = false;

	/*
	// (y > y2 + a) ou (y + a < y2)
	if (pEntidade_Ref->get_Y() > (pEntidade2->get_Y() + pEntidade2->get_Altura())) {
		cima = false;
	}
	*/
	if (!mesma_Altura_Para_Colisao(pEntidade_Ref, pEntidade2)) {
		cima = false;
	}
	else {

		// (y <= y2+a) && (y + a/2 >= y2 + a)
		if ((pEntidade_Ref->get_Y() <= (pEntidade2->get_Y() + pEntidade2->get_Altura())) &&	
			((pEntidade_Ref->get_Y() + (pEntidade_Ref->get_Altura()/2)) >= (pEntidade2->get_Y()+pEntidade2->get_Altura()))) 
		{

			// (x> x2+L) ou (x+l< x2)
			if ((pEntidade_Ref->get_X() > (pEntidade2->get_X() + pEntidade2->get_Largura()))) 
			{
				cima = false;
			}
			else if ((pEntidade_Ref->get_X() + pEntidade_Ref->get_Largura()) < pEntidade2->get_X()) {
				cima = false;
			}
			else {
				cima = true;
			}
		}
	}

	return cima;
}


const bool Gerenciador_colisoes::verifica_Colisao_Esquerda(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	esquerda = false;


	if (!mesma_Altura_Para_Colisao(pEntidade_Ref, pEntidade2)) {
		esquerda = false;
	}
	else {

	}


	return esquerda;
}


const bool Gerenciador_colisoes::verifica_Colisao_Baixo(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	baixo = false;


	return baixo;
}

const bool Gerenciador_colisoes::verifica_Colisao_Direita(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	direita = false;


	return direita;
}

void Gerenciador_colisoes::Executar(){
	//tratar_Fisica();
	tratar_Fisica_Jogadores();
	tratar_Fisica_Obstaculos();
	tratar_Colisoes_Jogador_Obstaculo();

}
