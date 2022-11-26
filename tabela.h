
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

    case 0:
        printf("[ ]");
    break;
    case 1:
        printf("[");
        SetConsoleTextAttribute(12, 3);
        printf("x");
        SetConsoleTextAttribute(12, 6);
        printf("]");
    break;
    case 2:
        printf("[");
        SetConsoleTextAttribute(12, 4);
        printf("o");
        SetConsoleTextAttribute(12, 6);
        printf("]");
    break;
    case 3:
        SetConsoleTextAttribute(12, 10);
        printf("[x]");
        SetConsoleTextAttribute(12, 6);

    break;
    case 4:
        SetConsoleTextAttribute(12, 10);
        printf("[o]");
        SetConsoleTextAttribute(12, 6);
    break;
    case 5:
        SetConsoleTextAttribute(12, 10);
        printf("[ ]");
        SetConsoleTextAttribute(12, 6);
    break;


    }

}

void jog_pos_init(int v[9][9]){

    int i, x, y, c, l, verf;

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

void tabela(int v[9][9]){

    int i, j, co;

    printf("\t\t\t\t\t     ");

    SetConsoleTextAttribute(12, 6);

    for(co = 1; co <= 9; co++) col_alf(co);

    printf("\n");

    for(i = 0; i < 9; i++){
        printf("\t\t\t\t\t  %d ", i + 1);
        for(j = 0; j < 9; j++){
            jog_alf(v[i][j]);

        }
        printf("\n");
    }

    SetConsoleTextAttribute(12, 7);

}
