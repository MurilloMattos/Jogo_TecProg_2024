#pragma once
#include "Entidade.h"
#include <cmath>
namespace Entidades {

	namespace Personagens {

		class Personagem : public Entidade
		{
		protected:
			int num_vitalidade;
			int dano;
			sf::Vector2f tamanho;
			float angulo;

		public:
			Personagem();
			~Personagem();

			void setar_Vitalidade(int vida);
			void diminuir_Vitalidade(int dano);
			int get_Vitalidade();
			int danificar();

			virtual void Salvar() = 0;
			virtual void Executar() = 0;
			unsigned int coordenada_Polar();
			unsigned int distancia(Personagem *p); 
			sf::Vector2f coordenada_Polar(Personagem *p);
			float get_Angulo()const;
		};
	}
}
