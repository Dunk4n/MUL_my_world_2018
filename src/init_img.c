/*
** EPITECH PROJECT, 2018
** src/init_texture
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "world.h"

const char      *img_name[10] = {"img/grass.png", "img/diamant.jpg",
"img/face1.jpg", "img/face2.jpg", "img/face3.jpg", "img/face4.jpg",
"img/face5.jpg", "img/face6.jpg", "img/pine-tree-leaf.jpg",
"img/pine-tree-bark.jpg"};

void    set_img(my_game_t *game)
{
    int i = 0;
    game->nb_img = 10;

    if (game->nb_img < 1 ||
    !(game->img = malloc(sizeof(sfImage*) * game->nb_img)))
        return ;
    while (i < game->nb_img) {
        game->img[i] = sfImage_createFromFile(img_name[i]);
        i++;
    }
}
