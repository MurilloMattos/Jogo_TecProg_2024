#pragma once
#include "Fase.h"
#include "Capitao.h"
#include "Piratas.h"
#include "Piso.h"
#include "Obstaculo.h"

namespace Fases{
	class Fase_1 : public Fase
	{
	private:

	Entidades::Obstaculos::Piso* piso;
	Entidades::Obstaculos::Piso* plataforma;
	Entidades::Personagens::Piratas* pirata;
	Entidades::Personagens::Capitao* capitao;



	sf::Vector2f tam_Piso_Fase;
	sf::Vector2f pos_Piso;

	int num_plataformas;

	sf::Vector2f tam_plataforma;
	sf::Vector2f pos_original;

	public:

		Fase_1();
		~Fase_1();

		//piso é inerente as fases e a plataforma  obstáculo nas 2 fases.
		void Cria_Piso();
		void Cria_Plataforma();
		void Cria_Obstaculos();
		
		//inimigos fáceis		
		void Cria_Inimigos();
		void Cria_Inimigos_Piratas();
		void Cria_Inimigos_Capitao();
		void Executar();
	};
};
