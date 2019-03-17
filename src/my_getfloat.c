/*
** EPITECH PROJECT, 2018
** src/my_getfloat
** File description:
** C-x C-c
*/

#include "my.h"

double  my_getfloat(char *str)
{
    int i = 0;
    int n = 0;
    double nb1 = my_getnbr(str);
    double nb2;

    while (str[i] && str[i] != '.')
        i++;
    i++;
    nb2 = my_getnbr(str + i);
    while (str[i + n] && str[i + n] >= '0' && str[i + n] <= '9')
        n++;
    if (nb1 < 0 || (nb1 >= 0 && str[0] == '-'))
        nb2 *= -1;
    nb1 += nb2 / my_pow(10, n);
    return (nb1);
}
