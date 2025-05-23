#pragma once
#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {

		class Inimigo_Facil : public Inimigo
		{
			private:
				int tamanho;

			public:
				Inimigo_Facil();
				~Inimigo_Facil();

				void Executar();
				void Danificar();
				void salvar();
		};
	}
}