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

    if (game->map->move_point_x == 0 && game->map->move_point_y == 0 &&
game->map->move_point_z == 0)
        return ;
    while (i < game->map->obj->nb_point) {
        game->map->obj->point_3d[i].x += game->map->move_point_x;
        game->map->obj->point_3d[i].y += game->map->move_point_y;
        game->map->obj->point_3d[i].z += game->map->move_point_z;
        i++;
    }
}

void    transform_lower(my_game_t *game)
{
    int i = 0;

    if (game->map->enlargement == 1)
        return ;
    while (i < game->map->obj->nb_point) {
        game->map->obj->point_3d[i].x *= game->map->enlargement;
        game->map->obj->point_3d[i].y *= game->map->enlargement;
        game->map->obj->point_3d[i].z *= game->map->enlargement;
        i++;
    }
}
