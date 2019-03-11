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

static void    rotation_cond(map_t *map)
{
    int i = 0;
    float sr = sin(map->roll_fg * M_PI / 180);
    float cr = cos(map->roll_fg * M_PI / 180);
    float sy = sin(map->yaw_fg * M_PI / 180);
    float cy = cos(map->yaw_fg * M_PI / 180);
    float sp = sin(map->pitch_fg * M_PI / 180);
    float cp = cos(map->pitch_fg * M_PI / 180);
    double tmp;

    while (i < map->obj->nb_point) {
        tmp = map->obj->point_3d[i].z;
        map->obj->point_3d[i].z = (sr * map->obj->point_3d[i].y) + (cr * tmp);
        map->obj->point_3d[i].y = (cr * map->obj->point_3d[i].y) - (sr * tmp);
        tmp = map->obj->point_3d[i].x;
        map->obj->point_3d[i].x = (cy * tmp) + (sy * map->obj->point_3d[i].z);
        map->obj->point_3d[i].z = -(sy * tmp) + (cy * map->obj->point_3d[i].z);
        tmp = map->obj->point_3d[i].x;
        map->obj->point_3d[i].x = (cp * tmp) - (sp * map->obj->point_3d[i].y);
        map->obj->point_3d[i].y = (sp * tmp) + (cp * map->obj->point_3d[i].y);
        i++;
    }
}

void    rotation(map_t *map)
{
    if (map->roll_fg == 0 && map->yaw_fg == 0 && map->pitch_fg == 0)
        return ;
    rotation_cond(map);
}

void    to_2d(my_game_t *game)
{
    int     i = 0;
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect;

    while (i < game->map->obj->nb_point) {
        prospect = (game->map->obj->point_3d[i].z + game->map->zoom == 0) ?
1 : 1.0 / (game->map->obj->point_3d[i].z + game->map->zoom);
        game->map->obj->point_2d[i].x = (game->map->obj->point_3d[i].x *
prospect) * (width_d2) * (height_width) + (width_d2);
        game->map->obj->point_2d[i].y = (-(game->map->obj->point_3d[i].y)
* prospect + 1) * (height_d2);
        game->map->obj->point_2d[i].z = game->map->obj->point_3d[i].z +
game->map->zoom;
        i++;
    }
}
