
col_alf(int n){

    switch(n){

    case 1:
        printf("A  ");
    break;
    case 2:
        printf("B  ");
    break;
    case 3:
        printf("C  ");
    break;
    case 4:
        printf("D  ");
    break;
    case 5:
        printf("E  ");
    break;
    case 6:
        printf("F  ");
    break;
    case 7:
        printf("G  ");
    break;
    case 8:
        printf("H  ");
    break;
    case 9:
        printf("I");
    break;

    }

}

jog_alf(int n){

    switch(n){

    // Exibir peças vazinhas
    case 0:
        printf("[ ]");
    break;
    // Exibir peça jogador 1
    case 1:
        printf("[");
        SetConsoleTextAttribute(7, 3); // 3 igual azul
        printf("x");
        SetConsoleTextAttribute(7, 6);
        printf("]");
    break;
    // Exibir peça jogador 2
    case 2:
        printf("[");
        SetConsoleTextAttribute(7, 4); // 4 igual vermelho
        printf("o");
        SetConsoleTextAttribute(7, 6);
        printf("]");
    break;
    // Selecionado peça
    case 3:
        SetConsoleTextAttribute(7, 10); // 10 igual verde
        printf("[x]");
        SetConsoleTextAttribute(7, 6);

    break;
    // Selecionado peça
    case 4:
        SetConsoleTextAttribute(7, 10); // 10 igual verde
        printf("[o]");
        SetConsoleTextAttribute(7, 6);
    break;
    // Possivel caminho
    case 5:
        SetConsoleTextAttribute(7, 10); // 10 igual verde
        printf("[ ]");
        SetConsoleTextAttribute(7, 6);
    break;
    // Peça deixada após o movimento do jogador 1
    case 6:
        printf("[");
        SetConsoleTextAttribute(7, 3); // 3 igual azul
        printf("\4");
        SetConsoleTextAttribute(7, 6);
        printf("]");
    break;
    // Peça deixada após o movimento do jogador 2
    case 7:
        printf("[");
        SetConsoleTextAttribute(7, 4); // 4 igual vermelho
        printf("\4");
        SetConsoleTextAttribute(7, 6);
        printf("]");
    break;
    }
}

void posicao_aleatoria(int v[9][9]){

    int i, x, y;

    for(i=0; i<5; i++){

        do{
            x = (rand() % 9);
            y = (rand() % 9);
        }while(v[x][y] != 0);

        v[x][y] = 1;

    }

    for(i=0; i<5; i++){

        do{
            x = (rand() % 9);
            y = (rand() % 9);
        }while(v[x][y] != 0);

        v[x][y] = 2;

    }

}

void exibeTabuleiro(int v[9][9]){

    int i, j, co;

    printf("\t\t\t\t\t     ");

    SetConsoleTextAttribute(7, 6);

    for(co = 1; co <= 9; co++) col_alf(co);

    printf("\n");

    for(i = 0; i < 9; i++){
        printf("\t\t\t\t\t  %d ", i + 1);
        for(j = 0; j < 9; j++){
            jog_alf(v[i][j]);

        }
        printf("\n");
    }

    SetConsoleTextAttribute(7, 7);

}
