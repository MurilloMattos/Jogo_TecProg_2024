#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {

        class Obstaculo_Esteira : public Obstaculo {
        private:
            float velocidadeTransporte; // Velocidade que a esteira joga o player
            sf::Vector2f direcao;       // Determina a direção do transporte
            Personagens::Jogador* jogadorSobre; // Ponteiro para o jogador atualmente sobre a esteira (se houver)
            sf::Vector2f tamanhoEsteira; // Tamanho da esteira para cálculos de colisão
        public:
            Obstaculo_Esteira(float vel, sf::Vector2f dir);
            ~Obstaculo_Esteira();

            void Executar(); // Pode animar a textura aqui
            void Salvar();
            
            // Método específico da esteira: empurra o jogador
            void obstacular(Entidades::Personagens::Jogador* p);
        };
    }
}