/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** put char to stdout
*/

#include <unistd.h>

int my_putchar(char c)
{
    return (write(1, &c, 1));
}
