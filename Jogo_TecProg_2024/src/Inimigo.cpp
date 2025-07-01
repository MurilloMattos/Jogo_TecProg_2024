#include "Inimigo.h"
#include "Fase.h"

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo() :semente_id_entidade(100), Personagem(){
	fase = NULL;	
	setId(semente_id_entidade);

	nivel_raiva = -1;
	dano = -1;

	pos_inicial.x = 0;
	pos_inicial.y = 0;

	pos_final.x = 0;
	pos_final.y = 0;
}

Inimigo::~Inimigo() {

}

void Inimigo::andar_ate(float em_x, float em_y){

	pos_final.x = x;
	pos_final.y = y;
}
void Inimigo::set_Atacar(bool b) {
	atacar = b;
}
bool Inimigo::get_Atacar() const {
	return atacar;
}
void Inimigo::associa_Fase(Fases::Fase *f) { 
	if(f) { this->fase = f; }
}
