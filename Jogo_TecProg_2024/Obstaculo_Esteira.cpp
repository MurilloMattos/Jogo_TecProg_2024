#include "Obstaculo_Esteira.h"

// Implementações usando qualificação completa de namespace
Entidades::Obstaculos::Obstaculo_Esteira::Obstaculo_Esteira(float vel, sf::Vector2f dir)
    : Obstaculo(), velocidadeTransporte(vel), direcao(dir) {
    agressivo = false; // Esteira não é agressiva
    vel = -1.0f;
    tamanhoEsteira = sf::Vector2f(50.0f, 10.0f); // Exemplo de tamanho
}
Entidades::Obstaculos::Obstaculo_Esteira::~Obstaculo_Esteira() {}

void Entidades::Obstaculos::Obstaculo_Esteira::Executar() {
    // Lógica de animação da esteira rodando (mudança de rect da textura)
}

void Entidades::Obstaculos::Obstaculo_Esteira::Salvar() {
    // Implementar salvamento
}

void Entidades::Obstaculos::Obstaculo_Esteira::obstacular(Entidades::Personagens::Jogador* p) {
    // A esteira só deve mover o jogador se ele estiver EM CIMA dela.
    // Verificação simples de colisão superior:
    // Se o pé do jogador está próximo ao topo da esteira

    if (p == nullptr) return;

    float margemErro = 6.0f; // tolerância em pixels

    float playerLeft   = p->get_X();
    float playerRight  = p->get_Comprimento_L();
    float playerBottom = p->get_Y() + p->get_Altura();

    float obstLeft  = this->get_X();
    float obstRight = this->get_Comprimento_L();
    float obstTop   = this->get_Y();

    // Sobreposição horizontal
    bool overlapX = (playerRight > obstLeft) && (playerLeft < obstRight);

    // Pé do jogador perto do topo da esteira (com margem)
    bool pertoTopo = (playerBottom >= obstTop - margemErro) && (playerBottom <= obstTop + margemErro);

    if (overlapX && pertoTopo) {
        // Aplica movimento extra na posição do jogador (efeito de transporte)
        p->setar_Pos(p->get_X() + (velocidadeTransporte * direcao.x), p->get_Y());
    }
}