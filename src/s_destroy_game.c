/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** destroy a game scene
*/

#include "my_gras.h"
#include "my_runner.h"

void s_destroy_game(scenne_entity_t *scene,
        __attribute__((unused)) window_controler_t *manager)
{
    sfClock_destroy(scene->clock);
}
