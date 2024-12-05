#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {

		class Obstaculo_Facil :public Obstaculo
		{
			private:
				//definir oq vai fazer esse obstáculo;

			public:
				Obstaculo_Facil();
				~Obstaculo_Facil();

				void executar();
				void danificar(Jogador* p);
		};
	}
}