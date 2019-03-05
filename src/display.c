/*
** EPITECH PROJECT, 2018
** src/display
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include "world.h"

double glob;

sfVector3f      normal_vec(sfVector3f a, sfVector3f b, sfVector3f c)
{
    //printf("a = %f, %f, %f\n", a.x, a.y, a.z);
    //printf("b = %f, %f, %f\n", b.x, b.y, b.z);
    //printf("c = %f, %f, %f\n", c.x, c.y, c.z);
    sfVector3f ab = {b.x - a.x, b.y - a.y, b.z - a.z};
    sfVector3f ac = {c.x - a.x, c.y - a.y, c.z - a.z};

    return ((sfVector3f){ab.y * ac.z - ab.z * ac.y,
                         ab.z * ac.x - ab.z * ac.z,
                         ab.x * ac.y - ab.y * ac.x});
}

void    display_triangle_in_map(my_game_t *game, int i, int j)
{
    sfVector3f lum = {0, 0, 1};
    double res;
    sfVector3f normal;
    sfVector3f pos[] = {game->map->map_2d[i * game->map->tab_size_x + j],
game->map->map_2d[i * game->map->tab_size_x + j + 1],
game->map->map_2d[(i + 1) * game->map->tab_size_x + j]};

    if (((pos[0].x >= 0 && pos[0].x < WM && pos[0].y >= 0 && pos[0].y < HM) ||
(pos[1].x >= 0 && pos[1].x < WM && pos[1].y >= 0 && pos[1].y < HM) ||
(pos[2].x >= 0 && pos[2].x < WM && pos[2].y >= 0 && pos[2].y < HM)) &&
pos[0].z > 0 && pos[1].z > 0 && pos[1].z > 0) {
        normal = normal_vec(game->map->map_3d[i * game->map->tab_size_x + j],
                game->map->map_3d[i * game->map->tab_size_x + j + 1],
                game->map->map_3d[(i + 1) * game->map->tab_size_x + j]);
        res = lum.x * normal.x + lum.y * normal.y + lum.z * normal.z;
        if (res < 0)
            res *= -1;
        glob = res;
        //res = (5 / (game->map->map_3d[i * game->map->tab_size_x + j].z + game->map->zoom)) * res;
        //if (res > 1)
        //    res = 1;
        sfColor col = sfWhite;
        //col.r *= res;
        //col.g *= res;
        //col.b *= res;
        draw_triangle(game, pos, col);
    }
    pos[0] = game->map->map_2d[(i + 1) * game->map->tab_size_x + j + 1];
    if (((pos[0].x >= 0 && pos[0].x < WM && pos[0].y >= 0 && pos[0].y < HM) ||
(pos[1].x >= 0 && pos[1].x < WM && pos[1].y >= 0 && pos[1].y < HM) ||
(pos[2].x >= 0 && pos[2].x < WM && pos[2].y >= 0 && pos[2].y < HM)) &&
pos[0].z > 0 && pos[1].z > 0 && pos[1].z > 0) {
        normal = normal_vec(game->map->map_3d[(i + 1) * game->map->tab_size_x + j + 1],
                game->map->map_3d[i * game->map->tab_size_x + j + 1],
                game->map->map_3d[(i + 1) * game->map->tab_size_x + j]);
        res = lum.x * normal.x + lum.y * normal.y + lum.z * normal.z;
        if (res < 0)
            res *= -1;
        glob = res;
        //res = (5 / (game->map->map_3d[i * game->map->tab_size_x + j].z + game->map->zoom)) * res;
        //if (res > 1)
        //    res = 1;
        sfColor col = sfWhite;
        //col.r *= res;
        //col.g *= res;
        //col.b *= res;
        draw_triangle(game, pos, col);
    }
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
