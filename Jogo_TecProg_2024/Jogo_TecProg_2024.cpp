#include "Jogo.h"
#include <iostream>

int main()
{
    // Tenta iniciar o jogo. Se algo der muito errado (como não conseguir criar a janela),
    // o 'catch' vai nos avisar.
    try {
        Jogo meuJogo;
        meuJogo.Executar();
    }
    catch (const std::exception& e) {
        std::cerr << "Ocorreu uma excecao: " << e.what() << std::endl;
        std::cin.get(); // Pausa para podermos ler o erro.
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}