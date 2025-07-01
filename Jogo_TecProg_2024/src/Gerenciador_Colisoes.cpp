#include "Gerenciador_Colisoes.h"
using namespace Gerenciadores;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace std;


Gerenciador_colisoes::Gerenciador_colisoes() : direita(1),cima(2),esquerda(3),baixo(4)
{
	empurrao = 50.0f;

	lista_Inimigos.clear();
	lista_Obstaculos.clear();
	
	pJogador1 = nullptr;
	pJogador2 = nullptr;
}

Gerenciador_colisoes::~Gerenciador_colisoes(){

	lista_Inimigos.clear();
	lista_Obstaculos.clear();

	pJogador1 = nullptr;
	pJogador2 = nullptr;
}

void Gerenciador_colisoes::Incluir_Obstaculo(Obstaculo* p_Obstaculo){
	lista_Obstaculos.push_back(p_Obstaculo);
}

void Gerenciador_colisoes::Incluir_Inimigo(Inimigo* p_Inimigo){
	lista_Inimigos.push_back(p_Inimigo);
}

void Gerenciador_colisoes::Incluir_Projetil(Projetil* p_Projetil){
	lista_Projeteis.insert(p_Projetil);
}

void Gerenciador_colisoes::Setar_Jogador(Jogador* p_Jogador1, Jogador* p_Jogador2){

	if (p_Jogador1 != nullptr) {
		pJogador1 = p_Jogador1;
	}
	if (p_Jogador2 != nullptr) {
		pJogador2 = p_Jogador2;
	}
}

/*
Entidades::Entidade* Gerenciadores::Gerenciador_colisoes::projetil_Destruido()
{


	return nullptr;
}
*/

// Definitivamente uma melhor solução seria colocar essa fução na classe fase
Entidade* Gerenciador_colisoes::Inimigo_neutralizado()
{
	int i;

	Entidade* aux;

	for (i = 0; i < lista_Inimigos.size(); i++) {

		if (lista_Inimigos[i]->get_Vitalidade() <= 0) {

 			aux = lista_Inimigos[i];
			lista_Inimigos.erase(lista_Inimigos.begin() + i);
			
			return aux;
		}
	}
	return nullptr;
}

bool Gerenciador_colisoes::verifica_Lista_Inimigos_Vazia()
{
	if (lista_Inimigos.size() == 0) {
		return true;
	}
	else {
		return false;
	}
}

//classe nova?
void Gerenciador_colisoes::tratar_Fisica_Inimigos(){

	int i;

	for (i = 0; i < lista_Inimigos.size(); i++) {
		lista_Inimigos[i]->executar_Gravidade();
	}
}

void Gerenciador_colisoes::tratar_Fisica_Projeteis(){

	
	set<Projetil*>::iterator itr;

	for (itr = lista_Projeteis.begin(); itr != lista_Projeteis.end(); itr++) {

		(*itr)->executar_Gravidade();

		itr++;
	}
}

void Gerenciador_colisoes::tratar_Fisica_Jogadores() {
	if (pJogador1)
		pJogador1->executar_Gravidade();

	if (pJogador2)
		pJogador2->executar_Gravidade();
}

void Gerenciador_colisoes::tratar_Fisica_Obstaculos(){

	list<Obstaculo*>::iterator itr;

	itr = lista_Obstaculos.begin();

	while (itr != lista_Obstaculos.end()) {

		(*itr)->executar_Gravidade();

		itr++;
	}
}

void Gerenciador_colisoes::tratar_Colisoes_Jogador_Obstaculo(Jogador* p_Jogador) {

	list<Obstaculo*>::iterator itr;

	itr = lista_Obstaculos.begin();


	//verifica o tipo de colisão especificamente com objetos.
	while (itr != lista_Obstaculos.end()) {

		int lado = verifica_Tipo_De_Colisao(static_cast<Entidade*>(p_Jogador), static_cast<Entidade*>(*itr));

		//direita
 		if (lado == 1) {

			p_Jogador->setar_Pos(((*itr)->get_X() - p_Jogador->get_Largura()), p_Jogador->get_Y());
			//(*itr)->obstacular(p_Jogador);
		}
		//cima
		else if (lado == 2) {

			p_Jogador->setar_Pos(p_Jogador->get_X(), (*itr)->get_Comprimento_A());
			//(*itr)->obstacular(p_Jogador);
		}
		//esquerda
		else if (lado == 3) {

			p_Jogador->setar_Pos((*itr)->get_Comprimento_L(), p_Jogador->get_Y());
			//(*itr)->obstacular(p_Jogador);
		}
		//baixo
		else if (lado == 4) {

			p_Jogador->setar_Pos(p_Jogador->get_X(), ((*itr)->get_Y() - p_Jogador->get_Altura()));
			//(*itr)->obstacular(p_Jogador);
			p_Jogador->setar_Estado(false);
		}

		itr++;
	}
}

bool Gerenciador_colisoes::tratar_Colisoes_Jogador_Projeteis(Jogador* p_Jogador){

	set<Projetil*>::iterator itr;

	itr = lista_Projeteis.begin();

	while (itr != lista_Projeteis.end()) {

		int lado = verifica_Tipo_De_Colisao(static_cast<Entidade*>(p_Jogador), static_cast<Entidade*>(*itr));

		if (lado != 0) {
			return true;
		}

		itr++;
	}

	return false;
}

void Gerenciador_colisoes::tratar_Colisoes_Obstaculo(Entidade* pEntidadeRef) {

	list<Obstaculo*>::iterator itr;

	itr = lista_Obstaculos.begin();


	//verifica o tipo de colisão especificamente com objetos.
	while (itr != lista_Obstaculos.end()) {

		int lado = verifica_Tipo_De_Colisao(static_cast<Entidade*>(pEntidadeRef), static_cast<Entidade*>(*itr));
		//direita
		if (lado == 1) {

			pEntidadeRef->setar_Pos(((*itr)->get_X() - pEntidadeRef->get_Largura()), pEntidadeRef->get_Y());
			//(*itr)->obstacular(static_cast<Jogador*>(pEntidadeRef));

		}
		//cima
		else if (lado == 2) {

			pEntidadeRef->setar_Pos(pEntidadeRef->get_X(), (*itr)->get_Comprimento_A());
			//(*itr)->obstacular(static_cast<Jogador*>(pEntidadeRef));
		}
		//esquerda
		else if (lado == 3) {
			pEntidadeRef->setar_Pos((*itr)->get_Comprimento_L(), pEntidadeRef->get_Y());	
			//(*itr)->obstacular(static_cast<Jogador*>(pEntidadeRef));
		}
		//baixo
		else if (lado == 4) {
			pEntidadeRef->setar_Pos(pEntidadeRef->get_X(), ((*itr)->get_Y() - pEntidadeRef->get_Altura()));
			//(*itr)->obstacular(static_cast<Jogador*>(pEntidadeRef));
		}
		itr++;
	}
}

void Gerenciador_colisoes::tratar_Colisoes_Projeteis(){

	set<Projetil*>::iterator itr_proj;
	list<Obstaculo*>::iterator itr_obst;

	itr_proj = lista_Projeteis.begin();

	while (itr_proj != lista_Projeteis.end()) {

		itr_obst = lista_Obstaculos.begin();

		while (itr_obst != lista_Obstaculos.end()) {

			int lado = verifica_Tipo_De_Colisao(static_cast<Entidade*>(*itr_proj), static_cast<Entidade*>(*itr_obst));

			if (lado != 0) {

			}

			itr_obst++;
		}

		itr_proj++;
	}
}

void Gerenciador_colisoes::tratar_Colisoes_Inimigos(){

	int i;

	for (i = 0; i < lista_Inimigos.size(); i++) {

		if (lista_Inimigos[i]->get_Vitalidade() < 0) {
			std::cout << "entidade " << i << " foi neutralizada" << std::endl;
		}


		if (pJogador2 != nullptr) {
			tratar_Colisoes_Obstaculo(static_cast<Entidade*>(lista_Inimigos[i]));
			tratar_Colisoes_Jogador_Inimigos(pJogador1, lista_Inimigos[i]);
			tratar_Colisoes_Jogador_Inimigos(pJogador2, lista_Inimigos[i]);

			lista_Inimigos[i]->andar_ate(pJogador1->get_Centro().x, pJogador1->get_Centro().y);
			lista_Inimigos[i]->andar_ate(pJogador2->get_Centro().x, pJogador2->get_Centro().y);
		}
		else {
			tratar_Colisoes_Obstaculo(static_cast<Entidade*>(lista_Inimigos[i]));
			tratar_Colisoes_Jogador_Inimigos(pJogador1, lista_Inimigos[i]);

			lista_Inimigos[i]->andar_ate(pJogador1->get_Centro().x, pJogador1->get_Centro().y);

		}

	}

}

// 
void Gerenciador_colisoes::tratar_Colisoes_Jogador_Inimigos(Jogador* pJogador, Inimigo* pInimigo) {

	int lado = verifica_Tipo_De_Colisao(pJogador, pInimigo);



	pInimigo->coordenada_Polar(static_cast<Personagem*>(pJogador));
	if(visar_Personagem(static_cast<Personagem*>(pInimigo), static_cast<Personagem*>(pJogador))) {
		const bool &e = true;
		try {
  			pInimigo->set_Atacar(false);		
		} catch (const bool &e) {
			pInimigo->set_Atacar(false);
		}	
	}
	
	//direita
	if (lado == 1) {

		pJogador->setar_Pos((pInimigo->get_X() - pJogador->get_Largura() - empurrao), pJogador->get_Y());
		pJogador->diminuir_Vitalidade(pInimigo->danificar());
	}
	//cima
	else if (lado == 2) {

		pJogador->setar_Pos(pJogador->get_X(), pInimigo->get_Comprimento_A() + empurrao);
		pJogador->diminuir_Vitalidade(pInimigo->danificar());
	}
	//esquerda
	else if (lado == 3) {

		pJogador->setar_Pos(pInimigo->get_Comprimento_L() + empurrao, pJogador->get_Y());
		pJogador->diminuir_Vitalidade(pInimigo->danificar());
	}
	//baixo
	else if (lado == 4) {

		pJogador->setar_Pos(pJogador->get_X(), (pInimigo->get_Y() - pJogador->get_Altura()));
		pJogador->setar_Estado(false);
		pJogador->executando_Pulo();
		pInimigo->diminuir_Vitalidade(pJogador->danificar());
	}

}

//Essa classe tem como objetivo Garantir corretamente o lado colidido da entidade referência.
//Primeiro ela verifica as coordenadas principais, depois confirma com as secundárias, referente a colisão respectivamente.
const int Gerenciador_colisoes::verifica_Tipo_De_Colisao(Entidade* pEntidade_Ref, Entidade* pEntidade2) {
	
	float maior = 0;
	int lado = 0;
	bool colisao = false;
	float comprimento_baixo = 0;
	float comprimento_cima = 0;
	float comprimento_direita = 0;
	float comprimento_esquerda = 0;

	//Baixo
	if (verifica_Colisao_Baixo(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_X() < pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_X())) {

			comprimento_baixo = pEntidade_Ref->get_Comprimento_L() - pEntidade2->get_X();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_X() >= pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() <= pEntidade2->get_Comprimento_L())) {

			comprimento_baixo = pEntidade_Ref->get_Largura();
			colisao = true;
		}

		else if ((pEntidade_Ref->get_X() > pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_Comprimento_L())) {
			
			comprimento_baixo = pEntidade2->get_Comprimento_L() - pEntidade_Ref->get_X();
			colisao = true;
		}

	}

	//Cima
	if (verifica_Colisao_Cima(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_X() < pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_X())) {

			comprimento_cima = pEntidade_Ref->get_Comprimento_L() - pEntidade2->get_X();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_X() >= pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() <= pEntidade2->get_Comprimento_L())){

			comprimento_cima = pEntidade_Ref->get_Largura();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_X() > pEntidade2->get_X()) && (pEntidade_Ref->get_Comprimento_L() > pEntidade2->get_Comprimento_L())) {

			comprimento_cima = pEntidade2->get_Comprimento_L() - pEntidade_Ref->get_X();
			colisao = true;
		}
	}
	
	//Direita
	if (verifica_Colisao_Direita(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_Y() < pEntidade2->get_Y()) && (pEntidade2->get_Y() < pEntidade_Ref->get_Comprimento_A())) {

			comprimento_direita = pEntidade_Ref->get_Comprimento_A() - pEntidade2->get_Y();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() >= pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() <= pEntidade2->get_Comprimento_A()) ) {
			
			comprimento_direita = pEntidade_Ref->get_Altura();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() > pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() > pEntidade2->get_Comprimento_A())) {

			comprimento_direita = pEntidade2->get_Comprimento_A() - pEntidade_Ref->get_Y();
			colisao = true;
		}
	}

	//Esquerda
	if (verifica_Colisao_Esquerda(static_cast<Entidade*>(pEntidade_Ref), static_cast<Entidade*>(pEntidade2))) {

		if ((pEntidade_Ref->get_Y() < pEntidade2->get_Y()) && (pEntidade2->get_Y() < pEntidade_Ref->get_Comprimento_A())) {

			comprimento_esquerda = pEntidade_Ref->get_Comprimento_A() - pEntidade2->get_Y();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() >= pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() <= pEntidade2->get_Comprimento_A())) {

			comprimento_esquerda = pEntidade_Ref->get_Altura();
			colisao = true;
		}
		else if ((pEntidade_Ref->get_Y() > pEntidade2->get_Y()) && (pEntidade_Ref->get_Comprimento_A() > pEntidade2->get_Comprimento_A())) {

			comprimento_esquerda = pEntidade2->get_Comprimento_A() - pEntidade_Ref->get_Y();
			colisao = true;
		}
	}
	
	// verifica o maior lado em contato da entidade Referência com a colidida e retorna o lado colidido.
	if (colisao) {
		if (maior < comprimento_baixo) {

			maior = comprimento_baixo;
			lado = baixo;
		}

		if (maior < comprimento_cima) {

			maior = comprimento_cima;
			lado = cima;
		}
		if (maior < comprimento_direita) {

			maior = comprimento_direita;
			lado = direita;
		}
		if (maior < comprimento_esquerda) {

			maior = comprimento_esquerda;
			lado = esquerda;
		}
	}

	return lado;
}

//verifica se o objeto esta com possibilidade de colisão.
const bool Gerenciador_colisoes::verifica_Mesma_Pos(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	bool pos = true;

	// (y > y2 + a) ou (y + a < y2)
	if ((pEntidade_Ref->get_Y() > pEntidade2->get_Comprimento_A()) ||
		(pEntidade_Ref->get_Comprimento_A() < pEntidade2->get_Y())) {
		pos = false;
	}
	// (x > x2 + l) ou (x + l < x2)
	else if ((pEntidade_Ref->get_X() > pEntidade2->get_Comprimento_L()) ||
		(pEntidade_Ref->get_Comprimento_L() < pEntidade2->get_X())) {
		pos = false;
	}

	return pos;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Cima(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		// (y <= y2 + a) && (y + a >= y2 + a)
		if ((pEntidade_Ref->get_Y() <= pEntidade2->get_Comprimento_A()) &&
			(pEntidade_Ref->get_Comprimento_A() >= pEntidade2->get_Comprimento_A()))
		{
			return true;
		}
	}

	return false;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Esquerda(Entidade* pEntidade_Ref, Entidade* pEntidade2) {


	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		// (x <= x2 + l) && (x + l >= x2 + l)
		if ((pEntidade_Ref->get_X() <= pEntidade2->get_Comprimento_L()) &&
			(pEntidade_Ref->get_Comprimento_L() >= pEntidade2->get_Comprimento_L()))
		{
			return true;
		}

	}

	return false;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Baixo(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		//(y + a >= y2) && (y + a <= y2 + h)
		if ((pEntidade_Ref->get_Comprimento_A() >= pEntidade2->get_Y()) &&
			(pEntidade_Ref->get_Comprimento_A() <= pEntidade2->get_Comprimento_A()))
		{
			return true;

		}
	}

	return false;
}

//Auto explicativo
const bool Gerenciador_colisoes::verifica_Colisao_Direita(Entidade* pEntidade_Ref, Entidade* pEntidade2) {

	if (!verifica_Mesma_Pos(pEntidade_Ref, pEntidade2)) {
		return false;
	}
	else {

		// (x <= x2) && (x + l => x2)
		if ((pEntidade_Ref->get_X() <= pEntidade2->get_X()) &&
			(pEntidade_Ref->get_Comprimento_L() >= pEntidade2->get_X()))
		{
			return true;
		}
	}

	return false;
}

void Gerenciador_colisoes::Executar(){
	tratar_Fisica_Jogadores();
	tratar_Fisica_Obstaculos();
	tratar_Fisica_Inimigos();
	tratar_Fisica_Projeteis();

	tratar_Colisoes_Jogador_Obstaculo(pJogador1);
	tratar_Colisoes_Jogador_Projeteis(pJogador1);
	if (pJogador2) {
		tratar_Colisoes_Jogador_Obstaculo(pJogador2);
		tratar_Colisoes_Jogador_Projeteis(pJogador2);
	}
	tratar_Colisoes_Inimigos();
	tratar_Colisoes_Projeteis();
}
Entidades::Personagens::Jogador* Gerenciador_colisoes::get_Jogador1() {
	return pJogador1;
}
Entidades::Personagens::Jogador* Gerenciador_colisoes::get_Jogador2() {
	return pJogador2;
}
float Gerenciador_colisoes::produto_Escalar(sf::Vector2f v1, sf::Vector2f v2) {
	return v1.x * v2.x + v1.y * v2.y;	
}
float Gerenciador_colisoes::cosseno_Entre(sf::Vector2f v1, sf::Vector2f v2) {
	float d = produto_Escalar(v1, v2);
	float norma1 = std::sqrt(produto_Escalar(v1, v1));
	float norma2 = std::sqrt(produto_Escalar(v2, v2));
	if(norma1 == 0 || norma2 == 0) { return 0; }
	
	return (d / (norma1 * norma2));
}
bool Gerenciador_colisoes::visar_Personagem(Personagem *p1, Personagem *p2) {
    	sf::Vector2f frente(std::cos(p1->get_Angulo()), std::sin(p1->get_Angulo()));
    	sf::Vector2f ateAlvo(p2->get_X() - p1->get_X(), p2->get_Y() - p1->get_Y());
    float cosen = cosseno_Entre(frente, ateAlvo);

 	if(cosen > 0) {
		return true; // no angulo de visao do inimigo
	}
	return false;
}
int Gerenciador_colisoes::lado_DoAlvo(Personagem* atual, Personagem* alvo) {
    if (!alvo || !atual) return 0;

    sf::Vector2f dirFrente(std::cos(atual->get_Angulo()), std::sin(atual->get_Angulo()));
    sf::Vector2f ateAlvo(alvo->get_X() - atual->get_X(), alvo->get_Y() - atual->get_Y());

    float cruz = dirFrente.x * ateAlvo.y - dirFrente.y * ateAlvo.x;

    if (cruz > 0) return -1; // esquerda
    if (cruz < 0) return 1;  // direita
    return 0; // alinhado
}
void Gerenciador_colisoes::limpar_Projeteis() {
	std::set<Projetil*>::iterator it;
  if(lista_Projeteis.size() >= 10) {
	for(it = lista_Projeteis.begin(); it != lista_Projeteis.end(); it++) {
		if(*it) {
			delete *it;
			lista_Projeteis.erase(it);
		}

	}
  }	
}
