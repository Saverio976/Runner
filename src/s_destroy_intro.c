/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** destroy the intro scenne
*/

#include "my_gras.h"
#include "my_runner.h"

void s_destroy_intro(scenne_entity_t *scenne,
        __attribute__((unused)) window_controler_t *manager)
{
    sfClock_destroy(scenne->clock);
    return;
}