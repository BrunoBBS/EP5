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


play *bridge_vect(int **board, play p)
{
    int count = 0;
    play *bridges = malloc(6 * sizeof(play));

    if (p.l > 0 && p.c > 0)
    {
        bridges[count].l = p.l - 1;
        bridges[count].c = p.c - 1;
        count++;
    }
}

void my_play(int **table, int color, play *plays, int nplays)
{
    int i, j;
    play act_play = plays[nplays-1];
    if (color == BLK)
    {
        if (act_play.c < SIZE/2)
            for (i = act_play.l; table[i][act_play.c] == (color == WHT)?BLK:WHT && i; i--)
    }
}

int main(int argc, char *argv[])
{
    int mode, dbg, **table, i, nplays;
    play p, *plays;

    if (argv[1][0] == 'b')
    {
        mode = BLK;
    }
    else
        mode = WHT;

    if (argc == 3)
        if (argv[2][0] == 'd')
            dbg = 1;
    table = create_table();

    while (1)
    {
        scanf("%d %d", &p.l, &p.c);
        if (p.l < SIZE  && p.l >= 0 && p.c < SIZE && p.c >= 0)
            if (table[p.l][p.c] != 0)
                if (nplays == 1)
                    /*pierule*/;
    }
}
