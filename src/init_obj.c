/*
** EPITECH PROJECT, 2018
** src/init_obj
** File description:
** M-x doctor
*/

#include <stdlib.h>
#include <fcntl.h>
#include "world.h"
#include "my.h"

void    free_array(char **array)
{
    int i = 0;

    if (!array)
        return ;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}

static void     set_nb_of_obj(obj_t *obj, char *line)
{
    char    *ref[3] = {"v", "f", "vt"};
    int     *val[3] = {&(obj->nb_point), &(obj->nb_tr), &(obj->nb_tx)};
    char    **array = my_str_to_word_array(line, " \t");
    int     i = 0;

    while (array[i])
        i++;
    if (i < 4) {
        free_array(array);
        return ;
    }
    i = 0;
    while (i < 3) {
        if (!my_strcmp(ref[i], array[0]))
            (*(val[i]))++;
        i++;
    }
    free_array(array);
}

int     get_nbr_arg(obj_t *obj, char *name)
{
    int     fd = open(name, O_RDONLY);
    char    *line;

    if (fd == -1)
        return (0);
    line = get_next_line(fd);
    while (line) {
        set_nb_of_obj(obj, line);
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (1);
}

obj_t   *init_obj(void)
{
    obj_t *obj;

    if (!(obj = malloc(sizeof(obj_t))))
        return (NULL);
    obj->nb_point = 0;
    obj->nb_tr = 0;
    obj->point_3d = NULL;
    obj->point_2d = NULL;
    obj->triangle = NULL;
    return (obj);
}
