/*
** EPITECH PROJECT, 2018
** my_strlowcase
** File description:
** low letter
*/

char    *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
    return (str);
}
