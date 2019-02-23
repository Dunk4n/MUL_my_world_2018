/*
** EPITECH PROJECT, 2018
** src/triangle
** File description:
** don't forget to free at the end
*/

#include "world.h"

void    sort_pos_triangle(sfVector2f *pos)
{
    sfVector2f tmp;

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

void    set_coordinates(sfVector2f *arr, double *dx, sfVector2f *pos)
{
    arr[0] = pos[0];
    arr[1] = pos[1];
    arr[2] = pos[2];
    arr[3] = arr[0];
    arr[4] = arr[0];
    dx[0] = ((arr[1].y - arr[0].y) > 0) ?
        (arr[1].x - arr[0].x) / (arr[1].y - arr[0].y) : 0;
    dx[1] = ((arr[2].y - arr[0].y) > 0) ?
        (arr[2].x - arr[0].x) / (arr[2].y - arr[0].y) : 0;
    dx[2] = ((arr[2].y - arr[1].y) > 0) ?
        (arr[2].x - arr[1].x) / (arr[2].y - arr[1].y) : 0;
}

void    draw_triangle(my_framebuff_t *buff, sfVector2f *pos, sfColor color)
{
    sfVector2f arr[5];
    double dx[3];

    sort_pos_triangle(pos);
    set_coordinates(arr, dx, pos);
    if (dx[0] > dx[1]) {
        for (; arr[4].y <= arr[1].y; arr[4].y++, arr[3].y++, arr[4].x+=dx[1], arr[3].x+=dx[0])
            draw_line_horizontal(buff, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, color);
        arr[3] = arr[1];
        for(; arr[4].y<=arr[2].y; arr[4].y++, arr[3].y++, arr[4].x+=dx[1], arr[3].x+=dx[2])
            draw_line_horizontal(buff, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, color);
    } else {
        for(; arr[4].y<=arr[1].y; arr[4].y++, arr[3].y++, arr[4].x+=dx[0], arr[3].x+=dx[1])
            draw_line_horizontal(buff, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, color);
        arr[4] = arr[1];
        for(; arr[4].y<=arr[2].y; arr[4].y++, arr[3].y++, arr[4].x+=dx[2], arr[3].x+=dx[1])
            draw_line_horizontal(buff, (sfVector3f){arr[4].x, arr[3].x, arr[4].y}, color);
    }
}
