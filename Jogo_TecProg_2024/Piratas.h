//Inimigo Fácil

#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        class Piratas : public Inimigo {

            private:
                //definir var�aveis distintas dos outros inimigos
                //int boo;

            public:
                Piratas();
                ~Piratas();

                void andar_ate(float em_x, float em_y);
                void Salvar();
                void Executar();
                void Danificar();

        };
    }
}