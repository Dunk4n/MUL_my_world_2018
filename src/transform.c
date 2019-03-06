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

    while (i < (game->map->tab_size_x + 1) * (game->map->tab_size_y + 1)) {
        game->map->map_3d[i].x += game->map->move_point_x;
        game->map->map_3d[i].y += game->map->move_point_y;
        i++;
    }
}
