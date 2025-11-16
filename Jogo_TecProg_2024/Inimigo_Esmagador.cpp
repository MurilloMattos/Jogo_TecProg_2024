#include "Inimigo_Esmagador.h"

using namespace Entidades;
using namespace Personagens;

// ... Construtor ...

Inimigo_Esmagador::Inimigo_Esmagador() : 
    estado_atual(EstadoEsmagador::PATRULHANDO), 
    tempo_preparacao_seg(1.0f), 
    raio_deteccao(150.f), 
    raio_ataque(75.f) 
{
    
    velocidade.x = 0.5f; // Anda devagar
}

Inimigo_Esmagador::~Inimigo_Esmagador() {
    // ... limpeza se necessário ...
}

// Executar apenas gerencia o estado ATUAL
void Inimigo_Esmagador::Executar() {

    // O Gerenciador de Colisões vai mudar o estado
    // de PATRULHANDO para PREPARANDO.

    switch (estado_atual) {
    
    case EstadoEsmagador::PATRULHANDO:
        Mover(); // Implementar lógica de patrulha (como no Inimigo_Medio)
        if (pFigura) pFigura->setFillColor(sf::Color::Blue); // Cor de patrulha
        break;

    case EstadoEsmagador::PREPARANDO:
        // O inimigo para (não chama Mover())
        if (pFigura) pFigura->setFillColor(sf::Color::Yellow); // Cor de preparação

        // Verifica se o tempo de espera passou
        if (relogio_preparacao.getElapsedTime().asSeconds() > tempo_preparacao_seg) {
            Atacar(); // Manda executar o ataque
        }
        break;

    case EstadoEsmagador::ATACANDO:
        // Este estado é "instantâneo". O Gerenciador de Colisões
        // vai detectar este estado e aplicar o dano no mesmo frame.
        if (pFigura) pFigura->setFillColor(sf::Color::Red); // Cor de ataque

        // Ação de ataque (ex: tocar som, mudar sprite)
        Danificar(); 
        
        // Volta a patrulhar
        estado_atual = EstadoEsmagador::PATRULHANDO;
        break;
    }

    Desenhar();
    setar_Pos(x, y);
}

// O Gerenciador de Colisões vai chamar esta função
void Inimigo_Esmagador::IniciarPreparacao() {
    if (estado_atual == EstadoEsmagador::PATRULHANDO) {
        estado_atual = EstadoEsmagador::PREPARANDO;
        relogio_preparacao.restart();
    }
}

void Inimigo_Esmagador::Atacar() {
    estado_atual = EstadoEsmagador::ATACANDO;
}

// Implementações mínimas para métodos declarados no header
void Inimigo_Esmagador::Mover() {
    // Movimento simples de patrulha: avança uma pequena distância
    x += 0.5f;
}

void Inimigo_Esmagador::Danificar() {
    // Implementação mínima: pode ser estendida para aplicar dano ao jogador
}

void Inimigo_Esmagador::Salvar() {
    // Persistência não implementada aqui; placeholder
}

EstadoEsmagador Inimigo_Esmagador::get_Estado() {
    return estado_atual;
}

float Inimigo_Esmagador::get_RaioDeteccao() {
    return raio_deteccao;
}

float Inimigo_Esmagador::get_RaioAtaque() {
    return raio_ataque;
}