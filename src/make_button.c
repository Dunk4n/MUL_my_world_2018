/*
** EPITECH PROJECT, 2018
** src/make_button
** File description:
** example of bad code:
*/

#include "world.h"

void    make_button_texture(my_game_t *game)
{
    if (game->t_or_c_fg == 0) {
        game->tex_col_fg = (game->tex_col_fg + 1 < game->nb_col_max) ?
game->tex_col_fg + 1 : 0;
        sfSprite_setColor(game->button[3].sp, color[game->tex_col_fg]);
        return ;
    }
    game->tex_col_fg = (game->tex_col_fg + 1 < game->nb_img) ?
game->tex_col_fg + 1 : 0;
    sfSprite_setTexture(game->button[3].sp,
sfTexture_createFromImage(game->img[game->tex_col_fg],
&((sfIntRect){0, 0, game->button[3].rect.width, game->button[3].rect.height})),
sfTrue);
}
