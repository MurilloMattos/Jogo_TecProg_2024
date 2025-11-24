#include "Entidades/Personagens/Inimigos/Esmagador.h"

using namespace Entidades;
using namespace Personagens;

Esmagador::Esmagador() : 
    estado_atual(EstadoEsmagador::PATRULHANDO), 
    tempo_preparacao_seg(1.5f),
    tempo_ataque_seg(1.0f),
    raio_deteccao(60.f), 
    raio_ataque(60.f) 
{

    setar_Pontos_Por_Eliminacao(300);
    
    num_vitalidade = 150;
    dano = 40;

    tamanho.x = 40.0f;
    tamanho.y = 40.0f;

    pos_inicial.x = 500.f;
    pos_inicial.y = 100.f;

    pos_final = pos_inicial;

    velocidade.x = 0.5f; // Anda devagar

    if (pFigura != nullptr) {
        // IMPORTANTE: Remove qualquer textura herdada para que a cor funcione
        pFigura->setTexture(nullptr); 
        
        pFigura->setFillColor(sf::Color::Blue);
        pFigura->setSize(tamanho);
        // A posição será atualizada pelo setar_Pos, mas é bom garantir aqui também
        pFigura->setPosition(pos_inicial); 
        
    }
}

Esmagador::~Esmagador() {
    
}

// Executar apenas gerencia o estado ATUAL
void Esmagador::Executar() {

    pFigura->setPosition(x, y);

    switch (estado_atual) {
    
        case EstadoEsmagador::PATRULHANDO:
            
            Mover();
            AtualizarAnimacao();
            break;

        case EstadoEsmagador::PREPARANDO:
            
            AtualizarAnimacao();
            if (relogio_ataque.getElapsedTime().asSeconds() > tempo_preparacao_seg) {
                estado_atual = EstadoEsmagador::ATACANDO;
                relogio_ataque.restart();// Reinicia para o tempo de ataque
            }
            break;

        case EstadoEsmagador::ATACANDO:
            // Este estado é "instantâneo". O Gerenciador de Colisões
            // vai detectar este estado e aplicar o dano no mesmo frame.
            AtualizarAnimacao();
            VerificaAtaqueEmArea();
            if (relogio_ataque.getElapsedTime().asSeconds() > tempo_ataque_seg) {
                estado_atual = EstadoEsmagador::PATRULHANDO;
            }
            break;

    }   
    Desenhar();
    setar_Pos(x, y);
}

void Esmagador::Mover() {

    Jogador* jogador_alvo = nullptr;
    float distancia_jogador1 = 1000.f;
    float distancia_jogador2 = 1000.f;
    
    if(ponteiro_jogador1) {
        float dx1 = ponteiro_jogador1->get_X() - x;
        float dy1 = ponteiro_jogador1->get_Y() - y;
        distancia_jogador1 = sqrt(dx1 * dx1 + dy1 * dy1);
    }

    if(ponteiro_jogador2) {
        float dx2 = ponteiro_jogador2->get_X() - x;
        float dy2 = ponteiro_jogador2->get_Y() - y;
        distancia_jogador2 = sqrt(dx2 * dx2 + dy2 * dy2);
    }

    float dist_alvo = distancia_jogador1;
    if (distancia_jogador2 < distancia_jogador1) {
        jogador_alvo = ponteiro_jogador2;
        dist_alvo = distancia_jogador2;
    }
    else {
        jogador_alvo = ponteiro_jogador1;
    }

    andar_ate(jogador_alvo->get_X(), jogador_alvo->get_Y());

}

void Esmagador::VerificaAtaqueEmArea() {

    if (ponteiro_jogador1) {
        float dx1 = ponteiro_jogador1->get_X() - x;
        float dy1 = ponteiro_jogador1->get_Y() - y;
        float distancia1 = sqrt(dx1 * dx1 + dy1 * dy1);

        if (distancia1 <= raio_ataque) {

            if(dx1 > 0) {
                ponteiro_jogador1->setar_Pos(ponteiro_jogador1->get_X() + 10, ponteiro_jogador1->get_Y() - 10);

            }
            else {
                ponteiro_jogador1->setar_Pos(ponteiro_jogador1->get_X() - 10, ponteiro_jogador1->get_Y() - 10);
            }

            danificar(ponteiro_jogador1);
        }
    }

    if (ponteiro_jogador2) {
        float dx2 = ponteiro_jogador2->get_X() - x;
        float dy2 = ponteiro_jogador2->get_Y() - y;
        float distancia2 = sqrt(dx2 * dx2 + dy2 * dy2);

        if (distancia2 <= raio_ataque) {
            if(dx2 > 0) {
                ponteiro_jogador2->setar_Pos(ponteiro_jogador2->get_X() + 10, ponteiro_jogador2->get_Y() - 10);

            }
            else {
                ponteiro_jogador2->setar_Pos(ponteiro_jogador2->get_X() - 10, ponteiro_jogador2->get_Y() - 10);
            }
            danificar(ponteiro_jogador2);
        }
    }


}

void Esmagador::AtualizarAnimacao() {

    if (estado_atual == EstadoEsmagador::PATRULHANDO) {
        pFigura->setFillColor(sf::Color::Blue);
    }
    else if (estado_atual == EstadoEsmagador::PREPARANDO) {
        pFigura->setFillColor(sf::Color::Yellow);
    }
    else if (estado_atual == EstadoEsmagador::ATACANDO) {
        pFigura->setFillColor(sf::Color::Red);
    }
    
}

void Esmagador::Danificar() {
    
}

void Esmagador::Salvar() {
    // Persistência não implementada aqui; placeholder
}

void Esmagador::set_Estado(EstadoEsmagador novo_estado) {
    estado_atual = novo_estado;
}

EstadoEsmagador Esmagador::get_Estado() {
    return estado_atual;
}

void Esmagador::setar_Pontos_Por_Eliminacao(int pontos){
	
	pontos_de_eliminacao = pontos;
}

/*float Esmagador::get_RaioDeteccao() {
    return raio_deteccao;
}

float Esmagador::get_RaioAtaque() {
    return raio_ataque;
}*/