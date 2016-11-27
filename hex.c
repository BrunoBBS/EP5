#include "types.h"
#include <stdio.h>
#include <stdlib.h>

#define BLK 1
#define WHT 2
#define SIZE 14

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

void my_play_b(int **table, int color, play plays[], int nplays)
{
    int i, j;
    play enemy_play = plays[nplays-2];
    if (color == BLK)
    {
        if (enemy_play.c < SIZE/2)
        {
            if (enemy_play.l - 1 >= 0 &&
                    table[enemy_play.l - 1][enemy_play.c] == 0)
            {
                table[enemy_play.l - 1][enemy_play.c] = color;
                printf("%d %d\n", enemy_play.l-1, enemy_play.c);
            }
            else if (enemy_play.l -1 >= 0 && enemy_play.c + 1 <
                    SIZE && table[enemy_play.l - 1][enemy_play.c + 1] == 0 )
            {
                table[enemy_play.l - 1][enemy_play.c+1] = color;
                printf("%d %d\n", enemy_play.l-1, enemy_play.c+1);
            }
            else
            {
                for (i = 0; (enemy_play.l - i) >= 0 &&
                        table[enemy_play.l - i][enemy_play.c] ==
                        ((color == WHT)?BLK:WHT); i++);
                if(enemy_play.l - i >= 0 &&
                        table[enemy_play.l - i][enemy_play.c] == 0)
                {

                    table[enemy_play.l - i][enemy_play.c] = color;
                    printf("%d %d\n", enemy_play.l - i, enemy_play.c);
                }
                else
                {
                    for (i = 0; ((enemy_play.l + i) < SIZE) &&
                            ((enemy_play.c - i) > -1) &&
                            table[enemy_play.l + i][enemy_play.c-i] ==
                            ((color == WHT)?BLK:WHT); i++);
                    if (table[enemy_play.l + i][enemy_play.c - i] ==
                            ((color == WHT)?BLK:WHT))
                    {
                        do
                        {
                            i = rand() % SIZE;
                            j = rand() % SIZE;
                        } while(table[i][j] != 0);
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
                printf("%d %d\n", enemy_play.l + 1 , enemy_play.c);
            }
            else if (enemy_play.l + 1 < SIZE && enemy_play.c - 1 >= 0 &&
                    table[enemy_play.l + 1][enemy_play.c - 1] == 0 )
            {
                table[enemy_play.l + 1][enemy_play.c - 1] = color;
                printf("%d %d\n", enemy_play.l + 1 , enemy_play.c-1);
            }
            else
            {
                for (i = 0; enemy_play.l + i < SIZE &&
                        table[enemy_play.l + i][enemy_play.c] ==
                        ((color == WHT)?BLK:WHT); i++);
                if(enemy_play.l + i < SIZE && table[enemy_play.l + i][enemy_play.c]  == 0)
                {
                    table[enemy_play.l + i][enemy_play.c] = color;
                    printf("%d %d\n", enemy_play.l + i , enemy_play.c);
                }
                else
                {
                    for (i = 0; ((enemy_play.l -i)>-1) &&
                            ((enemy_play.c + i)<SIZE) &&
                            table[enemy_play.l - i][enemy_play.c+i] ==
                            ((color == WHT)?BLK:WHT) ; i++);
                    if (table[enemy_play.l - i][enemy_play.c+i] ==
                            (color == WHT)?BLK:WHT)
                    {
                        do
                        {
                            i = rand() % SIZE;
                            j = rand() % SIZE;
                        } while(table[i][j] != 0);
                        table[i][j] = color;
                        printf("%d %d\n", i, j);

                    }
                }
            }
        }
    }
}

void my_play_w(int **table, int color, play wplay, play my_plays[], int *nwplays)
{
    int l,c;
    l = wplay.l - (2 * *nwplays);
    c = wplay.c + (1 * *nwplays);
    if (*nwplays < (SIZE / 2))
    {
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
        (*nwplays) ++;
        printf("%d %d\n", l, c);
    }
    else
    {

    }
}

void print(int **table)
{
    int i,j;
    for (i = 0; i<SIZE ;i++)
    {
        for (j = 0; j<i ; j++)
        {
            fprintf(stderr, " ");
        }
        for (j=0; j<SIZE; j++)
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

int has_won(int **table)
{

}

int main(int argc, char *argv[])
{
    int color, dbg = 0, **table, nplays = 1, *nwplays;
    play p, *plays, wplay, *my_plays;

    plays = malloc(200 * sizeof(play));

    nwplays = malloc(sizeof(int));
    *nwplays = 0;

    if (argc > 1 && argv[1][0] == 'b')
    {
        color = WHT;
    }
    else if(argc > 1 && argv[1][0] == 'p')
    {
        color = BLK;
    }
    if (argc == 3)
        if (argv[2][0] == 'd')
            dbg = 1;

    table = create_table();

    wplay.c = rand() % 7;
    wplay.l = SIZE - 1;

    while (1)
    {
        if (dbg)
            print(table);

        if (color == WHT)
        {
            my_play_w(table, color, wplay, my_plays, nwplays);
        }

        scanf("%d %d", &p.l, &p.c);

        if (p.l < SIZE  && p.l >= 0 && p.c < SIZE && p.c >= 0)
        {
            if (table[p.l][p.c] != 0)
            {
                if (nplays == 1 && p.c == plays[0].c && p.l == plays[0].l)
                {
                    color = ((color == WHT)?BLK:WHT);
                    plays[nplays-1] = p;
                    nplays ++;
                }
                continue;
            }
            else
            {
                table[p.l][p.c] = ((color == WHT)?BLK:WHT);
                plays[nplays-1] = p;
                nplays ++;
            }
            if (color == BLK)
                my_play_b(table, color, plays, nplays);
        }
    }
}
