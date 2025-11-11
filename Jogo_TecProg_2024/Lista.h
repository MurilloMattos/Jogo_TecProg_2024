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

		//percorrer a lista, dever� ser implementada por outra classe, no caso, j� possu� dentor do UML b�sico do jogo o listaEntidades
		//po�s � necess�rio saber oque deve ser buscado.
	};

	template<class TL>
	Lista<TL>::Lista() {
		aterrar();
	}

	template<class TL>
	Lista<TL>::~Lista() {
		deletaLista();
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
	void Lista<TL>::deletaLista() {

		Elemento<TL>* aux = nullptr;
		Elemento<TL>* aux1 = nullptr;
		
		aux = getPrimeiro();
		aux1 = getPrimeiro()->getProx();

		if (aux != nullptr) {

			while (aux1 != nullptr) {

				delete aux;
				aux = aux1;
				aux1 = aux->getProx();
			}

			delete aux;
		}
		aux = nullptr;
		aux1 = nullptr;
		aterrar();
	}

	template<class TL>
	void Lista<TL>::incluiElemento(Elemento<TL>* novoElemento) {

		if (novoElemento != nullptr) {

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

			std::cout << "Erro, elemento nullo, n�o adicionado na lista!" << std::endl;
		}

	}
}
