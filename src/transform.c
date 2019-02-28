/*
** EPITECH PROJECT, 2018
** src/transform
** File description:
** vim > emacs
*/

#include "world.h"

void    transform_move(map_t *map)
{
    int i = 0;

    while (i < map->tab_size_x * map->tab_size_y) {
        map->map_3d[i].x += map->move_point_x;
        map->map_3d[i].y += map->move_point_y;
        i++;
    }
}

void    transform_to_2d(map_t *map)
{
    int i = 0;
    int j = 0;
    float per;

    while (map->triangle[i]) {
        j = 0;
        while (j < 3) {
            per = (map->triangle[i]->space[j].z == 0) ? 1 :
1.0 / (map->triangle[i]->space[j].z + 2);
            map->triangle[i]->plane[j].x =
(map->triangle[i]->plane[j].x * per + 1) * (WM / 2);
            map->triangle[i]->plane[j].y =
(-map->triangle[i]->plane[j].y * per + 1) * (WM / 2);
            map->triangle[i]->plane[j].z = map->triangle[i]->space[j].z;
            j++;
        }
        i++;
    }
}
