
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
        printf("I  ");
    break;

    }

}

jog_alf(int n){

    switch(n){

    case 1:
        printf("[x]");
    break;
    case 2:
        printf("[o]");
    break;

    }

}

int pos_init_jog1(int v[9][9]){

    int i, x, y, c, l, verf;

    for(i=0; i<5; i++){
        x = (rand() % 9);
        y = (rand() % 9);

        do{
            for(l = 0; l < 9; l++){
                for(c = 0; c < 9; c++){
                    if(v[x][y] == v[l][c] && v[l][c] != 0){
                        x = (rand() % 9);
                        y = (rand() % 9);
                        verf = 1;
                    } else {
                        verf = 0;
                    }
                }
            }
        }while(verf == 1);

        v[x][y] = 1;

    }

    return v[x][y];

}

int pos_init_jog2(int v[9][9]){

    int i, x, y, c, l, verf;

    for(i=0; i<5; i++){
        x = rand() % 9;
        y = rand() % 9;

        do{
            for(l = 0; l < 9; l++){
                for(c = 0; c < 9; c++){
                    if(v[x][y] == v[l][c] && v[l][c] != 0){
                        x = (rand() % 9);
                        y = (rand() % 9);
                        verf = 1;
                    } else {
                        verf = 0;
                    }
                }
            }
        }while(verf == 1);

        v[x][y] = 2;

    }

    return v[x][y];

}

void tabela(int v[9][9]){

    int i, j, co, init = 0;

    printf("\t\t\t\t\t     ");

    for(co = 1; co <= 9; co++) col_alf(co);

    printf("\n");

    if(init == 0){
            pos_init_jog1(v);
            pos_init_jog2(v);
    }

    init = 1;


    for(i = 0; i < 9; i++){
        printf("\t\t\t\t\t  %d ", i + 1);
        for(j = 0; j < 9; j++){
            if(v[i][j] == 0) printf("[ ]", v[i][j]);
            else jog_alf(v[i][j]);
        }
        printf("\n");
    }

}
