/*
** EPITECH PROJECT, 2018
** src/main
** File description:
** M-x doctor
*/

#include "world.h"
#include "my.h"

int     display_usage(const char *av)
{
    my_printf("USAGE\n %s\tmap\n map\t\tobject file to load in game\n\n", av);
    my_printf("USER INTERACTION\nbuttons to zoom, move, rotate the object\n");
    my_printf("load file, save current object, change texture/color\n");
    return 0;
}

int     main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return (84);
    if ((!my_strcmp(av[1], "-h")) || (!my_strcmp(av[1], "--help")))
        return (display_usage(av[0]));
    return (window(av[1]));
}
