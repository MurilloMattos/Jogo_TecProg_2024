#pragma once
#include "Fase.h"
#include "Obstaculo_Dificil.h"
namespace Fases {
	class TorreFogo : public Fase {
	private:
		
	public:
		TorreFogo();
		~TorreFogo();

		void Cria_Inimigo_Dificeis();
		void Cria_Obstaculos_Medios();
		void Executar();	
	};

}
