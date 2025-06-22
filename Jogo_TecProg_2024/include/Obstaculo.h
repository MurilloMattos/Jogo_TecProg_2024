#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {

	namespace Obstaculos {

		class Obstaculo : public Entidade
		{
			protected:
				bool agressivo;
				const int semente_id_entidade;

			public:
				Obstaculo();
				~Obstaculo();

				virtual void executar_Gravidade();
				virtual void Salvar() = 0;
				virtual void Executar() = 0;
				virtual void obstacular(Entidades::Personagens::Jogador* p) = 0;
		};
	}
}
