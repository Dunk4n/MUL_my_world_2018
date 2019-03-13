/*
** EPITECH PROJECT, 2018
** src/draw_poly_interpolation
** File description:
** code on paper!
*/

#include <stdlib.h>
#include "world.h"

void    swap_float(double *a, double *b)
{
    double c = *a;

    *a = *b;
    *b = c;
}

void    poly_horizontal_line(my_game_t *game, triangle_t *tri,
arg_interpolation_t *arg, double *tab)
{
    sfVector3f cord;
    int x1 = arg->xa;
    int x2 = arg->xb;

    tab[3] = 1 - (arg->xa - x1);
    tab[4] = arg->iza + tab[3] * arg->dizdx;
    tab[5] = arg->uiza + tab[3] * arg->duizdx;
    tab[6] = arg->viza + tab[3] * arg->dvizdx;
    while (x1++ < x2) {
        tab[0] = 1 / tab[4];
        tab[1] = tab[5] * tab[0];
        tab[2] = tab[6] * tab[0];
        cord.x = x1;
        cord.y = arg->y1;
        cord.z = tab[0];
        put_pixel3d(game, cord, sfImage_getPixel(game->img[tri->texture],
(int)(tab[1] * tab[7]) % (int)tab[7], (int)(tab[2] * tab[8]) % (int)tab[8]));
        tab[4] += arg->dizdx;
        tab[5] += arg->duizdx;
        tab[6] += arg->dvizdx;
    }
}

void    draw_poly_interpolation(my_game_t *game, triangle_t *tri,
arg_interpolation_t *arg)
{
    sfVector2u lim = sfImage_getSize(game->img[tri->texture]);
    double tab[9];

    tab[7] = lim.x;
    tab[8] = lim.y;
    while (arg->y1 < arg->y2) {
        poly_horizontal_line(game, tri, arg, tab);
        arg->xa += arg->dxdya;
        arg->xb += arg->dxdyb;
        arg->iza += arg->dizdya;
        arg->uiza += arg->duizdya;
        arg->viza += arg->dvizdya;
        arg->y1++;
    }
}

void    init_draw_poly(triangle_t *tri, double *tab)
{
    tab[0] = tri->point_2d[0]->x + 0.5;
    tab[1] = tri->point_2d[0]->y + 0.5;
    tab[2] = tri->point_2d[1]->x + 0.5;
    tab[3] = tri->point_2d[1]->y + 0.5;
    tab[4] = tri->point_2d[2]->x + 0.5;
    tab[5] = tri->point_2d[2]->y + 0.5;
    tab[6] = 1.0 / tri->point_2d[0]->z;
    tab[7] = 1.0 / tri->point_2d[1]->z;
    tab[8] = 1.0 / tri->point_2d[2]->z;
    tab[9] = tri->point_tx[0]->x * tab[6];
    tab[10] = tri->point_tx[0]->y * tab[6];
    tab[11] = tri->point_tx[1]->x * tab[7];
    tab[12] = tri->point_tx[1]->y * tab[7];
    tab[13] = tri->point_tx[2]->x * tab[8];
    tab[14] = tri->point_tx[2]->y * tab[8];
}

void    sort_ordone(double *tab)
{
    if (tab[1] > tab[3]) {
        swap_float(&(tab[0]), &(tab[2]));
        swap_float(&(tab[1]), &(tab[3]));
        swap_float(&(tab[6]), &(tab[7]));
        swap_float(&(tab[9]), &(tab[11]));
        swap_float(&(tab[10]), &(tab[12]));
    }
    if (tab[1] > tab[5]) {
        swap_float(&(tab[0]), &(tab[4]));
        swap_float(&(tab[1]), &(tab[5]));
        swap_float(&(tab[6]), &(tab[8]));
        swap_float(&(tab[9]), &(tab[13]));
        swap_float(&(tab[10]), &(tab[14]));
    }
    if (tab[3] > tab[5]) {
        swap_float(&(tab[2]), &(tab[4]));
        swap_float(&(tab[3]), &(tab[5]));
        swap_float(&(tab[7]), &(tab[8]));
        swap_float(&(tab[11]), &(tab[13]));
        swap_float(&(tab[12]), &(tab[14]));
    }
}
