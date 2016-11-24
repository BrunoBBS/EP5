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

void check_neighbor(int **table, int **board, int l, int c, int color)
{
    if (board[l][c] == color)
    {

        if (board[l - 1][c] == 0)
            table[l - 1][c] = 1;
        else if (board[l - 1][c] == color)
            check_neighbor(table, board, l - 1, c, color);

        if (board[l - 1][c + 1] == 0)
            table[l - 1][c + 1] = 1;
        else if (board[l - 1][c + 1] == color)
            check_neighbor(table, board, l - 1, c + 1, color);

        if (board[l][c + 1] == 0)
            table[l][c + 1] = 1;
        else if (board[l][c + 1] == color)
            check_neighbor(table, board, l, c + 1, color);

        if (board[l + 1][c] == 0)
            table[l + 1][c] = 1;
        else if (board[l + 1][c] == color)
            check_neighbor(table, board, l + 1, c, color);

        if (board[l + 1][c - 1] == 0)
            table[l + 1][c - 1] = 1;
        else if (board[l + 1][c - 1] == color)
            check_neighbor(table, board, l + 1, c - 1, color);

        if (board[l][c - 1] == 0)
            table[l][c - 1] = 1;
        else if (board[l][c - 1] == color)
            check_neighbor(table, board, l, c - 1, color);

        if (board[l+1][c - 2] == 0)
            table[l+1][c -2] = 1;
        else if (board[l+1][c - 2] == color)
            check_neighbor(table, board, l+1, c - 2, color);

        if (board[l+2][c -1] == 0)
            table[l+2][c - 1] = 1;
        else if (board[l+2][c - 1] == color)
            check_neighbor(table, board, l+2, c - 1, color);

        if (board[l-1][c - 1] == 0)
            table[l-1][c - 1] = 1;
        else if (board[l-1][c - 1] == color)
            check_neighbor(table, board, l-1, c - 1, color);

        if (board[l-1][c + 2] == 0)
            table[l-1][c +2] = 1;
        else if (board[l-1][c +2] == color)
            check_neighbor(table, board, l-1, c+2, color);
    }
    return;
}

void my_play(int **table, int color, play *plays, int nplays)
{
    int i, j;
    play act_play = plays[nplays-1];
    if (color == BLK)
    {
        if (act_play.c < SIZE/2)
        {
            if (table[act_play.l - 1][act_play.c] == 0)
            {
                table[act_play.l - 1][act_play.c] = color;
            }
            else if (table[act_play.l - 1][act_play.c + 1] == 0 )
            {
                table[act_play.l - 1][act_play.c+1] = color;
            }
            else
            {
                for (i = act_play.l; table[i][act_play.c] ==
                        (color == WHT)?BLK:WHT && i; i--);
                if(i>0)
                    table[i][act_play.c] = color;
                else
                {
                    for (i = 0; table[act_play.l - i][act_play.c+i] ==
                            (color == WHT)?BLK:WHT && ((act_play.l -i)>-1) &&
                            ((act_play.c + i)<SIZE);i++);
                    if ()

                }
            }
        }
    }
}

int has_won(int **table)
{

}
int main(int argc, char *argv[])
{
    int color, dbg, **table, nplays = 1;
    play p, *plays;

    plays = malloc(200 * sizeof(play));

    if (argv[1][0] == 'b')
    {
        color = BLK;
    }
    else
        color = WHT;

    if (argc == 3)
        if (argv[2][0] == 'd')
            dbg = 1;
    table = create_table();

    while (1)
    {
        scanf("%d %d", &p.l, &p.c);
        if (p.l < SIZE  && p.l >= 0 && p.c < SIZE && p.c >= 0)
            if (table[p.l][p.c] != 0)
            {
                if (nplays == 1 && p.c == plays[0].c && p.l == plays[0].l)
                    color = (color == WHT)?BLK:WHT;
                plays[nplays-1] = p;
                nplays ++;
            }
    }
}
