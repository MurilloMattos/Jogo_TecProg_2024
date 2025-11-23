#include "Entidades/Projetil.h"
#include "Entidades/Personagens/Inimigos/Capitao.h"

using namespace Entidades;

Projetil::Projetil(): semente_id_entidade(10000) {

	setId(semente_id_entidade);
	dano = 0;

	cap = nullptr;

	sf::Vector2f tamanho;
	tamanho.x = 10.f;
	tamanho.y = 15.f;

	atingiu_jogador = false;

	tempo_ativo = 0;
	tempo_de_vida = 180;

	x = 0;
	y = 0;

	ativo = false;
	lado = 0;
	velocidade.x = 0.5f;
	velocidade.y = 0.f;
	

	pFigura->setFillColor(sf::Color(222, 120, 31));
	pFigura->setSize(tamanho);
	pFigura->setPosition(x, y);
}


Projetil::Projetil(float saida_x, float saida_y, int direcao) : semente_id_entidade(10000) {

	setId(semente_id_entidade);
	dano = 0;

	cap = nullptr;

	sf::Vector2f tamanho;
	tamanho.x = 5.f;
	tamanho.y = 10.f;

	tempo_ativo = 0;
	tempo_de_vida = 180;

	velocidade.x = 0.f;
	velocidade.y = 0.f;

	x = saida_x;
	y = saida_y;

	ativo = false;
	lado = direcao;

	pFigura->setFillColor(sf::Color(222, 120, 31));
	pFigura->setSize(tamanho);
	pFigura->setPosition(x, y);
}

Projetil::~Projetil(){

	ativo = false;
}

void Projetil::setar_Ativo(bool atv){
	ativo = atv;
}

void Projetil::setar_Dano(int dan){
	dano = dan;
}

void Projetil::setar_Direcao(int direcao) {
	lado = direcao;
}

void Entidades::Projetil::setar_Capitao(Entidades::Personagens::Inimigo_Capitao* capitao)
{
	cap = capitao;
}

int Projetil::get_Dano() {
	return dano;
}

bool Entidades::Projetil::get_Ativo()
{
	return ativo;
}

void Projetil::executar_Gravidade() {
	y += gravidade;
	y -= gravidade;
}

void Projetil::Executar() {

	setar_Pos(x, y);

	if (ativo) {

		//tempo_ativo++;

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

		Desenhar();
	}
	else {

		//std::cout << "Projetil ID " << getId() << " inativo na pos (" << x << "," << y << ")" << std::endl;
	}

	/*
	if(tempo_ativo >= tempo_de_vida){
		ativo = false;
		tempo_ativo = 0;
	}
	*/
}

void Projetil::Salvar() {

}

void Projetil::Atingiu_Jogador(Entidades::Personagens::Jogador* pJogador)
{
	if(ativo){
		pJogador->diminuir_Vitalidade(dano);
	}
}
