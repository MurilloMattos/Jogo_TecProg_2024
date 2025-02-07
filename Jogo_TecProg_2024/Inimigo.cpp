#include "Inimigo.h"

using namespace Entidades;
using namespace Personagens;


Inimigo::Inimigo() {
	nivel_raiva = -1;
	dano = -1;

	//pJogador_1 = nullptr;
	//pJogador_2 = nullptr;

	pos_final.x = 0;
	pos_final.y = 0;
}

Inimigo::~Inimigo() {

}

/*
void Entidades::Personagens::Inimigo::setar_Jogador_No_Inimigo(Jogador* pJogador1, Jogador* pJogador2){

	if ((pJogador1 != nullptr) && (pJogador2 == nullptr)) {

		pJogador_1 = pJogador1;
	}
	else if ((pJogador1 != nullptr) && (pJogador2 != nullptr)) {

		pJogador_2 = pJogador2;
	}

	else {
		std::cout << "ERRO, SEM REF DE JOGADOR fase.cpp" << std::endl;
		system("pause");
	}

}
*/

void Inimigo::andar_ate(float em_x, float em_y){

	pos_final.x = x;
	pos_final.y = y;
}

void Inimigo::Executar() {
	/*
	if ((pos_final.x != x) && (pos_final.y != y)) {

		if (pos_final.x > x) {
			x += velocidade;
		}
		else if (pos_final.x < x) {
			x -= velocidade;
		}
		if (pos_final.y > y) {
			y += velocidade;
		}
		else if (pos_final.y < y) {
			y -= velocidade;
		}
	}
	*/
}

