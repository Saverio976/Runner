/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** function to update the background
*/

#include "my_gras.h"
#include "my_runner.h"

static void update_current_zindex(window_controler_t *manager)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(manager->clock)) < 0.5)
        return;
    manager->current_zindex = 1;
    sfClock_restart(manager->clock);
}

int o_update_settings_menu(object_entity_t *obj,
        __attribute__((unused)) scenne_entity_t *scene,
        window_controler_t *manager)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(manager->win);
    sfFloatRect pos_txt = sfText_getGlobalBounds(obj->text);

    sfText_setString(obj->text, "menu");
    if (pos_txt.left <= pos.x && pos.x <= pos_txt.left + pos_txt.width &&
            pos_txt.top <= pos.y && pos.y <= pos_txt.top + pos_txt.height) {
        sfText_setCharacterSize(obj->text, 30);
        sfText_setFillColor(obj->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            update_current_zindex(manager);
    } else {
        sfText_setCharacterSize(obj->text, 28);
        sfText_setFillColor(obj->text, sfWhite);
    }
    sfRenderWindow_drawText(manager->win, obj->text, NULL);
    return (0);
}
