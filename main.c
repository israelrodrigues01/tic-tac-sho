#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

int verficador(int *start){

    printf(
               "\n\n\n"
               "Jogo finalizado!!! Deseja jogar novamente?\n"
               "0 - Não\n"
               "1 - Sim"
               );
        scanf("%d", &start);
        printf("\n\n\n");

    return start;
}

int main(){

    srand(time(0));

    int tab[9][9], i, j, start = 0;

    for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++)
                tab[i][j] = 0;

    pos_init_jog1(tab);
    pos_init_jog2(tab);

    do{

        tabela(tab);
        start = verficador(&start);

    }while(start != 0);

    return 0;
}
