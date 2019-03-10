/*
** EPITECH PROJECT, 2018
** src/transform
** File description:
** vim > emacs
*/

#include "world.h"

void    transform_move(my_game_t *game)
{
    int i = 0;

    while (i < game->map->obj->nb_point) {
        game->map->obj->point_3d[i].x += game->map->move_point_x;
        game->map->obj->point_3d[i].y += game->map->move_point_y;
        i++;
    }
}
