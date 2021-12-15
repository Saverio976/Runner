/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** destroy a game scene
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

void s_destroy_game(scene_entity_t *scene,
        __attribute__((unused)) window_controller_t *manager)
{
    game_player_t *player = (game_player_t *) scene->data;

    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    sfClock_destroy(scene->clock);
    free(player);
}
