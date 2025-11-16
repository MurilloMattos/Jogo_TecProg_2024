#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {

        // O Inimigo precisa saber em que estado está
        enum class EstadoEsmagador {
            PATRULHANDO,
            PREPARANDO,
            ATACANDO
        };

        class Inimigo_Esmagador : public Inimigo
        {
        private:
            EstadoEsmagador estado_atual;
            sf::Clock relogio_preparacao; // Para contar o segundo de espera
            sf::Vector2f tamanhoDeteccao;

            const float tempo_preparacao_seg;
            //float raio_deteccao;
            //float raio_ataque;

            // Variáveis de patrulha (como no Inimigo_Medio)
            sf::Vector2f pos_inicial;
            sf::Vector2f pos_final;
            
            void Mover(); // Lógica de movimento de patrulha

        public:
            Inimigo_Esmagador();
            ~Inimigo_Esmagador();

            void Executar(); // Vai gerenciar a máquina de estados
            void Salvar();
            void Danificar(); // Pode ser usado para a animação do ataque

            // Novos métodos para o Gerenciador de Colisões controlar
            void set_Estado(EstadoEsmagador novo_estado);
            EstadoEsmagador get_Estado();
            float get_RaioDeteccao();
            float get_RaioAtaque();
            sf::Clock get_RelogioPreparacao();
            float get_TempoPreparacaoSeg();

            //void IniciarPreparacao(); // Muda o estado e reinicia o relógio
            //void Atacar(); // Muda o estado para ATACANDO
        };
    }
}