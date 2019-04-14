/*
** EPITECH PROJECT, 2018
** src/transform
** File description:
** vim > emacs
*/

#include "world.h"

void    transform_move(my_game_t *game, obj_t *obj)
{
    int i;

    if (!obj)
        return ;
    if (game->map->move_point_x == 0 && game->map->move_point_y == 0 &&
game->map->move_point_z == 0)
        return ;
    i = 0;
    while (i < obj->nb_point) {
        obj->point_3d[i].x += game->map->move_point_x;
        obj->point_3d[i].y += game->map->move_point_y;
        obj->point_3d[i].z += game->map->move_point_z;
        i++;
    }
}

void    transform_lower(my_game_t *game, obj_t *obj)
{
    int i = 0;

    if (!obj)
        return ;
    if (game->map->enlargement == 1)
        return ;
    while (i < obj->nb_point) {
        obj->point_3d[i].x *= game->map->enlargement;
        obj->point_3d[i].y *= game->map->enlargement;
        obj->point_3d[i].z *= game->map->enlargement;
        i++;
    }
}
