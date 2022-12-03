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

int validaMovimento(int v[9][9], int i, int j, int a_lin, int a_col){

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

void naCasa(int v[9][9]){

    int l, lin, col, a_lin, a_col, i, j;
    char c[5];

    do{

        exibeTabuleiro(v);

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

        if(validaPeca(v, lin, col, 1)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa pe�a n�o est� disponivel!!Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
        }

        system("cls");

    } while(validaPeca(v, lin, col, 1));

    // Jogada do 1� jogador

    // Se a linha e a coluna forem do jogador:
    a_lin = lin;
    a_col = col;

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(validaMovimento(v, i, j, a_lin, a_col)) v[i][j] = 5;

    do{
        v[a_lin][a_col] = 3;
        exibeTabuleiro(v);
        v[a_lin][a_col] = 6;

        SetConsoleTextAttribute(12, 3);
        printf("\n  \t\t\t\t\t\t >> 1� Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Mova a pe�a: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(validaPeca(v, lin, col, 5)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa pe�a n�o est� disponivel!!Escolha outra.\n\n");
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

    system("cls");

    do{
        exibeTabuleiro(v);

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

        if(validaPeca(v, lin, col, 2)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa pe�a n�o est� disponivel!!Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
        }

        system("cls");

    }while(validaPeca(v, lin, col, 2));

    // Jogada do 2� jogador

    a_lin = lin;
    a_col = col;

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(validaMovimento(v, i, j, a_lin, a_col)) v[i][j] = 5;

    do{
        v[a_lin][a_col] = 4;
        exibeTabuleiro(v);
        v[a_lin][a_col] = 7;

        SetConsoleTextAttribute(12, 4);
        printf("\n  \t\t\t\t\t\t >> 2� Jogador <<\n");
        SetConsoleTextAttribute(12, 2);
        printf("-Mova a pe�a: \n\n");
        SetConsoleTextAttribute(12, 7);

        printf("Linha(1-9): ");
        scanf("%d", &l);

        lin = l - 1;

        printf("Coluna(A-I): ");
        scanf("%s", &c);

        col = col_num(c[0]);

        if(validaPeca(v, lin, col, 5)){
            SetConsoleTextAttribute(12, 4);
            printf("\n\a\7Essa pe�a n�o est� disponivel!!Escolha outra.\n\n");
            SetConsoleTextAttribute(12, 7);
            system("pause");
            system("cls");
        }

    }while(validaPeca(v, lin, col, 5));

    v[lin][col] = 2;

    // Ireir passar o vetor, depois a linha atual e coluna, depois as posiveis linha e coluna, e a peça na qual devo roupa,
    //no caso 6 - que são os "cocôs" do adv.

    verificaConversao(v, a_lin, a_col, lin, col, 7, 6);

    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(v[i][j] == 5) v[i][j] = 0;

    system("cls");

}


int vitoria(int *start){

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
