/*
** EPITECH PROJECT, 2018
** src/display
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include "world.h"

void    display(my_game_t *game)
{
    sfColor color[] = {sfGreen, sfRed, sfYellow, sfBlue, sfMagenta, sfCyan};
    int i = 0;

    while ((game->map->triangle)[i] != NULL) {
        //draw_triangle(game->win, (game->map->triangle)[i], color[i % 6]);
        i++;
    }
}
