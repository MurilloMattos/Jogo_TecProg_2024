#include "Botao.h"

Botao::Botao(const std::string& texto, sf::Vector2f position, sf::Vector2f size, sf::Font* font, AcaoBotao acaoBotao) :
    pFonte(font), acao(acaoBotao) 
{
    shape.setPosition(position);
    shape.setSize(size);
    shape.setFillColor(sf::Color::Blue); // Cor padrão

    text.setFont(*pFonte);
    text.setString(texto);
    text.setCharacterSize(24); // Ou calcular baseado no tamanho
    text.setFillColor(sf::Color::White);
    
    // Centralizar texto no botão (exemplo simples)
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(position.x + size.x / 2.0f, position.y + size.y / 2.0f);
}

Botao::~Botao() {}

void Botao::desenhar(sf::RenderTarget& target) {
    target.draw(shape);
    target.draw(text);
}

bool Botao::isMouseOver(sf::Vector2f mousePos) {
    return shape.getGlobalBounds().contains(mousePos);
}

Botao::AcaoBotao Botao::getAcao() {
    return acao;
}

// Implementar setHover se quiser mudar a cor, etc.