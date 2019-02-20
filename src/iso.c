/*
** EPITECH PROJECT, 2018
** src/iso
** File description:
** vim > emacs
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "math.h"

sfVector2f      project_iso_point(double x, double y, double z, int f,
float roll, float yaw, float pitch, int hh, int ww, int dis)
{
    sfVector2f pos = {0, 0};
    float tab[] = {roll * M_PI / 180, yaw * M_PI / 180, pitch * M_PI / 180};
    double xx = x;
    double yy = y;

    z = z / 6;
    yy = (cos(tab[0]) * y) - (sin(tab[0]) * z);
    z = (sin(tab[0]) * y) + (cos(tab[0]) * z);

    xx = (cos(tab[1]) * x) + (sin(tab[1]) * z);
    z = -(sin(tab[1]) * x) + (cos(tab[1]) * z);

    x = (cos(tab[2]) * xx) - (sin(tab[2]) * yy);
    y = (sin(tab[2]) * xx) + (cos(tab[2]) * yy);

    pos.x = ww + ((x * f * 20) / (z + dis));
    pos.y = hh + ((y * f * 20) / (z + dis));
    return (pos);
}

void            create_2d_map(map_t *map)
{
    int         i = 0;
    int         j = 0;

    if (!(map->map_3d))
        return ;
    if (!(map->map_2d = malloc(sizeof(sfVector2f*) * map->tab_size_y)))
        return ;
    while (i < map->tab_size_y) {
        if (!((map->map_2d)[i] = malloc(sizeof(sfVector2f) * map->tab_size_x)))
            return ;
        j = 0;
        while (j < map->tab_size_x) {
            (map->map_2d)[i][j] = project_iso_point((double)i - map->tab_size_x
/ 2.0 + ((!(map->tab_size_x % 2)) ? 0.5 : 0), (double)j - map->tab_size_y / 2.0
+ ((!(map->tab_size_y % 2)) ? 0.5 : 0), (double)map->map_3d[i][j], 128,
map->roll, map->yaw, map->pitch, map->center_x, map->center_y, map->zoom);
            j++;
        }
        i++;
    }
}
