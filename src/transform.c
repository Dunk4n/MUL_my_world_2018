/*
** EPITECH PROJECT, 2018
** src/transform
** File description:
** vim > emacs
*/

#include "world.h"

void    transform_move_point(my_game_t *game, sfVector3f *point)
{
    point->x += game->map->move_point_x;
    point->y += game->map->move_point_y;
}

void    transform_move(my_game_t *game)
{
    int i = 0;

    while (i < game->map->tab_size_x * 2 * game->map->tab_size_y) {
        game->map->triangle[i].point_3d[0]->x += game->map->move_point_x;
        game->map->triangle[i].point_3d[0]->y += game->map->move_point_y;
        game->map->triangle[i].point_3d[1]->x += game->map->move_point_x;
        game->map->triangle[i].point_3d[1]->y += game->map->move_point_y;
        game->map->triangle[i].point_3d[2]->x += game->map->move_point_x;
        game->map->triangle[i].point_3d[2]->y += game->map->move_point_y;
        i++;
    }
}
