/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create the runner
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

static void create_data(game_runner_t *data)
{
    data->is_playing = 1;
    data->settings.global_sound = 1;
    data->settings.speed_paralax_1 = 10;
    data->settings.speed_paralax_2 = 5;
    data->settings.speed_paralax_3 = 2;
    data->settings.background_img = DEFAULT_BG_IMG;
    data->settings.block_img = DEFAULT_BLOCK_IMG;
    data->settings.spike_img = DEFAULT_SPIKE_IMG;
    data->settings.map_path = DEFAULT_MAP_PATH;
    data->settings.player_img = DEFAULT_PLAYER_IMG;
    data->settings.end_img = DEFAULT_END_IMG;
    data->is_win = -1;
}

int w_create_runner(window_controller_t *manager)
{
    game_runner_t *data;
    manager->data = malloc(sizeof(game_runner_t));

    if (manager->data == NULL)
        return (0);
    data = (game_runner_t *) manager->data;
    data->life = 3;
    data->music = sfMusic_createFromFile(MENU_MUSIC_PATH);
    if (data->music == NULL) {
        free(data);
        return (0);
    }
    manager->clock = sfClock_create();
    if (!manager->clock)
        return (0);
    sfMusic_play(data->music);
    sfMusic_setLoop(data->music, sfTrue);
    create_data(data);
    return (1);
}

void w_destroy_runner(window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *) manager->data;

    if (data == NULL)
        return;
    if (data->is_playing) {
        sfMusic_setLoop(data->music, sfFalse);
        sfMusic_stop(data->music);
    }
    sfMusic_destroy(data->music);
    sfClock_destroy(manager->clock);
    free(manager->data);
}
