/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** pass the game status to menu scene
*/

#include "my_gras.h"
#include "my_runner.h"

int pass_game_to_menu(window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *)manager->data;
    scene_entity_t *scene = get_current_scene_entity(manager);

    if (data->global_sound) {
        sfMusic_stop(data->music);
        sfMusic_play(data->music);
        data->is_playing = 1;
    }
    destroy_all_scene_obj(scene);
    manager->current_zindex = 1;
    return (0);
}
