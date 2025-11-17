#pragma once
#include "Entidade.h"

namespace Entidades {

	namespace Personagens {
		class Capitao;
	}


	class Projetil : public Entidade
	{
		const int semente_id_entidade;
		bool ativo;
		int lado;
		int dano;
		int tempo_de_vida;
		int tempo_ativo;

		
		Entidades::Personagens::Capitao* cap;

		const int direita, cima, esquerda, baixo;

	public:

		Projetil();
		Projetil(float x, float y, int lado);

		~Projetil();


		void setar_Ativo(bool atv);
		void setar_Dano(int dan);
		void setar_Direcao(int direcao);
		void setar_Capitao(Entidades::Personagens::Capitao* capitao);

		int get_Dano();
		bool get_Ativo();

		void executar_Gravidade();
		void Executar();
		void Salvar();
	};
}