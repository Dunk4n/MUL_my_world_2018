/*
** EPITECH PROJECT, 2018
** src/main
** File description:
** M-x doctor
*/

#include "world.h"
#include "my.h"

int     main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    return (window(av[1]));
}