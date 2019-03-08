/*
** EPITECH PROJECT, 2018
** src/triangle
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    sort_pos_triangle(sfVector3f *pos)
{
    sfVector3f tmp;

    if (pos[0].y > pos[1].y) {
        tmp = pos[0];
        pos[0] = pos[1];
        pos[1] = tmp;
    }
    if (pos[1].y > pos[2].y) {
        tmp = pos[1];
        pos[1] = pos[2];
        pos[2] = tmp;
    }
    if (pos[0].y > pos[1].y) {
        tmp = pos[0];
        pos[0] = pos[1];
        pos[1] = tmp;
    }
}

void    set_coordinates(sfVector2f *arr, sfVector3f *pos)
{
    arr[0].x = pos[0].x;
    arr[0].y = pos[0].y;
    arr[1].x = pos[1].x;
    arr[1].y = pos[1].y;
    arr[2].x = pos[2].x;
    arr[2].y = pos[2].y;
    arr[3] = arr[0];
    arr[4] = arr[0];
    pos[3].x = ((arr[1].y - arr[0].y) > 0) ?
        (arr[1].x - arr[0].x) / (arr[1].y - arr[0].y) : 0;
    pos[3].y = ((arr[2].y - arr[0].y) > 0) ?
        (arr[2].x - arr[0].x) / (arr[2].y - arr[0].y) : 0;
    pos[3].z = ((arr[2].y - arr[1].y) > 0) ?
        (arr[2].x - arr[1].x) / (arr[2].y - arr[1].y) : 0;
}

vector4f_t      calc_normal(sfVector3f *pos)
{
    sfVector3f v1 = {pos[1].x - pos[0].x, pos[1].y -
pos[0].y, pos[1].z - pos[0].z};
    sfVector3f v2 = {pos[1].x - pos[2].x, pos[1].y -
pos[2].y, pos[1].z - pos[2].z};
    vector4f_t nor = {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z,
v1.x * v2.y - v1.y * v2.x, 0};

    nor.t = -(-(nor.x * pos[1].x) - nor.y * pos[1].y - nor.z * pos[1].z);
    return (nor);
}

void    triangle_filler(sfVector3f *pos, sfVector2f *arr, sfColor color,
my_game_t *game)
{
    vector4f_t  nor = calc_normal(pos);

    if (pos[3].x > pos[3].y) {
        for (; arr[4].y <= arr[1].y; arr[4].y++, arr[3].y++,
arr[4].x += pos[3].y, arr[3].x += pos[3].x)
            horz_line(game, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, nor,
color);
        arr[3] = arr[1];
        for (; arr[4].y <= arr[2].y; arr[4].y++, arr[3].y++,
arr[4].x += pos[3].y, arr[3].x += pos[3].z)
            horz_line(game, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, nor,
color);
    }
    else {
        for (; arr[4].y <= arr[1].y; arr[4].y++, arr[3].y++,
arr[4].x += pos[3].x, arr[3].x += pos[3].y)
            horz_line(game, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, nor,
color);
        arr[4] = arr[1];
        for (; arr[4].y <= arr[2].y; arr[4].y++, arr[3].y++,
arr[4].x += pos[3].z, arr[3].x += pos[3].y)
            horz_line(game, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, nor,
color);
    }
}

void    draw_triangle(my_game_t *game, sfVector3f *pos, sfColor color)
{
    sfVector3f cp_pos[] = {pos[0], pos[1], pos[2], pos[0]};
    sfVector2f arr[5];

    if (cp_pos[0].y == cp_pos[2].y || cp_pos[1].y == cp_pos[2].y)
        cp_pos[2].y += 0.01;
    if (cp_pos[0].y == cp_pos[1].y)
        cp_pos[1].y += 0.01;
    sort_pos_triangle(cp_pos);
    set_coordinates(arr, cp_pos);
    triangle_filler(cp_pos, arr, color, game);
}
