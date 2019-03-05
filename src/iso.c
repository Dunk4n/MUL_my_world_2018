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

void    rotation_one_point(my_game_t *game)
{
    float sr = sin(game->map->roll_fg * M_PI / 180);
    float cr = cos(game->map->roll_fg * M_PI / 180);
    float sy = sin(game->map->yaw_fg * M_PI / 180);
    float cy = cos(game->map->yaw_fg * M_PI / 180);
    float sp = sin(game->map->pitch_fg * M_PI / 180);
    float cp = cos(game->map->pitch_fg * M_PI / 180);
    double tmp;

    tmp = game->map->sun.z;
    game->map->sun.z = (sr * game->map->sun.y) + (cr * tmp);
    game->map->sun.y = (cr * game->map->sun.y) - (sr * tmp);
    tmp = game->map->sun.x;
    game->map->sun.x = (cy * tmp) + (sy * game->map->sun.z);
    game->map->sun.z = -(sy * tmp) + (cy * game->map->sun.z);
    tmp = game->map->sun.x;
    game->map->sun.x = (cp * tmp) - (sp * game->map->sun.y);
    game->map->sun.y = (sp * tmp) + (cp * game->map->sun.y);
}

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

    while (i < map->tab_size_x * map->tab_size_y) {
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

void    to_2d_point(my_game_t *game)
{
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect = (game->map->sun.z + game->map->zoom == 0) ? 1 : 1.0 /
(game->map->sun.z + game->map->zoom);

    game->map->sun_2d.x = (game->map->sun.x * prospect) *
(width_d2) * (height_width) + (width_d2);
    game->map->sun_2d.y = (-(game->map->sun.y) * prospect + 1) *
(height_d2);
    game->map->sun_2d.z = game->map->sun.z + game->map->zoom;
}

void    to_2d(my_game_t *game)
{
    int     i = 0;
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect;

    to_2d_point(game);
    while (i < game->map->tab_size_x * game->map->tab_size_y) {
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
