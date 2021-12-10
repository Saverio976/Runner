/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** compare two str an return 0 if eq
*/

#include "my_strings.h"

int my_strcmp(char const *s1, char const *s2)
{
    char a;
    char b;
    int sub = 0;
    int max = (my_strlen(s1) > my_strlen(s2)) ? my_strlen(s1) : my_strlen(s2);

    for (int i = 0; sub == 0 && i < max; i++) {
        a = (i >= my_strlen(s1)) ? '\0' : s1[i];
        b = (i >= my_strlen(s2)) ? '\0' : s2[i];
        sub = a - b;
    }
    return (sub);
}
