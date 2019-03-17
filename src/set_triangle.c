/*
** EPITECH PROJECT, 2018
** src/set_triangle
** File description:
** if you code on paper, you're not a real programmer
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"

void    set_point(obj_t *obj, char **array)
{
    int i = 0;

    while (array[i])
        i++;
    if (i < 4)
        return ;
    obj->point_3d[obj->nb_point].x = my_getfloat(array[1]);
    obj->point_3d[obj->nb_point].y = my_getfloat(array[2]);
    obj->point_3d[obj->nb_point].z = my_getfloat(array[3]);
    obj->nb_point++;
}

static sfColor  indice_color(char *str)
{
    int i = 0;
    char *ref[] = {"WHITE", "BLACK", "RED", "GREEN", "BLUE", "YELLOW",
"CYAN", "MAGENTA", "BROWN", "PINEGREEN"};

    if (!str)
        return (color[rand() % 10]);
    while (i < 10) {
        if (!my_strcmp(ref[i], str))
            return (color[i]);
        i++;
    }
    return (sfWhite);
}

static void     set_triangle_texture(obj_t *obj, char **array, int nb)
{
    int i = 0;

    while (array[i])
        i++;
    obj->triangle[obj->nb_tr].texture = -1;
    if (i < 6 + nb) {
        obj->triangle[obj->nb_tr].color = indice_color(NULL);
        return ;
    }
    if (!my_strcmp(array[4 + nb], "#"))
        obj->triangle[obj->nb_tr].color = indice_color(array[5 + nb]);
    if (!my_strcmp(array[5 + nb], "#"))
        obj->triangle[obj->nb_tr].color = indice_color(array[6 + nb]);
    if (!my_strcmp(array[4 + nb], "#T") &&
my_getnbr(array[5 + nb]) > 0 && my_getnbr(array[5 + nb]) <= 13)
        obj->triangle[obj->nb_tr].texture = my_getnbr(array[5 + nb]) - 1;
    if (!my_strcmp(array[5 + nb], "#T") &&
my_getnbr(array[6 + nb]) > 0 && my_getnbr(array[6 + nb]) <= 13)
        obj->triangle[obj->nb_tr].texture = my_getnbr(array[6 + nb]) - 1;
}

void    set_triangle_tx(obj_t *obj, char **array, int nb)
{
    int i = 0;
    int k = 1;

    while (k <= 3) {
        i = 0;
        while (array[k + ((k > 1) ? nb : 0)][i] &&
array[k + ((k > 1) ? nb : 0)][i] != '/')
            i++;
        if (array[k + ((k > 1) ? nb : 0)][i] == '/') {
            obj->triangle[obj->nb_tr].point_tx[k - 1] = ((my_getnbr(array[k +
((k > 1) ? nb : 0)] + i + 1) - 1 < 0)) ? NULL :
&(obj->point_tx[(my_getnbr(array[k + ((k > 1) ? nb : 0)] + i + 1) - 1)]);
            obj->triangle[obj->nb_tr].indice_texture[k - 1] =
            my_getnbr(array[k + ((k > 1) ? nb : 0)] + i + 1);
        }
        k++;
    }
    set_triangle_texture(obj, array, nb);
    obj->triangle[obj->nb_tr].square_part = NULL;
}
