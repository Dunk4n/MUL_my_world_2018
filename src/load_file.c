/*
** EPITECH PROJECT, 2018
** src/load_file
** File description:
** fireplace 4k
*/

#include <stdlib.h> /* for free */
#include "world.h"

void    load_file(my_game_t *game)
{
    if (game->obj) {
        (game->map->obj->point_3d) ? free(game->map->obj->point_3d) : 0;
        (game->map->obj->point_2d) ? free(game->map->obj->point_2d) : 0;
        (game->map->obj->point_tx) ? free(game->map->obj->point_tx) : 0;
        (game->map->obj->triangle) ? free(game->map->obj->triangle) : 0;
        (game->map->obj) ? free(game->map->obj) : 0;
        game->obj = 0;
    }
    if (!(game->map->obj = open_file_obj(game->text)))
        game->obj = 0;
    else
        game->obj = 1;
    game->map->update = 1;
}
