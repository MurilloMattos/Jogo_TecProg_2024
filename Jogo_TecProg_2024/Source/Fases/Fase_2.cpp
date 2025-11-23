#include "Fases/Fase_2.h"

using namespace Entidades;
using namespace Personagens;
using namespace Fases;
using namespace Obstaculos;
using namespace Gerenciadores;

Fases::Fase_2::Fase_2():num_max_Capitoes(1) {

	i = 0;
	j = 0;

	zoom_camera = 1.0f;

	srand(static_cast<unsigned int>(time(0)));

	num_plataformas_totais = rand() % 10;

	num_max_andares = 4;

	tam_Piso_Fase.x = pGG->getCamera()->getSize().x * zoom_camera;
	tam_Piso_Fase.y = pGG->getCamera()->getSize().y / 3.f;

	pos_Piso.x = 0.f;
	pos_Piso.y = tam_Piso_Fase.y;


	lista_cap.clear();

	tamanho_da_tela_x = pGG->getCamera()->getSize().x * zoom_camera;
	espaco_vazio_x = 0;

	num_max_plataformas = 10;

	
	

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
	Cria_Capitao(0.f,pos_Piso.y - Inimigo_Capitao().get_Altura());
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

	pos_camera.x = tam_Piso_Fase.x/2;
	pos_camera.y = -tam_Piso_Fase.y/3;

	//trava a camera;
	pGG->getCamera()->setCenter(pos_camera);

}

void Fases::Fase_2::seta_Tamanho_Plataformas(int n_plataformas) {

	if(n_plataformas == 1){

		//70% do tamanho da tela.
		tam_plataforma.x = tamanho_da_tela_x*0.7f;
		espaco_vazio_x = static_cast<float>((tamanho_da_tela_x*0.3)/2);
	}
	else if(n_plataformas == 2){

		//35% do tamanho da tela
		tam_plataforma.x = tamanho_da_tela_x*0.35f;
		espaco_vazio_x = static_cast<float>((tamanho_da_tela_x*0.3)/3);
	}
	else if(n_plataformas == 3){

		//25% do tamanho da tela
		tam_plataforma.x = tamanho_da_tela_x*0.25f;
		espaco_vazio_x = static_cast<float>((tamanho_da_tela_x*0.25)/4);
	}
	else if(n_plataformas == 4){

		//15% do tamanho da tela
		tam_plataforma.x = tamanho_da_tela_x*0.15f;
		espaco_vazio_x = static_cast<float>((tamanho_da_tela_x*0.4)/5);
	}
	else {

		tam_plataforma.x = 0.0;
		espaco_vazio_x = 0.0;
	}
}

void Fases::Fase_2::seta_Num_Plataformas(){

	if (num_plataformas_totais < 5) {
		num_plataformas_totais = 5;
	}

	std::cout << "numero de plataformas "<< num_plataformas_totais << std::endl;

	int plataformas = 0;
	int plataformas_restantes = num_plataformas_totais;

	tam_plataforma.x = 0.f;

	//pode ter andares vazios, des que sejam os ultimos.
	int num_min_plataformas_andar = 1;

	for (i = 0; i<num_max_andares;i++) {

		//verifica se ainda tem plataformas para por
		if(plataformas_restantes > 0) {

			plataformas = num_min_plataformas_andar + (rand() % 3);

			//verifica se as plataformas que for por não são maiores do que as permitidas
			if(plataformas >= plataformas_restantes) {

				plataformas = plataformas_restantes; 
			}
			
		}
		else {
			//zera todos os valores do vetor então.
			plataformas = 0;
		}

		num_plataformas_por_andar.push_back(plataformas);
		plataformas_restantes -= plataformas;
	}


}

void Fases::Fase_2::Cria_Plataforma() {

    seta_Num_Plataformas();

	sf::Vector2f pos_plataforma;
	float posicao_da_ultima_plataforma = 0.f;
	
	for(i=0; i < num_max_andares; i++) {

		for (j = 0; j < num_plataformas_por_andar[i]; j++){

			seta_Tamanho_Plataformas(num_plataformas_por_andar[i]);

			pos_plataforma.y = pos_Piso.y - ((i + 1)* 180.f);
			pos_plataforma.x = posicao_da_ultima_plataforma + espaco_vazio_x;
			posicao_da_ultima_plataforma = pos_plataforma.x + tam_plataforma.x;


			std::cout << "andar : " << i << " " <<"Criando plataforma: " << pos_plataforma.x << " " << pos_plataforma.y << std::endl;

			plataforma = new Plataforma;
			plataforma->seta_Plataforma(tam_plataforma.y, tam_plataforma.x,pos_plataforma.x,pos_plataforma.y);

			gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(plataforma));
			lista_Entidades.Incluir(static_cast<Entidade*>(plataforma));
		}

		pos_plataforma.x = 0.f;
		posicao_da_ultima_plataforma = 0.f;
		
	}
	

}

void Fases::Fase_2::Cria_Piso() {

	piso = new Plataforma;
	piso->seta_Plataforma(tam_Piso_Fase.y, tam_Piso_Fase.x, pos_Piso.x, pos_Piso.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(piso));
}