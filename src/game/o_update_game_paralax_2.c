/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** function to update the background
*/

#include "my_gras.h"
#include "my_runner.h"

int o_update_game_paralax_2(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    game_runner_t *data = manager->data;
    sfFloatRect bounds = sfSprite_getGlobalBounds(obj->sprite);
    float tmp;

    obj->pos.x -= data->settings.speed_paralax_2;
    if (bounds.left + bounds.width - 10 < 0) {
        obj->pos.x += bounds.width;
    }
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfRenderWindow_drawSprite(manager->win, obj->sprite, NULL);
    tmp = obj->pos.x;
    obj->pos.x += bounds.width;
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfRenderWindow_drawSprite(manager->win, obj->sprite, NULL);
    obj->pos.x = tmp;
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (0);
}
