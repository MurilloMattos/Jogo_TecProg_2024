#include "Entidade.h"

using namespace Entidades;

Entidade::Entidade() : Ente()
{
	x = 0;
	y = 0;
	//gravidade = 9.807f;

	velocidade.x = 0;
	velocidade.y = 0;

	velocidade_inicial.y = 0;
	velocidade_inicial.x = 0;

	agressivo = false;
	gravidade = 5.0f;

	aceleracao.x = 0;
	aceleracao.y = gravidade;

	pFigura->setPosition(x, y);
}

Entidade::~Entidade(){

}

float Entidade::get_Gravidade() const{
	return gravidade;
}

void Entidades::Entidade::setar_Gravidade(float grav){
	gravidade = grav;
}

//irá funcionar?
void Entidades::Entidade::executar_Gravidade(){
	y += gravidade;

}

sf::Vector2f Entidades::Entidade::get_Centro()
{
	
	centro.x = x + (get_Largura() / 2);
	centro.y = y + (get_Altura() / 2);

	return sf::Vector2f(centro);
}

float Entidades::Entidade::get_Largura(){
	return pFigura->getLocalBounds().width;
}

float Entidades::Entidade::get_Altura(){
	return pFigura->getLocalBounds().height;
}


//esta é a posição relativa ao canto superior esquerdo da figura em relação a janela (o pixel (0,0))
float Entidades::Entidade::get_X() const{
	return x;
}

float Entidades::Entidade::get_Y() const{
	return y;
}

//retorna Y + A
float Entidades::Entidade::get_Comprimento_A() {

	return get_Y() + get_Altura();
}

//retorna X + L
float Entidades::Entidade::get_Comprimento_L() {
	return get_X() + get_Largura();
}


void Entidade::setar_Pos(float pos_x, float pos_y)
{
	x = pos_x;
	y = pos_y;

	pFigura->setPosition(x, y);
}

void Entidades::Entidade::setar_velocidade(float vel_x, float vel_y)
{
	velocidade.x = vel_x;
	velocidade.y = vel_y;
}

