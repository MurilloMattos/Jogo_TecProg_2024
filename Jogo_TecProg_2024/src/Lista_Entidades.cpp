#include "Lista_Entidades.h"

using namespace Entidades;
using namespace Listas;

Lista_Entidades::Lista_Entidades() {

}


Lista_Entidades::~Lista_Entidades() {

	//A lista já é deletada pelo template
}

void Lista_Entidades::Remover(Entidade* pE) {

	Lista<Entidade>::Elemento<Entidade>* aux_anterior, * aux_proximo, *aux_atual;

	aux_anterior = nullptr;
	aux_atual = nullptr;
	aux_proximo = nullptr;

	aux_anterior = lista_Ent.getPrimeiro();
	aux_atual = aux_anterior->getProx();

	if (aux_anterior != nullptr && pE != nullptr) {

		//para evitar que no primeiro loop ele acesse memoria já alocada.
		if (aux_atual != nullptr) {
			while (aux_atual->getInfo()->getId() != pE->getId() || aux_atual != nullptr )
			{

				aux_anterior = aux_atual;
				aux_atual = aux_anterior->getProx();

				if (aux_atual->getInfo()->getId() == pE->getId()){
					break;
				}
			}
		}

		if (aux_atual != nullptr) {

			aux_anterior->setProximo(aux_atual->getProx());
			delete aux_atual;
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
			aux->getInfo()->Executar();

			aux = aux1;
			aux1 = aux->getProx();
		}

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
			std::cout << aux->getInfo()->getId() << std::endl;

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

	//Lista<Entidade>::Elemento<Entidade>* aux, * aux1;

	//aux = nullptr;
	//aux1 = nullptr;

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

