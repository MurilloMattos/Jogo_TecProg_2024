#pragma once
#include "Fase.h"
#include "Capitao.h"
#include "Obstaculo_Medio.h"
#include "Obstaculo_Dificil.h"
namespace Fases{

	class Fase_1 : public Fase
	{
	private:

		//Entidades::Personagens::Capitao *capitao;

	public:

		Fase_1();
		~Fase_1();

		void Executar();
		void Cria_Inimigos();
		void Cria_Inimigos_Capitao();
		void Cria_Obstaculos_Medios(); 

	};
}
