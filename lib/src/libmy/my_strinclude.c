/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** check if str contain a char
*/

int my_strinclude(char const *str, char c)
{
    int i = 0;

    while (str[i] != '\0' && str[i] != c)
        i++;
    return (str[i] == c);
}
