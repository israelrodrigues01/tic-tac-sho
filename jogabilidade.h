int col_num(char coluna){

    int convert;

    switch(toupper(coluna)){

    case 'A':
        convert = 0;
        break;
    case 'B':
        convert = 1;
        break;
    case 'C':
        convert = 2;
        break;
    case 'D':
        convert = 3;
        break;
    case 'E':
        convert = 4;
        break;
    case 'F':
        convert = 5;
        break;
    case 'G':
        convert = 6;
        break;
    case 'H':
        convert = 7;
        break;
    case 'I':
        convert = 8;
        break;
    }

    return convert;

}

int jog_posivel(int v[9][9], int i, int j, int a_lin, int a_col){

    if(j == a_col || i == a_lin  || a_lin - a_col == i - j || a_lin + a_col == i + j){
        if(v[i][j] != v[a_lin][a_col] && v[i][j] == 0){
            return 1;
        } else {
            return 0;
        }
    } else{
        return 0;
    }

}

void rouba_peca(int v[9][9], int a_lin, int a_col, int lin, int col, int p_adv){

    int i, c, min_l = a_lin, max_l = lin, min_c = a_col, max_c = col;

    if(lin < min_l){
        min_l = lin;
        max_l = a_lin;
    }

    if(col < min_c){
        min_c = col;
        max_c = a_col;
    }

    if(a_col == col){

        for(i = min_l; i < max_l; i++){

            if(v[i][col] == p_adv)
                if(p_adv - 1 == 1) v[i][col] = p_adv - 1;
                else v[i][col] = p_adv + 1;

        }

    } else if(a_lin == lin){

        for(i = min_c; i < max_c; i++){

            if(v[lin][i] == p_adv)
                if(p_adv - 1 == 1) v[lin][i] = p_adv - 1;
                else v[lin][i] = p_adv + 1;

        }
    } else if(a_lin + a_col == lin + col){

        for(i = min_c + 1; i < max_c; i++){
            //printf("v[%d][%d] = %d -> %d\n", max_l + 2 - i, i, v[max_l + 2 - i][i], p_adv);
            if(v[max_l + 2 - i][i] == p_adv)
                if(p_adv - 1 == 1) v[max_l + 2 - i][i] = p_adv - 1;
                else v[max_l + 2 - i][i] = p_adv + 1;
                //printf("entrei!!!\n"); - 92


        }


    } else if(a_lin - a_col == lin - col){
        //printf("min_l = %d\nmin_c = %d\nmax_l = %d\nmax_col = %d\n", min_l, min_c, max_l, max_c);
        c = -1;
        for(i = min_l; i < max_l; i++){

        c++;

            //printf("v[%d][%d] = %d -> %d\n", i, min_c + c, v[i][min_c + c], p_adv);
            if(v[i][min_c + c] == p_adv){
                printf("entrei!!!\n");
                if(p_adv - 1 == 1) v[i][min_c + c] = p_adv - 1;
                else v[i][min_c + c] = p_adv + 1;
            }


        }

    }

    //system("pause");

}

void jog_turno(int v[9][9]){

    int l, lin, col, a_lin, a_col, i, j;
    char c[5];

    do{

        tabela(v);

        // Sele��o de pe�a 1� jogador

        SetConsoleTextAttribute(12, 3);
        printf("\n  \t\t\t\t\t\t >> 1� Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Escolha uma pe�a: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(v[lin][col] != 1){
            SetConsoleTextAttribute(12, 4);
            printf("\nEssa pe�a n�o est� disponivel!!Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
        }

        system("cls");

    } while(v[lin][col] != 1);

    // Jogada do 1� jogador

    a_lin = lin;
    a_col = col;

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(jog_posivel(v, i, j, a_lin, a_col)) v[i][j] = 5;

    do{
        v[a_lin][a_col] = 3;
        tabela(v);
        v[a_lin][a_col] = 1;

        SetConsoleTextAttribute(12, 2);
        printf("-Mova a pe�a: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(v[lin][col] != 5){
            SetConsoleTextAttribute(12, 4);
            printf("\nEssa pe�a n�o est� disponivel!!Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
            system("cls");
        }

    }while(v[lin][col] != 5);

    v[lin][col] = 1;

    rouba_peca(v, a_lin, a_col, lin, col, 2);

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(v[i][j] == 5) v[i][j] = 0;

    system("cls");

    do{
        tabela(v);

        // Sele��o de pe�a 2� jogador

        SetConsoleTextAttribute(12, 4);
        printf("\n  \t\t\t\t\t\t >> 2� Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Escolha uma pe�a: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(v[lin][col] != 2){
            SetConsoleTextAttribute(12, 4);
            printf("\nEssa pe�a n�o est� disponivel!!Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
        }

        system("cls");

    }while(v[lin][col] != 2);

    // Jogada do 2� jogador

    a_lin = lin;
    a_col = col;

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(jog_posivel(v, i, j, a_lin, a_col)) v[i][j] = 5;

    do{
        v[a_lin][a_col] = 4;
        tabela(v);
        v[a_lin][a_col] = 2;

        SetConsoleTextAttribute(12, 2);
        printf("-Mova a pe�a: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(v[lin][col] != 5){
            SetConsoleTextAttribute(12, 4);
            printf("\nEssa pe�a n�o est� disponivel!!Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
            system("cls");
        }

    }while(v[lin][col] != 5);

    v[lin][col] = 2;

    rouba_peca(v, a_lin, a_col, lin, col, 1);

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(v[i][j] == 5) v[i][j] = 0;

    system("cls");

}


int verficador(int *start){

    printf(
               "\n\n\n"
               "Jogo finalizado!!! Deseja jogar novamente?\n"
               "0 - N�o\n"
               "1 - Sim\n"
               ">>> "
               );
        scanf("%d", &start);
        printf("\n\n\n");

    return start;
}
