#include "Entidades/Obstaculos/Esteira.h"

using namespace Entidades;
using namespace Obstaculos;

Entidades::Obstaculos::Esteira::Esteira(float vel, float pos_x, float pos_y) :
Obstaculo(), velocidadeTransporte(vel), direcao(1), x(pos_x), y(pos_y) {

    agressivo = false;
    tamanhoEsteira = sf::Vector2f(100.0f, 10.0f);

}

Entidades::Obstaculos::Esteira::~Esteira() {

}

void Entidades::Obstaculos::Esteira::Executar() {

    if(colideAtual && !colideAnterior){
        direcao = -direcao;
    }

    if(direcao > 0){
        pFigura->setFillColor(sf::Color::Cyan); // Direita
    } else {
        pFigura->setFillColor(sf::Color::Blue); // Esquerda
    }

    colideAnterior = colideAtual;
    colideAtual = false;

    pFigura->setSize(tamanhoEsteira);
    pFigura->setPosition(x, y);
    this->Desenhar();

}

void Entidades::Obstaculos::Esteira::Salvar() {
    // Implementar salvamento
}

// assinatura totalmente qualificada (corrige erro de 'has not been declared')
void Entidades::Obstaculos::Esteira::obstacular(Entidades::Personagens::Jogador* p, int lado) {
    
    if (p == nullptr) return;

    if(lado == 4){

        colideAtual = true;

        float margemErro = 1.0f;//

        float playerLeft   = p->get_X();
        float playerRight  = p->get_Comprimento_L();
        float playerBottom = p->get_Y() + p->get_Altura();

        float obstLeft  = this->get_X();
        float obstRight = this->get_Comprimento_L();
        float obstTop   = this->get_Y(); // A parte de cima da esteira

        bool overlapX = (playerRight > obstLeft) && (playerLeft < obstRight);// Verifica sobreposição horizontal
        
        // Verifica se os pés do jogador estão tocando o topo da esteira
        bool pertoTopo = (playerBottom >= obstTop - margemErro) && (playerBottom <= obstTop + margemErro);

        if (overlapX && pertoTopo) {
            // 1. Aplica o movimento da esteira (Empurrão lateral)
            p->setar_Pos(p->get_X() + (direcao * velocidadeTransporte), p->get_Y());
            
        }

    }
}
