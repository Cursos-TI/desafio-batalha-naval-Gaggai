#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Aluno: Edgar Nicolau Fardin

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Área para declaração de variáveis
    int tamTabuleiro = 10;
    int tabuleiro[tamTabuleiro][tamTabuleiro];
    char linha[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int navioH[1][2] = {{7,5}}; //coordenadas do navio na horizontal
    int navioV[1][2] = {{4,3}}; //coordenadas do navio na vertical
    int tamNavio = 3; // tamanho dos navios

    //inicializando tabuleiro com 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }        
    }

    //Validação e Posicionamento do navio na hotizontal
    if(navioH[0][1] + tamNavio <= tamTabuleiro){
        for (int i = 0; i < tamNavio; i++)
        {
            tabuleiro[navioH[0][0]][navioH[0][1] + i] = 3;
        }
        
    }else{
        printf("Foi inserida um coordenada inválida para colocar um  navio\n");
    }

    //Validação e Posicionamento do navio na vertical
    if(navioV[0][0] + tamNavio <= tamTabuleiro){
        for (int i = 0; i < tamNavio; i++)
        {
            tabuleiro[navioV[0][0] + i][navioV[0][1]] = 3;
        }
        
    }else{
        printf("Foi inserida um coordenada inválida para colocar um  navio\n");
    }
    
    //Imprimindo tabuleiro
    printf("**** TABULEIRO BATALHA NAVAL ****\n\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%2c ", linha[i]);
    }
    printf("\n");
    

    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
        
    }

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
