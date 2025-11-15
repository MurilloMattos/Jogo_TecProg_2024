#include "Capitao.h"

using namespace Entidades;
using namespace Personagens;

Capitao::Capitao(): recarga(0){

	num_vitalidade = 200;
	
	dano = 20;
	dano_do_balote = 15;

	disparou = false;

	tamanho.x = 35.0;
	tamanho.y = 65.0;

	pos_inicial.x = 600.f;
	pos_inicial.y = 159.f;

	pos_final = pos_inicial;

	velocidade.x = 2.0f;

	pFigura->setFillColor(sf::Color::Magenta);

	pFigura->setSize(tamanho);
	pFigura->setPosition(pos_inicial);
}

Capitao::~Capitao(){

	//disparos.clear();
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


	if (direcao == esquerda) {
		projet->setar_Pos((x - projet->get_Largura()), (this->get_Centro().y - projet->get_Centro().y));

	}
	else if (direcao == direita) {
		projet->setar_Pos((x + this->get_Largura()), (this->get_Centro().y - projet->get_Centro().y));
	}

	disparos.push_back(projet);
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

void Capitao::Executar() {

	disparou = false;

	if (recarga < 180) {
		recarga++;
	}
	else {

		disparou = true;
		std::cout << "Disparou, pos (" << x << "," << y << ") direcao " << direcao <<std::endl;

		recarga = 0;
	}


	Desenhar();
}



void Capitao::Salvar() {

}
