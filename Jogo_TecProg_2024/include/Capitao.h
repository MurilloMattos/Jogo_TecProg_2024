#pragma once
#include "Inimigo.h"
#include "Projetil.h"

namespace Entidades {
	namespace Personagens {

		class Capitao : public Inimigo
		{

			private:
				std::vector<Projetil*> p;
				std::vector<Projetil*>::iterator it;
				bool atacar;
			public:
				 Capitao();
				~Capitao();
				
				void Executar();
				void Salvar();
				void Atualizar();
				bool obtem_Fim();
				Projetil *retorna_Atual();
				void operator++();
				void get_Inicio();
				void limpar_VetorProjeteis();
			        	
		};
	}
}
