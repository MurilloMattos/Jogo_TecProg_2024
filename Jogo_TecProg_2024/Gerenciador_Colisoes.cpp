#include "Gerenciador_Colisoes.h"


using namespace Gerenciadores;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace std;


Gerenciador_colisoes::Gerenciador_colisoes() : direita(1),cima(2),esquerda(3),baixo(4)
{

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

	if (p_Jogador1 != nullptr) {
		pJogador1 = p_Jogador1;
	}
	if (p_Jogador2 != nullptr) {
		pJogador2 = p_Jogador2;
	}
}

//classe nova?
void Gerenciador_colisoes::tratar_Fisica_Inimigos(){

	int i;

	for (i = 0; i < lista_Inimigos.size(); i++) {
		lista_Inimigos[i]->executar_Gravidade();
	}
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

void Gerenciador_colisoes::tratar_Colisoes_Obstaculo(Entidade* pEntidadeRef) {

	list<Obstaculo*>::iterator itr;

	itr = lista_Obstaculos.begin();


	//verifica o tipo de colisão especificamente com objetos.
	while (itr != lista_Obstaculos.end()) {

		int lado = verifica_Tipo_De_Colisao(static_cast<Entidade*>(pEntidadeRef), static_cast<Entidade*>(*itr));

		//direita
		if (lado == 1) {

			pEntidadeRef->setar_Pos(((*itr)->get_X() - pEntidadeRef->get_Largura()), pEntidadeRef->get_Y());
		}
		//cima
		else if (lado == 2) {

			pEntidadeRef->setar_Pos(pEntidadeRef->get_X(), (*itr)->get_Comprimento_A());
		}
		//esquerda
		else if (lado == 3) {

			pEntidadeRef->setar_Pos((*itr)->get_Comprimento_L(), pEntidadeRef->get_Y());
		}
		//baixo
		else if (lado == 4) {

			pEntidadeRef->setar_Pos(pEntidadeRef->get_X(), ((*itr)->get_Y() - pEntidadeRef->get_Altura()));
		}

		itr++;
	}
}

void Gerenciador_colisoes::tratar_Colisoes_Inimigos(){

	int i;

	for (i = 0; i < lista_Inimigos.size(); i++) {

		std::cout << lista_Inimigos[i]->get_X() << ", " << lista_Inimigos[i]->get_Y() << " altura: " << (lista_Inimigos[i]->get_Altura()+lista_Inimigos[i]->get_Y()) << std::endl;
		std::cout << pJogador1->get_X() << ", " << pJogador1->get_Y() << " altura: " << (pJogador1->get_Altura() + pJogador1->get_Y()) << std::endl;
		system("CLS");

		if (pJogador2 != nullptr) {
			tratar_Colisoes_Obstaculo(static_cast<Entidade*>(lista_Inimigos[i]));
			tratar_Colisoes_Jogador_Inimigos(pJogador1, lista_Inimigos[i]);
			tratar_Colisoes_Jogador_Inimigos(pJogador2, lista_Inimigos[i]);

		}
		else {
			tratar_Colisoes_Obstaculo(static_cast<Entidade*>(lista_Inimigos[i]));
			tratar_Colisoes_Jogador_Inimigos(pJogador1, lista_Inimigos[i]);

		}


	}

}

// 
void Gerenciador_colisoes::tratar_Colisoes_Jogador_Inimigos(Jogador* pJogador, Inimigo* pInimigo) {

	int lado = verifica_Tipo_De_Colisao(pJogador, pInimigo);

	//direita
	if (lado == 1) {

		pJogador->setar_Pos((pInimigo->get_X() - pJogador->get_Largura()), pJogador->get_Y());
	}
	//cima
	else if (lado == 2) {

		pJogador->setar_Pos(pJogador->get_X(), pInimigo->get_Comprimento_A());
	}
	//esquerda
	else if (lado == 3) {

		pJogador->setar_Pos(pInimigo->get_Comprimento_L(), pJogador->get_Y());
	}
	//baixo
	else if (lado == 4) {

		pJogador->setar_Pos(pJogador->get_X(), (pInimigo->get_Y() - pJogador->get_Altura()));
	}

}

//Essa classe tem como objetivo Garantir corretamente o lado colidido da entidade referência.
//Primeiro ela verifica as coordenadas principais, depois confirma com as secundárias, referente a colisão respectivamente.
const int Gerenciador_colisoes::verifica_Tipo_De_Colisao(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	
	float maior = 0;
	int lado = 0;
	bool colisao = false;
	float comprimento_baixo = 0;
	float comprimento_cima = 0;
	float comprimento_direita = 0;
	float comprimento_esquerda = 0;

	//Baixo
	if (verifica_Colisao_Baixo(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_X() < pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_X())) {

			comprimento_baixo = pEntidade_Ref->get_Comprimento_L() - pEntidade2->get_X();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_X() >= pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() <= pEntidade2->get_Comprimento_L())) {

			comprimento_baixo = pEntidade_Ref->get_Largura();
			colisao = true;
		}

		else if ((pEntidade_Ref->get_X() > pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_Comprimento_L())) {
			
			comprimento_baixo = pEntidade2->get_Comprimento_L() - pEntidade_Ref->get_X();
			colisao = true;
		}

	}

	//Cima
	if (verifica_Colisao_Cima(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_X() < pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_X())) {

			comprimento_cima = pEntidade_Ref->get_Comprimento_L() - pEntidade2->get_X();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_X() >= pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() <= pEntidade2->get_Comprimento_L())){

			comprimento_cima = pEntidade_Ref->get_Largura();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_X() > pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_Comprimento_L())) {

			comprimento_cima = pEntidade2->get_Comprimento_L() - pEntidade_Ref->get_X();
			colisao = true;
		}
	}
	
	//Direita
	if (verifica_Colisao_Direita(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_Y() < pEntidade2->get_Y()) && (pEntidade2->get_Y() < pEntidade_Ref->get_Comprimento_A())) {

			comprimento_direita = pEntidade_Ref->get_Comprimento_A() - pEntidade2->get_Y();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() >= pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() <= pEntidade2->get_Comprimento_A()) ) {
			
			comprimento_direita = pEntidade_Ref->get_Altura();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() > pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() > pEntidade2->get_Comprimento_A())) {

			comprimento_direita = pEntidade2->get_Comprimento_A() - pEntidade_Ref->get_Y();
			colisao = true;
		}
	}

	//Esquerda
	if (verifica_Colisao_Esquerda(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_Y() < pEntidade2->get_Y()) && (pEntidade2->get_Y() < pEntidade_Ref->get_Comprimento_A())) {

			comprimento_esquerda = pEntidade_Ref->get_Comprimento_A() - pEntidade2->get_Y();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() >= pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() <= pEntidade2->get_Comprimento_A())) {

			comprimento_esquerda = pEntidade_Ref->get_Altura();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() > pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() > pEntidade2->get_Comprimento_A())) {

			comprimento_esquerda = pEntidade2->get_Comprimento_A() - pEntidade_Ref->get_Y();
			colisao = true;
		}
	}
	
	// verifica o maior lado em contato da entidade Referência com a colidida e retorna o lado colidido.
	if (colisao) {
		if (maior < comprimento_baixo) {

			maior = comprimento_baixo;
			lado = baixo;
		}

		if (maior < comprimento_cima) {

			maior = comprimento_cima;
			lado = cima;
		}
		if (maior < comprimento_direita) {

			maior = comprimento_direita;
			lado = direita;
		}
		if (maior < comprimento_esquerda) {

			maior = comprimento_esquerda;
			lado = esquerda;
		}
	}

	return lado;
}

//verifica se o objeto esta com possibilidade de colisão.
const bool Gerenciador_colisoes::verifica_Mesma_Pos(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	bool pos = true;

	// (y > y2 + a) ou (y + a < y2)
	if ((pEntidade_Ref->get_Y() > pEntidade2->get_Comprimento_A()) ||
		(pEntidade_Ref->get_Comprimento_A() < pEntidade2->get_Y())) {
		pos = false;
	}
	// (x > x2 + l) ou (x + l < x2)
	else if ((pEntidade_Ref->get_X() > pEntidade2->get_Comprimento_L()) ||
		(pEntidade_Ref->get_Comprimento_L() < pEntidade2->get_X())) {
		pos = false;
	}

	return pos;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Cima(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		// (y <= y2 + a) && (y + a >= y2 + a)
		if ((pEntidade_Ref->get_Y() <= pEntidade2->get_Comprimento_A()) &&
			(pEntidade_Ref->get_Comprimento_A() >= pEntidade2->get_Comprimento_A()))
		{
			return true;
		}
	}

	return false;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Esquerda(Entidade* pEntidade_Ref, Entidade* pEntidade2) {


	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		// (x <= x2 + l) && (x + l >= x2 + l)
		if ((pEntidade_Ref->get_X() <= pEntidade2->get_Comprimento_L()) &&
			(pEntidade_Ref->get_Comprimento_L() >= pEntidade2->get_Comprimento_L()))
		{
			return true;
		}

	}

	return false;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Baixo(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		//(y + a >= y2) && (y + a <= y2 + h)
		if ((pEntidade_Ref->get_Comprimento_A() >= pEntidade2->get_Y()) &&
			(pEntidade_Ref->get_Comprimento_A() <= pEntidade2->get_Comprimento_A()))
		{
			return true;

		}
	}

	return false;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Direita(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		// (x <= x2) && (x + l => x2)
		if ((pEntidade_Ref->get_X() <= pEntidade2->get_X()) &&
			(pEntidade_Ref->get_Comprimento_L() >= pEntidade2->get_X()))
		{
			return true;
		}
	}

	return false;
}

void Gerenciador_colisoes::Executar(){

	//tratar_Fisica_Jogadores();
	//tratar_Fisica_Obstaculos();
	//tratar_Fisica_Inimigos();


	tratar_Colisoes_Obstaculo(static_cast<Entidade*>(pJogador1));
	if (pJogador2) {
		tratar_Colisoes_Obstaculo(static_cast<Entidade*>(pJogador2));
	}

	tratar_Colisoes_Inimigos();

}
