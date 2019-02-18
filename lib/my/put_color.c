/*
** EPITECH PROJECT, 2018
** make_color
** File description:
** try not to segfault, good luck :)
*/

#include <unistd.h>
#include "my.h"

void    put_color(char cd, int bold, int sortie)
{
    char    color[][10] = {"\033[0m", "\033[0;31m", "\033[0;32m", "\033[0;34m",
"\033[0;33m", "\033[0;35m", "\033[0;36m"};
    char    let[] = "WRGBMC";
    int     i = 0;

    while (i < 6) {
        if (cd == let[i]) {
            (bold == 1) ? color[i][2] = '1' : 0;
            write(sortie, color[i], my_strlen(color[i]));
            return ;
        }
        i++;
    }
}
