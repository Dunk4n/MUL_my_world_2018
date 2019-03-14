/*
** EPITECH PROJECT, 2018
** src/file_obj
** File description:
** no, real programmers use cat
*/

#include <stdlib.h>
#include <fcntl.h>
#include "world.h"
#include "my.h"

void    set_point_tx(obj_t *obj, char **array)
{
    int i = 0;

    while (array[i])
        i++;
    if (i < 3)
        return ;
    obj->point_tx[obj->nb_tx].x = my_getfloat(array[1]);
    obj->point_tx[obj->nb_tx].y = my_getfloat(array[2]);
    if (i >= 4)
        obj->point_tx[obj->nb_tx].z = my_getfloat(array[3]);
    obj->nb_tx++;
}

int     alloc_obj(obj_t *obj)
{
    if (obj->nb_point <= 0 ||
    !(obj->point_3d = malloc(sizeof(sfVector3f) * obj->nb_point)))
        return (0);
    if (obj->nb_point <= 0 ||
    !(obj->point_2d = malloc(sizeof(sfVector3f) * obj->nb_point))) {
        free(obj->point_3d);
        return (0);
    }
    if (obj->nb_tr <= 0 ||
    !(obj->triangle = malloc(sizeof(triangle_t) * obj->nb_tr))) {
        free(obj->point_3d);
        free(obj->point_2d);
        return (0);
    }
    obj->point_tx = NULL;
    if (obj->nb_tx <= 0)
        return (1);
    if (!(obj->point_tx = malloc(sizeof(sfVector3f) * obj->nb_tx))) {
        free(obj->point_3d);
        free(obj->point_2d);
        free(obj->triangle);
        return (0);
    }
    return (1);
}

obj_t   *open_file_obj(char *name)
{
    obj_t *obj = init_obj();

    if (!obj)
        return (NULL);
    if (!get_nbr_arg(obj, name)) {
        free(obj);
        return (NULL);
    }
    if (!alloc_obj(obj)) {
        free(obj);
        return (NULL);
    }
    if (!set_obj(obj, name)) {
        free(obj->point_3d);
        free(obj->point_2d);
        free(obj->triangle);
        return (NULL);
    }
    return (obj);
}
