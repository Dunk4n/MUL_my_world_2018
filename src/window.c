/*
** EPITECH PROJECT, 2018
** window
** File description:
** well, real programmers use ed
*/

#include <stdlib.h>
#include <math.h>
#include "world.h"
#include "my.h"

int     tab_dur[6][6] = {
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 5, 3, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0}
};

int     **creat_tab(void)
{
    int i = 0;
    int j = 0;
    int **tab = NULL;

    tab = malloc(sizeof(int*) * TAB_SIZE);
    while (i < TAB_SIZE) {
        tab[i] = malloc(sizeof(int) * TAB_SIZE);
        j = 0;
        while (j < TAB_SIZE) {
            tab[i][j] = tab_dur[i][j];
            j++;
        }
        i++;
    }
    return (tab);
}

int     window(char *str)
{
    my_game_t    *game = NULL;
    int roll[] = {0, HM / 2, WM / 2, 110, 45, 13, 20};
    float a = 0;
    int **tab = creat_tab();

    if (!(game = set_game(str)))
        return (84);
    sfVector2f **map_2d = create_2d_map(tab, roll);
    display_2d_map(game->win->framebuff, map_2d);
    while (sfRenderWindow_isOpen(game->win->window)) {
        //printf("%f\n", a);
        if (roll[0] == 1) {
            printf("%d, %d, %d\n\n", roll[3], roll[4], roll[5]);
            roll[0] = 0;
            clear_buff(game->win->framebuff);
            map_2d = create_2d_map(tab, roll);
            display_2d_map(game->win->framebuff, map_2d);
        }
        a++;
        if (a >= 360)
            a = 0;
        update(game);
        check(game, roll);
    }
    return (0);
}