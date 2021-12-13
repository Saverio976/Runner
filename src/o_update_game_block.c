/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** master update of one spike
*/

#include "my_gras.h"
#include "my_runner.h"

int o_update_game_block(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *) manager->data;
    sfFloatRect pos_spr = sfSprite_getGlobalBounds(obj->sprite);

    if (obj->object_is_visible)
        return (0);
    if (obj->pos.x + pos_spr.width < -10)
        obj->object_is_visible = 0;
    obj->pos.x -= data->speed_paralax_1;
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfRenderWindow_drawSprite(manager->win, obj->sprite, NULL);
    return (0);
}
