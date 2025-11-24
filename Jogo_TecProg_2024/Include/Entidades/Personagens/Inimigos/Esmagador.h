#pragma once

#include "Entidades/Personagens/Inimigos/Inimigo.h"
#include <cmath>

namespace Entidades {
    namespace Personagens {

        // O Inimigo precisa saber em que estado está
        enum class EstadoEsmagador {

            PATRULHANDO,
            PREPARANDO,
            ATACANDO

        };

        class Esmagador : public Inimigo {

        private:

            EstadoEsmagador estado_atual;   
            sf::Clock relogio_ataque; // Para contar o segundo de espera e de ataque
            sf::Vector2f tamanhoDeteccao;

            const float tempo_preparacao_seg;
            const float tempo_ataque_seg;
            const float raio_deteccao;
            const float raio_ataque;

            // Variáveis de patrulha 
            sf::Vector2f pos_inicial;
            sf::Vector2f pos_final;
            
            
            public:
            
            Esmagador();
            ~Esmagador();
            
            void Executar(); // Vai gerenciar a máquina de estados
            void Salvar();
            void Danificar();

            void Mover(); 
            void AtualizarAnimacao(); // Lógica de transição de estados
            void VerificaAtaqueEmArea(); // Aplica dano se jogadores estiverem perto
            
            void set_Estado(EstadoEsmagador novo_estado);
            EstadoEsmagador get_Estado();
            virtual void setar_Pontos_Por_Eliminacao(int pontos);
            //void IniciarPreparacao(); // Muda o estado e reinicia o relógio
            //void Atacar(); // Muda o estado para ATACANDO
        };
    }
}