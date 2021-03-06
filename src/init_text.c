/*
** EPITECH PROJECT, 2018
** src/init_text
** File description:
** xkcd.com/378
*/

#include <stdlib.h>
#include "world.h"

void    set_txt(my_game_t *game)
{
    sfFont *font = sfFont_createFromFile("ttf-menlo-bold.ttf");

    game->txt = sfText_create();
    sfText_setString(game->txt, "");
    sfText_setFont(game->txt, font);
    sfText_setCharacterSize(game->txt, 50);
    sfText_setColor(game->txt, sfRed);
    sfText_setPosition(game->txt, (sfVector2f){10, 120});
}

int     init_all_game(char *str, my_game_t *game)
{
    game->last_input = '\0';
    game->text_nb = 0;
    game->text[0] = '\0';
    set_value_game(game);
    game->obj = (!str) ? 0 : 1;
    game->select_obj = NULL;
    if (game->obj) {
        if (!(game->map->obj = malloc(sizeof(obj_t*))))
            return (84);
        if (!(game->map->obj[0] = open_file_obj(str)))
            return (84);
    }
    game->select_obj = (game->obj) ? game->map->obj[0] : NULL;
    set_img(game);
    init_button(game);
    set_txt(game);
    return (0);
}
