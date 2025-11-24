#include "Fases/Fase_1.h"

using namespace Entidades;
using namespace Personagens;
using namespace Fases;
using namespace Obstaculos;
using namespace Gerenciadores;

Fases::Fase_1::Fase_1() {

	i = 0;
	j = 0;

	lista_plat.clear();

	tam_Piso_Fase.x = 1500.f;
	tam_Piso_Fase.y = pGG->getCamera()->getSize().y ;

	pos_Piso.x = -750.f;
	pos_Piso.y = tam_Piso_Fase.y;

	Cria_Obstaculos();
	Cria_Inimigos();
	setar_Camera_Fase();

}

Fases::Fase_1::~Fase_1(){

	lista_plat.clear();

}

void Fases::Fase_1::Executar(){

	verifica_Inimigos_Neutralizados();

	if (!ganhou) {
		gerenciador_colisoes.Executar();
		lista_Entidades.Percorrer();
	}
	
}

void Fases::Fase_1::Cria_Obstaculos() {

	Cria_Piso();
	Cria_Plataforma();
	Cria_Esteira();

}

void Fases::Fase_1::Cria_Inimigos() {

	int i = 0;
	int num_max_esmagadores = rand() % 3 + 3;

	while (i < num_max_esmagadores) {

		int sorteio = rand() % 6;

		if(sorteio == 0){
			Cria_Esmagador(100.f, pos_Piso.y);
		}
		else if(sorteio == 1){
			Cria_Esmagador(300.f, pos_Piso.y);
		}
		else if(sorteio == 2){
			Cria_Esmagador(500.f, pos_Piso.y);
		}
		else if (sorteio == 3){
			Cria_Esmagador(-100.f, pos_Piso.y);
		}
		else if(sorteio == 4){
			Cria_Esmagador(-300.f, pos_Piso.y);
		}
		else {
			Cria_Esmagador(-500.f, pos_Piso.y);
		}

		i++;
	}

	int num_piratas = lista_plat.size();

	for(int i = 0; i < num_piratas; i++){
		Cria_Pirata(lista_plat[i]->get_X() + 10.f, lista_plat[i]->get_Y() - 40.f, lista_plat[i]->get_X(), lista_plat[i]->get_X() + lista_plat[i]->get_Largura() - 20.f);
	}

	Cria_Pirata(400.0f, pos_Piso.y, -400.f, 401.f);

}

void Fases::Fase_1::Cria_Piso() {

	piso = new Plataforma;
	piso->seta_Plataforma(tam_Piso_Fase.y, tam_Piso_Fase.x, pos_Piso.x, pos_Piso.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(piso));

}

void Fases::Fase_1::Cria_Plataforma() {

	int num_plataformas = rand() % 5 + 3; // entre 3 e 5 plataformas

	std::cout << num_plataformas << std::endl;

	int i = 0;
	int sorteio;

	float espaco = static_cast<float>(rand() % 100);

	while(i <= num_plataformas) {

		sorteio = rand() % 5;//

		if(sorteio == 0){
			plataforma = new Plataforma;
			plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x, -400.f, piso->get_Y() - 100.f);
			lista_plat.push_back(plataforma);

			i++;
		}

		else if(sorteio == 1){
			plataforma = new Plataforma;
			plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x, -200.f, piso->get_Y() - 120.f);
			lista_plat.push_back(plataforma);

			i++;
		}

		else if(sorteio == 2){
			plataforma = new Plataforma;
			plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x, 0.f, piso->get_Y() - 140.f);
			lista_plat.push_back(plataforma);

			i++;
		}

		else if (sorteio == 3){
			plataforma = new Plataforma;
			plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x, 200.f, piso->get_Y() - 120.f);
			lista_plat.push_back(plataforma);

			i++;
		}

		else if(sorteio == 4){
			plataforma = new Plataforma;
			plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x, 400.f, piso->get_Y() - 100.f);
			lista_plat.push_back(plataforma);

			i++;
		}

		gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(plataforma));
		lista_Entidades.Incluir(static_cast<Entidade*>(plataforma));
	}
	
}

void Fases::Fase_1::Cria_Esteira() {

	int i = 0;
	int num_total_esteira = lista_plat.size() - 1;

	while (i <= num_total_esteira) {
		
		int sorteio = rand() % 6;

		if(sorteio == 0){
			esteira = new Esteira(5.0f, lista_plat[i]->get_X() + 25, lista_plat[i]->get_Y()-1.f);
		}
		else if(sorteio == 1){
			esteira = new Esteira(6.0f, lista_plat[i]->get_X() + 25, lista_plat[i]->get_Y()-1.f);
		}
		else if(sorteio == 2){
			esteira = new Esteira(4.0f, lista_plat[i]->get_X() + 25, lista_plat[i]->get_Y()-1.f); 
		}
		else if(sorteio == 3){
			esteira = new Esteira(7.0f, lista_plat[i]->get_X() + 25, lista_plat[i]->get_Y()-1.f); 
		}
		else if(sorteio == 4){
			esteira = new Esteira(3.0f, lista_plat[i]->get_X() + 25, lista_plat[i]->get_Y()-1.f); 
		}
		else{
			esteira = new Esteira(9.0f, lista_plat[i]->get_X() + 25, lista_plat[i]->get_Y()-1.f); 
		}
		gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(esteira));
		lista_Entidades.Incluir(static_cast<Entidade*>(esteira));
		i++;
	}

	esteira = new Esteira(5.0f, piso->get_X() + 25.f, piso->get_Y() - 1.f);
	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(esteira));
	lista_Entidades.Incluir(static_cast<Entidade*>(esteira));

}

void Fases::Fase_1::Cria_Esmagador(float x, float y) {

	Esmagador* esmagador;
	esmagador = new Esmagador();

	esmagador->setar_Pos(x, y);
	gerenciador_colisoes.Incluir_Inimigo(esmagador);
	lista_Entidades.Incluir(static_cast<Entidade*>(esmagador));
	lista_id_inimigos.push_front(esmagador->getId());

}


void Fases::Fase_1::setar_Camera_Fase()
{
	pGG->getCamera()->zoom(1.5f);
}

void Fases::Fase_1::atualiza_Camera_Fase(Jogador* p_jogador1, Jogador* p_jogador2)
{
	//centraliza a camera no jogador 1
	if(!p_jogador1->get_Eliminado()){
		pGG->getCamera()->setCenter(p_jogador1->get_Centro());
	}
	else if(!p_jogador2->get_Eliminado()){
		pGG->getCamera()->setCenter(p_jogador2->get_Centro());
	}
	else{
		std::cout << "Erro ao atualizar camera fase 1" << std::endl;
	}
	//pGG->getCamera()->setCenter(p_jogador1->get_Centro());

}