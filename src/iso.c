/*
** EPITECH PROJECT, 2018
** src/iso
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

void    rotation(map_t *map)
{
    int i = 0;
    float sr = sin(map->roll * M_PI / 180);
    float cr = cos(map->roll * M_PI / 180);
    float sy = sin(map->yaw * M_PI / 180);
    float cy = cos(map->yaw * M_PI / 180);
    float sp = sin(map->pitch * M_PI / 180);
    float cp = cos(map->pitch * M_PI / 180);
    double tmp[2];

    while (i < map->tab_size_x * map->tab_size_y) {
        tmp[1] = map->map_3d[i].z;
        map->map_3d[i].z = (sr * map->map_3d[i].y) + (cr * tmp[1]);
        map->map_3d[i].y = (cr * map->map_3d[i].y) - (sr * tmp[1]);
        tmp[0] = map->map_3d[i].x;
        map->map_3d[i].x = (cy * tmp[0]) + (sy * map->map_3d[i].z);
        map->map_3d[i].z = -(sy * tmp[0]) + (cy * map->map_3d[i].z);
        tmp[0] = map->map_3d[i].x;
        map->map_3d[i].x = (cp * tmp[0]) - (sp * map->map_3d[i].y);
        map->map_3d[i].y = (sp * tmp[0]) + (cp * map->map_3d[i].y);
        i++;
    }
}

void    to_2d(map_t *map)
{
    int     i = 0;
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect;

    while (i < map->tab_size_x * map->tab_size_y) {
        prospect = (map->map_3d[i].z + map->zoom == 0) ? 1 : 1.0 /
(map->map_3d[i].z + map->zoom);
        map->map_2d[i].x = (map->map_3d[i].x * prospect) * (width_d2) *
(height_width) + (width_d2);
        map->map_2d[i].y = (-(map->map_3d[i].y) * prospect + 1) * (height_d2);
        map->map_2d[i].z = map->map_3d[i].z + map->zoom;
        i++;
    }
}
