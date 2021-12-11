/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** update the settings music
*/

#include "my_gras.h"
#include "my_runner.h"

static void update_music_settings(game_runner_t *data, scenne_entity_t *scene)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(scene->clock)) < 0.2)
        return;
    data->global_sound = !data->global_sound;
    if (!data->global_sound && data->is_playing) {
        sfMusic_pause(data->music);
        data->is_playing = 0;
    }
    if (data->global_sound && !data->is_playing) {
        sfMusic_play(data->music);
        data->is_playing = 1;
    }
    sfClock_restart(scene->clock);
}

int o_update_settings_music(object_entity_t *obj,
        scenne_entity_t *scene,
        window_controler_t *manager)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(manager->win);
    sfFloatRect pos_txt = sfText_getGlobalBounds(obj->text);
    game_runner_t *data = (game_runner_t *) manager->data;

    sfText_setString(obj->text, "play/pause music");
    if (pos_txt.left <= pos.x && pos.x <= pos_txt.left + pos_txt.width &&
            pos_txt.top <= pos.y && pos.y <= pos_txt.top + pos_txt.height) {
        sfText_setCharacterSize(obj->text, 30);
        sfText_setFillColor(obj->text, sfRed);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            update_music_settings(data, scene);
        }
    } else {
        sfText_setCharacterSize(obj->text, 28);
        sfText_setFillColor(obj->text, sfWhite);
    }
    sfRenderWindow_drawText(manager->win, obj->text, NULL);
    return (0);
}
