/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** print the current map
*/

#include "my_gras.h"
#include "my_runner.h"

static char *get_str_map(window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *) manager->data;
    char copy[] = "current : ";
    static char tab[50] = {0};
    int i = 0;
    int j = 0;

    for (; i < 50 && copy[i] != '\0'; i++)
        tab[i] = copy[i];
    for (; i + j < 50 && data->settings.music_path[j] != '\0'; j++)
        tab[i + j] = data->settings.music_path[j];
    for (int e = i + j; e < 50; e++)
        tab[e] = '\0';
    return (tab);
}

int print_current_music(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    sfText_setString(obj->text, get_str_map(manager));
    sfText_setCharacterSize(obj->text, 28);
    sfText_setFillColor(obj->text, sfMagenta);
    sfRenderWindow_drawText(manager->win, obj->text, NULL);
    return (0);
}
