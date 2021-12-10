/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** function to update the background
*/

#include "my_gras.h"
#include "my_runner.h"

int o_update_intro_background(object_entity_t *obj,
        __attribute__((unused)) scenne_entity_t *scene,
        window_controler_t *manager)
{
    sfRenderWindow_drawSprite(manager->win, obj->sprite, NULL);
    return (0);
}
