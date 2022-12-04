#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "tabela.h";
#include "jogabilidade.h";

int main(){

    setlocale(LC_ALL, "portuguese");

    srand(time(0));

    int tabuleiro[9][9], i, j, start = 0;

    for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++)
                tabuleiro[i][j] = 0;

    posicao_aleatoria(tabuleiro);

    do{
        naCasa(tabuleiro);

    }while(1); //vitoria != 0

    return 0;
}
