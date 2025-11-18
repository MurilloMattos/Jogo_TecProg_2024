#include "Obstaculo_Esteira.h"

// Implementações usando qualificação completa de namespace
Entidades::Obstaculos::Esteira::Esteira(float vel, sf::Vector2f dir) :
Obstaculo(), velocidadeTransporte(vel), direcao(dir) {

    agressivo = false;
    tamanhoEsteira = sf::Vector2f(100.0f, 10.0f); // Exemplo de tamanho

}

Entidades::Obstaculos::Esteira::~Esteira() {

}

void Entidades::Obstaculos::Esteira::Executar() {

    pFigura->setFillColor(sf::Color::Cyan); // Cor indicativa da esteira
    pFigura->setSize(tamanhoEsteira);
    pFigura->setPosition(x, y);
    this->Desenhar();

}

void Entidades::Obstaculos::Esteira::Salvar() {
    // Implementar salvamento
}

// assinatura totalmente qualificada (corrige erro de 'has not been declared')
void Entidades::Obstaculos::Esteira::obstacular(Entidades::Personagens::Jogador* p) {
    if (p == nullptr) return;

    float margemErro = 1.0f;

    float playerLeft   = p->get_X();
    float playerRight  = p->get_Comprimento_L();
    float playerBottom = p->get_Y() + p->get_Altura();

    float obstLeft  = this->get_X();
    float obstRight = this->get_Comprimento_L();
    float obstTop   = this->get_Y(); // A parte de cima da esteira

    bool overlapX = (playerRight > obstLeft) && (playerLeft < obstRight);
    
    // Verifica se os pés do jogador estão tocando o topo da esteira
    bool pertoTopo = (playerBottom >= obstTop - margemErro) && (playerBottom <= obstTop + margemErro);

    if (overlapX && pertoTopo) {
        // 1. Aplica o movimento da esteira (Empurrão lateral)
        p->setar_Pos(p->get_X() + (velocidadeTransporte * direcao.x), p->get_Y());

        // --- CORREÇÃO AQUI ---
        // 2. Impede que o jogador atravesse a esteira para baixo (Simula chão sólido)
        // Define a posição Y do jogador exatamente em cima da esteira
        p->setar_Pos(p->get_X(), this->get_Comprimento_A()); // get_Comprimento_A deve retornar o topo Y do obstáculo

        // 3. Avisa o jogador que ele está no chão (para resetar a gravidade/pulo)
        p->setar_Estado(false); 
        // ---------------------
    }
}

// CORREÇÃO: Adicione Entidades::Obstaculos:: antes de Esteira
sf::Vector2f Entidades::Obstaculos::Esteira::get_Tamanho_Esteira() {
    return tamanhoEsteira;
}