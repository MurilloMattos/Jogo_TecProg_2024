#pragma once
#include "Entidades/Entidade.h"

namespace Entidades {

	namespace Personagens {
		class Capitao;
	}
	namespace Personagens {
		class Jogador;
	}


	class Projetil : public Entidade
	{
		const int semente_id_entidade;
		bool ativo;
		int lado;
		int dano;
		int tempo_de_vida;
		int tempo_ativo;
		bool atingiu_jogador;

		
		Entidades::Entidade* entidade_pertencedoura;

	public:

		Projetil();
		Projetil(float x, float y, int lado);

		~Projetil();


		void setar_Ativo(bool atv);
		void setar_Dano(int dan);
		void setar_Direcao(int direcao);
		void setar_Entidade(Entidades::Entidade* entedad);

		int get_Dano();
		bool get_Ativo();
		void atingiu_Jogador(Entidades::Personagens::Jogador* pJogador);

		void executar_Gravidade();
		void Executar();
		void Salvar();

		void setar_Cor(sf::Color cor);
	};
}