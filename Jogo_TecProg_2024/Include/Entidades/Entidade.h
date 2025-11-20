#pragma once
#include "Entidades/Ente.h"

namespace Entidades 
{
	class Entidade : public Ente
	{
	protected:
		float x, y;
		float gravidade;
		bool agressivo;
		//const int semente_id_jogador;
		//const int id_set;


		//est� faltando o ostream para escrever em arquivos, utilizado para salvar e carregar um bloco de notas por exemplo.

		sf::Vector2f aceleracao;
		sf::Vector2f velocidade;
		sf::Vector2f velocidade_inicial;
		sf::Vector2f centro;

	public:
		Entidade();
		~Entidade();

		float get_Gravidade() const;
		void setar_Gravidade(float grav);
		virtual void executar_Gravidade();


		// escolhi deixar o pFigura mais restrito.
		sf::Vector2f get_Centro();

		float get_Largura();
		float get_Altura();

		float get_Comprimento_A();
		float get_Comprimento_L();

		float get_X() const;
		float get_Y() const;
		void setar_Pos(float pos_x, float pos_y);
		void setar_velocidade(float vel_x, float vel_y);

		virtual void Executar() = 0;
		virtual void Salvar() = 0;

	};

}