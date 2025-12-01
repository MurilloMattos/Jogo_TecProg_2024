#pragma once
#include "Entidades/Obstaculos/Obstaculo.h"
#include "Entidades/Projetil.h"
#include "Entidades/Personagens/Personagem.h"

namespace Entidades {
	namespace Obstaculos {

		class Espinhos :public Obstaculo
		{
			private:

				int dano;
				int dano_sangramento;
				int dano_espinho;

				bool soltar_espinho;
				//bool espinho_ativo;

				bool sangramento;
				int duracao_sangramento;

				float empurrar;
				
				int fragilidade_espinho;
				int tempo_para_cair_espinho;

				Entidades::Projetil* espinho;

			public:
				Espinhos();
				~Espinhos();

				void Salvar();
				void Executar();

				void setar_Espinhos(float pos_plat_x, float pos_embaixo_plat_y, float tam_plat_x);

				void obstacular(Entidades::Personagens::Jogador* p, int lado);
				void danificar(Entidades::Personagens::Personagem* pAtacado);

				void setar_Espinho(Entidades::Projetil* esp);
				bool get_Soltar_Espinho();

				void desativar_Espinho();
				Entidades::Projetil* get_Espinho();
				
		};
	}
}



