#pragma once
#include "Entidade.h"

namespace Entidades {

	class Projetil : public Entidade
	{
		const int semente_id_entidade;
		bool ativo;
		int lado;
		int dano;

		const int direita, cima, esquerda, baixo;

	public:

		Projetil();
		Projetil(float x, float y, int lado);

		~Projetil();


		void setar_Ativo(bool atv);
		void setar_Dano(int dan);

		int get_Dano();

		void executar_Gravidade();
		void Executar();
		void Salvar();
	};
}