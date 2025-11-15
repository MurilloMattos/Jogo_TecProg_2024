#include "Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Fase::Fase() {
	srand(static_cast<unsigned int>(time(0)));

	ganhou = false;
	perdeu = false;

}

Fase::~Fase() {

}

/*
Gerenciadores::Gerenciador_colisoes* Fase::get_Gerenciador_Colisoes()
{
	return &gerenciador_colisoes;
}
Listas::Lista_Entidades* Fase::get_Lista_Entidades()
{
	return &lista_Entidades;
}

int Fases::Fase::get_Num_Plataformas()
{
	return num_plataformas;
}
*/
void Fases::Fase::Setar_Jogadores_Colisoes(Jogador* p_jogador1, Jogador* p_jogador2){

	if ((p_jogador1 != nullptr) && (p_jogador2 == nullptr)) {

		gerenciador_colisoes.Setar_Jogador(p_jogador1, nullptr);
	}
	else if ((p_jogador1 !=nullptr) && (p_jogador2 != nullptr)) {

		gerenciador_colisoes.Setar_Jogador(p_jogador1, p_jogador2);
	}

	else {
		std::cout << "ERRO, SEM REF DE JOGADOR fase.cpp" << std::endl;
		system("pause");
	}
}

void Fases::Fase::Cria_Plataforma() {
}

bool Fases::Fase::get_Ganhou()
{
	return ganhou;
}

void Fases::Fase::verifica_Inimigos_Neutralizados(){

	lista_Entidades.Remover(gerenciador_colisoes.Inimigo_neutralizado());

	if (gerenciador_colisoes.verifica_Lista_Inimigos_Vazia()) {

		std::cout << "todos os inimigos foram eliminados!" << std::endl;
		ganhou = true;
	}
}
