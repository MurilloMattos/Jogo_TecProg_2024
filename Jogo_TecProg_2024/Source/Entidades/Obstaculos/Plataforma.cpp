#include "Entidades/Obstaculos/Plataforma.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Plataforma::Plataforma()
{
	se_move = false;
	ativa = true;

	pos_final.x = x;
	pos_final.y = y;

	tamanho.x = 0;
	tamanho.y = 0;
}

Plataforma::~Plataforma(){

}

void Plataforma::seta_Plataforma(float alt, float larg, float origem_x, float origem_y)
{

	tamanho.x = larg;
	tamanho.y = alt;

	pFigura->setFillColor(sf::Color::Green);
	pFigura->setSize(tamanho);
	this->setar_Pos(origem_x, origem_y);
}

void Plataforma::Salvar(){

}



void Plataforma::Executar() {

	if(ativa){
		
		if(se_move){


		}

		Desenhar();
	}
	
}

void Plataforma::obstacular(Jogador* p, int lado) {

	if(lado == cima){
		p->setar_Bateu_A_Cabeca();
		p->setar_Estado_Pulando(true );
		p->setar_No_Ar(true);
	}
	if(lado == baixo){
		
		p->setar_Estado_Pulando(false);
		p->setar_No_Ar(false);
	}
	
}

void Plataforma::seta_Movimento(float x_esq, float x_dir, float y_cima, float y_baixo){


}