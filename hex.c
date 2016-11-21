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
            table[i] = malloc(14 * sizeof(int));
            if (table[i] == NULL)
                return NULL;
        }
    return table;
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
}
