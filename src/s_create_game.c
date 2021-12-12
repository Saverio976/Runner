/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create the game scene
*/

#include "my_gras.h"
#include "my_runner.h"

int s_create_game(scenne_entity_t *scene,
        __attribute__((unused)) window_controler_t *manager)
{
    sfVector2f pos_bg = {0, 0};
    sfVector2f pos_txt = {10, 10};
    game_runner_t *data = (game_runner_t *) manager->data;

    create_picture(scene, data->bg_game, pos_bg,
            o_update_game_background);
    create_map_obj_from(data, scene);
    create_text(scene, FONT_PATH, pos_txt, o_update_game_time);
    scene->clock = sfClock_create();
    if (!scene->clock)
        return (0);
    return (1);
}
