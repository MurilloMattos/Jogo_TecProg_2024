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

	if (p_jogador2 == nullptr) {

		gerenciador_colisoes.Setar_Jogador(p_jogador1, nullptr);
	}
	else if (p_jogador1 != nullptr) {

		gerenciador_colisoes.Setar_Jogador(p_jogador1, p_jogador2);

	}
	else {
		std::cout << "ERRO, SEM REF DE JOGADOR fase.cpp" << std::endl;
		system("pause");
	}
}

void Fases::Fase::Executar(){

	gerenciador_colisoes.Executar();
	lista_Entidades.Percorrer();
}

void Fase::Cria_Piso() {
	piso = new Piso;

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(piso));

	piso->seta_Piso(75.f, 1000.f);
}

Personagens::Inimigo_Medio* Fase::Cria_Inimigos() {
	Inimigo_Medio* pirata;

	pirata = new Inimigo_Medio;
	pirata->setar_Pos(200.f, 100.f);

	gerenciador_colisoes.Incluir_Inimigo(pirata);

	//std::cout << pirata->
	std::cout << pirata->get_X() << "," << pirata->get_Y() << std::endl;
	std::cout << pirata->get_Largura() << "," << pirata->get_Altura() << std::endl;

	return pirata;
}
/*
void Fase::executa_Colisões(){
	
}
*/
