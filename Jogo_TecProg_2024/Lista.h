#pragma once

namespace Listas 
{

	template <class TL>
	class Lista
	{
	public:
		template<class TE>
		class Elemento {

		private:
			Elemento<TE>* pontProx;
			TE* pontInfoTipo;

		public:
			Elemento() {
				pontInfoTipo = nullptr;
				pontProx = nullptr;
			}
			~Elemento() {};

			void setProximo(Elemento<TE>* pontP) {
				pontProx = pontP;
			}

			Elemento<TE>* getProx() const{
				return pontProx;
			}

			void setInfo(TE* pInfo) {
				pontInfoTipo = pInfo;
			}

			TE* getInfo() const {
				return pontInfoTipo;
			}
		};
		

	private:

		int tamanho_da_lista;
		Elemento<TL>* pontPrimeiro;
		Elemento<TL>* pontUltimo;
		
		void incluiElemento(Elemento<TL>* novoElemento);

	public:
		Lista();
		~Lista();

		Elemento<TL>* getPrimeiro() const{

			return pontPrimeiro;
		}

		Elemento<TL>* getUltimo() const{

			return pontUltimo;
		}

		void aterrar();
		void incluiInfoNaLista(TL* info);
		void deletaLista();
		int get_Tamanho_Da_Lista() const;
		
		// remove o elemento que contém o ponteiro info. Retorna true se removido.
		bool removeInfo(TL* info);

		//percorrer a lista, deverá ser implementada por outra classe, no caso, já possuí dentor do UML básico do jogo o listaEntidades
		//poís é necessário saber oque deve ser buscado.
	};

	template<class TL>
	Lista<TL>::Lista() {
		aterrar();
		tamanho_da_lista = 0;
	}

	template<class TL>
	Lista<TL>::~Lista() {
		deletaLista();
		tamanho_da_lista = 0;
	}

	template<class TL>
	void Lista<TL>::aterrar() {
		pontPrimeiro = nullptr;
		pontUltimo = nullptr;
	}

	template<class TL>
	void Lista<TL>::incluiInfoNaLista(TL* info) {

		if(info != nullptr){

			Elemento<TL>* novoE;
			novoE = new Elemento<TL>;

			novoE->setInfo(info);

			incluiElemento(novoE);
		}
		else {
			std::cout << "Info errada, erro Lista.h" << std::endl;
		}

	}

	template<class TL>
	int Lista<TL>::get_Tamanho_Da_Lista() const {
		return tamanho_da_lista;
	}

	template<class TL>
	void Lista<TL>::deletaLista() {

		Elemento<TL>* aux = nullptr;
		Elemento<TL>* aux1 = nullptr;
		
		aux = getPrimeiro();
		if (aux == nullptr) {
			// lista vazia
			aterrar();
			return;
		}
		aux1 = aux->getProx();

		if (aux != nullptr) {

			while (aux1 != nullptr) {

				tamanho_da_lista--;
				delete aux;
				aux = aux1;
				aux1 = aux->getProx();
			}

			tamanho_da_lista--;
			delete aux;
		}
		aux = nullptr;
		aux1 = nullptr;
		aterrar();
	}

	template<class TL>
	void Lista<TL>::incluiElemento(Elemento<TL>* novoElemento) {

		if (novoElemento != nullptr) {

			tamanho_da_lista++;

			if (pontPrimeiro == nullptr) {

				pontPrimeiro = novoElemento;
				pontUltimo = novoElemento;
				novoElemento->setProximo(nullptr);
			}
			else {

				pontUltimo->setProximo(novoElemento);
				pontUltimo = novoElemento;
				novoElemento->setProximo(nullptr);
			}
		}
		else {

			std::cout << "Erro, elemento nullo, não adicionado na lista!";
		}

	}

	// Implementação do método de remoção por ponteiro de info.
	template<class TL>
	bool Lista<TL>::removeInfo(TL* info) {

		if (info == nullptr || pontPrimeiro == nullptr) {
			return false;
		}

		Elemento<TL>* anterior = nullptr;
		Elemento<TL>* atual = pontPrimeiro;

		while (atual != nullptr) {

			if (atual->getInfo() == info) {
				// remove atual

				if (anterior == nullptr) {
					// removendo o primeiro elemento
					pontPrimeiro = atual->getProx();
					if (pontPrimeiro == nullptr) {
						pontUltimo = nullptr;
					}
				}
				else {
					anterior->setProximo(atual->getProx());
					if (atual == pontUltimo) {
						pontUltimo = anterior;
					}
				}

				tamanho_da_lista--;
				delete atual; // deleta apenas o elemento da lista (não o objeto info em si)
				return true;
			}

			anterior = atual;
			atual = atual->getProx();
		}

		return false; // não encontrado
	}
}
