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
    my_printf("USAGE\n %s\t[map]\n map\t\tobject file to load in game\n\n", av);
    my_printf("USER INTERACTION\n buttons to zoom\t'q'/'e'\n buttons to ");
    my_printf("size up\t'z'/'x'\n move\t\t\t'arrow'/'up key'/'down key'");
    my_printf("\n\nrotate the object:\n ROLL\t'j'/'u'\n YAW\t'k'/'i'\n");
    my_printf(" PITCH\t'l'/'o'\n\n");
    my_printf("load file, save current object, change texture/color\n");
    my_printf("filename must be composed of letters and numbers\n");
    return (0);
}

int     main(int ac, char **av)
{
    if (ac > 2)
        return (84);
    if (ac > 1 && (!my_strcmp(av[1], "-h") || !my_strcmp(av[1], "--help")))
        return (display_usage(av[0]));
    return (window(av[1]));
}
