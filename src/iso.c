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

sfVector2f      project_iso_point(double *cord, int *arg)
{
    sfVector2f pos = {-1, -1};
    double xx = cord[0];
    double yy = cord[1];

    cord[2] = cord[2] / 6;
    yy = (cos(cord[3]) * cord[1]) - (sin(cord[3]) * cord[2]);
    cord[2] = (sin(cord[3]) * cord[1]) + (cos(cord[3]) * cord[2]);

    xx = (cos(cord[4]) * cord[0]) + (sin(cord[4]) * cord[2]);
    cord[2] = -(sin(cord[4]) * cord[0]) + (cos(cord[4]) * cord[2]);

    cord[0] = (cos(cord[5]) * xx) - (sin(cord[5]) * yy);
    cord[1] = (sin(cord[5]) * xx) + (cos(cord[5]) * yy);

    if (-cord[2] <= arg[3] - 2) {
        pos.x = arg[1] + ((cord[0] * arg[0] * 20) / (cord[2] + arg[3]));
        pos.y = arg[2] + ((cord[1] * arg[0] * 20) / (cord[2] + arg[3]));
    }
    return (pos);
}

void    assign(map_t *map, double *cord, int i, int j)
{
    cord[0] = (double)i - map->tab_size_x
/ 2.0 + ((!(map->tab_size_x % 2)) ? 0.5 : 0);
    cord[1] = (double)j - map->tab_size_y / 2.0
+ ((!(map->tab_size_y % 2)) ? 0.5 : 0);
    cord[2] = (double)map->map_3d[i][j];
}

void            create_2d_map(map_t *map)
{
    int         i = 0;
    int         j = 0;
    double      cord[] = {0, 0, 0, map->roll * M_PI / 180, map->yaw * M_PI /
180, map->pitch * M_PI / 180};
    int         arg[] = {map->pixel, map->center_x, map->center_y, map->zoom};

    if (!(map->map_3d) ||
!(map->map_2d = malloc(sizeof(sfVector2f*) * map->tab_size_y)))
        return ;
    while (i < map->tab_size_y) {
        if (!((map->map_2d)[i] = malloc(sizeof(sfVector2f) * map->tab_size_x)))
            return ;
        j = 0;
        while (j < map->tab_size_x) {
            assign(map, cord, i, j);
            (map->map_2d)[i][j] = project_iso_point(cord, arg);
            j++;
        }
        i++;
    }
}
