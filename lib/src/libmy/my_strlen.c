/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** get length of null terminated str
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}
