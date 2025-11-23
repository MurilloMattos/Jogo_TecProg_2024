#include "Fases/Fase_1.h"

using namespace Entidades;
using namespace Personagens;
using namespace Fases;
using namespace Obstaculos;
using namespace Gerenciadores;

Fases::Fase_1::Fase_1():num_max_Capitoes(2) {

	i = 0;
	j = 0;

	lista_cap.clear();

	tam_Piso_Fase.x = pGG->getCamera()->getSize().x * 20.f;
	tam_Piso_Fase.y = pGG->getCamera()->getSize().y / 3.f;

	pos_Piso.x = 0.f;
	pos_Piso.y = tam_Piso_Fase.y;


	Cria_Inimigos();
	Cria_Obstaculos();
	setar_Camera_Fase();

}

Fases::Fase_1::~Fase_1(){

	lista_cap.clear();

}

void Fases::Fase_1::Executar(){

	verifica_Inimigos_Neutralizados();

	if (!ganhou) {
		verifica_Projeteis_Destroidos();
		gerenciador_colisoes.Executar();
		lista_Entidades.Percorrer();

		for (i = 0; i < lista_cap.size(); i++) {

			if (lista_cap[i]->get_Disparou()) {

				lista_cap[i]->incluir_Projetil(Cria_Projetil());
			}
		}
	}
	
}

void Fases::Fase_1::Cria_Obstaculos() {

	Cria_Piso();
	Cria_Plataforma();
	Cria_Esteira();

}

void Fases::Fase_1::Cria_Inimigos() {

	Cria_Inimigo_Pirata(400.0f, 200.0f);
	Cria_Capitao(600.f,159.f);

}

void Fases::Fase_1::Cria_Piso() {

	piso = new Plataforma;
	piso->seta_Plataforma(tam_Piso_Fase.y, tam_Piso_Fase.x, pos_Piso.x, pos_Piso.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(piso));

}

void Fases::Fase_1::Cria_Plataforma() {

	
	if (num_plataformas < 4){
		num_plataformas = 4;
	}


	std::cout << num_plataformas << std::endl;

	int i;
	float espaco = static_cast<float>(rand() % 100);

	for (i = 0; i < num_plataformas; i++) {

		plataforma = new Plataforma;
		plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x, pos_original.x + espaco, pos_original.y + -10.f);

		
		espaco += (tam_plataforma.x*2.5f + rand()%200);
		if (espaco > tam_Piso_Fase.x) {
			espaco = tam_Piso_Fase.x;
		}

		gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(plataforma));
		lista_Entidades.Incluir(static_cast<Entidade*>(plataforma));
	}
	
}

void Fases::Fase_1::Cria_Esteira() {

	esteira = new Esteira(5.0f, 1.0f); // Velocidade 5.0f, direção para a direita (1)

	esteira->setar_Pos(50.0f,tam_Piso_Fase.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(esteira));
	lista_Entidades.Incluir(static_cast<Entidade*>(esteira));

    std::cout << "[Fase_1] Esteira criada em (" << 50.0f << "," << (tam_Piso_Fase.y - 20.0f) << ")" << std::endl;

}


//cria o inimigo dificil (Boss)
void Fase_1::Cria_Capitao(float x, float y){

	for(int k = 0; k < num_max_Capitoes; k++){
	Inimigo_Capitao* capitao;
	capitao = new Inimigo_Capitao;

	capitao->setar_Pos(x + k * 50.0f, y);
	gerenciador_colisoes.Incluir_Inimigo(capitao);
	lista_Entidades.Incluir(static_cast<Entidade*>(capitao));
	lista_cap.push_back(capitao);
	lista_id_inimigos.push_front(capitao->getId());
	}

}

//auto explicativo
Projetil* Fases::Fase_1::Cria_Projetil()
{

	Projetil* proj;
	proj = new Projetil;
	
	lista_Entidades.Incluir(static_cast<Entidade*>(proj));
	gerenciador_colisoes.Incluir_Projetil(proj);

	return proj;
}

void Fases::Fase_1::verifica_Projeteis_Destroidos()
{
	
	Projetil* projetil_deletado;

	for(i=0;i<lista_cap.size(); i++) {

		for(j = 0; j < lista_cap[i]->get_Vetor_De_Projetis()->size(); j++) {


			// conteudo apontado pelo ponteiro do vetor de projeteis do capitao
			if (!((*lista_cap[i]->get_Vetor_De_Projetis())[j]->get_Ativo())) {

				projetil_deletado = (*(lista_cap[i]->get_Vetor_De_Projetis()))[j];


				if (projetil_deletado) {
					//remove da lista de colisões
					gerenciador_colisoes.projetil_Destruido(projetil_deletado);

				}
				else {
					std::cout << "Erro ao remover projetil (Gerenciador_colisoes)" << std::endl;
				}

				if (projetil_deletado) {
					//remove do capitão
					lista_cap[i]->remover_Projetil(projetil_deletado);
				}
				else {
					std::cout << "Erro ao remover projetil (Capitao)" << std::endl;
				}

				if (projetil_deletado) {
					//remove da lista de entidades
					lista_Entidades.Remover(static_cast<Entidade*>(projetil_deletado));
				}
				else {
					std::cout << "Erro ao remover projetil (Lista_Entidades)" << std::endl;
				}

			}
		}

		projetil_deletado = nullptr;
	}

	

}

void Fases::Fase_1::setar_Camera_Fase()
{
	pGG->getCamera()->zoom(2.0f);
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