/*
** EPITECH PROJECT, 2018
** src/display
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include "world.h"

double glob;
triangle_t *fraude;

sfVector3f      normal_vec(sfVector3f a, sfVector3f b, sfVector3f c)
{
    sfVector3f ab = {b.x - a.x, b.y - a.y, b.z - a.z};
    sfVector3f ac = {c.x - a.x, c.y - a.y, c.z - a.z};

    return ((sfVector3f){ab.y * ac.z - ab.z * ac.y,
                         ab.z * ac.x - ab.z * ac.z,
                         ab.x * ac.y - ab.y * ac.x});
}

int     is_drawable(triangle_t *tri)
{
    if (tri->point_2d[0]->z < 0 || tri->point_2d[1]->z < 0 || tri->point_2d[2]->z
< 0 || ((tri->point_2d[0]->x < 0 || tri->point_2d[0]->x >= WM) &&
(tri->point_2d[0]->y < 0 || tri->point_2d[0]->y >= HM) && (tri->point_2d[1]->x < 0
|| tri->point_2d[1]->x >= WM) && (tri->point_2d[1]->y < 0 || tri->point_2d[1]->y >=
HM) && (tri->point_2d[2]->x < 0 || tri->point_2d[2]->x >= WM) &&
(tri->point_2d[2]->y < 0 || tri->point_2d[2]->y >= HM)))
        return (0);
    return (1);
}

static void     display_triangle_in_map(my_game_t *game, triangle_t *tri)
{
    double res;
    sfVector3f pos[3] = {*(tri->point_2d[0]), *(tri->point_2d[1]),
*(tri->point_2d[2])};
    sfVector3f normal = normal_vec(*(tri->point_3d[0]), *(tri->point_3d[1]),
*(tri->point_3d[2]));

    res = normal.z;
    if (res < 0)
        res *= -1;
    glob = res;
    fraude = tri;
    draw_triangle(game, pos, tri->color);
}

/*void    condition_line(my_game_t *game, int i, int j)
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
}*/

void    display(my_game_t *game)
{
    int i = 0;

    while (i < game->map->tab_size_x * 2 * game->map->tab_size_y) {
        if (is_drawable(&(game->map->triangle[i])))
            display_triangle_in_map(game, &(game->map->triangle[i]));
        i++;
    }
}
