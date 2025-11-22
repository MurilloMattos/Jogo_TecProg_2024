#include "Listas/Lista_Entidades.h"

using namespace Entidades;
using namespace Listas;

Lista_Entidades::Lista_Entidades() {

}


Lista_Entidades::~Lista_Entidades() {

	//A lista j� � deletada pelo template
}

void Lista_Entidades::Remover(Entidade* pE) {

	if (pE != nullptr) {

		// Usa rotina segura do template Lista para remover o elemento que cont�m o ponteiro pE
		bool removido = lista_Ent.removeInfo(pE);

		if (removido) {
			std::cout << "eliminando a Entidade " << pE->getId() << std::endl;
			delete pE;
		}
		else {
			std::cout << "Nao encontrado" << std::endl;
		}
	}
}

void Lista_Entidades::Incluir(Entidade* pE) {
	lista_Ent.incluiInfoNaLista(pE);
}

void Lista_Entidades::Percorrer() {

	Lista<Entidade>::Elemento<Entidade>* aux, * aux1;

	aux = nullptr;
	aux1 = nullptr;

	aux = lista_Ent.getPrimeiro();
	aux1 = aux->getProx();

	if (aux != nullptr) {

		while (aux1 != nullptr)
		{
			aux->getInfo()->executar_Gravidade();
			aux->getInfo()->Executar();

			aux = aux1;
			aux1 = aux->getProx();
		}

		aux->getInfo()->executar_Gravidade();
		aux->getInfo()->Executar();
	}
	else {
		std::cout << " Lista vazia, nao percorrida. ";
	}

}

void Listas::Lista_Entidades::imprimir_Ids()
{
	Lista<Entidade>::Elemento<Entidade>* aux, * aux1;

	aux = nullptr;
	aux1 = nullptr;

	aux = lista_Ent.getPrimeiro();
	aux1 = aux->getProx();

	if (aux != nullptr) {

		while (aux1 != nullptr)
		{
			std::cout << "ID:" << aux->getInfo()->getId() << " prox:" << aux->getProx()->getInfo()->getId()<< " " << std::endl;

			aux = aux1;
			aux1 = aux->getProx();
		}

		std::cout << aux->getInfo()->getId() << std::endl;
	}
	else {
		std::cout << " Lista vazia, nao percorrida. ";
	}
}

bool Listas::Lista_Entidades::verifica_Lista_Vazia(){

	if (lista_Ent.getPrimeiro() == nullptr) {
		return true;
	}
	else {
		return false;
	}
}


Lista_Entidades* Lista_Entidades::get_Lista_Entidades() {

	return this;
}

Entidade* Lista_Entidades::get_Entidade_Por_Id(int id_busca) {

	Lista<Entidade>::Elemento<Entidade>* aux, * aux1;
	aux = nullptr;
	aux1 = nullptr;
	aux = lista_Ent.getPrimeiro();
	aux1 = aux->getProx();

	if (aux != nullptr) {
		while (aux1 != nullptr)
		{
			if (aux->getInfo()->getId() == id_busca) {
				return aux->getInfo();
			}
			aux = aux1;
			aux1 = aux->getProx();
		}
		if (aux->getInfo()->getId() == id_busca) {
			return aux->getInfo();
		}
	}

	else {
		std::cout << " Lista vazia, nao percorrida. ";
	}

	return nullptr;
}

const int Lista_Entidades::get_Tamanho_Da_Lista() const {
	return lista_Ent.get_Tamanho_Da_Lista();
}
