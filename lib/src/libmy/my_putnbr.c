/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put a decimal nbr in stdout
*/

#include "my_puts.h"

int my_putnbr(int nb)
{
    char const base[] = "0123456789";

    return (my_putnbr_base(nb, base));
}
