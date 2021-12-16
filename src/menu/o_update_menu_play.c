/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** function to update the background
*/

#include "my_gras.h"
#include "my_runner.h"

int o_update_menu_play(object_entity_t *obj,
        scene_entity_t *scene,
        window_controller_t *manager)
{
    sfVector2f scale = {0.60, 0.60};
    sfVector2f normal = {0.50, 0.50};
    sfVector2i pos = sfMouse_getPositionRenderWindow(manager->win);
    sfFloatRect pos_spr = sfSprite_getGlobalBounds(obj->sprite);

    if (pos_spr.left <= pos.x && pos.x <= pos_spr.left + pos_spr.width &&
            pos_spr.top <= pos.y && pos.y <= pos_spr.top + pos_spr.height) {
        sfSprite_setScale(obj->sprite, scale);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            manager->current_zindex = 3;
            restart_game(scene->next->next, manager);
        }
    } else if (sfKeyboard_isKeyPressed(sfKeySpace)) {
        manager->current_zindex = 3;
        restart_game(scene->next->next, manager);
    } else {
        sfSprite_setScale(obj->sprite, normal);
    }
    sfRenderWindow_drawSprite(manager->win, obj->sprite, NULL);
    return (0);
}
