#include "Fases/Fase_2.h"

using namespace Entidades;
using namespace Personagens;
using namespace Fases;
using namespace Obstaculos;
using namespace Gerenciadores;

Fases::Fase_2::Fase_2():num_max_Capitoes(1) {

	i = 0;
	j = 0;

	zoom_camera = 1.6f;

	tam_Piso_Fase.x = pGG->getCamera()->getSize().x * zoom_camera;
	tam_Piso_Fase.y = pGG->getCamera()->getSize().y / 4.f;

	pos_Piso.x = tam_Piso_Fase.x / -2.f;
	pos_Piso.y = tam_Piso_Fase.y;

	lista_cap.clear();

	setar_Camera_Fase();
	Cria_Inimigos();
	Cria_Obstaculos();
}

Fases::Fase_2::~Fase_2(){

	lista_cap.clear();
}


void Fases::Fase_2::Cria_Obstaculos(){

	Cria_Piso();
	Cria_Plataforma();
}

void Fases::Fase_2::Executar(){

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

void Fases::Fase_2::Cria_Inimigos(){

	//Cria_Inimigo_Pirata(300.0f, pos_Piso.y - Pirata().get_Altura());
	Cria_Capitao(300.f,pos_Piso.y - Inimigo_Capitao().get_Altura());
}

//cria o inimigo dificil (Boss)
void Fase_2::Cria_Capitao(float x, float y){

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
Projetil* Fases::Fase_2::Cria_Projetil()
{

	Projetil* proj;
	proj = new Projetil;
	
	lista_Entidades.Incluir(static_cast<Entidade*>(proj));
	gerenciador_colisoes.Incluir_Projetil(proj);

	return proj;
}

void Fases::Fase_2::verifica_Projeteis_Destroidos()
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

void Fases::Fase_2::setar_Camera_Fase()
{
	pGG->getCamera()->zoom(zoom_camera);
}

void Fases::Fase_2::atualiza_Camera_Fase(Jogador* p_jogador1, Jogador* p_jogador2)
{
	sf::Vector2f pos_camera;

	pos_camera.x = 0.f;
	pos_camera.y = -200.f;

	//trava a camera;
	pGG->getCamera()->setCenter(pos_camera);

}

void Fases::Fase_2::Cria_Plataforma() {

	if (num_plataformas < 4) {
		num_plataformas = 4;
	}

	srand(static_cast<unsigned int>(time(0)));

	int n_plataformas_por_nível;
	n_plataformas_por_nível = rand() % 2 + 2;

	float tamanho_da_tela = pGG->getCamera()->getSize().x * zoom_camera;


	sf::Vector2f pos_plataforma;
	pos_plataforma.x = (tamanho_da_tela / n_plataformas_por_nível);
	pos_plataforma.y = pos_Piso.y - 120.f;

	/*
	sf::Vector2f distancia_maxima_entre_plataformas;
	distancia_maxima_entre_plataformas.x = 400.f;
	distancia_maxima_entre_plataformas.y = pos_Piso.y - 50.f;
	*/
	

	//tem que setar como vai colocar as plataformas na fase
	//aparentemente vão ter que ter andares, se nao cabe mais em pos_Piso.y - 120.f 
	//vai ter que ser pos_Piso.y - 1 * 120.f e assim por diante;
	for(i=0; i < num_plataformas; i++) {

		plataforma = new Plataforma;
		plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x,0.f,pos_plataforma.y);

		gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(plataforma));
		lista_Entidades.Incluir(static_cast<Entidade*>(plataforma));
	}
	

}

void Fases::Fase_2::Cria_Piso() {

	piso = new Plataforma;
	piso->seta_Plataforma(tam_Piso_Fase.y, tam_Piso_Fase.x, pos_Piso.x, pos_Piso.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(piso));
}