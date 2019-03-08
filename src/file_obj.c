/*
** EPITECH PROJECT, 2018
** src/file_obj
** File description:
** no, real programmers use cat
*/

#include <stdlib.h>
#include "world.h"
#include "my.h"

void    get_nbr_arg()
{

}

map_t   *open_file_obj(char *name)
{
    map_t *map;

    set_map(&map);
    get_nbr_arg(map, name);
}
