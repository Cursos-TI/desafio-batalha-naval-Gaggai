#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Aluno: Edgar Nicolau Fardin

//função para verificar se a posição ja tem um navio
int verificaElemento(int matriz[10][10], int linha, int coluna){
    if(matriz[linha][coluna] == 0){
        return 0;
    }else if(matriz[linha][coluna] == 3){
        return 1;
    }else{
        return -1;
    }
}

//função para verificar se a posição é válida no tabuleiro
int verificaPosicaoHV(int posicao, int tamanhoNavio, int tamanhoMatriz){
    if(posicao + tamanhoNavio <= tamanhoMatriz){
        return 1;
    }else{
        return 0;
    }
}

int main() {

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.


    // Área para declaração de variáveis
    int tamTabuleiro = 10;
    int tabuleiro[tamTabuleiro][tamTabuleiro];
    char linha[11] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int navioH[1][2] = {{0,0}}; //coordenadas do navio na horizontal
    int navioV[1][2] = {{7,9}}; //coordenadas do navio na vertical
    int navioD[2][2] = {{4,1},{2,6}}; //coordenadas dos navios na diagonal
    int tamNavio = 3; // tamanho dos navios

    int resultado = 0; // para saber se posição é ocupada

    //inicializando tabuleiro com 0
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = 0;
        }        
    }

    //Validação e Posicionamento do navio na hotizontal
    if(verificaPosicaoHV(navioH[0][1], tamNavio, tamTabuleiro)){ // verifica posições dentro do tabuleiro       
        resultado = 0;
        for (int i = 0; i < tamNavio; i++)//verifica posições ocupadas
        {
            resultado += verificaElemento(tabuleiro, navioH[0][0], navioH[0][1] + i);
        }if(resultado == 0){
             for (int i = 0; i < tamNavio; i++)
            {
            tabuleiro[navioH[0][0]][navioH[0][1] + i] = 3;
            }
         }else{
            printf("Foi inserida um coordenada já ocupada por um navio\n");
         }        
    }else{
        printf("Foi inserida um coordenada inválida para colocar um  navio\n");
    }

    //Validação e Posicionamento do navio na vertical
    if(verificaPosicaoHV(navioV[0][0], tamNavio, tamTabuleiro)){// verifica posições dentro do tabuleiro 
        resultado = 0;      
        for (int i = 0; i < tamNavio; i++)//verifica posições ocupadas
        {
            resultado += verificaElemento(tabuleiro, navioV[0][0] + i, navioV[0][1]);
        }if(resultado == 0){
             for (int i = 0; i < tamNavio; i++)
            {
            tabuleiro[navioV[0][0] + i][navioV[0][1]] = 3;
            }
         }else{
            printf("Foi inserida um coordenada já ocupada por um navio\n");
         }       
    }else{
        printf("Foi inserida um coordenada inválida para colocar um  navio\n");
    }

    //Validação e Posicionamento do navio na Diagonal
    if(verificaPosicaoHV(navioD[0][0], tamNavio, tamTabuleiro) && verificaPosicaoHV(navioD[0][1], tamNavio, tamTabuleiro)){// verifica posições dentro do tabuleiro 
        resultado = 0;      
        for (int i = 0; i < tamNavio; i++)//verifica posições ocupadas
        {
            resultado += verificaElemento(tabuleiro, navioD[0][0] + i, navioD[0][1] + i);
        }if(resultado == 0){
             for (int i = 0; i < tamNavio; i++)
            {
            tabuleiro[navioD[0][0] + i][navioD[0][1] + i] = 3;
            }
         }else{
            printf("Foi inserida um coordenada já ocupada por um navio\n");
         }       
    }else{
        printf("Foi inserida um coordenada inválida para colocar um  navio\n");
    }

    //Validação e Posicionamento do segundo navio na Diagonal (invertida)
    if(verificaPosicaoHV(navioD[1][0], tamNavio, tamTabuleiro) && verificaPosicaoHV(navioD[1][1], tamNavio, tamTabuleiro) && navioD[1][1] >=2 ){// verifica posições dentro do tabuleiro 
        resultado = 0;      
        for (int i = 0; i < tamNavio; i++)//verifica posições ocupadas
        {
            resultado += verificaElemento(tabuleiro, navioD[1][0] + i, navioD[1][1] + i);
        }if(resultado == 0){
             for (int i = 0; i < tamNavio; i++)
            {
            tabuleiro[navioD[1][0] + i][navioD[1][1] - i] = 3;
            }
         }else{
            printf("Foi inserida um coordenada já ocupada por um navio\n");
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
