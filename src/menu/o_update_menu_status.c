/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** show if you win the last game or not
*/

#include "my_gras.h"
#include "my_runner.h"

int o_update_menu_status(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *) manager->data;

    if (data->is_win == 1)
        sfText_setString(obj->text, "last game : win");
    else if (data->is_win == 0)
        sfText_setString(obj->text, "last game : lose");
    else
        sfText_setString(obj->text, "last game : (no data)");
    sfText_setFillColor(obj->text, sfRed);
    sfText_setCharacterSize(obj->text, 28);
    sfRenderWindow_drawText(manager->win, obj->text, NULL);
    return (0);
}
