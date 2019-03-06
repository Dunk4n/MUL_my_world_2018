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

void    rotation_one_point(my_game_t *game, triangle_t *tri)
{
    int j = 0;
    float sr = sin(game->map->roll_fg * M_PI / 180);
    float cr = cos(game->map->roll_fg * M_PI / 180);
    float sy = sin(game->map->yaw_fg * M_PI / 180);
    float cy = cos(game->map->yaw_fg * M_PI / 180);
    float sp = sin(game->map->pitch_fg * M_PI / 180);
    float cp = cos(game->map->pitch_fg * M_PI / 180);
    double tmp;

    while (j < 3) {
        tmp = tri->point_3d[j].z;
        tri->point_3d[j].z = (sr * tri->point_3d[j].y) + (cr * tmp);
        tri->point_3d[j].y = (cr * tri->point_3d[j].y) - (sr * tmp);
        tmp = tri->point_3d[j].x;
        tri->point_3d[j].x = (cy * tmp) + (sy * tri->point_3d[j].z);
        tri->point_3d[j].z = -(sy * tmp) + (cy * tri->point_3d[j].z);
        tmp = tri->point_3d[j].x;
        tri->point_3d[j].x = (cp * tmp) - (sp * tri->point_3d[j].y);
        tri->point_3d[j].y = (sp * tmp) + (cp * tri->point_3d[j].y);
        j++;
    }
}

void    rotation(map_t *map)
{
    int i = 0;
    int j = 0;
    float sr = sin(map->roll_fg * M_PI / 180);
    float cr = cos(map->roll_fg * M_PI / 180);
    float sy = sin(map->yaw_fg * M_PI / 180);
    float cy = cos(map->yaw_fg * M_PI / 180);
    float sp = sin(map->pitch_fg * M_PI / 180);
    float cp = cos(map->pitch_fg * M_PI / 180);
    double tmp;

    while (i < map->tab_size_x * 2 * map->tab_size_y) {
        j = 0;
        while (j < 3) {
            tmp = map->triangle[i].point_3d[j].z;
            map->triangle[i].point_3d[j].z =
(sr * map->triangle[i].point_3d[j].y) + (cr * tmp);
            map->triangle[i].point_3d[j].y =
(cr * map->triangle[i].point_3d[j].y) - (sr * tmp);
            tmp = map->triangle[i].point_3d[j].x;
            map->triangle[i].point_3d[j].x =
(cy * tmp) + (sy * map->triangle[i].point_3d[j].z);
            map->triangle[i].point_3d[j].z =
-(sy * tmp) + (cy * map->triangle[i].point_3d[j].z);
            tmp = map->triangle[i].point_3d[j].x;
            map->triangle[i].point_3d[j].x =
(cp * tmp) - (sp * map->triangle[i].point_3d[j].y);
            map->triangle[i].point_3d[j].y =
(sp * tmp) + (cp * map->triangle[i].point_3d[j].y);
        j++;
        }
        i++;
    }
}

void    to_2d_point(my_game_t *game, triangle_t *tri)
{
    int j = 0;
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect;

    while (j < 3) {
        prospect = (tri->point_3d[j].z + game->map->zoom == 0) ? 1 : 1.0 /
(tri->point_3d[j].z + game->map->zoom);
        tri->point_2d[j].x = (tri->point_3d[j].x * prospect) * (width_d2) *
(height_width) + (width_d2);
        tri->point_2d[j].y = (-(tri->point_3d[j].y) * prospect + 1) *
(height_d2);
        tri->point_2d[j].z = tri->point_3d[j].z + game->map->zoom;
        j++;
    }
}

void    to_2d(my_game_t *game)
{
    int     i = 0;
    int     j = 0;
    double  width_d2 = WM / 2;
    double  height_d2 = HM / 2;
    double  height_width = (double)HM / (double)WM;
    float   prospect;

    while (i < game->map->tab_size_x * 2 * game->map->tab_size_y) {
        j = -1;
        while (++j < 3) {
            prospect = (game->map->triangle[i].point_3d[j].z + game->map->zoom
== 0) ? 1 : 1.0 / (game->map->triangle[i].point_3d[j].z + game->map->zoom);
            game->map->triangle[i].point_2d[j].x = (game->map->triangle[i].
point_3d[j].x * prospect) * (width_d2) * (height_width) + (width_d2);
            game->map->triangle[i].point_2d[j].y =
(-(game->map->triangle[i].point_3d[j].y) * prospect + 1) * (height_d2);
            game->map->triangle[i].point_2d[j].z =
game->map->triangle[i].point_3d[j].z + game->map->zoom;
        }
        i++;
    }
}
