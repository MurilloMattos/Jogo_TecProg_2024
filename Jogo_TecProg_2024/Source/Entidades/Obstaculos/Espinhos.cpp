#include "Entidades/Obstaculos/Espinhos.h"

using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

Espinhos::Espinhos() {

    agressivo = true;

    dano = 10;
    dano_sangramento = 1;

    empurrar = 15.f;

    sangramento = false;
    soltar_espinho = false;

    duracao_sangramento = 10;

    fragilidade_espinho = 0;
    tempo_para_cair_espinho = 120;

    tamanho.x = 0.f;
    tamanho.y = 5.f;
}

Espinhos::~Espinhos() {


    agressivo = false;
    soltar_espinho = false;
    fragilidade_espinho = 0;
}

void Espinhos::Salvar() {

}

void Espinhos::Executar() {

    Desenhar();

    soltar_espinho = false;
    
    if(fragilidade_espinho < tempo_para_cair_espinho){

        fragilidade_espinho++;
    }
    else if(fragilidade_espinho >= tempo_para_cair_espinho && !soltar_espinho){

        soltar_espinho = true;

        fragilidade_espinho = 0;
    }

}

void Espinhos::setar_Espinhos(float pos_plat_x, float pos_embaixo_plat_y, float tam_plat_x){

    //tem que ser possivel eliminar o inimigo.
    tamanho.x = tam_plat_x/2;

    //cinza.
    pFigura->setFillColor(sf::Color(192, 192, 192));

    pFigura->setSize(tamanho);
    setar_Pos(pos_plat_x, pos_embaixo_plat_y);
}


void Espinhos::setar_Espinho(Projetil* esp){

    espinho = esp;
    espinho->setar_Cor(sf::Color(192, 192, 192));
}


bool Espinhos::get_Soltar_Espinho(){

    return soltar_espinho;
}

void Espinhos::danificar(Personagem* pAtacado){

	pAtacado->diminuir_Vitalidade(dano);
}


void Espinhos::obstacular(Jogador* p, int lado) {

    if(lado != 0){
        danificar(static_cast<Personagem*>(p));
        p->setar_Pos(p->get_X(), (p->get_Y() + empurrar));
        p->setar_Estado_Pulando(true);
        p->setar_No_Ar(true);
        p->setar_Bateu_A_Cabeca();
    }
    
}



