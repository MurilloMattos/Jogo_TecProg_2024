//Obstaculo_Facil

#pragma once
#include "Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {

		class Plataforma :public Obstaculo
		{
			private:
				//definir oq vai fazer esse obst�culo;

			public:
				Plataforma();
				~Plataforma();

				void executar();
				void obstacular(Entidades::Personagens::Jogador* p);
		};
	}
}