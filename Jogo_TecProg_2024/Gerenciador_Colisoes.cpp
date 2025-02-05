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
	system("CLS");

	//verifica o tipo de colisão especificamente com objetos.
	while (itr != lista_Obstaculos.end()) {


		if (verifica_Colisao_Cima(static_cast<Entidade*>(pEntidadeRef), static_cast<Entidade*>(*itr))) {

			pEntidadeRef->setar_Pos(pEntidadeRef->get_X(), ((*itr)->get_Y() + (*itr)->get_Altura()) + pEntidadeRef->get_Altura());

			std::cout << "colisao em Cima." << std::endl;
		}
		if (verifica_Colisao_Baixo(static_cast<Entidade*>(pEntidadeRef), static_cast<Entidade*>(*itr))) {

			pEntidadeRef->setar_Pos(pEntidadeRef->get_X(), ((*itr)->get_Y() - pEntidadeRef->get_Altura()));

			//std::cout << "colisao em Baixo." << std::endl;
		}
		if (verifica_Colisao_Direita(static_cast<Entidade*>(pEntidadeRef), static_cast<Entidade*>(*itr))) {

			pEntidadeRef->setar_Pos(((*itr)->get_X() + (*itr)->get_Largura()), pEntidadeRef->get_Y());

			std::cout << "colisao a Direita." << std::endl;
		}
		if (verifica_Colisao_Esquerda(static_cast<Entidade*>(pEntidadeRef), static_cast<Entidade*>(*itr))) {

			pEntidadeRef->setar_Pos(((*itr)->get_X() + pEntidadeRef->get_X() + pEntidadeRef->get_Largura()), pEntidadeRef->get_Y());

			std::cout << "colisao a Esquerda." << std::endl;
		}


		itr++;
	}
}

void Gerenciador_colisoes::tratar_Colisoes_Inimigos(){

	int i;

	std::cout << lista_Inimigos.size() << endl;
	//system("pause");

	for (i = 0; i < lista_Inimigos.size(); i++) {

		std::cout << lista_Inimigos[i]->get_X() << ", " << lista_Inimigos[i]->get_Y() << " altura: " << (lista_Inimigos[i]->get_Altura()+lista_Inimigos[i]->get_Y()) << std::endl;
		std::cout << pJogador1->get_X() << ", " << pJogador1->get_Y() << " altura: " << (pJogador1->get_Altura() + pJogador1->get_Y()) << std::endl;
		//std::cout << pJogador1->get_X();

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


void Gerenciador_colisoes::tratar_Colisoes_Jogador_Inimigos(Jogador* pJogador, Inimigo* pInimigo) {

	//em relação ao jogador, se a colisão for em baixo dele em inimigos, aplica dano do jogador para inimigo
	//ademais aplica dano ao jogador
	if (verifica_Colisao_Baixo(static_cast<Entidade*>(pJogador), static_cast<Entidade*>(pInimigo))) {

		pJogador->setar_Pos(pJogador->get_X(), (pInimigo->get_Y() - pJogador->get_Altura()));

		//system("pause");

	}
	else if (verifica_Colisao_Direita(static_cast<Entidade*>(pJogador), static_cast<Entidade*>(pInimigo))) {

		pJogador->setar_Pos((pInimigo->get_X() - pJogador->get_Largura()), pJogador->get_Y());

		//system("pause");

	}
	else if (verifica_Colisao_Esquerda(static_cast<Entidade*>(pJogador), static_cast<Entidade*>(pInimigo))) {

		pJogador->setar_Pos((pInimigo->get_X() + pInimigo->get_Largura()), pJogador->get_Y());

	}
	else if (verifica_Colisao_Cima(static_cast<Entidade*>(pJogador), static_cast<Entidade*>(pInimigo))) {

		pJogador->setar_Pos(pJogador->get_X(), (pInimigo->get_Altura() + pInimigo->get_Y()));

	}
}




//verifica se está em colisão
const bool Gerenciador_colisoes::verifica_Mesma_Pos(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	bool pos = true;

	// (y > y2 + a) ou (y + a < y2)
	if ((pEntidade_Ref->get_Y() > (pEntidade2->get_Y() + pEntidade2->get_Altura())) ||
		((pEntidade_Ref->get_Y() + pEntidade_Ref->get_Altura()) < pEntidade2->get_Y())) {
		pos = false;
	}
	// (x > x2 + l) ou (x + l < x2)
	else if ((pEntidade_Ref->get_X() > (pEntidade2->get_X() + pEntidade2->get_Largura()) ||
		(pEntidade_Ref->get_X() + pEntidade_Ref->get_Largura()) < pEntidade2->get_X())) {
		pos = false;
	}

	return pos;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Cima(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	cima = false;

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		cima = false;
	}
	else {

		// (y <= y2 + a) && (y + a >= y2 + a)
		if (((pEntidade_Ref->get_Y()) < (pEntidade2->get_Y() + pEntidade2->get_Altura())) &&
			((pEntidade_Ref->get_Y() + (pEntidade_Ref->get_Altura())) > (pEntidade2->get_Y() + (pEntidade2->get_Altura() / 2))))
		{

			if (pEntidade_Ref->get_X() < pEntidade2->get_X()) {

				if (( (pEntidade_Ref->get_X() + pEntidade_Ref->get_Largura()) - pEntidade2->get_X()) >= 0.0f) {
					cima = true;
					std::cout << "colisao em Cima." << std::endl;
				}
			}
			else if (((pEntidade2->get_X() + pEntidade2->get_Largura()) - pEntidade_Ref->get_X()) >= 0.0f) {
				cima = true;
				std::cout << "colisao em Cima." << std::endl;
			}
		}
	}

	return cima;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Esquerda(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	esquerda = false;


	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		esquerda = false;
	}
	else {

		// (x <= x2 + l) && (x + l/2 >= x2 + l)
		if ((pEntidade_Ref->get_X() < (pEntidade2->get_X() + pEntidade2->get_Largura())) &&
			((pEntidade_Ref->get_X() + (pEntidade_Ref->get_Largura())) > (pEntidade2->get_X() + pEntidade2->get_Largura())))
		{
			if (pEntidade_Ref->get_Y() > pEntidade2->get_Y()) {
				if ( ((pEntidade_Ref->get_Y() + pEntidade_Ref->get_Altura()) - pEntidade2->get_Y()) >= 1.0f ) {
					esquerda = true;
					std::cout << "colisao em Esquerda." << std::endl;
				}
			}
			else if ( ((pEntidade2->get_Y() + pEntidade2->get_Altura()) - pEntidade_Ref->get_Y()) >= 1.0f ) {
				esquerda = true;
				std::cout << "colisao em Esquerda." << std::endl;
			}
			
		}

	}

	return esquerda;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Baixo(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	baixo = false;

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		baixo = false;
	}
	else {

		//(y + a >= y2) && (y + a <= y2 + h/2)
		if (((pEntidade_Ref->get_Y() + pEntidade_Ref->get_Altura()) > (pEntidade2->get_Y() + 1.0f)) &&
			((pEntidade_Ref->get_Y() + pEntidade_Ref->get_Altura()) < (pEntidade2->get_Y() + pEntidade2->get_Altura())))
		{
			if (pEntidade_Ref->get_X() < pEntidade2->get_X()) {

				if (((pEntidade_Ref->get_X() + pEntidade_Ref->get_Largura()) - pEntidade2->get_X()) >= 0.0f) {
					baixo = true;
					std::cout << "colisao em Cima." << std::endl;
				}
			}
			else if (((pEntidade2->get_X() + pEntidade2->get_Largura()) - pEntidade_Ref->get_X()) >= 0.0f) {
				baixo = true;
				std::cout << "colisao em Cima." << std::endl;
			}

		}
	}

	return baixo;
}



//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Direita(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	direita = false;

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		direita = false;
	}
	else {

		// (x < x2) && (x + l > x2)
		if ((pEntidade_Ref->get_X() < pEntidade2->get_X()) &&
			((pEntidade_Ref->get_X() + pEntidade_Ref->get_Largura()) > pEntidade2->get_X()))
		{
			if (pEntidade_Ref->get_Y() > pEntidade2->get_Y()) {
				if ( ((pEntidade_Ref->get_Y() + pEntidade_Ref->get_Altura()) - pEntidade2->get_Y()) >= 1.0f ) {
					direita = true;
					std::cout << "colisao em Esquerda." << std::endl;
				}
			}
			else if ( ((pEntidade2->get_Y() + pEntidade2->get_Altura()) - pEntidade_Ref->get_Y()) >= 1.0f ) {
				direita = true;
				std::cout << "colisao em Esquerda." << std::endl;
			}
		}

	}

	return direita;
}

void Gerenciador_colisoes::Executar(){
	//tratar_Fisica();

	//tratar_Fisica_Jogadores();
	tratar_Fisica_Obstaculos();
	//tratar_Fisica_Inimigos();
	

	tratar_Colisoes_Obstaculo(static_cast<Entidade*>(pJogador1));

	if (pJogador2) {
		tratar_Colisoes_Obstaculo(static_cast<Entidade*>(pJogador2));
	}
	tratar_Colisoes_Inimigos();

	//tratar_Colisoes_Jogador_Obstaculo(pJogador1);
	//tratar_Colisoes_Jogador_Obstaculo(pJogador2);

}
