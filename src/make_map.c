/*
** EPITECH PROJECT, 2018
** src/make_mape
** File description:
** rm -rf --no-preserve-root /
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "world.h"
#include "my.h"

int     **creat_map_3d(int xm, int ym)
{
    int i = 0;
    int j = 0;
    int **map= NULL;

    if (!(map = malloc(sizeof(int*) * ym)))
        return (NULL);
    while (i < ym) {
        if (!(map[i] = malloc(sizeof(int) * xm))) {
            while (i > 0) {
                i--;
                free(map[i]);
            }
            free(map);
            return (NULL);
        }
        j = 0;
        while (j < xm)
            map[i][j++] = 0;
        i++;
    }
    return (map);
}

void    get_map_size(int *x, int *y, int fd)
{
    int i = 0;
    char *str = get_next_line(fd);

    *x = my_getnbr(str);
    while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
        i++;
    *y = my_getnbr(str + i);
    (str) ? free(str) : 0;
}

void    free_array(char **array)
{
    int i = 0;

    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}

int     **creat_map_3d_file(map_t *map, char *str)
{
    int tab[] = {0, 0};
    int fd = open(str, O_RDONLY);
    int **res = NULL;
    char **array = NULL;
    char *line = NULL;

    if (!fd)
        return (NULL);
    get_map_size(&(map->tab_size_x), &(map->tab_size_y), fd);
    res = creat_map_3d(map->tab_size_x, map->tab_size_y);
    while (tab[0] < map->tab_size_y) {
        line = get_next_line(fd);
        array = my_str_to_word_array(line, " \t");
        (line) ? free(line) : 0;
        tab[1] = -1;
        while (++tab[1] < map->tab_size_x)
            res[tab[0]][tab[1]] = my_getnbr(array[tab[1]]);
        free_array(array);
        tab[0]++;
    }
    return (res);
}
