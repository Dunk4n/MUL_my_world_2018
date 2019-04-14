/*
** EPITECH PROJECT, 2018
** src/load_file
** File description:
** fireplace 4k
*/

#include <stdlib.h>
#include "world.h"

void    load_more_file(my_game_t *game)
{
    int i = 0;
    obj_t **new;

    if (!(new = malloc(sizeof(obj_t*) * (game->obj + 1))))
        return ;
    while (i < game->obj) {
        new[i] = game->map->obj[i];
        i++;
    }
    new[i] = NULL;
    if (!(new[i] = open_file_obj(game->text))) {
        free(new);
        return ;
    }
    free(game->map->obj);
    game->map->obj = new;
    game->obj++;
}

void    load_file(my_game_t *game)
{
    if (!game->obj) {
        if (!(game->map->obj = malloc(sizeof(obj_t*) * (game->obj + 1))))
            return ;
        game->obj = 1;
        if (!(game->map->obj[0] = open_file_obj(game->text))) {
            free(game->map->obj);
            game->obj = 0;
        }
        game->select_obj = game->map->obj[0];
    }
    else
        load_more_file(game);
    clear_buff(game->win->framebuff);
    game->map->update = 1;
}
