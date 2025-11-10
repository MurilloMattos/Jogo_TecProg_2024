# 🎮 Como Compilar o Jogo (JOGO_TECPROG_2024)
Este projeto usa CMake para compilação. As instruções a seguir são focadas no Visual Studio Code (VSCode).

# 📦 Pré-requisitos Gerais (VSCode)
Antes de começar, certifique-se de ter o VSCode instalado, juntamente com as seguintes extensões:

C/C++ (Publicado pela Microsoft)

CMake Tools (Publicado pela Microsoft)

# ⚠️ Passo Manual Obrigatório: Baixar o SFML
Este projeto espera que a biblioteca SFML esteja em uma pasta chamada SFML-2.5.1/ na raiz do projeto.

Acesse a página oficial de downloads: www.sfml-dev.org/download.php

1. Instruções
Crie uma pasta chamada SFML-2.5.1/ na raiz do projeto.

Baixe UMA das versões do SFML, dependendo do sistema que você quer usar:

Para Windows (Visual Studio): SFML-2.x.x-windows-visual-studio-17-64-bit.zip

Para Windows (MinGW): SFML-2.x.x-windows-gcc-xx-mingw-64-bit.zip

Para Linux (GCC): SFML-2.x.x-linux-gcc-64-bit.tar.gz

Extraia o conteúdo do arquivo baixado (pastas como bin, lib, include, SFMLConfig.cmake) para dentro da pasta SFML-2.5.1/ que você criou.

A estrutura final deve ser:

JOGO_TECPROG_2024/
└── SFML-2.5.1/
    ├── bin/
    ├── include/
    ├── lib/
    └── SFMLConfig.cmake
Se você quiser trocar de sistema (do Windows para o Linux), você deverá apagar o conteúdo desta pasta e extrair os binários corretos para o novo sistema.

🖥️ Compilando (Windows ou Linux)
O processo no VSCode é o mesmo, desde que você tenha os binários corretos do SFML na pasta SFML-2.5.1/.

1. Pré-requisitos do Compilador
No Windows (MSVC): Instale o Visual Studio 2022 (Community) com a carga de trabalho "Desenvolvimento para desktop com C++".

No Windows (MinGW): Instale o MSYS2 e o toolchain mingw-w64-x86_64-gcc. Adicione o bin ao PATH.

No Linux: Instale as ferramentas de build: sudo apt install build-essential g++ cmake

2. Passos no VSCode
Abra a pasta raiz JOGO_TECPROG_2024 no VSCode.

A extensão CMake Tools perguntará se você deseja configurar. Clique em Sim.

Selecione seu "Kit" (Compilador). Aperte Ctrl+Shift+P e digite CMake: Select a Kit.

Windows (MSVC): Escolha Visual Studio Community 2022 - amd64.

Windows (MinGW): Escolha GCC ... (o que aponta para seu MinGW).

Linux: Escolha GCC ....

Aperte Ctrl+Shift+P e digite CMake: Configure. O painel "Output" deve mostrar que o SFML foi encontrado com sucesso em SFML-2.5.1/.

Clique no botão Build (ou "Construir") na barra de status azul.

Clique no botão Play (▶️) na barra de status para executar.

# 🐛 Resolução de Problemas
Erro: "Could not find SFML" (CMake não encontrou o SFML)

Solução: Verifique se a pasta se chama exatamente SFML-2.5.1 (maiúsculas e minúsculas importam!) e se ela contém o arquivo SFMLConfig.cmake na sua raiz.

Erro: "undefined reference to" (Linker Error) no Windows

Solução: Você misturou compiladores. Você está tentando compilar com MSVC mas a sua pasta SFML-2.5.1/ contém os arquivos para MinGW (ou vice-versa). Apague a pasta e coloque a versão correta.