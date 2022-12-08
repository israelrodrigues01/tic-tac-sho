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

int validaPeca(int v[9][9], int lin, int col, int m_peca){
    if(v[lin][col] != m_peca) return 1;
    else return 0;
}

int validaMovimento(int v[9][9], int a_lin, int a_col){

    int i, j, val_l[2], val_c[2], cont[2], val_dp[2], val_ds[2];

    for(i = 0; i < 2; i++) cont[i] = 0;
    val_l[0] = 0;
    val_l[1] = 8;
    val_c[0] = 0;
    val_c[1] = 8;

    for(i = 0; i < 9; i++){

        if(v[i][a_col] == 1 || v[i][a_col] == 2){

            if(i < a_lin) val_l[0] = i;
            if(i > a_lin && cont[0] == 0){
                cont[0]++;
                val_l[1] = i;
            }

        }

        if(v[a_lin][i] == 1 || v[a_lin][i] == 2){

            if(i < a_col) val_c[0] = i;
            if(i > a_col && cont[1] == 0){
                cont[1]++;
                val_c[1] = i;
            }

        }

    }

    for(i = 0; i < 2; i++) cont[i] = 0;

    if(a_lin + a_col >= 8){
        val_dp[0] = a_lin + a_col - 8;
        val_dp[1] = 8;
    } else {
        val_dp[0] = 0;
        val_dp[1] = a_lin + a_col;

    }

    if(a_lin - a_col <= 0){
        val_ds[0] = 0;
        val_ds[1] = 8 - (a_col - a_lin);
    } else {
        val_ds[0] = a_lin - a_col;
        val_ds[1] = 8;

    }

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++){

            if(i + j == a_lin + a_col)
                if(v[i][j] == 1 || v[i][j] == 2){

                    if(i < a_lin) val_dp[0] = i;
                    if(i > a_lin && cont[0] == 0){
                        cont[0]++;
                        val_dp[1] = i;
                    }

                }

            if(i - j == a_lin - a_col)
                if(v[i][j] == 1 || v[i][j] == 2){

                    if(i < a_lin) val_ds[0] = i;
                    if(i > a_lin && cont[1] == 0){
                        cont[1]++;
                        val_ds[1] = i;
                    }

                }
        }

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++){

            if(j == a_col || i == a_lin  || a_lin - a_col == i - j || a_lin + a_col == i + j){
                if(v[i][j] != v[a_lin][a_col] && v[i][j] == 0){
                    if(j == a_col && i >= val_l[0] && i <= val_l[1])
                        v[i][j] = 5;
                    if(i == a_lin && j >= val_c[0] && j <= val_c[1])
                        v[i][j] = 5;
                    if(i + j == a_lin + a_col && i >= val_dp[0] && i <= val_dp[1])
                        v[i][j] = 5;
                    if(i - j == a_lin - a_col && i >= val_ds[0] && i <= val_ds[1])
                        v[i][j] = 5;
                }
            }

        }

    return v[i][j];

}

// Estou recebendo a o vetor, posições das peças e posições de caminho e peça adiversária;
void verificaConversao(int v[9][9], int a_lin, int a_col, int lin, int col, int m_peca, int p_adv){

    int i, c, min_l = a_lin, max_l = lin, min_c = a_col, max_c = col;

    if(lin < min_l){
        min_l = lin;
        max_l = a_lin;
    }

    if(col < min_c){
        min_c = col;
        max_c = a_col;
    }

    // Verificar nas linhas

    if(a_col == col){
        for(i = min_l + 1; i < max_l; i++){
            if(v[i][col] == p_adv){
                v[i][col] = m_peca;
            }else if(v[i][col] == m_peca){
                v[i][col] = p_adv;
            }
        }
    }

    // Verificar nas colunas

    else if(a_lin == lin){
        for(i = min_c + 1; i < max_c; i++){
            if(v[lin][i] == p_adv){
                v[lin][i] = m_peca;
            }else if(v[lin][i] == m_peca){
                v[lin][i] = p_adv;
            }
        }
    }

    // Verificar nas diagonais principais

    else if(a_lin - a_col == lin - col){
        for(i = min_c + 1; i < max_c; i++){
            if(v[i][i] == p_adv){
                v[i][i] = m_peca;
            }else if(v[i][i] == m_peca){
                v[i][i] = p_adv;
            }
        }
    }

    // Verificar nas diagonais secundarias

    else if(a_lin + a_col == lin + col){
        for(
            i = min_l+1, c = max_c-1;
            i < max_l, c > min_c;
            i++, c--
        ){
            if(v[i][c] == p_adv){
                v[i][c] = m_peca;
            }else if(v[i][c] == m_peca){
                v[i][c] = p_adv;
            }
        }
    }
}

int vitoria(int v[9][9], int m_peca, int p_adv){

    int cont_m = 0, cont_adv = 0, i, j, m, t;

    // Coluna
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
                if(v[i][j] == m_peca){
                    cont_m++;
                    if(cont_m == 2){
                        printf("\n\n\n");
                        SetConsoleTextAttribute(12, 3);
                        printf("\t\t\t\t\t\t Jogador 1 GANHOU!");
                        SetConsoleTextAttribute(12, 7);
                        return 1;
                    }
                }else if(v[i][j] == p_adv){
                    cont_adv++;
                    if(cont_adv == 2){
                        printf("\n\n\n");
                        SetConsoleTextAttribute(12, 3);
                        printf("\t\t\t\t\t\t Jogador 2 GANHOU!");
                        SetConsoleTextAttribute(12, 7);
                        return 1;
                    }
                }else{
                    cont_m = 0;
                    cont_adv = 0;
                }
        }
    }

    cont_m = 0;
    cont_adv = 0;

    // Linha
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
                if(v[j][i] == m_peca){
                    cont_m++;
                    if(cont_m == 2){
                        printf("\n\n\n");
                                SetConsoleTextAttribute(12, 3);
                                printf("\t\t\t\t\t\t Jogador 1 GANHOU!");
                                SetConsoleTextAttribute(12, 7);
                        return 1;
                    }
                }else if(v[j][i] == p_adv){
                    cont_adv++;
                    if(cont_adv == 2){
                        printf("\n\n\n");
                                SetConsoleTextAttribute(12, 3);
                                printf("\t\t\t\t\t\t Jogador 2 GANHOU!");
                                SetConsoleTextAttribute(12, 7);
                        return 1;
                    }
                }else{
                    cont_m = 0;
                    cont_adv = 0;
                }
        }
    }

    cont_m = 0;
    cont_adv = 0;
    
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){

             for(m = 0; m < 9; m++){
                for(t = 0; t < 9; t++){

                    // Diagonal principal
                    if(i - j == m - t){
                        if(v[m][t] == m_peca){
                            cont_m++;
                            if(cont_m == 2){
                                printf("\n\n\n");
                                SetConsoleTextAttribute(12, 3);
                                printf("\t\t\t\t\t\t Jogador 1 GANHOU!");
                                SetConsoleTextAttribute(12, 7);
                                return 1;
                            }
                        }else if(v[m][t] == p_adv){
                            cont_adv++;
                            if(cont_adv == 2){
                                printf("\n\n\n");
                                SetConsoleTextAttribute(12, 3);
                                printf("\t\t\t\t\t\t Jogador 2 GANHOU!");
                                SetConsoleTextAttribute(12, 7);
                                return 1;
                            }
                        }else{
                            cont_m = 0;
                            cont_adv = 0;
                        }
                    }
                    
                    // Diagonal secundária
                    else if(i + j == m + t){
                        if(v[m][t] == m_peca){
                            cont_m++;
                            if(cont_m == 2){
                                printf("\n\n\n");
                                SetConsoleTextAttribute(12, 3);
                                printf("\t\t\t\t\t\t Jogador 1 GANHOU!");
                                SetConsoleTextAttribute(12, 7);
                                return 1;
                            }
                        }else if(v[m][t] == p_adv){
                            cont_adv++;
                            if(cont_adv == 2){
                                printf("\n\n\n");
                                SetConsoleTextAttribute(12, 3);
                                printf("\t\t\t\t\t\t Jogador 2 GANHOU!");
                                SetConsoleTextAttribute(12, 7);
                                return 1;
                            }
                        }else{
                            cont_m = 0;
                            cont_adv = 0;
                        }
                    }                    
                }
            }
        }
    }

    cont_m = 0;
    cont_adv = 0;

    return 0;

}

int naCasa(int v[9][9]){

    // a_lin = Linha atual;
    // a_col = Coluna atual;

    int l, lin, col, a_lin, a_col, i, j;
    char c[5]; // Letra da posição da coluna

    do{

        exibeTabuleiro(v);

        // Sele��o de pe�a 1� jogador

        SetConsoleTextAttribute(12, 3);
        printf("\n  \t\t\t\t\t\t >> 1º Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Escolha uma peça: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(validaPeca(v, lin, col, 1)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa peça não está disponivel!! Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
        }

        system("cls");

    } while(validaPeca(v, lin, col, 1));

    // Jogada do 1� jogador

    // Se a linha e a coluna forem do jogador:
    a_lin = lin;
    a_col = col;

    validaMovimento(v, a_lin, a_col);

    do{
        v[a_lin][a_col] = 3;
        exibeTabuleiro(v);
        v[a_lin][a_col] = 6;

        SetConsoleTextAttribute(12, 3);
        printf("\n  \t\t\t\t\t\t >> 1º Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Mova a peça: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(validaPeca(v, lin, col, 5)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa peça não está disponivel!! Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
            system("cls");
        }

    }while(validaPeca(v, lin, col, 5));

    v[lin][col] = 1;

    // Ireir passar o vetor, depois a linha atual e coluna, depois as posiveis linha e coluna.
    // E adicionei a minha peça e a peça do adversario

    verificaConversao(v, a_lin, a_col, lin, col, 6, 7);


    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(v[i][j] == 5) v[i][j] = 0;
    

    if(vitoria(v, 6, 7)){
        return 1;
    }
    
    system("cls");


    do{
        exibeTabuleiro(v);

        // Sele��o de pe�a 2� jogador

        SetConsoleTextAttribute(12, 4);
        printf("\n  \t\t\t\t\t\t >> 2º Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Escolha uma peça: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(validaPeca(v, lin, col, 2)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa peça não está disponivel!! Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
        }

        system("cls");

    }while(validaPeca(v, lin, col, 2));

    // Jogada do 2� jogador

    a_lin = lin;
    a_col = col;

    validaMovimento(v, a_lin, a_col);

    do{
        v[a_lin][a_col] = 4;
        exibeTabuleiro(v);
        v[a_lin][a_col] = 7;

        SetConsoleTextAttribute(12, 4);
        printf("\n  \t\t\t\t\t\t >> 2º Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Mova a peça: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(validaPeca(v, lin, col, 5)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa peça não está disponivel!! Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
            system("cls");
        }

    }while(validaPeca(v, lin, col, 5));

    v[lin][col] = 2;

    // Ireir passar o vetor, depois a linha atual e coluna, depois as posiveis linha e coluna, e a peça na qual devo roupa,
    //no caso 6 - que são os "cocôs" do adv.

    verificaConversao(v, a_lin, a_col, lin, col, 7, 6);

    if(vitoria(v, 6, 7)){
        return 1;
    }

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(v[i][j] == 5) v[i][j] = 0;

    system("cls");

    return 0;
}