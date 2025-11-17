#include "Inimigo_Esmagador.h"

using namespace Entidades;
using namespace Personagens;

// ... Construtor ...

Inimigo_Esmagador::Inimigo_Esmagador() : 
    estado_atual(EstadoEsmagador::PATRULHANDO), 
    tempo_preparacao_seg(1.0f)
    //raio_deteccao(150.f), 
    //raio_ataque(75.f) 
{
    num_vitalidade = 150;
    dano = 40;

    tamanho.x = 30.0f;
    tamanho.y = 30.0f;

    pos_inicial.x = 700.f;
    pos_inicial.y = 159.f;

    pos_final = pos_inicial;

    velocidade.x = 0.5f; // Anda devagar

    if (pFigura != nullptr) {
        // IMPORTANTE: Remove qualquer textura herdada para que a cor funcione
        pFigura->setTexture(nullptr); 
        
        pFigura->setFillColor(sf::Color::Blue);
        pFigura->setSize(tamanho);
        // A posição será atualizada pelo setar_Pos, mas é bom garantir aqui também
        pFigura->setPosition(pos_inicial); 
        
        // Garante que a origem esteja no canto superior esquerdo (padrão)
        // ou ajuste se sua colisão usar centro (ex: tamanho.x/2, tamanho.y/2)
        pFigura->setOrigin(0.f, 0.f); 
    }
}

Inimigo_Esmagador::~Inimigo_Esmagador() {
    
}

// Executar apenas gerencia o estado ATUAL
void Inimigo_Esmagador::Executar() {

    switch (estado_atual) {
    
        case EstadoEsmagador::PATRULHANDO:
            
            if (pFigura) pFigura->setFillColor(sf::Color::Blue); // Cor de patrulha
            Mover();
            break;

        case EstadoEsmagador::PREPARANDO:
            // O inimigo para (não chama Mover())
            if (pFigura) pFigura->setFillColor(sf::Color::Yellow); // Cor de preparação

            // Verifica se o tempo de espera passou
            /*if (relogio_preparacao.getElapsedTime().asSeconds() > tempo_preparacao_seg) {
                Atacar(); // Manda executar o ataque
            }*/
            break;

        case EstadoEsmagador::ATACANDO:
            // Este estado é "instantâneo". O Gerenciador de Colisões
            // vai detectar este estado e aplicar o dano no mesmo frame.
            if (pFigura) pFigura->setFillColor(sf::Color::Magenta); // Cor de ataque
            break;

        }   
        Desenhar();
        setar_Pos(x, y);
    }

/*void Inimigo_Esmagador::IniciarPreparacao() {
    if (estado_atual == EstadoEsmagador::PATRULHANDO) {
        estado_atual = EstadoEsmagador::PREPARANDO;
        relogio_preparacao.restart();
    }
}

void Inimigo_Esmagador::Atacar() {
    estado_atual = EstadoEsmagador::ATACANDO;
}*/

void Inimigo_Esmagador::Mover() {
    x += 0.5f;

    if ((pos_final.x != x) && (pos_final.y != y)) {

	if (pos_final.x > x) {
		x += velocidade.x;
	}
	else if (pos_final.x < x) {
		x -= velocidade.x;
	}
    }

}

void Inimigo_Esmagador::Danificar() {
    // Implementação mínima: pode ser estendida para aplicar dano ao jogador
}

void Inimigo_Esmagador::Salvar() {
    // Persistência não implementada aqui; placeholder
}

void Inimigo_Esmagador::set_Estado(EstadoEsmagador novo_estado) {
    estado_atual = novo_estado;
}

EstadoEsmagador Inimigo_Esmagador::get_Estado() {
    return estado_atual;
}

float Inimigo_Esmagador::get_TempoPreparacaoSeg() {
    return tempo_preparacao_seg;
}

sf::Clock Inimigo_Esmagador::get_RelogioPreparacao() {
    return relogio_preparacao;
}
/*float Inimigo_Esmagador::get_RaioDeteccao() {
    return raio_deteccao;
}

float Inimigo_Esmagador::get_RaioAtaque() {
    return raio_ataque;
}*/