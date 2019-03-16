/*
** EPITECH PROJECT, 2018
** src/save_write
** File description:
** no, real programmers use cat
*/

#include <unistd.h>
#include "world.h"

void    my_put_nbr_cus(int nb, int fd)
{
    char tmp;

    if (nb > 9 || nb < -9) {
        my_put_nbr_cus((nb < 0) ? (-(nb / 10)) : (nb / 10), fd);
        tmp = ((nb < 0) ? (-(nb % 10)) : (nb % 10)) + '0';
        write(fd, &tmp, 1);
        return ;
    }
    tmp = ((nb < 0) ? (-nb) : nb) + '0';
    write(fd, &tmp, 1);
}

void    my_put_float(double nb, int fd)
{
    char tmp;
    int i = 0;

    my_put_nbr_cus((int)nb, fd);
    if (nb < 0)
        nb *= -1;
    write(fd, ".", 1);
    while (i < 6) {
        nb -= (int)nb;
        nb *= 10;
        tmp = (int)nb + '0';
        write(fd, &tmp, 1);
        i++;
    }
}

void    write_all_vertice(my_game_t *game, int fd)
{
    int i = 0;

    while (i < game->map->obj->nb_point) {
        write(fd, "v ", 2);
        (game->map->obj->point_3d[i].x < 0) ? write(fd, "-", 1) : 0;
        my_put_float(game->map->obj->point_3d[i].x, fd);
        write(fd, " ", 1);
        (game->map->obj->point_3d[i].y < 0) ? write(fd, "-", 1) : 0;
        my_put_float(game->map->obj->point_3d[i].y, fd);
        write(fd, " ", 1);
        (game->map->obj->point_3d[i].z < 0) ? write(fd, "-", 1) : 0;
        my_put_float(game->map->obj->point_3d[i].z, fd);
        write(fd, "\n", 1);
        i++;
    }
    write(fd, "\n", 1);
}

void    write_all_vertice_tex(my_game_t *game, int fd)
{
    int i = 0;

    while (i < game->map->obj->nb_tx) {
        write(fd, "vt ", 3);
        (game->map->obj->point_tx[i].x < 0) ? write(fd, "-", 1) : 0;
        my_put_float(game->map->obj->point_tx[i].x, fd);
        write(fd, " ", 1);
        (game->map->obj->point_tx[i].y < 0) ? write(fd, "-", 1) : 0;
        my_put_float(game->map->obj->point_tx[i].y, fd);
        write(fd, " ", 1);
        (game->map->obj->point_tx[i].z < 0) ? write(fd, "-", 1) : 0;
        my_put_float(game->map->obj->point_tx[i].z, fd);
        write(fd, "\n", 1);
        i++;
    }
    write(fd, "\n", 1);
}

void    write_one_face(triangle_t *tri, int fd)
{
    write(fd, "f ", 2);
    my_put_nbr_cus(tri->indice_point[0], fd);
    write(fd, "/", 1);
    my_put_nbr_cus(tri->indice_texture[0], fd);
    write(fd, "/ ", 2);
    my_put_nbr_cus(tri->indice_point[1], fd);
    write(fd, "/", 1);
    my_put_nbr_cus(tri->indice_texture[1], fd);
    write(fd, "/ ", 2);
    my_put_nbr_cus(tri->indice_point[2], fd);
    write(fd, "/", 1);
    my_put_nbr_cus(tri->indice_texture[2], fd);
    write(fd, "/", 1);
    write(fd, "\n", 1);
}
