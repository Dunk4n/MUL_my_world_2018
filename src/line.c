/*
** EPITECH PROJECT, 2018
** src/line
** File description:
** try not to segfault, good luck :)
*/

#include "world.h"
#include "my.h"

void horz_line(my_game_t *game, sfVector3f pos, vector4f_t nor, sfColor color)
{
    int x = pos.x;
    int y = pos.z;

    if (pos.x > pos.y)
        x = pos.y;
    while (x <= pos.y) {
        put_pixel3d(game, (sfVector3f){x, y, (nor.t - (nor.x * (double)x) -
(nor.y * (double)y)) / ((nor.z == 0) ? 1 : nor.z)}, color);
        x++;
    }
}

void horz_line_tx(my_game_t *game, sfVector3f pos, vector4f_t nor,
sfColor color)
{
    int x = pos.x;
    int y = pos.z;
    double bary_a;
    double bary_b;
    double bary_c;
    double z;
    sfVector2u lim = sfImage_getSize(game->img[game->map->ptr_tri->texture]);

    if (pos.x > pos.y)
        x = pos.y;
    while (x <= pos.y) {
        bary_a = (nor.bcy * (x - nor.c_point.x) +
        (nor.cbx * (y - nor.c_point.y))) * nor.div;
        bary_b = (nor.cay * (x - nor.c_point.x) +
        (nor.acx * (y - nor.c_point.y))) * nor.div;
        bary_c = 1.0 - bary_a - bary_b;
        z = (nor.t - (nor.x * (double)x) -
(nor.y * (double)y)) / ((nor.z == 0) ? 1 : nor.z);
        //printf("z = %f\n", z - game->map->zoom);
        color = sfImage_getPixel(game->img[game->map->ptr_tri->texture],
(int)(bary_a * nor.a_uv.x + bary_b * nor.b_uv.x + bary_c * nor.c_uv.x) % lim.x,
(int)(bary_a * nor.a_uv.y + bary_b * nor.b_uv.y + bary_c * nor.c_uv.y) % lim.y);
        put_pixel3d(game, (sfVector3f){x, y, z}, color);
        x++;
    }
}

void    draw_linex(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color)
{
    double a = (pos[0].y - pos[1].y) / (pos[0].x - pos[1].x);
    double b = pos[0].y - a * pos[0].x;
    sfVector2f ptr = {pos[0].x, pos[0].y};
    sfVector2i size = {r, r};

    ptr.x += ((ptr.x < pos[1].x) ? 1.0 : -1.0);
    ptr.y = a * ptr.x + b;
    while ((int)ptr.x != (int)pos[1].x) {
        if (r > 1)
            square(buff, ptr, size, color);
        else
            put_pixel(buff, ptr.x, ptr.y, color);
        ptr.x += ((ptr.x < pos[1].x) ? 1.0 : -1.0);
        ptr.y = a * ptr.x + b;
    }
}

void    draw_liney(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color)
{
    double a = (pos[0].x - pos[1].x) / (pos[0].y - pos[1].y);
    double b = pos[0].x - a * pos[0].y;
    sfVector2f ptr = {pos[0].x, pos[0].y};
    sfVector2i size = {r, r};

    ptr.y += ((ptr.y < pos[1].y) ? 1.0 : -1.0);
    ptr.x = a * ptr.y + b;
    while ((int)ptr.y != (int)pos[1].y) {
        if (r > 1)
            square(buff, ptr, size, color);
        else
            put_pixel(buff, ptr.x, ptr.y, color);
        ptr.y += ((ptr.y < pos[1].y) ? 1.0 : -1.0);
        ptr.x = a * ptr.y + b;
    }
}

void    draw_line(my_framebuff_t *buff, sfVector2f *pos, int r, sfColor color)
{
    if ((int)pos[0].x != (int)pos[1].x)
        draw_linex(buff, pos, r, color);
    if ((int)pos[0].y != (int)pos[1].y)
        draw_liney(buff, pos, r, color);
}
