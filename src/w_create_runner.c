/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create the runner
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

int w_create_runner(window_controler_t *manager)
{
    manager->data = malloc(sizeof(game_runner_t));

    if (manager->data == NULL)
        return (0);
    ((game_runner_t *) manager->data)->life = 3;
    return (1);
}
