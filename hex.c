#include "types.h"
#include <stdio.h>
#include <stdlib.h>

#define BLK 1;
#define WHT 2;

int **create_table()
{
    int **table;
    int i;
    table = malloc(14 * sizeof(int *));
    if (table != NULL)
        for (i = 0; i < 14; i++)
        {
            table[i] = calloc(14, sizeof(int));
            if (table[i] == NULL)
                return NULL;
        }
    return table;
}

int mmiterate(int alpha, int beta, int max)
{
}

void check_neighbor(int **table, int **board, int l, int c, int color, int val)
{
    if (board[l][c] == color)
    {
        if (table[l][c] == 0)
            table[l][c] = val;

        if (board[l - 1][c] == 0)
            table[l - 1][c] = val + 1;
        else if (board[l - 1][c] == color)
            check_neighbor(table, board, l - 1, c, color, val);

        if (board[l - 1][c + 1] == 0)
            table[l - 1][c + 1] = val + 1;
        else if (board[l - 1][c + 1] == color)
            check_neighbor(table, board, l - 1, c + 1, color, val);

        if (board[l][c + 1] == 0)
            table[l][c + 1] = val + 1;
        else if (board[l][c + 1] == color)
            check_neighbor(table, board, l, c + 1, color, val);

        if (board[l + 1][c] == 0)
            table[l + 1][c] = val + 1;
        else if (board[l + 1][c] == color)
            check_neighbor(table, board, l + 1, c, color, val);

        if (board[l + 1][c - 1] == 0)
            table[l + 1][c - 1] = val + 1;
        else if (board[l + 1][c - 1] == color)
            check_neighbor(table, board, l + 1, c - 1, color, val);

        if (board[l][c - 1] == 0)
            table[l][c - 1] = val + 1;
        else if (board[l][c - 1] == color)
            check_neighbor(table, board, l, c - 1, color, val);
    }
    return;
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

int play_value(int **board, int color)
{
    int **aux, i, j;
    aux = create_table();
    for (i = 0; i < 14; i++)
    {
        for (j = 0; j < 14; j++)
        {
            if (board[i][j] == 0 && aux[i][j] == 0)
                aux[i][j] = i + 1;
            else if (board[i][j] == color)
            {
                aux[i][j] = i + 1;
                check_neighbor(aux, board, i, j, color, i + 1);
            }
        }
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
        if (p.l <= 13 && p.l >= 0 && p.c <= 13 && p.c >= 0)
            for (i = 0; i < nplays; i++)
                if (plays[i].c == p.c && plays[i].l == p.l)
                    if (nplays == 1)
                        /*pierule*/;
    }
}
