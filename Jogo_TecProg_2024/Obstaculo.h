#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Entidades {

	namespace Obstaculos {

		using namespace Personagens;

		class Obstaculo : public Entidade
		{
			protected:
				bool agressivo;

			public:
				Obstaculo();
				~Obstaculo();

				virtual void Salvar() = 0;
				virtual void Executar() = 0;
				virtual void obstacular(Jogador* p) = 0;
		};
	}
}