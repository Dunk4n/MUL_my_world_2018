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

void    display_triangle_in_map(my_game_t *game, int i, int j)
{
    sfVector2f pos[3] = {game->map->map_2d[i][j], game->map->map_2d[i + 1][j],
game->map->map_2d[i + 1][j + 1]};
    sfColor color[] = {sfGreen, sfRed, sfYellow, sfBlue};

    if (pos[0].x != -1 && pos[1].x != -1 && pos[2].x != -1)
        draw_triangle(game->win->framebuff, pos, color[(i + j) % 4]);
    pos[1] = game->map->map_2d[i][j + 1];
    if (pos[0].x != -1 && pos[1].x != -1 && pos[2].x != -1)
        draw_triangle(game->win->framebuff, pos, color[(i + j) % 4]);
}

void    condition_line(my_game_t *game, int i, int j)
{
    sfVector2f pos[2];

    if (j + 1 < game->map->tab_size_y && i + 1 < game->map->tab_size_x)
        display_triangle_in_map(game, i, j);
    pos[0] = game->map->map_2d[i][j];
    if (j + 1 < game->map->tab_size_y && pos[0].x != -1 &&
game->map->map_2d[i][j + 1].x != -1) {
        pos[1] = game->map->map_2d[i][j + 1];
        draw_line(game->win->framebuff, pos, 1, sfBlack);
    }
    if (i + 1 < game->map->tab_size_x && pos[0].x != -1 &&
game->map->map_2d[i + 1][j].x != -1) {
        pos[1] = game->map->map_2d[i + 1][j];
        draw_line(game->win->framebuff, pos, 1, sfBlack);
    }
}

void    display_2d_map(my_game_t *game)
{
    int i = 0;
    int j = 0;

    while (i < game->map->tab_size_x) {
        j = 0;
        while (j < game->map->tab_size_y && (j + 1 < game->map->tab_size_y ||
i + 1 < game->map->tab_size_x)) {
            condition_line(game, i, j);
            j++;
        }
        i++;
    }
}
