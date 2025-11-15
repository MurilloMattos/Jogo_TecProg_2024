#include "Inimigo.h"

using namespace Entidades;
using namespace Personagens;


Inimigo::Inimigo() :semente_id_entidade(100), direita(1), esquerda(3), direcao(0){
	
	setId(semente_id_entidade);
	ponteiro_jogador1 = nullptr;
	ponteiro_jogador2 = nullptr;

	nivel_raiva = -1;
	//dano = -1;

	pos_inicial.x = 0;
	pos_inicial.y = 0;

	pos_final.x = 0;
	pos_final.y = 0;
}

Inimigo::~Inimigo() {

}

void Inimigo::andar_ate(float em_x, float em_y){

	if (em_x > x) 
	{
		direcao = direita;
	}
	else{
		direcao = esquerda;
	}

	pos_final.x = x;
	pos_final.y = y;
}

void Inimigo::Executar() {


}


void Inimigo::setar_Jogador_No_Inimigo(Jogador* pJogador1, Jogador* pJogador2) {

	if(pJogador1 == nullptr && pJogador2 == nullptr){
		std::cout << "Erro: ponteiros de jogador nulos ao setar no inimigo." << std::endl;
	}
	else {
		if (pJogador2 == nullptr) {
			ponteiro_jogador1 = pJogador1;
		}
		else if (pJogador1 == nullptr) {
			ponteiro_jogador2 = pJogador2;
		}
		else {
			ponteiro_jogador1 = pJogador1;
			ponteiro_jogador2 = pJogador2;
		}
	}
}
