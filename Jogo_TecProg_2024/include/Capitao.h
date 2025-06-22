#pragma once
#include "Inimigo.h"
#include "Projetil.h"

namespace Entidades {
	namespace Personagens {

		class Capitao : public Inimigo
		{


			public:
				Capitao();
				~Capitao();
				
				void Executar();
				void Salvar();

		};
	}
}
