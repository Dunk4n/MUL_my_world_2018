/*
** EPITECH PROJECT, 2018
** src/transform
** File description:
** vim > emacs
*/

#include "world.h"

void    transform_move_point(my_game_t *game)
{
    game->map->sun.x += game->map->move_point_x;
    game->map->sun.y += game->map->move_point_y;
}

void    transform_move(my_game_t *game)
{
    int i = 0;

    transform_move_point(game);
    while (i < game->map->tab_size_x * game->map->tab_size_y) {
        game->map->map_3d[i].x += game->map->move_point_x;
        game->map->map_3d[i].y += game->map->move_point_y;
        i++;
    }
}
