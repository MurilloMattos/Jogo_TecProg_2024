//Obstacullo Médio: Esteira que empurra o jogador

#pragma once
#include "Entidades/Obstaculos/Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {

        class Esteira : public Obstaculo {
        private:

            float velocidadeTransporte; // Velocidade que a esteira joga o player
            int direcao;       // Determina a direção do transporte
            Personagens::Jogador* jogadorSobre; // Ponteiro para o jogador atualmente sobre a esteira (se houver)
            sf::Vector2f tamanhoEsteira; // Tamanho da esteira para cálculos de colisão
            bool colideAtual;
            bool colideAnterior;
            float x, y;
            
        public:

            Esteira(float vel, float pos_x, float pos_y);
            ~Esteira();

            void Executar();
            void Salvar();
            
            // Método específico da esteira: empurra o jogador
            void obstacular(Entidades::Personagens::Jogador* p, int lado);

            sf::Vector2f get_Tamanho_Esteira();
            
        };
    }
}