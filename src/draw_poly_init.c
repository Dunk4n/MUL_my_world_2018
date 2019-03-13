/*
** EPITECH PROJECT, 2018
** src/draw_poly_init
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "world.h"

void    init_arg(arg_interpolation_t *arg, double *tab)
{
    tab[15] = 1 / tab[15];
    arg->dizdx = ((tab[8] - tab[6]) * (tab[3] - tab[1]) - (tab[7] - tab[6]) *
(tab[5] - tab[1])) * tab[15];
    arg->duizdx = ((tab[13] - tab[9]) * (tab[3] - tab[1]) - (tab[11] - tab[9]) *
(tab[5] - tab[1])) * tab[15];
    arg->dvizdx = ((tab[14] - tab[10]) * (tab[3] - tab[1]) - (tab[12] - tab[10])
* (tab[5] - tab[1])) * tab[15];
    tab[16] = ((tab[7] - tab[6]) * (tab[4] - tab[0]) - (tab[8] - tab[6]) *
(tab[2] - tab[0])) * tab[15];
    tab[17] = ((tab[11] - tab[9]) * (tab[4] - tab[0]) - (tab[13] - tab[9]) *
(tab[2] - tab[0])) * tab[15];
    tab[18] = ((tab[12] - tab[10]) * (tab[4] - tab[0]) - (tab[14] - tab[10]) *
(tab[2] - tab[0])) * tab[15];
    if (tab[3] > tab[1])
        tab[19] = (tab[2] - tab[0]) / (tab[3] - tab[1]);
    if (tab[5] > tab[1])
        tab[20] = (tab[4] - tab[0]) / (tab[5] - tab[1]);
    if (tab[5] > tab[3])
        tab[21] = (tab[4] - tab[2]) / (tab[5] - tab[3]);
}

int     calc_side(double *tab)
{
    int side;

    side = tab[20] > tab[19];
    if (tab[1] == tab[3])
        side = tab[0] > tab[2];
    if (tab[3] == tab[5])
        side = tab[2] > tab[4];
    return (side);
}

int     cond_inter(double *tab, int y1i, int y2i, int y3i)
{
    if ((y1i == y2i && y1i == y3i)
|| ((int)tab[0] == (int)tab[2] && (int)tab[0] == (int)tab[4]))
        return (1);
    if (!(tab[15] = ((tab[4] - tab[0]) * (tab[3] - tab[1]) - (tab[2] - tab[0]) *
(tab[5] - tab[1]))))
        return (1);
    return (0);
}
