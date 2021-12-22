/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** function to update the background
*/

#include "my_gras.h"
#include "my_runner.h"

int draw_explanation(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    sfText_setString(obj->text,
            "Escape : Quit the game\n"
            "Pause : Freeze the game\n"
            "Space : Jump / start the game\n"
            "E : Enabled/Disabled V-Sync");
    sfText_setCharacterSize(obj->text, 28);
    sfText_setFillColor(obj->text, sfGreen);
    sfRenderWindow_drawText(manager->win, obj->text, NULL);
    return (0);
}
