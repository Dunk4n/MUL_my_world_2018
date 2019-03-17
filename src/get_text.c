/*
** EPITECH PROJECT, 2018
** src/get_text
** File description:
** you're a bad developer
*/

#include "world.h"

const   int letter[39] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF,
sfKeyG, sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN, sfKeyO, sfKeyP,
sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU, sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ,
sfKeySlash, sfKeyPeriod, sfKeyHyphen, sfKeyNum0, sfKeyNum1, sfKeyNum2,
sfKeyNum3, sfKeyNum4, sfKeyNum5, sfKeyNum6, sfKeyNum7, sfKeyNum8, sfKeyNum9};
const char *list_letters = "abcdefghijklmnopqrstuvwxyz/.-0123456789";

void    write_on_txt(my_game_t *game)
{
    int i = 0;

    while (i < 39) {
        if (sfKeyboard_isKeyPressed(letter[i]) &&
(game->last_input != list_letters[i])) {
            game->text[game->text_nb] = list_letters[i];
            game->text_nb++;
            game->text[game->text_nb] = '\0';
        }
        if (sfKeyboard_isKeyPressed(letter[i]))
            game->last_input =
                (game->last_input != list_letters[i]) ? list_letters[i] : '\0';
        i++;
    }
}

void    get_name_file(my_game_t *game)
{
    if (game->text_nb > 45 || sfKeyboard_isKeyPressed(sfKeyReturn)) {
        (game->save_fg == 1) ? save_file(game) : load_file(game);
        game->save_fg = 0;
        game->load_fg = 0;
        game->text_nb = 0;
        game->text[0] = '\0';
    }
    write_on_txt(game);
    sfText_setString(game->txt, game->text);
}
