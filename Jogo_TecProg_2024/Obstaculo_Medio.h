#pragma once
#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Obstaculo_Medio :public Obstaculo
        {
            private:
                //definir;

            public:
                Obstaculo_Medio();
                ~Obstaculo_Medio();

                void Salvar();
                void Executar();
                void danificar(Jogador* p);
        };

    }
}