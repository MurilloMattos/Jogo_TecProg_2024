#pragma once
#include "Ente.h"
#include "Lista_Entidades.h"
#include "Piso.h"
#include "Inimigo_Medio.h"
#include "Jogador.h"
//#include "Gerenciador_Colisoes.h"

//using namespace Listas;
//using namespace Entidades;
//using namespace Obstaculos;
//using namespace Personagens;
//using namespace Gerenciadores;
//using namespace Ente;

namespace Fases {
	class Fase : public Ente
	{
		private:
			Listas::Lista_Entidades lista_Entidades;
			Obstaculos::Piso* piso;


		public:
			Fase();
			~Fase();

			void Setar_Jogadores_Colisoes(Personagens::Jogador* p_jogador1, Personagens::Jogador* p_jogador2);
			void Executar();
			void cria_Piso();
			Personagens::Inimigo_Medio* cria_Inimigos();

	};
}