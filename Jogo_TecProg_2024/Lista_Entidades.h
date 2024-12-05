#pragma once
#include "Entidade.h"
#include "Lista.h"

namespace Listas {
	using namespace Listas;
	using namespace Entidades;

	class Lista_Entidades
	{
		private:
			Lista<Entidade> lista_Ent;

		public:
			Lista_Entidades();
			~Lista_Entidades();

			Lista_Entidades* get_Lista_Entidades();

			void Incluir(Entidade* pE);
			void Percorrer();
	};

}