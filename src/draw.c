/*
** EPITECH PROJECT, 2018
** src/draw
** File description:
** xkcd.com/378
*/

#include <math.h>
#include "my.h"
#include "world.h"

double glob;

sfColor get_real_z(my_game_t *game, sfVector3f cord, sfColor color)
{
    double res = glob;

    res *= (5 / cord.z);
    if (res > 1)
        res = 1;
    color.r *= res;
    color.g *= res;
    color.b *= res;
    return (color);
}

void    put_pixel3d(my_game_t *game, sfVector3f cord, sfColor color)
{
    if (cord.x >= game->win->framebuff->width || cord.x < 0 ||
cord.y >= game->win->framebuff->height || cord.y < 0)
        return ;
    if ((cord.z >= (game->win->z_buff)[(int)(WM * cord.y + cord.x)] ||
cord.z < 0) && (game->win->z_buff)[(int)(WM * cord.y + cord.x)] != -42)
        return ;
    color = get_real_z(game, cord, color);
    game->win->z_buff[(int)(game->win->framebuff->width * cord.y + cord.x)] =
cord.z;
    game->win->framebuff->pixels[(int)((game->win->framebuff->width *
(int)cord.y + (int)cord.x) * 4)] = color.r;
    game->win->framebuff->pixels[(int)((game->win->framebuff->width *
(int)cord.y + (int)cord.x) * 4 + 1)] = color.g;
    game->win->framebuff->pixels[(int)((game->win->framebuff->width *
(int)cord.y + (int)cord.x) * 4 + 2)] = color.b;
    game->win->framebuff->pixels[(int)((game->win->framebuff->width *
(int)cord.y + (int)cord.x) * 4 + 3)] = color.a;
}

void    put_pixel(my_framebuff_t *framebuff, int x, int y, sfColor color)
{
    if (x >= framebuff->width || x < 0 || y >= framebuff->height || y < 0)
        return ;
    framebuff->pixels[(framebuff->width * y + x) * 4] = color.r;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 1] = color.g;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 2] = color.b;
    framebuff->pixels[(framebuff->width * y + x) * 4 + 3] = color.a;
}

void    square(my_framebuff_t *buff, sfVector2f pos, sfVector2i size,
sfColor color)
{
    int i = 0;
    int j = 0;

    while (i < size.x) {
        j = 0;
        while (j < size.y) {
            put_pixel(buff, pos.x + j, pos.y + i, color);
            j++;
        }
        i++;
    }
}

void    draw_circle(my_framebuff_t *buff, sfVector2i cnt, int *tab,
sfColor color)
{
    int i = tab[2] * tab[0];
    int j = tab[4] * tab[0];

    while (i <= tab[3] * tab[0]) {
        j = 0;
        while (j <= tab[5] * tab[0]) {
            (my_pow(cnt.x - tab[0] + j - cnt.x, 2) + my_pow(cnt.y - tab[0] + i -
cnt.y, 2) <= my_pow(tab[0], 2) && my_pow(cnt.x - tab[0] + j - cnt.x, 2) +
my_pow(cnt.y - tab[0] + i - cnt.y, 2) >= my_pow(tab[1], 2)) ? put_pixel(buff,
cnt.x - tab[0] + j, cnt.y - tab[0] + i, color) : 0;
            j++;
        }
        i++;
    }
}
