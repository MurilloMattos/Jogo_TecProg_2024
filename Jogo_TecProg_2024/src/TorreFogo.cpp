#include "TorreFogo.h"
using namespace Entidades;
using namespace Personagens;

Fases::TorreFogo::TorreFogo(): Fase() {
	Cria_Inimigos();
	setFile("./assets/fasefogo.png");
	atribuirFigura();
	pFigura->setPosition(0.0f, 0.0f);	

}
Fases::TorreFogo::~TorreFogo() {

}
void Fases::TorreFogo::Cria_Inimigo_Dificeis() {


}
void Fases::TorreFogo::Cria_Obstaculos_Faceis() {


}
void Fases::TorreFogo:: Executar() {
	
}
