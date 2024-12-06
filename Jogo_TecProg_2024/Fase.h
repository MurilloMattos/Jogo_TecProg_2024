#pragma once
#include "Ente.h"
#include "Lista_Entidades.h"
#include "Piso.h"
#include "Inimigo_Medio.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"

namespace Fases {
	class Fase : public Ente
	{
		private:
			Listas::Lista_Entidades lista_Entidades;
			Entidades::Obstaculos::Piso* piso;


		public:
			Fase();
			~Fase();

			void Setar_Jogadores_Colisoes(Entidades::Personagens::Jogador* p_jogador1, Entidades::Personagens::Jogador* p_jogador2);
			void Executar();
			void Cria_Piso();
			Entidades::Personagens::Inimigo_Medio* Cria_Inimigos();

	};
}