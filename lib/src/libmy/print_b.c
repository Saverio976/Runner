/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** take valist and put int to binary
*/

#include <stdarg.h>
#include "my_puts.h"

int print_b(va_list ap)
{
    return (my_putunbr_base(va_arg(ap, unsigned int), "01"));
}
