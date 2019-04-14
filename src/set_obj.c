/*
** EPITECH PROJECT, 2018
** src/set_obj
** File description:
** 01100010 01101001 01101110 01100001 01110010 01111001
*/

#include <stdlib.h>
#include <fcntl.h>
#include "world.h"
#include "my.h"

const sfColor   color[10] =
{(sfColor){255, 255, 255, 255}, (sfColor){0, 0, 0, 255},
(sfColor){255, 0, 0, 255}, (sfColor){0, 255, 0, 255}, (sfColor){0, 0, 255, 255},
(sfColor){255, 255, 0, 255}, (sfColor){0, 255, 255, 255},
(sfColor){255, 0, 255, 255}, (sfColor){96, 64, 32, 255},
(sfColor){51, 102, 0, 255}};

static void     set_triangle(obj_t *obj, char **array, int i)
{
    obj->triangle[obj->nb_tr].obj = obj;
    obj->triangle[obj->nb_tr].point_3d[0] =
    &(obj->point_3d[my_getnbr(array[1]) - 1]);
    obj->triangle[obj->nb_tr].indice_point[0] = my_getnbr(array[1]);
    obj->triangle[obj->nb_tr].point_2d[0] =
    &(obj->point_2d[my_getnbr(array[1]) - 1]);
    obj->triangle[obj->nb_tr].point_3d[1] =
    &(obj->point_3d[my_getnbr(array[2 + i]) - 1]);
    obj->triangle[obj->nb_tr].indice_point[1] = my_getnbr(array[2 + i]);
    obj->triangle[obj->nb_tr].point_2d[1] =
    &(obj->point_2d[my_getnbr(array[2 + i]) - 1]);
    obj->triangle[obj->nb_tr].point_3d[2] =
    &(obj->point_3d[my_getnbr(array[3 + i]) - 1]);
    obj->triangle[obj->nb_tr].indice_point[2] = my_getnbr(array[3 + i]);
    obj->triangle[obj->nb_tr].point_2d[2] =
    &(obj->point_2d[my_getnbr(array[3 + i]) - 1]);
    set_triangle_tx(obj, array, i);
    obj->nb_tr++;
}

static void     set_face(obj_t *obj, char **array)
{
    int i = 0;

    while (array[i])
        i++;
    if (i < 4)
        return ;
    set_triangle(obj, array, 0);
    if (i > 4 && array[4][0] != '#')
        set_triangle(obj, array, 1);
}

static void    set_arg_obj(obj_t *obj, char *line)
{
    char        *ref[3] = {"v", "vt", "f"};
    void        (*tab[])(obj_t *obj, char **array) = {set_point, set_point_tx,
set_face};
    char        **array = my_str_to_word_array(line, " \t");
    int         i = 0;

    if (!array[0]) {
        free_array(array);
        return ;
    }
    while (i < 3) {
        if (!my_strcmp(ref[i], array[0]))
            tab[i](obj, array);
        i++;
    }
    free_array(array);
}

int     set_obj(obj_t *obj, char *name)
{
    int     fd = open(name, O_RDONLY);
    char    *line;

    if (fd == -1)
        return (0);
    obj->nb_point = 0;
    obj->nb_tr = 0;
    obj->nb_tx = 0;
    line = get_next_line(fd);
    while (line) {
        set_arg_obj(obj, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (1);
}
