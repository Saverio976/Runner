/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put unsigned decimal number in base b
*/

#include <stdlib.h>
#include "my_strings.h"
#include "my_puts.h"

static char *dup_and_cat(char *dest, char c, int *cap)
{
    int len = my_strlen(dest);
    char *new = NULL;

    if (len + 2 >= *cap) {
        *cap = *cap + 12;
        new = my_calloc(*cap);
        if (!new)
            return (NULL);
        for (int i = 0; i < len; i++)
            new[i] = dest[i];
        free(dest);
        dest = new;
    }
    dest[len] = c;
    return (dest);
}

int my_putunbr_base(unsigned int nb, char const *base)
{
    int i = 0;
    int max_cap = 12;
    char *result = my_calloc(max_cap);

    if (nb == 0 && result != NULL)
        result[i++] = '0';
    for (; nb != 0 && result != NULL; i++) {
        result = dup_and_cat(result, base[nb % my_strlen(base)], &max_cap);
        nb /= my_strlen(base);
    }
    result = my_revstr(result);
    i = my_putstr(result);
    free(result);
    return (i);
}
