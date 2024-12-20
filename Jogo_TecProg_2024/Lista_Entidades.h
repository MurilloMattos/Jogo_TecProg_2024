#pragma once
#include "Entidade.h"
#include "Lista.h"

namespace Listas {

	class Lista_Entidades
	{
		private:
			Listas::Lista<Entidades::Entidade> lista_Ent;

		public:
			Lista_Entidades();
			~Lista_Entidades();

			Lista_Entidades* get_Lista_Entidades();

			void Incluir(Entidades::Entidade* pE);
			void Percorrer();
	};

}