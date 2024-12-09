#include "Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Fase::Fase() {
	Cria_Piso();

	lista_Entidades.Incluir(static_cast<Entidade*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(Cria_Inimigos()));
}

Fase::~Fase() {

}

void Fases::Fase::Setar_Jogadores_Colisoes(Jogador* p_jogador1, Jogador* p_jogador2){
	gerenciador_colisoes.Setar_Jogador(p_jogador1, p_jogador2);
}

void Fases::Fase::Executar(){

	lista_Entidades.Percorrer();
}

void Fase::Cria_Piso() {
	piso = new Piso;

	piso->seta_Piso(50.f, 1000.f);
}

Personagens::Inimigo_Medio* Fase::Cria_Inimigos() {
	Inimigo_Medio* pirata;

	pirata = new Inimigo_Medio;
	pirata->setar_Pos(200.f, 159.f);

	return pirata;
	
}
