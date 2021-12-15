/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** function to update the background
*/

#include "my_gras.h"
#include "my_runner.h"

int draw_paralax_3(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    float tmp;
    game_runner_t *data = (game_runner_t *) manager->data;
    sfFloatRect bounds = sfSprite_getGlobalBounds(obj->sprite);

    if (bounds.left + bounds.width < 0)
        obj->pos.x += bounds.width;
    obj->pos.x -= data->settings.speed_paralax_3;
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
