#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {

        class Pirata : public Inimigo
        {
            private:
                //definir var�aveis distintas dos outros inimigos
                //int boo;

            public:
                Pirata();
                //Inimigo_Medio(float pos_x, float pos_y);
                ~Pirata();

                void andar_ate(float em_x, float em_y);
                void Salvar();
                void Executar();
                void Danificar();

        };
    }
}