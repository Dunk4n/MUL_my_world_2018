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
    sfVector2f A = pos[0];
    sfVector2f B = pos[1];
    sfVector2f C = pos[2];
    sfVector2f E = A;
    sfVector2f S = A;
    double dx1;
    double dx2;
    double dx3;

    sort_pos_triangle(pos);
    dx1 = ((B.y - A.y) > 0) ? (B.x - A.x) / (B.y - A.y) : 0;
    dx2 = ((C.y - A.y) > 0) ? (C.x - A.x) / (C.y - A.y) : 0;
    dx3 = ((C.y - B.y) > 0) ? (C.x - B.x) / (C.y - B.y) : 0;

    if (dx1 > dx2) {
        for (; S.y <= B.y; S.y++, E.y++, S.x+=dx2, E.x+=dx1)
            draw_line(buff, S.x,E.x,S.y, color);
        E = B;
        for(; S.y<=C.y; S.y++, E.y++, S.x+=dx2, E.x+=dx3)
            draw_line(buff, S.x,E.x,S.y, color);
    } else {
        for(; S.y<=B.y; S.y++, E.y++, S.x+=dx1, E.x+=dx2)
            draw_line(buff, S.x,E.x,S.y, color);
        S = B;
        for(; S.y<=C.y; S.y++, E.y++, S.x+=dx3, E.x+=dx2)
            draw_line(buff, S.x,E.x,S.y, color);
    }
}
