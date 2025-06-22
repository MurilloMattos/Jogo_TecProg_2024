#pragma once
#include "Fase.h"
namespace Fases {
	class TorreFogo : public Fase {
	private:
		
	public:
		TorreFogo();
		~TorreFogo();

		void Cria_Inimigo_Dificeis();
		void Cria_Obstaculos_Faceis();
		void Executar();	
	};

}
