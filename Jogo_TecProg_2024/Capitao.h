#pragma once
#include "Inimigo.h"
#include "Projetil.h"

namespace Entidades {
	namespace Personagens {

		class Capitao : public Inimigo
		{

			bool disparou;
			int recarga;

			sf::Vector2f velocidade_proj;

			sf::Vector2f velocidade_proj;


			std::vector<Entidades::Projetil*> disparos;

			int dano_do_balote;

			public:
				Capitao();
				~Capitao();
				
				const bool get_Disparou();

				void incluir_Projetil(Projetil* projet);
				void remover_Projetil(Projetil* projet);

				void Executar();
				void Salvar();

		};
	}
}
