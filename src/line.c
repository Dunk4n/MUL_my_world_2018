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
    double iz;
    double u;
    double v;
    sfVector3f f = {x, y, 0};
    sfVector2u lim = sfImage_getSize(game->img[game->map->ptr_tri->texture]);

    if (pos.x > pos.y)
        x = pos.y;
    while (x <= pos.y) {
        z = (nor.t - (nor.x * (double)x) -
(nor.y * (double)y)) / ((nor.z == 0) ? 1 : nor.z);
        f.x = x;
        f.z = z;
//        printf("%f, %f\n", z, x / z);
/*        bary_a = (nor.bcy * (x - nor.c_point.x) +
        (nor.cbx * (y - nor.c_point.y))) * nor.div;
        bary_b = (nor.cay * (x - nor.c_point.x) +
        (nor.acx * (y - nor.c_point.y))) * nor.div;
        bary_c = 1.0 - bary_a - bary_b;
        u = (bary_a * nor.a_uv.x + bary_b * nor.b_uv.x + bary_c * nor.c_uv.x);
        v = (bary_a * nor.a_uv.y + bary_b * nor.b_uv.y + bary_c * nor.c_uv.y);
*/
        //printf("%f, %f, %f\n", nor.su.x, nor.su.y, nor.su.z);
        bary_a = magnitude(normal_vec(f, nor.su, nor.sv)) * nor.div;
        bary_b = magnitude(normal_vec(f, nor.sv, nor.sz)) * nor.div;
        bary_c = magnitude(normal_vec(f, nor.sz, nor.su)) * nor.div;
        //printf("%f, %f, %f\n", bary_a, bary_b, bary_c);

        u = (bary_a * nor.a_uv.x + bary_b * nor.b_uv.x + bary_c * nor.c_uv.x);
        v = (bary_a * nor.a_uv.y + bary_b * nor.b_uv.y + bary_c * nor.c_uv.y);
        //printf("u = %f, v = %f\n", u, v);
/*
        iz = (1 / nor.sz.z) * bary_a + (1 / nor.su.z) * bary_b +
        (1 / nor.sv.z) * bary_c;
        u = (nor.sz.x / nor.sv.z) * bary_a + (nor.su.x / nor.sv.z) * bary_b +
        (nor.sv.x / nor.sv.z) * bary_c;
        v = (nor.sz.y / nor.sv.z) * bary_a + (nor.su.y / nor.sv.z) * bary_b +
        (nor.sv.y / nor.sv.z) * bary_c;
*/
//        iz = 1.0 / (nor.sz.z + nor.sz.y * (x) + nor.sz.x * (y));
//        u = (nor.su.z + nor.su.y * (x) + nor.su.x * (y));
//        v = (nor.sv.z + nor.sv.y * (x) + nor.sv.x * (y));
//        if (u < lim.x && u >= 0 && v >= 0 && v < lim.y) {
            color = sfImage_getPixel(game->img[game->map->ptr_tri->texture],
            (int)(u) % lim.x, (int)(v) % lim.y);
//        }
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
