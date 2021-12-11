/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** destroy the runner
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

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
