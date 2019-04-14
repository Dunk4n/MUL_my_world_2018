/*
** EPITECH PROJECT, 2018
** src/init_texture
** File description:
** segmentation fault (core dumped)
*/

#include <stdlib.h>
#include "world.h"

const char      *img_name[13] = {"img/grass.png", "img/diamant.jpg",
"img/face1.jpg", "img/face2.jpg", "img/face3.jpg", "img/face4.jpg",
"img/face5.jpg", "img/face6.jpg", "img/pine-tree-leaf.jpg",
"img/pine-tree-bark.jpg", "img/ground.jpg", "img/dragon1.jpg",
"img/dragon2.jpg"};

void    set_img(my_game_t *game)
{
    int i = 0;
    game->nb_col_max = 10;
    game->nb_img = 13;

    if (game->nb_img < 1 ||
    !(game->img = malloc(sizeof(sfImage*) * game->nb_img)))
        return ;
    while (i < game->nb_img) {
        game->img[i] = sfImage_createFromFile(img_name[i]);
        i++;
    }
}

void    set_value_game(my_game_t *game)
{
    game->map->obj = NULL;
    game->select = NULL;
    game->save_fg = 0;
    game->load_fg = 0;
    game->point_or_face_fg = 0;
    game->t_or_c_fg = 0;
    game->tex_col_fg = 0;
    game->nb_img = 0;
    game->nb_col_max = 0;
}
