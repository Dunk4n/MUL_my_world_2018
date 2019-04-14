/*
** EPITECH PROJECT, 2018
** src/action_on_obj
** File description:
** code on paper!
*/

#include <math.h>
#include "world.h"

sfVector3f      *get_nearest_point(my_game_t *game, triangle_t *tri)
{
    int i = 1;
    int j = 0;
    double tmp;
    double res = pow(game->win->event.mouseButton.y - tri->point_2d[0]->y, 2) +
pow(game->win->event.mouseButton.x - tri->point_2d[0]->x, 2);

    while (i < 3) {
        tmp = pow(game->win->event.mouseButton.y - tri->point_2d[i]->y, 2) +
            pow(game->win->event.mouseButton.x - tri->point_2d[i]->x, 2);
        if (tmp < res) {
            j = i;
            res = tmp;
        }
        i++;
    }
    return (tri->point_3d[j]);
}

void    action_on_obj(my_game_t *game)
{
    triangle_t *tri;

    game->select = NULL;
    if (game->win->t_buff[WM * game->win->event.mouseButton.y +
game->win->event.mouseButton.x] == NULL)
        return ;
    tri = game->win->t_buff[WM * game->win->event.mouseButton.y +
game->win->event.mouseButton.x];
    if (game->point_or_face_fg == 2) {
        game->select_obj = tri->obj;
        return ;
    }
    if (game->point_or_face_fg == 0) {
        game->select = get_nearest_point(game, tri);
        return ;
    }
    game->map->update = 1;
    if (game->t_or_c_fg == 0) {
        tri->texture = -1;
        tri->color = color[game->tex_col_fg];
    }
    else
        tri->texture = game->tex_col_fg;
}
