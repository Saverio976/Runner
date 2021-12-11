/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** update the intro
*/

#include "my_gras.h"
#include "my_runner.h"

int s_update_intro(scenne_entity_t *scenne,
        window_controler_t *manager)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(scenne->clock)) > 2.0)
        manager->current_zindex = 1;
    return (0);
}
