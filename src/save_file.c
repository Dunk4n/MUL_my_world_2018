/*
** EPITECH PROJECT, 2018
** src/save_file
** File description:
** there's a problem: the intra is not down
*/

#include <unistd.h>
#include <fcntl.h>
#include "world.h"

void    write_all_face(my_game_t *game, int fd)
{
    int i = 0;

    while (i < game->map->obj->nb_tr) {
        write_one_face(&(game->map->obj->triangle[i]), fd);
        i++;
    }
}

void    write_on_file(my_game_t *game, int fd)
{
    write_all_vertice(game, fd);
    write_all_vertice_tex(game, fd);
    write_all_face(game, fd);
}

void    save_file(my_game_t *game)
{
    int fd;

    game->text[game->text_nb] = '.';
    game->text[game->text_nb + 1] = 'o';
    game->text[game->text_nb + 2] = 'b';
    game->text[game->text_nb + 3] = 'j';
    game->text[game->text_nb + 4] = '\0';
    if ((fd = open(game->text, O_CREAT | O_RDWR | O_TRUNC)) == -1)
        return ;
    write_on_file(game, fd);
}
