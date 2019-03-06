/*
** EPITECH PROJECT, 2018
** set_3d_map
** File description:
** no, real programmers use cat
*/

#include <stdlib.h>
#include "world.h"

static triangle_t      make_triangle(map_t *map, int x, int y, int k)
{
    triangle_t tri;

    tri.point_3d[0].x = ((double)(x) - (double)(map->tab_size_x) / 2.0) +
((map->tab_size_x % 2) ? 0 : 0.5) / map->zoom;
    tri.point_3d[0].y = ((double)(y) - (double)(map->tab_size_y) / 2.0) +
((map->tab_size_y % 2) ? 0 : 0.5) / map->zoom;
    tri.point_3d[0].z = 0;
        tri.point_3d[1].x = (k == 0) ? tri.point_3d[0].x : ((double)(x + 1) -
(double)(map->tab_size_x) / 2.0) + ((map->tab_size_x % 2) ? 0 : 0.5) /
map->zoom;
        tri.point_3d[1].y = (k == 0) ? ((double)(y + 1) -
(double)(map->tab_size_y) / 2.0) + ((map->tab_size_y % 2) ? 0 : 0.5) /
map->zoom : tri.point_3d[0].y;
    tri.point_3d[1].z = 0;
    tri.point_3d[2].x = ((double)(x + 1) - (double)(map->tab_size_x) / 2.0)
+ ((map->tab_size_x % 2) ? 0 : 0.5) / map->zoom;
    tri.point_3d[2].y = ((double)(y + 1) - (double)(map->tab_size_y) /
2.0) + ((map->tab_size_y % 2) ? 0 : 0.5) / map->zoom;
    tri.point_3d[2].z = 0;
    return (tri);
}

static void    make_square(map_t *map, int x, int y, int k)
{
    map->triangle[k] = make_triangle(map, x, y, 0);
    map->triangle[k + 1] = make_triangle(map, x, y, 1);
}

static void    set_white_map(map_t **map)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < (*map)->tab_size_y) {
        j = 0;
        while (j < (*map)->tab_size_x) {
            make_square(*map, j, i, k);
            j++;
            k += 2;
        }
        i++;
    }
}

void    set_3d_map(map_t **map, char *str)
{
    if (!str) {
        if (!((*map)->triangle = malloc(sizeof(triangle_t) * ((*map)->tab_size_x * 2 * (*map)->tab_size_x))))
            return ;
        set_white_map(map);
        return ;
    }
}
