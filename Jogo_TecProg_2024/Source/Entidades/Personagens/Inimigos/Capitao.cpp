#include "Entidades/Personagens/Inimigos/Capitao.h"

using namespace Entidades;
using namespace Personagens;

Capitao::Capitao(): recarga(0){

	num_vitalidade = 200;
	
	dano = 20;
	dano_do_balote = 15;

	lado_fraco = cima;

	disparou = false;
	pode_disparar = true;

	tamanho.x = 35.0;
	tamanho.y = 65.0;

	pos_inicial.x = 600.f;
	pos_inicial.y = 159.f;

	pos_final = pos_inicial;

	velocidade.x = 2.0f;

	velocidade_proj.x = 3.0f;
	velocidade_proj.y = 0.0f;

	pFigura->setFillColor(sf::Color::Magenta);

	pFigura->setSize(tamanho);
	pFigura->setPosition(pos_inicial);

	setar_Pontos_Por_Eliminacao(400);
}

Capitao::~Capitao(){

	/*
	int i;

	for(i=0; i<disparos.size();i++){

		disparos[i]->setar_Ativo(false);
	}
	*/

	disparos.clear();
	pode_disparar = false;
	disparou = false;
}

const bool Capitao::get_Disparou()
{
	return disparou;
}


void Entidades::Personagens::Capitao::incluir_Projetil(Projetil* projet) {

	projet->setar_Ativo(true);
	projet->setar_Direcao(direcao);
	projet->setar_Dano(dano_do_balote);
	projet->setar_Capitao(this);
	projet->setar_velocidade(velocidade_proj.x, velocidade_proj.y);


	if (direcao == esquerda) {
		projet->setar_Pos((x - projet->get_Largura()), (this->get_Centro().y - projet->get_Centro().y));

	}
	else if (direcao == direita) {
		projet->setar_Pos((x + this->get_Largura()), (this->get_Centro().y - projet->get_Centro().y));
	}

	//std::cout << "Incluiu projetil ID " << projet->getId() << " na pos (" << projet->get_X() << "," << projet->get_Y() << ")" << std::endl;

	disparos.push_back(projet);
	//imprime_Projeteis_Ids_Ativos_e_Pos();
}

void Capitao::remover_Projetil(Projetil* projet) {

	std::vector<Entidades::Projetil*>::iterator itr;
	itr = disparos.begin();

	while (itr != disparos.end()) {

		
		if ((*itr)->getId() == projet->getId()) {
			disparos.erase(itr);
			break;
		}
		itr++;
	}
}

std::vector<Projetil*>* Capitao::get_Vetor_De_Projetis(){

	return &disparos;
}

void Capitao::Executar() {

	disparou = false;
	setar_direcao();

	if (pode_disparar) {

		if (recarga < 240) {
			recarga++;
		}
		else {

			disparou = true;
			// << "Disparou, pos (" << x << "," << y << ") direcao " << direcao << std::endl;

			recarga = 0;
		}
	}

	Desenhar();
}

void Capitao::imprime_Projeteis_Ids_Ativos_e_Pos() {

	for (int i = 0; i < disparos.size(); i++) {
		if (disparos[i]->get_Ativo()) {
			std::cout << "  Projetil ID: " << disparos[i]->getId() << " Pos (" << disparos[i]->get_X() << "," << disparos[i]->get_Y() << ")" << std::endl;
		}
	}
}


void Capitao::Salvar() {

}


void Capitao::verifica_Acao_de_Colisao(int lado, Jogador* pJogador){

	if(lado == lado_fraco){
		pJogador->danificar(static_cast<Personagem*>(this));

		if(get_Eliminado()){
			pJogador->aumentar_Pontuacao(pontos_de_eliminacao);
		}
	}
	else {
		danificar(static_cast<Personagem*>(pJogador));
	}

}

void Capitao::setar_Pontos_Por_Eliminacao(int pontos){

	pontos_de_eliminacao = pontos;
}