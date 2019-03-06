/*
** EPITECH PROJECT, 2018
** set_3d_map
** File description:
** no, real programmers use cat
*/

#include <stdlib.h>
#include "world.h"

void    set_point_on_triangle(map_t *map, int i, int j, int k)
{
    map->triangle[k].point_3d[0] = &(map->map_3d[j * (map->tab_size_x + 1) + i]);
    map->triangle[k].point_3d[1] = &(map->map_3d[j * (map->tab_size_x + 1) + i + 1]);
    map->triangle[k].point_3d[2] = &(map->map_3d[(j + 1) * (map->tab_size_x + 1) + i]);
    map->triangle[k].point_2d[0] = &(map->map_2d[j * (map->tab_size_x + 1) + i]);
    map->triangle[k].point_2d[1] = &(map->map_2d[j * (map->tab_size_x + 1) + i + 1]);
    map->triangle[k].point_2d[2] = &(map->map_2d[(j + 1) * (map->tab_size_x + 1) + i]);
    map->triangle[k].color = sfWhite;
    map->triangle[k].square_part = &(map->triangle[k + 1]);
    //printf("init: %p\n", map->triangle[k].point_2d[0]);
    //printf("init: %p\n", map->triangle[k].point_2d[1]);
    //printf("init: %p\n\n", map->triangle[k].point_2d[2]);

    map->triangle[k + 1].point_3d[0] = &(map->map_3d[(j + 1) * (map->tab_size_x + 1) + i + 1]);
    map->triangle[k + 1].point_3d[1] = map->triangle[k].point_3d[1];
    map->triangle[k + 1].point_3d[2] = map->triangle[k].point_3d[2];
    //printf("init2: %f, %f, %f\n", map->triangle[k + 1].point_3d[0]->x, map->triangle[k + 1].point_3d[0]->y, map->triangle[k + 1].point_3d[0]->z);
    //printf("init2: %f, %f, %f\n", map->triangle[k + 1].point_3d[1]->x, map->triangle[k + 1].point_3d[1]->y, map->triangle[k + 1].point_3d[1]->z);
    //printf("init2: %f, %f, %f\n\n", map->triangle[k + 1].point_3d[2]->x, map->triangle[k + 1].point_3d[2]->y, map->triangle[k + 1].point_3d[2]->z);
    map->triangle[k + 1].point_2d[0] = &(map->map_2d[(j + 1) * (map->tab_size_x + 1) + i + 1]);
    map->triangle[k + 1].point_2d[1] = map->triangle[k].point_2d[1];
    map->triangle[k + 1].point_2d[2] = map->triangle[k].point_2d[2];
    map->triangle[k + 1].color = sfWhite;
    map->triangle[k + 1].square_part = &(map->triangle[k]);
    //printf("init2: %p\n", map->triangle[k + 1].point_2d[0]);
    //printf("init2: %p\n", map->triangle[k + 1].point_2d[1]);
    //printf("init2: %p\n\n", map->triangle[k + 1].point_2d[2]);
}

void    set_white_map(map_t **map)
{
    int i = 0;
    int j = 0;

    (*map)->map_3d = malloc(sizeof(sfVector3f) *
((*map)->tab_size_x + 1) * ((*map)->tab_size_y + 1));
    while (i < (*map)->tab_size_y + 1) {
        j = 0;
        while (j < (*map)->tab_size_x + 1) {
            (*map)->map_3d[i * ((*map)->tab_size_x + 1) + j].x = ((double)(i) -
(double)((*map)->tab_size_x + 1) / 2.0) + ((((*map)->tab_size_x + 1) % 2) ?
0 : 0.5) / (*map)->zoom;
            (*map)->map_3d[i * ((*map)->tab_size_x + 1) + j].y = ((double)(j) -
(double)((*map)->tab_size_y + 1) / 2.0) + ((((*map)->tab_size_y + 1) % 2) ?
0 : 0.5) / (*map)->zoom;
            if (i != 0 && j != 0 && i + 1 != ((*map)->tab_size_x + 1) && j + 1 != (*map)->tab_size_y + 1)
                (*map)->map_3d[i * ((*map)->tab_size_x + 1) + j].z = (double)((rand() % 20)) / 6.0;
            else
                (*map)->map_3d[i * ((*map)->tab_size_x + 1) + j].z = 0;
            j++;
        }
        i++;
    }
}

void    assign_triangle(map_t *map)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (!(map->triangle = malloc(sizeof(triangle_t) *
map->tab_size_x * 2 * map->tab_size_y)))
        return ;
    while (i < map->tab_size_y) {
        j = 0;
        while (j < map->tab_size_x && (j < map->tab_size_x ||
i < map->tab_size_y)) {
            set_point_on_triangle(map, i, j, k);
            k += 2;
            j++;
        }
        i++;
    }
}

void    set_3d_map(map_t **map, char *str)
{
    if (!str) {
        if (!((*map)->triangle = malloc(sizeof(triangle_t) *
((*map)->tab_size_x * 2 * (*map)->tab_size_y))))
            return ;
        set_white_map(map);
        assign_triangle(*map);
        return ;
    }
}
