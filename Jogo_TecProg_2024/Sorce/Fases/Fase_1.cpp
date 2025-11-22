#include "Fases/Fase_1.h"

using namespace Fases;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Gerenciadores;

Fase_1::Fase_1() : Fase() , max_inimigos_medios(3) {


	Cria_Obstaculos();
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

	verifica_Inimigos_Neutralizados();

	if (!ganhou) {
		gerenciador_colisoes.Executar();
		lista_Entidades.Percorrer();
	}
}

/*
void Fase_1::Cria_Piso() {

	piso = new Plataforma;
	piso->seta_Plataforma(tam_Piso_Fase.y, tam_Piso_Fase.x, pos_Piso.x, pos_Piso.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(piso));
}

void Fase_1::Cria_Plataforma() {

	
	if (num_plataformas < 4){
		num_plataformas = 4;
	}


	std::cout << num_plataformas << std::endl;

	int i;
	float espaco = static_cast<float>(rand() % 100);

	for (i = 0; i < num_plataformas; i++) {

		plataforma = new Plataforma;
		plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x, pos_original.x + espaco, pos_original.y);

		
		espaco += (tam_plataforma.x*2.5f + rand()%200);
		if (espaco > tam_Piso_Fase.x) {
			espaco = tam_Piso_Fase.x;
		}

		gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(plataforma));
		lista_Entidades.Incluir(static_cast<Entidade*>(plataforma));
	}
	
}
*/

void Fase_1::Cria_Inimigos() {

	Cria_Inimigo_Pirata(300.0f, 200.0f);
	Cria_Inimigo_Pirata(500.0f, 200.0f);
}

void Fase_1::Cria_Obstaculos() {

	Cria_Piso();
	Cria_Plataforma();
}


void Fase_1::atualiza_Camera_Fase(Jogador* p_jogador1, Jogador* p_jogador2)
{
	pGG->getCamera()->setCenter(p_jogador1->get_Centro());
}

void Fase_1::setar_Camera_Fase()
{
	pGG->getCamera()->zoom(1.0f);
}