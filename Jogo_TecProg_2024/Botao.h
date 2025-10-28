// Botao.h
#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <functional> // Para poder passar a ação do botão

class Botao {
private:
    sf::RectangleShape shape;
    sf::Text text;
    sf::Font* pFonte; // Ponteiro para a fonte (geralmente carregada no Menu)
    
    // Poderia guardar a ação a ser executada
    // Opção 1: Usar um enum para identificar a ação
    enum AcaoBotao { NENHUMA, JOGAR_FASE1, JOGAR_FASE2, SAIR };
    AcaoBotao acao; 

    // Opção 2: Usar std::function para guardar a função a ser chamada (mais avançado)
    // std::function<void()> onClickAction; 

public:
    // Construtor poderia receber texto, posição, tamanho, fonte, e a ação
    Botao(const std::string& texto, sf::Vector2f position, sf::Vector2f size, sf::Font* font, AcaoBotao acaoBotao);
    ~Botao();

    void desenhar(sf::RenderTarget& target);
    bool isMouseOver(sf::Vector2f mousePos);
    
    // Método para obter a ação que este botão representa
    AcaoBotao getAcao();

    // Poderia ter métodos para mudar cor no hover, etc.
    // void setHover(bool hover); 
};

