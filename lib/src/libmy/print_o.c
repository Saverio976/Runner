/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put uint in octal base
*/

#include <stdarg.h>
#include "my_puts.h"

int print_o(va_list ap)
{
    return (my_putunbr_base(va_arg(ap, unsigned int), "01234567"));
}
