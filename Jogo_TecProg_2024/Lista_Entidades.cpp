#include "Lista_Entidades.h"

using namespace Entidades;
using namespace Listas;

Lista_Entidades::Lista_Entidades() {

}

Lista_Entidades::~Lista_Entidades() {

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


Lista_Entidades* Lista_Entidades::get_Lista_Entidades() {

	return this;
}

