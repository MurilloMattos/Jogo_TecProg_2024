#pragma once
#include "Gerenciador_Grafico.h"
#include "Ente.h"
#include <iostream>
//#include "Lista.h"
#include "Jogador.h"
#include "Fase.h"


using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Fases;
//using namespace Listas;

class Jogo
{
	private:
		Gerenciador_Grafico* Ger_Graf;
		Jogador jogador_1;
		Fase fase1;

	public:
		Jogo();
		~Jogo();
		void Executar();
		void Atualiza_cam();
		void Atualiza();

};