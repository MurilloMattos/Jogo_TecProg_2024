#pragma once
#include "Obstaculo.h"
namespace Entidades {
	namespace Obstaculos {

		class Obstaculo_Dificil :public Obstaculo
		{
			private:
				//definir
			public:
				Obstaculo_Dificil();
				~Obstaculo_Dificil();

				void Salvar();
				void Executar();
				void obstacular(Entidades::Personagens::Jogador* p);
		};
	}
}



