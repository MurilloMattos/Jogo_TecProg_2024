#pragma once
#include "Personagem.h"
//#include "Jogador.h"
namespace Fases {
	class Fase;
}
//#include "Fase.h"
namespace Entidades {
	namespace Personagens {
		class Inimigo : public Personagem
		{
			protected:
				int nivel_raiva;
				const int semente_id_entidade;
				//int dano;
				bool atacar;
				Fases::Fase *fase;
				sf::Vector2f pos_inicial;
				sf::Vector2f pos_final;
			public:
				Inimigo();
				~Inimigo();
				//void setar_Jogador_No_Inimigo(Entidades::Personagens::Jogador* pJogador1, Entidades::Personagens::Jogador* pJogador2);
				virtual void andar_ate(float em_x, float em_y);
				virtual void Salvar() = 0;
				//virtual void Danificar() = 0;
				virtual void Executar() = 0;
				virtual void Atualizar() = 0;
				void set_Atacar(bool b);
				bool get_Atacar() const;
				void associa_Fase(Fases::Fase *f);
		};
	}
}
