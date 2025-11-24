#include "Entidades/Personagens/Personagem.h"

using namespace Entidades;
using namespace Personagens;

Personagem::Personagem() {

	eliminado = false;

	num_vitalidade = -1;
	dano = -1;
	velocidade.x = 0.0;
	velocidade.y = 0.0;

	tamanho.x = 0.0;
	tamanho.y = 0.0;
}

Personagem::~Personagem() {

}

void Personagem::setar_Vitalidade(int vida)
{
	num_vitalidade = vida;
}

void Personagem::diminuir_Vitalidade(int dano) {
	num_vitalidade -= dano;
}

int Entidades::Personagens::Personagem::get_Vitalidade()
{
	return num_vitalidade;
}

void Personagem::danificar(Personagem* pAtacado) {
	pAtacado->diminuir_Vitalidade(dano);
}

const bool Personagem::get_Eliminado(){

	if(get_Vitalidade()>=0){
		return false;
	}

	return true;
}