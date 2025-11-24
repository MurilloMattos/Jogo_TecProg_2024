#include "Fases/Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Fase::Fase() {

	srand(static_cast<unsigned int>(time(0)));
	num_plataformas_totais = rand() % 7;

	srand(static_cast<unsigned int>(time(0)));
	num_inimigos = rand() % 8;

	lista_id_inimigos.clear();

	ganhou = false;

	tam_Piso_Fase.x = 2500.f;
	tam_Piso_Fase.y = 100.f;
	pos_Piso.x = -100.f;
	pos_Piso.y = 200.f;

	tam_plataforma.x = 150.f;
	tam_plataforma.y = 30.f;

	pos_original.x = 10;
	pos_original.y = 80;
	
}

Fase::~Fase() {

	delete plataforma;
	delete piso;
}


void Fases::Fase::Setar_Jogadores(Jogador* p_jogador1,Jogador* p_jogador2)
{
	Setar_Jogadores_Colisoes(p_jogador1, p_jogador2);
	Setar_Jogadores_Inimigos(p_jogador1, p_jogador2);
}

void Fases::Fase::Setar_Jogadores_Colisoes(Jogador* p_jogador1, Jogador* p_jogador2){

	if ((p_jogador1 != nullptr) && (p_jogador2 == nullptr)) {

		gerenciador_colisoes.Setar_Jogador(p_jogador1, nullptr);
	}
	else if ((p_jogador1 !=nullptr) && (p_jogador2 != nullptr)) {

		gerenciador_colisoes.Setar_Jogador(p_jogador1, p_jogador2);
	}

	else {
		std::cout << "ERRO, SEM REF DE JOGADOR fase1.cpp" << std::endl;
		//system("pause");
	}
}

void Fases::Fase::Setar_Jogadores_Inimigos(Jogador* p_jogador1, Jogador* p_jogador2)
{
	std::list<int>::iterator itr;

	itr = lista_id_inimigos.begin();

	while (itr != lista_id_inimigos.end()) {
		
		static_cast<Inimigo*>(lista_Entidades.get_Entidade_Por_Id(*itr))->setar_Jogador_No_Inimigo(p_jogador1, p_jogador2);

		itr++;
	}

}

void Fases::Fase::Cria_Pirata(float x, float y, float patrulha_ate_a, float patrula_ate_b){
	Pirata* pirata;

	pirata = new Pirata;
	pirata->setar_Pos(x, y - pirata->get_Altura());
	pirata->setar_Patrulha(patrulha_ate_a, patrula_ate_b);

	lista_id_inimigos.push_front(pirata->getId());
	gerenciador_colisoes.Incluir_Inimigo(pirata);
	lista_Entidades.Incluir(static_cast<Entidade*>(pirata));

}

bool Fases::Fase::get_Ganhou()
{
	return ganhou;
}


void Fases::Fase::criar_cenario()
{


}


void Fases::Fase::verifica_Inimigos_Neutralizados() {

	auto itr = lista_id_inimigos.begin();

    while (itr != lista_id_inimigos.end() && !(lista_id_inimigos.empty())) {

        int id = *itr;
        Entidade* ent = lista_Entidades.get_Entidade_Por_Id(id);

        // id inv�lido -> remover da lista de ids
        if (ent == nullptr) {
            itr = lista_id_inimigos.erase(itr);
            continue;
        }

        // garantir que � um inimigo (mais seguro que static_cast)
        Inimigo* inim = dynamic_cast<Inimigo*>(ent);
        if (inim == nullptr) {
            ++itr;
            continue;
        }

        if (inim->get_Eliminado()) {

            // remove entidade do gerenciador/lista de entidades
            lista_Entidades.Remover(ent);
			gerenciador_colisoes.Inimigo_neutralizado(inim);

            // tamb�m remover o id da lista de inimigos para n�o iterar sobre ele novamente
            itr = lista_id_inimigos.erase(itr);
        } else {
            ++itr;
        }
    }

    if (gerenciador_colisoes.verifica_Lista_Inimigos_Vazia() && lista_id_inimigos.empty()) {
        std::cout << "todos os inimigos foram eliminados!" << std::endl;
        ganhou = true;
    }
}

void Fases::Fase::Executar() {

	verifica_Inimigos_Neutralizados();
	gerenciador_colisoes.Executar();
	lista_Entidades.Percorrer();
	
}

