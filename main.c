#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "tabela.h"
#include "jogabilidade.h"

int main(){

    setlocale(LC_ALL, "portuguese");

    srand(time(0));

    int tab[9][9], i, j, start = 0;

    for(i = 0; i < 9; i++)
            for(j = 0; j < 9; j++)
                tab[i][j] = 0;

    //tab[8][7] = 1;
    //tab[5][4] = 2;

    jog_pos_init(tab);

    do{

        //tabela(tab);
        jog_turno(tab);
        //start = verficador(&start);

    }while(1); //start != 0

    return 0;
}
