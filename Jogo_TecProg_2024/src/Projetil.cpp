#include "Projetil.h"

using namespace Entidades;

Projetil::Projetil():Entidade(), direita(1),cima(2),esquerda(3),baixo(4), semente_id_entidade(10000) {

	setId(semente_id_entidade);

	sf::Vector2f tamanho;
	tamanho.x = 10.f;
	tamanho.y = 15.f;


	x = 50.f;
	y = 159.f;

	ativo = false;
	lado = 0;

	//pFigura->setFillColor(sf::Color(222, 120, 31));
	//pFigura->setSize(tamanho);
	setFile("./assets/projetil.png");
	atribuirFigura();
        pFigura->setScale(0.3f , 0.3f);	
	pFigura->setPosition(x, y);
	setar_Pos(x , y);
}


Projetil::Projetil(float saida_x, float saida_y, int direcao) : Entidade(), direita(1),cima(2),esquerda(3),baixo(4), semente_id_entidade(10000) {

	setId(semente_id_entidade);

	sf::Vector2f tamanho;
	tamanho.x = 10.f;
	tamanho.y = 15.f;


	x = saida_x;
	y = saida_y;

	ativo = false;
	lado = direcao;

	//pFigura->setColor(sf::Color(222, 120, 31));
	setFile("./assets/projetil.png");
	atribuirFigura();
        pFigura->setScale(0.3f , 0.3f);	
	pFigura->setPosition(x, y);

}

Projetil::~Projetil(){


}

void Projetil::setar_Ativo(bool atv){
	ativo = atv;
}

void Projetil::setar_Dano(int dan){
	dano = dan;
}

int Projetil::get_Dano() {
	return dano;
}

void Projetil::executar_Gravidade() {
	y += gravidade;
	y -= gravidade;
}

void Projetil::Executar() {

	Ente::Desenhar();

	if (ativo) {

		if (lado == direita) {
			x += velocidade.x;
		}
		else if (lado == cima) {
			y -= velocidade.y;
		}
		else if (lado == esquerda) {
			x -= velocidade.x;
		}
		else if (lado == baixo) {
			y += velocidade.y;
		}
	}
	x -= velocidade.x;
	setar_Pos(x, y);
}

void Projetil::Salvar() {

}
