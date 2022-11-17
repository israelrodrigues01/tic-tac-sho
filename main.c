#include <stdio.h>
#include <stdlib.h>
#include "tabela.h"

int main(){

    srand(time(0));

    int tab[9][9], i, j;

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            tab[i][j] = 0;

    tabela(tab);

    return 0;
}
