#include "Personagem.h"

using namespace Entidades;
using namespace Personagens;

Personagem::Personagem() {
	num_vitalidade = -1;
	velocidade = 0.0;

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