/*
** EPITECH PROJECT, 2018
** src/draw
** File description:
** xkcd.com/378
*/

#include "my.h"
#include "world.h"

void    put_pixel3d(my_window_t *win, sfVector3f cord, sfColor color)
{
    if (cord.x >= win->framebuff->width || cord.x < 0 ||
cord.y >= win->framebuff->height || cord.y < 0)
        return ;
    if ((cord.z >= (win->z_buff)[(int)(WM * cord.y + cord.x)] || cord.z < 0)
&& (win->z_buff)[(int)(WM * cord.y + cord.x)] != -42)
        return ;
    win->z_buff[(int)(win->framebuff->width * cord.y + cord.x)] = cord.z;
    win->framebuff->pixels[(int)((win->framebuff->width * (int)cord.y +
(int)cord.x) * 4)] = color.r;
    win->framebuff->pixels[(int)((win->framebuff->width * (int)cord.y +
(int)cord.x) * 4 + 1)] = color.g;
    win->framebuff->pixels[(int)((win->framebuff->width * (int)cord.y +
(int)cord.x) * 4 + 2)] = color.b;
    win->framebuff->pixels[(int)((win->framebuff->width * (int)cord.y +
(int)cord.x) * 4 + 3)] = color.a;
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
