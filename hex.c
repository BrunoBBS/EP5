#include "types.h"
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
            table[i] = calloc(14 * sizeof(int));
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
    if (board[i][j] == color)
    {
    }
    return;
}

int play_value(int **board, int color)
{
    int **aux, i, j;
    tab = create_table();
    for (i = 0; i < 14; 1 ++)
    {
        for (j = 0; j < 14; j++)
        {
            if (board[i][j] == 0 && aux[i][j] == 0)
                aux[i][j] = i + 1;
            else if (board[i][j] == color)
            {
                aux[i][j] = i + 1;
                check_negbor(aux, board, i, j, color, i + 1);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int mode, dbg, **table;

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

    while ()
}
