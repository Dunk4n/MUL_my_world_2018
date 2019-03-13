/*
** EPITECH PROJECT, 2018
** src/draw_poly
** File description:
** you're a bad developer
*/

#include <stdlib.h>
#include "world.h"

void    cond_if_not_side(my_game_t *game, triangle_t *tri, double *tab,
arg_interpolation_t *arg)
{
    if (arg->y1i < arg->y2i) {
        arg->xb = tab[0] + tab[22] * tab[19];
        arg->dxdyb = tab[19];
        arg->y1 = arg->y1i;
        arg->y2 = arg->y2i;
        draw_poly_interpolation(game, tri, arg);
    }
    if (arg->y2i < arg->y3i) {
        arg->xb = tab[2] + (1 - (tab[3] - arg->y2i)) * tab[21];
        arg->dxdyb = tab[21];
        arg->y1 = arg->y2i;
        arg->y2 = arg->y3i;
        draw_poly_interpolation(game, tri, arg);
    }
}

void    if_not_side(my_game_t *game, triangle_t *tri, double *tab,
arg_interpolation_t *arg)
{
    arg->dxdya = tab[20];
    arg->dizdya = tab[20] * arg->dizdx + tab[16];
    arg->duizdya = tab[20] * arg->duizdx + tab[17];
    arg->dvizdya = tab[20] * arg->dvizdx + tab[18];
    tab[22] = 1 - (tab[1] - arg->y1i);
    arg->xa = tab[0] + tab[22] * arg->dxdya;
    arg->iza = tab[6] + tab[22] * arg->dizdya;
    arg->uiza = tab[9] + tab[22] * arg->duizdya;
    arg->viza = tab[10] + tab[22] * arg->dvizdya;
    cond_if_not_side(game, tri, tab, arg);
}

void    cond_if_side(my_game_t *game, triangle_t *tri, double *tab,
arg_interpolation_t *arg)
{
    if (arg->y2i < arg->y3i) {
        arg->dxdya = tab[21];
        arg->dizdya = tab[21] * arg->dizdx + tab[16];
        arg->duizdya = tab[21] * arg->duizdx + tab[17];
        arg->dvizdya = tab[21] * arg->dvizdx + tab[18];
        tab[22] = 1 - (tab[3] - arg->y2i);
        arg->xa = tab[2] + tab[22] * arg->dxdya;
        arg->iza = tab[7] + tab[22] * arg->dizdya;
        arg->uiza = tab[11] + tab[22] * arg->duizdya;
        arg->viza = tab[12] + tab[22] * arg->dvizdya;
        arg->y1 = arg->y2i;
        arg->y2 = arg->y3i;
        draw_poly_interpolation(game, tri, arg);
    }
}

void    if_side(my_game_t *game, triangle_t *tri, double *tab,
arg_interpolation_t *arg)
{
    arg->dxdyb = tab[20];
    tab[22] = 1 - (tab[1] - arg->y1i);
    arg->xb = tab[0] + tab[22] * arg->dxdyb;
    if (arg->y1i < arg->y2i) {
        arg->dxdya = tab[19];
        arg->dizdya = tab[19] * arg->dizdx + tab[16];
        arg->duizdya = tab[19] * arg->duizdx + tab[17];
        arg->dvizdya = tab[19] * arg->dvizdx + tab[18];
        arg->xa = tab[0] + tab[22] * arg->dxdya;
        arg->iza = tab[6] + tab[22] * arg->dizdya;
        arg->uiza = tab[9] + tab[22] * arg->duizdya;
        arg->viza = tab[10] + tab[22] * arg->dvizdya;
        arg->y1 = arg->y1i;
        arg->y2 = arg->y2i;
        draw_poly_interpolation(game, tri, arg);
    }
    cond_if_side(game, tri, tab, arg);
}

void    draw_poly(my_game_t *game, triangle_t *tri)
{
    double tab[23];
    arg_interpolation_t *arg;
    int side;

    if (!(arg = malloc(sizeof(arg_interpolation_t))))
        return ;
    init_draw_poly(tri, tab);
    sort_ordone(tab);
    arg->y1i = tab[1];
    arg->y2i = tab[3];
    arg->y3i = tab[5];
    if (cond_inter(tab, arg->y1i, arg->y2i, arg->y3i))
        return ;
    init_arg(arg, tab);
    side = calc_side(tab);
    if (!side)
        if_not_side(game, tri, tab, arg);
    else
        if_side(game, tri, tab, arg);
}
