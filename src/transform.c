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
