
# Tic Tac Sho

Projeto desenvolvido para Cadeira de Introdução a Programação em Linguagem C.

## Regras do jogo

Algumas regras foram ditas para estrutura base do projeto que são:

 - Jogo para 2 jogadores cada jogador controla cinco peões
 - Tabuleiro 9x9 no qual são inseridos cinco peões de cada jogador em posições aleatórias
 - Jogadores alternam seus turnos durante a partida
 - O objetivo do jogo é formar um agrupamento ininterrupto de cinco aliados organizados em linha (horizontal, vertical ou diagonal) 

Todas as peças movem-se igual à rainha do Xadrez,seja seguindo uma coluna, uma linha
ou diagonal do tabuleiro, com alguns detalhes relevantes: 
 - i) não é permitido encerrar o movimento em um espaço ocupado (seja por peão ou aliado de qualquer jogador); 
 - ii) durante um movimento o peão não pode pular outros peões (sejam do oponente ou seus); 
 - iii) após mover-se, todas as peças de aliado que o jogador passar por cima são convertidas para o outro jogador, isto é, aliados seus viram do oponente;

## Funções Obrigatórias
Durante a implementação do projeto, deverão ser implementadas algumas funções
obrigatórias:
 - exibeTabuleiro: imprimir todo o tabuleiro na tela de acordo com a matriz do jogo.
 - naCasa: retorna o que está em uma determinada casa (espaço) do tabuleiro. Todas as casas do tabuleiro são endereçadas como no Xadrez, usando números e letras. Exemplo: na casa 6f pode ter um peão de um dos jogadores, o número indica a linha e a letra indica a coluna.
 - validaPeca: verifica se a casa indicada possui uma peça que ele pode mover ou não.
 - validaMovimento: verifica se o movimento realizado pelo jogador é possível ou não.
 - verificaConversao: verifica quais aliados devem ser virados após um movimento.
 - verificaVitoria: verifica se algum jogador conseguiu obter a vitória.

 ## O jogo

![image](https://user-images.githubusercontent.com/90703943/229311537-49cec109-5aa9-484c-bf36-55b66ecd69b4.png)
