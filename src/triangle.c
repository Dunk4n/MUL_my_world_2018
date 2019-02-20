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

void    draw_triangle(my_framebuff_t *buff, sfVector2f *pos, sfColor color)
{
    sort_pos_triangle(pos);
    double dx1 = (pos[1].y - pos[0].y > 0) ?
(pos[1].x - pos[0].x) / (pos[1].y - pos[0].y) : 0;
    double dx2 = (pos[2].y - pos[0].y > 0) ?
(pos[2].x - pos[0].x) / (pos[2].y - pos[0].y) : 0;
    double dx3 = (pos[2].y - pos[0].y > 0) ?
(pos[1].x - pos[0].x) / (pos[1].y - pos[0].y) : 0;
    sfVector2f S = pos[0];
    sfVector2f E = pos[0];


}
