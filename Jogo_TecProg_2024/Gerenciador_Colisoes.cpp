#include "Gerenciador_Colisoes.h"


using namespace Gerenciadores;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace std;


Gerenciador_colisoes::Gerenciador_colisoes(){
	lista_Inimigos.clear();
	lista_Obstaculos.clear();
	
	pJogador1 = nullptr;
	pJogador2 = nullptr;

	i = 0;
}

Gerenciador_colisoes::~Gerenciador_colisoes(){

}

void Gerenciador_colisoes::Incluir_Obstaculo(Obstaculo* p_Obstaculo){
	lista_Obstaculos.push_back(p_Obstaculo);
}

void Gerenciador_colisoes::Incluir_Inimigo(Inimigo* p_Inimigo){
	lista_Inimigos.push_back(p_Inimigo);
}

void Gerenciador_colisoes::Incluir_Projetil(Projetil* p_Projetil){

}

void Gerenciador_colisoes::Setar_Jogador(Jogador* p_Jogador1, Jogador* p_Jogador2){
	pJogador1 = p_Jogador1;
	pJogador2 = p_Jogador2;
}

void Gerenciador_colisoes::Tratar_Colisoes_Inimigos(){

	for (i = 0; i < lista_Inimigos.size(); i++) {

		lista_Inimigos[i]->executar_Gravidade();
		//lista_Inimigos[i]->getFigura()->

	}

}

void Gerenciador_colisoes::Tratar_Colisoes_Obstaculo(){

}

void Gerenciador_colisoes::Tratar_Colisoes_Jogadores(){

}

void Gerenciador_colisoes::Executar(){

}
