/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create the runner
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

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
    sfMusic_play(data->music);
    sfMusic_setLoop(data->music, sfTrue);
    data->is_playing = 1;
    return (1);
}
