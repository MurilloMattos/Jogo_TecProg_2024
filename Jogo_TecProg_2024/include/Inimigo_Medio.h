#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {

        class Inimigo_Medio : public Inimigo
        {
            private:
                //definir varíaveis distintas dos outros inimigos
                //int boo;

            public:
                Inimigo_Medio();
                //Inimigo_Medio(float pos_x, float pos_y);
                ~Inimigo_Medio();

                void andar_ate(float em_x, float em_y);
                void Salvar();
                void Executar();
                void Danificar();
		virtual void Atualizar();

        };
    }
}
