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
    float sr = sin(map->roll_fg * M_PI / 180);
    float cr = cos(map->roll_fg * M_PI / 180);
    float sy = sin(map->yaw_fg * M_PI / 180);
    float cy = cos(map->yaw_fg * M_PI / 180);
    float sp = sin(map->pitch_fg * M_PI / 180);
    float cp = cos(map->pitch_fg * M_PI / 180);
    double tmp;

    while (i < (map->tab_size_x + 1) * (map->tab_size_y + 1)) {
        tmp = map->map_3d[i].z;
        map->map_3d[i].z = (sr * map->map_3d[i].y) + (cr * tmp);
        map->map_3d[i].y = (cr * map->map_3d[i].y) - (sr * tmp);
        tmp = map->map_3d[i].x;
        map->map_3d[i].x = (cy * tmp) + (sy * map->map_3d[i].z);
        map->map_3d[i].z = -(sy * tmp) + (cy * map->map_3d[i].z);
        tmp = map->map_3d[i].x;
        map->map_3d[i].x = (cp * tmp) - (sp * map->map_3d[i].y);
        map->map_3d[i].y = (sp * tmp) + (cp * map->map_3d[i].y);
        i++;
    }
}

void    to_2d(my_game_t *game)
{
    int     i = 0;
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect;

    while (i < (game->map->tab_size_x + 1) * (game->map->tab_size_y + 1)) {
        prospect = (game->map->map_3d[i].z + game->map->zoom == 0) ? 1 : 1.0 /
(game->map->map_3d[i].z + game->map->zoom);
        game->map->map_2d[i].x = (game->map->map_3d[i].x * prospect) *
(width_d2) * (height_width) + (width_d2);
        game->map->map_2d[i].y = (-(game->map->map_3d[i].y) * prospect + 1) *
(height_d2);
        game->map->map_2d[i].z = game->map->map_3d[i].z + game->map->zoom;
        i++;
    }
}
