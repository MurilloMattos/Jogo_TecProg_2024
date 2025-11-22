#pragma once
#include "Entidades/Obstaculos/Obstaculo.h"

namespace Entidades {
	namespace Obstaculos {

		class Obstaculo_Facil :public Obstaculo
		{
			private:
				//definir oq vai fazer esse obst�culo;

			public:
				Obstaculo_Facil();
				~Obstaculo_Facil();

				void executar();
				void danificar(Entidades::Personagens::Jogador* p);
				void Obstacular(Entidades::Personagens::Jogador* p, int lado);
		};
	}
}