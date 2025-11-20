#pragma once
#include "Entidades/Personagens/Inimigos/Inimigo.h"
#include "Entidades/Projetil.h"

namespace Entidades {
	namespace Personagens {

		class Inimigo_Capitao : public Inimigo
		{

			bool disparou;
			int recarga;
			bool pode_disparar;

			sf::Vector2f velocidade_proj;


			std::vector<Entidades::Projetil*> disparos;

			int dano_do_balote;

			public:
				Inimigo_Capitao();
				~Inimigo_Capitao();
				
				const bool get_Disparou();

				void incluir_Projetil(Projetil* projet);
				void remover_Projetil(Projetil* projet);

				std::vector<Entidades::Projetil*>* get_Vetor_De_Projetis();
				void imprime_Projeteis_Ids_Ativos_e_Pos();

				void Executar();
				void Salvar();

		};
	}
}
