 #include "Entidades/Personagens/Jogador.h"

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador() : semente_id_entidade(10) {

	//arrumar isso posteriormente
	setId(semente_id_entidade);

	segundo_jogador = false;
	estado_pulando = false;
	no_ar = false;
	estado_caindo = true;

	num_vitalidade = 100;

	dano = 70;

	gravidade = 6.0f;

	tamanho.x = 20;
	tamanho.y = 40;

	x = 0.f;
	y = (pGG->getCamera()->getSize().y/3);

	setar_Vitalidade(100);
	setar_Figura();
	setar_Pos(x,y);

	forca_de_impulso = -9.0;
	acelerando = false;
	
	//altura_de_pulo = 50.0;
	
	velocidade.y = -5.0;
	velocidade.x = 3.0;
	//velocidade.y = 5.0;

	pontos = 0;
}

Jogador::~Jogador() {

}

void Jogador::Executar() {


	if (!eliminado) {

		executar_Gravidade();

		Desenhar();
		setar_Pos(x, y);

		if (!segundo_jogador) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				x += velocidade.x;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				x -= velocidade.x;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {

				executando_Pulo();
			}

		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				x += velocidade.x;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				x -= velocidade.x;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				executando_Pulo();
			}
		}
	}
	
}

void Jogador::setar_Estado_Pulando(bool estado){
	estado_pulando = estado;
}

bool Jogador::get_Eliminado() const
{
	return eliminado;
}

void Entidades::Personagens::Jogador::executar_Gravidade() {

	if (velocidade.y <= forca_de_impulso) {
		acelerando = false;
	}

	if (estado_pulando) {
		if (acelerando) {
			velocidade.y -= 0.3f;
		}
		else {
			velocidade.y += 0.3f;
		}
		//velocidade.y += 1.5f;
	}

	else if (velocidade.y <= gravidade) {
		//y += velocidade.y;
		velocidade.y += 1.5f;
		//velocidade.y = gravidade;
	}
	if (velocidade.y > gravidade) {
		velocidade.y = gravidade;
	}

	y += velocidade.y;
}


void Jogador::setar_Dois_Jogadores(bool jogador_dois) {

	if (jogador_dois) {
		segundo_jogador = jogador_dois;
		pFigura->setFillColor(sf::Color::Cyan);
		setar_Pos(x + 25, y);
		eliminado = false;
		estado_pulando = false;
		no_ar = false;
	}
	else {
		eliminado = true;
	}
}

bool Jogador::get_Dois_Jogadores() {
	return segundo_jogador;
}

void Entidades::Personagens::Jogador::executando_Pulo()
{
	if (!estado_pulando && !no_ar) {

		velocidade.y = forca_de_impulso + 3.0f;
		estado_pulando = true;
		no_ar = true;

		acelerando = true;
	}
}

void Jogador::Salvar(){

}


void Jogador::danificar(Personagem* pAtacado) {

	pAtacado->diminuir_Vitalidade(dano);
	setar_Estado_Pulando(false);
	setar_No_Ar(false);
	executando_Pulo();
}


void Jogador::diminuir_Vitalidade(int dano) {

	num_vitalidade -= dano;
	if (num_vitalidade <= 0) {
		num_vitalidade = 0;
		eliminado = true;
	}
	std::cout << "Jogador " << getId() << " tomou " << dano << " de dano. Vitalidade atual: " << num_vitalidade << std::endl;

	if (eliminado) {
		std::cout << "Jogador " << getId() << " foi eliminado!" << std::endl;
	}
}

// adicionar em classes primordiais? tais como Ente ou Entidades?
void Jogador::setar_Figura() {

	pFigura->setSize(tamanho);
	pFigura->setFillColor(sf::Color::Blue);
}

void Jogador::aumentar_Pontuacao(int pontos_a_adicionar){

	pontos += pontos_a_adicionar;
}

int Jogador::get_Pontuacao() const {

	return pontos;
}

void Jogador::setar_Caindo(bool caindo){
	estado_caindo = caindo;
}

void Jogador::setar_No_Ar(bool no_meio_do_ar){

	no_ar = no_meio_do_ar;
}

void Jogador::setar_Bateu_A_Cabeca(){
	
	velocidade.y = 0;
	acelerando = false;
}