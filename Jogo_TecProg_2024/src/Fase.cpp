#include "Fase.h"

using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Fase::Fase():Ente() {

	srand(static_cast<unsigned int>(time(0)));
	num_plataformas = rand() % 7;

	ganhou = false;

	tam_Piso_Fase.x = 25.0f;//2500.f;
	tam_Piso_Fase.y = 1.0f;//;100.f;
	pos_Piso.x = -600.f; //10.f;
	pos_Piso.y = 200.f; //80.f;

	tam_plataforma.x = 0.3f;//150.f;
	tam_plataforma.y = 0.5f;

	pos_original.x = 100.f;
	pos_original.y = 30.f;

	Cria_Piso();
	Cria_Plataforma();
	//Cria_Inimigos();
}

Fase::~Fase() {

	delete plataforma;
	delete piso;
}

/*
Gerenciadores::Gerenciador_colisoes* Fase::get_Gerenciador_Colisoes()
{
	return &gerenciador_colisoes;
}
*/
Listas::Lista_Entidades* Fase::get_Lista_Entidades()
{
	return &lista_Entidades;
}
/*
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

void Fase::Cria_Piso() {
	piso = new Piso;
	piso->seta_Piso(tam_Piso_Fase.y, tam_Piso_Fase.x, pos_Piso.x, pos_Piso.y);

	gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(piso));
	lista_Entidades.Incluir(static_cast<Entidade*>(piso));	
}

void Fases::Fase::Cria_Plataforma() {	
	if (num_plataformas < 4){
		num_plataformas = 4;
	}
	//num_plataformas = 7;
	srand(static_cast<unsigned int>(time(0)));

	std::cout << num_plataformas << std::endl;
	int i;
	float aux = static_cast<float>((rand() % (700 - 200 + 1)) + 200);
	float espaco = aux;
	
	for (i = 0; i < num_plataformas; i++) {

		plataforma = new Piso;
		plataforma->seta_Piso(tam_plataforma.y, tam_plataforma.x, pos_original.x + espaco, pos_original.y);
	        aux = static_cast<float>((rand() % (700 - 200 + 1)) + 200);
		espaco += (tam_plataforma.x*2.5f + aux);//rand()%200);
		//if (espaco > tam_Piso_Fase.x) {
		//	espaco = tam_Piso_Fase.x;
		//}
		gerenciador_colisoes.Incluir_Obstaculo(static_cast<Obstaculo*>(plataforma));
		lista_Entidades.Incluir(static_cast<Entidade*>(plataforma));
	}
}
void Fases::Fase::Cria_Inimigos_Piratas(){
	Inimigo_Medio* pirata;

	pirata = new Inimigo_Medio;
	pirata->setar_Pos(290.f, 100.f);

	gerenciador_colisoes.Incluir_Inimigo(pirata);
	lista_Entidades.Incluir(static_cast<Entidade*>(pirata));
}

bool Fases::Fase::get_Ganhou()
{
	return ganhou;
}

void Fase::Cria_Inimigos() {

	Cria_Inimigos_Piratas();
}

void Fases::Fase::verifica_Inimigos_Neutralizados(){

	lista_Entidades.Remover(gerenciador_colisoes.Inimigo_neutralizado());

	if (gerenciador_colisoes.verifica_Lista_Inimigos_Vazia()) {

		std::cout << "todos os inimigos foram eliminados!" << std::endl;
		ganhou = true;
	}
}

void Fases::Fase::Executar() {
	verifica_Inimigos_Neutralizados();
	gerenciador_colisoes.Executar();
	lista_Entidades.Percorrer();
}
/*
void Fase::executa_Colisões(){
	
}
*/

