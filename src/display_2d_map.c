/*
** EPITECH PROJECT, 2018
** display_2d_map
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "math.h"

void    display_2d_map(my_game_t *game)
{
    sfVector2f pos[2];
    int i = 0;
    int j = 0;

    while (i < game->map->tab_size_x) {
        j = 0;
        while (j < game->map->tab_size_y && (j + 1 < game->map->tab_size_y ||
i + 1 < game->map->tab_size_x)) {
            pos[0] = game->map->map_2d[i][j];
            if (j + 1 < game->map->tab_size_y) {
                pos[1] = game->map->map_2d[i][j + 1];
                draw_line(game->win->framebuff, pos, 3, sfWhite);
            }
            if (i + 1 < game->map->tab_size_x) {
                pos[1] = game->map->map_2d[i + 1][j];
                draw_line(game->win->framebuff, pos, 3, sfWhite);
            }
            j++;
        }
        i++;
    }
}
