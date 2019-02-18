/*
** EPITECH PROJECT, 2018
** my_put_nbre
** File description:
** display number
*/

#include <unistd.h>
#include "my.h"

int     my_putchare(char c)
{
    write(2, &c, 1);
    return (1);
}

int     my_putstre(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
    return (len);
}

int     my_put_nbre(int nb)
{
    int n = (nb < 0) ? my_putchare('-') : 0;

    if (nb > 9 || nb < -9) {
        n += my_put_nbre((nb < 0) ? (-(nb / 10)) : (nb / 10));
        n += my_putchare(((nb < 0) ? (-(nb % 10)) : (nb % 10)) + '0');
        return (n);
    }
    n += my_putchare(((nb < 0) ? (-nb) : nb) + '0');
    return (n);
}
