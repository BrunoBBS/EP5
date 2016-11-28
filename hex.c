#include "types.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BLK 1
#define WHT 2
#define SIZE 14

/*A funcao retorna uma matriz do tabuleiro preenchida com zeros.*/
int **create_table()
{
    int **table;
    int i;
    table = malloc(SIZE * sizeof(int *));
    if (table != NULL)
        for (i = 0; i < SIZE; i++)
        {
            table[i] = calloc(SIZE, sizeof(int));
            if (table[i] == NULL)
                return NULL;
        }
    return table;
}

/*A funcao recebe o tabuleiro, a cor, um vetor de jogadas e o numero de jogadas
 * inimigas e faz a jogada das pecas pretas , colocando-as na matriz e
 * imprimindo a jogada.*/
void my_play_b(int **table, int color, play plays[], int nplays)
{
    int i, j;
    play enemy_play = plays[nplays - 2];
    if (color == BLK)
    {
        if (enemy_play.l == 0)
        {
            do
            {
                i = rand() % SIZE;
                j = rand() % SIZE;
            } while (table[i][j] != 0);

            table[i][j] = color;
            printf("%d %d\n", i, j);
        }
        if (enemy_play.c < SIZE / 2)
        {
            if (enemy_play.l - 1 >= 0 &&
                table[enemy_play.l - 1][enemy_play.c] == 0)
            {
                table[enemy_play.l - 1][enemy_play.c] = color;
                printf("%d %d\n", enemy_play.l - 1, enemy_play.c);
            }
            else if (enemy_play.l - 1 >= 0 && enemy_play.c + 1 < SIZE &&
                     table[enemy_play.l - 1][enemy_play.c + 1] == 0)
            {
                table[enemy_play.l - 1][enemy_play.c + 1] = color;
                printf("%d %d\n", enemy_play.l - 1, enemy_play.c + 1);
            }
            else
            {
                for (i = 0; (enemy_play.l - i) >= 0 &&
                            table[enemy_play.l - i][enemy_play.c] ==
                                ((color == WHT) ? BLK : WHT);
                     i++)
                    ;
                if ((enemy_play.l - i) >= 0 &&
                    table[enemy_play.l - i][enemy_play.c] == 0)
                {
                    table[enemy_play.l - i][enemy_play.c] = color;
                    printf("%d %d\n", enemy_play.l - i, enemy_play.c);
                }
                else
                {
                    for (i = 0; ((enemy_play.l + i) < SIZE) &&
                                ((enemy_play.c - i) > -1) &&
                                table[enemy_play.l + i][enemy_play.c - i] ==
                                    ((color == WHT) ? BLK : WHT);
                         i++)
                        ;
                    if (enemy_play.l + i < SIZE && enemy_play.c - i >= 0 &&
                        table[enemy_play.l + i][enemy_play.c - i] ==
                            ((color == WHT) ? BLK : WHT))
                    {
                        do
                        {
                            i = rand() % SIZE;
                            j = rand() % SIZE;
                        } while (table[i][j] != 0);

                        table[i][j] = color;
                        printf("%d %d\n", i, j);
                    }
                }
            }
        }

        else
        {
            if (enemy_play.l + 1 < SIZE &&
                table[enemy_play.l + 1][enemy_play.c] == 0)
            {
                table[enemy_play.l + 1][enemy_play.c] = color;
                printf("%d %d\n", enemy_play.l + 1, enemy_play.c);
            }
            else if (enemy_play.l + 1 < SIZE && enemy_play.c - 1 >= 0 &&
                     table[enemy_play.l + 1][enemy_play.c - 1] == 0)
            {
                table[enemy_play.l + 1][enemy_play.c - 1] = color;
                printf("%d %d\n", enemy_play.l + 1, enemy_play.c - 1);
            }
            else
            {
                for (i = 0; enemy_play.l + i < SIZE &&
                            table[enemy_play.l + i][enemy_play.c] ==
                                ((color == WHT) ? BLK : WHT);
                     i++)
                    ;
                if (enemy_play.l + i < SIZE &&
                    table[enemy_play.l + i][enemy_play.c] == 0)
                {
                    table[enemy_play.l + i][enemy_play.c] = color;
                    printf("%d %d\n", enemy_play.l + i, enemy_play.c);
                }
                else
                {
                    for (i = 0; ((enemy_play.l - i) > -1) &&
                                ((enemy_play.c + i) < SIZE) &&
                                table[enemy_play.l - i][enemy_play.c + i] ==
                                    ((color == WHT) ? BLK : WHT);
                         i++)
                        ;
                    if (enemy_play.l + i < SIZE && enemy_play.c - i >= 0 &&
                                table[enemy_play.l - i][enemy_play.c + i] ==
                                    (color == WHT)
                            ? BLK
                            : WHT)
                    {
                        do
                        {
                            i = rand() % SIZE;
                            j = rand() % SIZE;
                        } while (table[i][j] != 0);
                        table[i][j] = color;
                        printf("%d %d\n", i, j);
                    }
                }
            }
        }
    }
}

/*A funcao receba o tabuleiro, a cor, a posicao para a jogada inicial, um vetor
 * das proprias jogadas, o numero de proprias jogadas ja feitas, um ponteiro
 * para um contador, e faz a jogada das brancas posicionando-a no tabuleiro e
 * imprimindo-a.*/
void my_play_w(int **table, int color, play wplay, play my_plays[], int *nwplays, int *bn)
{
    int l, c;
    if (*nwplays < (SIZE / 2))
    {
        l = wplay.l - (2 * *nwplays);
        c = wplay.c + (1 * *nwplays);
        if (table[l][c] != 0)
        {
            l -= 1;
            if (table[l][c] != 0)
            {
                c -= 1;
                if (table[l][c] != 0)
                {
                    do
                    {
                        l = rand() % SIZE;
                        c = rand() % SIZE;
                    } while (table[l][c] != 0);
                }
            }
        }

        table[l][c] = color;
        my_plays[*nwplays].l = l;
        my_plays[*nwplays].c = c;
        (*nwplays)++;
        printf("%d %d\n", l, c);
    }
    else
    {
        if (*bn < *nwplays)
        {
            l = my_plays[*bn].l - 1;
            c = my_plays[*bn].c;

            if (table[l][c] != 0)
            {
                c += 1;
                if (table[l][c] != 0)
                {
                    do
                    {
                        l = rand() % SIZE;
                        c = rand() % SIZE;
                    } while (table[l][c] != 0);
                }
            }
            table[l][c] = color;
            (*bn)++;
        }
        else
        {
            do
            {
                l = rand() % SIZE;
                c = rand() % SIZE;
            } while (table[l][c] != 0);
            table[l][c] = color;
        }
    }
}

/*A funcao recebe o tabuleiro e imprime-o.*/
void print(int **table)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < i; j++)
        {
            fprintf(stderr, " ");
        }
        for (j = 0; j < SIZE; j++)
        {
            if (table[i][j] == 0)
                fprintf(stderr, "-");
            else if (table[i][j] == BLK)
                fprintf(stderr, "p");
            else if (table[i][j] == WHT)
                fprintf(stderr, "b");
        }
        fprintf(stderr, "\n");
    }
}

/*A funcao recebe o tabuleiro, um tabuleiro auxiliar, a cor pela qual deve
 * procurar, e as coordenadas para verificar e retorna 0 se a cor nao cagnhou e
 * 1 se a cor ganhou.*/
int has_won(int **table, int **aux, int color, int l, int c)
{
    int winner;
    if (l >= 0 && l < SIZE && c >= 0 && c < SIZE)
    {
        aux[l][c] = 1;
        if (table[l][c] == color)
        {
            if (color == BLK && c == SIZE - 1)
                return 1;
            if (color == WHT && l == 0)
                return 1;

            /*Chama recursivamente para cada vizinho.*/
            if (l - 1 >= 0 && c + 1 < SIZE && aux[l - 1][c + 1] == 0)
            {
                winner = has_won(table, aux, color, l - 1, c + 1);
                if (winner)
                    return winner;
            }

            if (l - 1 >= 0 && aux[l - 1][c] == 0)
            {
                winner = has_won(table, aux, color, l - 1, c);
                if (winner)
                    return winner;
            }

            if (c - 1 >= 0 && aux[l][c - 1] == 0)
            {
                winner = has_won(table, aux, color, l, c - 1);
                if (winner)
                    return winner;
            }

            if (l - 1 >= 0 && c - 1 >= 0 && aux[l - 1][c - 1] == 0)
            {
                winner = has_won(table, aux, color, l - 1, c - 1);
                if (winner)
                    return winner;
            }

            if (l + 1 < SIZE && aux[l + 1][c] == 0)
            {
                winner = has_won(table, aux, color, l + 1, c);
                if (winner)
                    return winner;
            }

            if (c + 1 < SIZE && aux[l][c + 1] == 0)
            {
                winner = has_won(table, aux, color, l, c + 1);
                if (winner)
                    return winner;
            }
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int color, dbg = 0, **table, nplays = 1, *nwplays, **aux, winner = 0, i, *bn;
    play p, *plays, wplay, *my_plays;

    srand(time(0));

    plays = malloc(SIZE * SIZE * sizeof(play));

    bn = malloc(sizeof(int));
    *bn = 0;

    nwplays = malloc(sizeof(int));
    *nwplays = 0;

    my_plays = malloc(SIZE * SIZE * sizeof(play));

    /*Inicializa com os argumwntos*/
    if (argc > 1 && argv[1][0] == 'b')
    {
        color = WHT;
    }
    else if (argc > 1 && argv[1][0] == 'p')
    {
        color = BLK;
    }
    if (argc == 3)
        if (argv[2][0] == 'd')
            dbg = 1;

    table = create_table();
    aux = create_table();

    wplay.c = rand() % 7;
    wplay.l = SIZE - 1;

    /*Loop de jogo*/
    while (1)
    {
        if (color == WHT)
        {
            my_play_w(table, color, wplay, my_plays, nwplays, bn);
        }

        if (dbg)
            print(table);

        /*Loop de entrada*/
        while (1)
        {
            scanf("%d %d", &p.l, &p.c);
            if (p.l < SIZE && p.l >= 0 && p.c < SIZE && p.c >= 0)
            {
                if (nplays == 1 && table[p.l][p.c] != 0)
                {
                    break;
                }
                else if (table[p.l][p.c] == 0)
                {
                    break;
                }
            }
        }
        if (table[p.l][p.c] != 0)
        {
            if (nplays == 1 && p.c == plays[0].c && p.l == plays[0].l)
            {
                /*pie rule*/
                color = ((color == WHT) ? BLK : WHT);
                plays[nplays - 1] = p;
                nplays++;
            }
            continue;
        }

        /*Posiciona a jogada do oponente.*/
        else
        {
            table[p.l][p.c] = ((color == WHT) ? BLK : WHT);
            plays[nplays - 1] = p;
            nplays++;
        }

        /*Faz a propria jogada das pretas.*/
        if (color == BLK)
            my_play_b(table, color, plays, nplays);

        /*Verifica se alguem ganhou*/
        for (i = 0; i < SIZE && winner == 0; i++)
        {
            winner = has_won(table, aux, WHT, SIZE - 1, SIZE - 1 - i);
        }
        if (winner)
        {
            fprintf(stderr, "b ganhou\n");
            break;
        }

        for (i = 0; i < SIZE && winner == 0; i++)
        {
            winner = has_won(table, aux, BLK, i, 0);
        }
        if (winner)
        {
            fprintf(stderr, "p ganhou\n");
            break;
        }
    }
}
