/*
** EPITECH PROJECT, 2021
** ...
** File description:
** the main entry point for the project
*/

#include "my_runner.h"
#include "my_puts.h"

int main(int ac, char **av)
{
    for (int i = 0; i < ac; i++)
        my_printf("%s\n", av[i]);
    return (0);
}
