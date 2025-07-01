#include "Personagem.h"

using namespace Entidades;
using namespace Personagens;

Personagem::Personagem(): Entidade()  {
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


int Personagens::Personagem::get_Vitalidade()
{
	return num_vitalidade;
}

int Personagem::danificar() {
	return dano;
}
sf::Vector2f Personagem::coordenada_Polar(Personagem *p) {
	if(!p) { std::cout << "personagen nao existente " << std::endl;}
	float dx = p->get_X() - get_X();
	float dy = p->get_Y() - get_Y();
	float dist = std::sqrt((dx * dx) + (dy * dy));
	angulo = std::atan2(dy, dx);
	return sf::Vector2f(dist, angulo);
}
float Personagem::get_Angulo()const {
	return angulo;
}
