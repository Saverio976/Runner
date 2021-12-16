/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** change the map
*/

#include "paths.h"
#include "my_gras.h"
#include "my_runner.h"

static void update_current_music(window_controller_t *manager)
{
    static int current = 0;
    game_runner_t *data;

    if (sfTime_asSeconds(sfClock_getElapsedTime(manager->clock)) < 0.5)
        return;
    data = (game_runner_t *) manager->data;
    sfMusic_stop(data->music);
    sfMusic_destroy(data->music);
    data->music = NULL;
    while (data->music == NULL) {
        current = (current + NUMBER_MUSICS - 1) % NUMBER_MUSICS;
        data->music = sfMusic_createFromFile(MUSICS[current]);
    }
    data->settings.music_path = MUSICS[current];
    sfMusic_play(data->music);
    data->is_playing = 1;
    data->settings.global_sound = 1;
    sfClock_restart(manager->clock);
}

int switch_music_prev(object_entity_t *obj,
        __attribute__((unused)) scene_entity_t *scene,
        window_controller_t *manager)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(manager->win);
    sfFloatRect pos_txt = sfText_getGlobalBounds(obj->text);

    sfText_setString(obj->text, "music next ->");
    if (pos_txt.left <= pos.x && pos.x <= pos_txt.left + pos_txt.width &&
            pos_txt.top <= pos.y && pos.y <= pos_txt.top + pos_txt.height) {
        sfText_setCharacterSize(obj->text, 30);
        sfText_setFillColor(obj->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            update_current_music(manager);
    } else {
        sfText_setCharacterSize(obj->text, 28);
        sfText_setFillColor(obj->text, sfWhite);
    }
    sfRenderWindow_drawText(manager->win, obj->text, NULL);
    return (0);
}
