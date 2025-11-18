#include "Fase_2.h"

using namespace Entidades;
using namespace Personagens;
using namespace Fases;

Fases::Fase_2::Fase_2():num_max_Capitoes(1), i(0){

	i = 0;
	j = 0;

	lista_cap.clear();


	Cria_Inimigos();
	Cria_Esteira();
}

Fases::Fase_2::~Fase_2(){

	lista_cap.clear();
}


void Fases::Fase_2::Cria_Obstaculos()
{
	Cria_Plataforma();
}

void Fases::Fase_2::Cria_Esteira(){
	esteira = new Entidades::Obstaculos::Esteira(1.5f, sf::Vector2f(-1.0f, 0.f));
	esteira->setar_Pos(300.f, piso->get_Y()); // Posiciona a esteira um pouco acima do piso

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Entidades::Obstaculos::Obstaculo*>(esteira));
	lista_Entidades.Incluir(static_cast<Entidade*>(esteira));
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

	Cria_Inimigo_Pirata(400.0f, 200.0f);
	Cria_Capitao(600.f,159.f);
}

//cria o inimigo dificil (Boss)
void Fase_2::Cria_Capitao(float x, float y){

	Inimigo_Capitao* capitao;
	capitao = new Inimigo_Capitao;

	capitao->setar_Pos(x, y);
	gerenciador_colisoes.Incluir_Inimigo(capitao);
	lista_Entidades.Incluir(static_cast<Entidade*>(capitao));
	lista_cap.push_back(capitao);
	lista_id_inimigos.push_front(capitao->getId());
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