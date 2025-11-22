#include "Fases/Fase_1.h"

using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Gerenciadores;

Fase_1::Fase_1() : Fase() , max_inimigos_medios(3) {



	Cria_Inimigos();
}

Fase_1::~Fase_1() {


}

void Fase_1::cria_Obstaculos_Dificeis()
{

}

void Fase_1::cria_Inimigos_Medios()
{
}

void Fase_1::Executar() {

}

void Fase_1::Cria_Piso() {

}

void Fase_1::Cria_Plataforma() {

}

void Fase_1::Cria_Inimigos() {
}

void Fase_1::Cria_Obstaculos() {

}

void Fase_1::atualiza_Camera_Fase(Jogador* p_jogador1, Jogador* p_jogador2)
{
	pGG->getCamera()->setCenter(p_jogador1->get_Centro());
}

void Fase_1::setar_Camera_Fase()
{
	pGG->getCamera()->zoom(1.0f);
}