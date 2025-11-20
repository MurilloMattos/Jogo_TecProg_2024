#pragma once
#include "Entidades/Entidade.h"
#include "Listas/Lista.h"

namespace Listas {

	class Lista_Entidades
	{
		private:
			Listas::Lista<Entidades::Entidade> lista_Ent;

		public:
			Lista_Entidades();
			~Lista_Entidades();

			Lista_Entidades* get_Lista_Entidades();

			Entidades::Entidade* get_Entidade_Por_Id(int id_busca);

			void Remover(Entidades::Entidade* pE);
			void Incluir(Entidades::Entidade* pE);
			void Percorrer();

			void imprimir_Ids();

			bool verifica_Lista_Vazia();

			const int get_Tamanho_Da_Lista() const;
	};

}