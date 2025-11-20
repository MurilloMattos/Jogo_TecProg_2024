#include "Entidades/Personagens/Personagem.h"

using namespace Entidades;
using namespace Personagens;

Personagem::Personagem() {
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

int Personagem::danificar() {
	return dano;
}
