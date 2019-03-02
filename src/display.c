/*
** EPITECH PROJECT, 2018
** src/display
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include "world.h"

void    display_triangle_in_map(my_game_t *game, int i, int j)
{
    sfVector3f pos[] = {game->map->map_2d[i * game->map->tab_size_x + j],
game->map->map_2d[i * game->map->tab_size_x + j + 1],
game->map->map_2d[(i + 1) * game->map->tab_size_x + j]};

    draw_triangle(game->win, pos, sfGreen);
    pos[0] = game->map->map_2d[(i + 1) * game->map->tab_size_x + j + 1];
    draw_triangle(game->win, pos, sfBlue);
}

void    condition_line(my_game_t *game, int i, int j)
{
    sfVector2f pos[2] = {{game->map->map_2d[i * game->map->tab_size_x + j].x,
game->map->map_2d[i * game->map->tab_size_x + j].y}, {0, 0}};

    if (j + 1 < game->map->tab_size_y && i + 1 < game->map->tab_size_x)
        display_triangle_in_map(game, i, j);
    return ;
    if (j + 1 < game->map->tab_size_y && ((pos[0].x >= 0 && pos[0].x < WM &&
pos[0].y >= 0 && pos[0].y <= HM) ||
(game->map->map_2d[i * game->map->tab_size_x + j + 1].x >= 0 &&
(game->map->map_2d[i * game->map->tab_size_x + j + 1].x < WM &&
game->map->map_2d[i * game->map->tab_size_x + j + 1].y >= 0) &&
game->map->map_2d[i * game->map->tab_size_x + j + 1].y < HM)) &&
((game->map->map_2d[i * game->map->tab_size_x + j].z > 0) +
(game->map->map_2d[i * game->map->tab_size_x + j + 1].z > 0) == 2)) {
        pos[1].x = game->map->map_2d[i * game->map->tab_size_x + j + 1].x;
        pos[1].y = game->map->map_2d[i * game->map->tab_size_x + j + 1].y;
        draw_line(game->win->framebuff, pos, 1, sfWhite);
    }
    if (i + 1 < game->map->tab_size_x && ((pos[0].x >= 0 && pos[0].x < WM &&
pos[0].y >= 0 && pos[0].y < HM) ||
(game->map->map_2d[(i + 1) * game->map->tab_size_x + j].x >= 0 &&
(game->map->map_2d[(i + 1) * game->map->tab_size_x + j].x < WM &&
game->map->map_2d[(i + 1) * game->map->tab_size_x + j].y >= 0) &&
game->map->map_2d[(i + 1) * game->map->tab_size_x + j].y < HM)) &&
((game->map->map_2d[i * game->map->tab_size_x + j].z > 0) +
(game->map->map_2d[(i + 1) * game->map->tab_size_x + j].z > 0) == 2)) {
        pos[1].x = game->map->map_2d[(i + 1) * game->map->tab_size_x + j].x;
        pos[1].y = game->map->map_2d[(i + 1) * game->map->tab_size_x + j].y;
        draw_line(game->win->framebuff, pos, 1, sfWhite);
    }
}

void    display(my_game_t *game)
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
