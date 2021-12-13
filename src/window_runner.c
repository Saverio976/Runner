/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create the runner
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

static const char *BG_PATHS[4] = {"assets/blue_bg.jpg", "assets/green_bg.png",
    "assets/purple_bg.jpg", "assets/red_bg.png"};

static void create_data(game_runner_t *data)
{
    data->is_playing = 1;
    data->global_sound = 1;
    data->speed_paralax_1 = 10;
    data->speed_paralax_2 = 5;
    data->speed_paralax_3 = 2;
    data->bg_game = BG_PATHS[0];
    data->block = "assets/block.png";
    data->spike = "assets/spike.png";
    data->map_txt = "map/basic.txt";
    data->player = "assets/cubes_1.png";
    data->end = "assets/end_block.png";
}

int w_create_runner(window_controler_t *manager)
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

void w_destroy_runner(window_controler_t *manager)
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
