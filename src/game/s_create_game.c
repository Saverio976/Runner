/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create the game scene
*/

#include <stdlib.h>
#include "my_gras.h"
#include "my_runner.h"

static int create_scene_data(game_player_t *player, game_runner_t *data)
{
    player->texture = sfTexture_createFromFile(data->settings.player_img, NULL);
    if (!player->texture)
        return (0);
    player->sprite = sfSprite_create();
    if (!player->sprite)
        return (0);
    player->pos = (sfVector2f) {50, 300};
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setOrigin(player->sprite, (sfVector2f) {25, 25});
    player->gravity = 5;
    player->buffer_gravity = 0;
    player->on_ground = 0;
    player->clock = sfClock_create();
    if (!player->clock)
        return (0);
    return (1);
}


int restart_game_two(scene_entity_t *scene, game_runner_t *data)
{
    game_player_t *player = (game_player_t *) scene->data;
    sfVector2f pos_bg = {0, 0};
    sfVector2f pos_paralax2 = {0, 0};
    sfVector2f pos_paralax3 = {0, 0};

    if (create_picture(scene, data->settings.background_img, pos_bg,
            o_update_game_background) != 1)
        return (0);
    if (create_picture(scene, PARALAX_3_PATH, pos_paralax3,
            draw_paralax_3) != 1)
        return (0);
    if (create_picture(scene, PARALAX_2_PATH, pos_paralax2,
            o_update_game_paralax_2) != 1)
        return (0);
    sfSprite_destroy(player->sprite);
    sfTexture_destroy(player->texture);
    sfClock_destroy(player->clock);
    create_scene_data(player, data);
    return (1);
}

int restart_game(scene_entity_t *scene,
        window_controller_t *manager)
{
    sfVector2f pos_txt = {10, 10};
    game_runner_t *data = (game_runner_t *) manager->data;
    game_player_t *player = (game_player_t *) scene->data;

    if (restart_game_two(scene, data) != 1)
        return (0);
    create_map_obj_from(manager->data, scene);
    sfClock_restart(scene->clock);
    player->pos = (sfVector2f) {50, 300};
    player->buffer_gravity = 0;
    player->on_ground = 0;
    sfSprite_setPosition(player->sprite, player->pos);
    create_text(scene, FONT_PATH, pos_txt, o_update_game_time);
    return (1);
}

int s_create_game(scene_entity_t *scene,
        window_controller_t *manager)
{
    game_runner_t *data = (game_runner_t *) manager->data;

    scene->clock = sfClock_create();
    if (!scene->clock)
        return (0);
    scene->data = malloc(sizeof(game_player_t));
    if (!scene->data)
        return (0);
    if (!create_scene_data((game_player_t *) scene->data, data))
        return (0);
    return (1);
}
