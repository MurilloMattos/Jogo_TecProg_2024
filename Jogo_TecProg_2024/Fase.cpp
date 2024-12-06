#include "Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Fase::Fase() {
	cria_Piso();

	lista_Entidades.Incluir(static_cast<Entidade*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(cria_Inimigos()));
}

Fase::~Fase() {
	delete piso;
}

void Fases::Fase::Setar_Jogadores_Colisoes(Jogador* p_jogador1, Jogador* p_jogador2){

}

void Fases::Fase::Executar()
{
	lista_Entidades.Percorrer();
}

void Fase::cria_Piso() {
	piso = new Piso;

	piso->seta_Piso(50.f, 1000.f);
}

Personagens::Inimigo_Medio* Fase::cria_Inimigos() {
	Inimigo_Medio* pirata;

	pirata = new Inimigo_Medio;
	pirata->setar_pos(200.f, 159.f);

	return pirata;
	
}
