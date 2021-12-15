/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** update the game scene
*/

#include "my_gras.h"
#include "my_runner.h"

int s_update_game(scene_entity_t *scene,
        window_controller_t *manager)
{
    int ret = player_update(scene, manager);

    return (ret);
}
