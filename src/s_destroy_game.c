/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** destroy a game scene
*/

#include "my_gras.h"
#include "my_runner.h"

void s_destroy_game(scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    sfClock_destroy(scene->clock);
}
