/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** destroy the runner
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

void w_destroy_runner(window_controler_t *manager)
{
    free(manager->data);
}
