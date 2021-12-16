/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** update the game scene
*/

#include "my_gras.h"
#include "my_runner.h"

static int collision_between(game_player_t *player, object_entity_t *obj)
{
    sfFloatRect bounds_pl = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect bounds_ob = sfSprite_getGlobalBounds(obj->sprite);

    if (check_point_in(bounds_ob.left, bounds_ob.top, &bounds_pl) ||
            check_point_in(bounds_ob.left + bounds_ob.width,
                bounds_ob.top + bounds_ob.height, &bounds_pl) ||
            check_point_in(bounds_ob.left, bounds_ob.top + bounds_ob.height,
                &bounds_pl) ||
            check_point_in(bounds_ob.left + bounds_ob.width, bounds_ob.top,
                &bounds_pl))
        return (1);
    return (0);
}

static int check_end_game(game_player_t *player, scene_entity_t *scene)
{
    sfFloatRect bounds_pl = sfSprite_getGlobalBounds(player->sprite);
    object_entity_t *cursor = scene->objects;
    int ret = 0;

    if (bounds_pl.top + bounds_pl.height > 600)
        return (1);
    for (; cursor != NULL; cursor = cursor->next) {
        if (cursor->type != SPRITE)
            continue;
        if (collision_between(player, cursor) == 0 || cursor->data == NULL)
            continue;
        if (cursor->data == (void *) 1)
            ret = 1;
        else
            ret = 2;
    }
    return (ret);
}

static int jump_player(game_player_t *player)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(player->clock)) < 1.0 / 20.0)
        return (0);
    if (sfKeyboard_isKeyPressed(sfKeySpace) && player->on_ground == 1) {
        player->buffer_gravity -= player->gravity * 5;
        player->pos.y -= 5;
        player->on_ground = 0;
        sfSprite_setPosition(player->sprite, player->pos);
    }
    if (player->on_ground == 0) {
        player->buffer_gravity += player->gravity;
        sfSprite_rotate(player->sprite, 25);
    } else {
        player->buffer_gravity += player->gravity / 2;
        sfSprite_setRotation(player->sprite, 0);
    }
    sfClock_restart(player->clock);
    return (0);
}

static int update_gravity_player(game_player_t *player, scene_entity_t *scene)
{
    sfFloatRect bounds_pl = sfSprite_getGlobalBounds(player->sprite);
    object_entity_t *cursor = scene->objects;

    for (; cursor != NULL; cursor = cursor->next) {
        if (cursor->type != SPRITE || collision_between(player, cursor) == 0 ||
                cursor->data != NULL)
            continue;
        if (bounds_pl.top + bounds_pl.height > cursor->pos.y + 40)
            return (1);
        while (bounds_pl.top + bounds_pl.height > cursor->pos.y) {
            player->pos.y -= 1;
            bounds_pl.top -= 1;
            player->on_ground = 1;
            player->buffer_gravity = 0;
        }
    }
    jump_player(player);
    player->pos.y += player->buffer_gravity;
    return (0);
}

int player_update(scene_entity_t *scene,
        window_controller_t *manager)
{
    game_player_t *player = (game_player_t *) scene->data;
    int end = check_end_game(player, scene);

    if (end == 1)
        return (pass_game_to_menu(manager, 0));
    if (end == 2)
        return (pass_game_to_menu(manager, 1));
    end = update_gravity_player(player, scene);
    if (end == 1)
        return (pass_game_to_menu(manager, 0));
    sfSprite_setPosition(player->sprite, player->pos);
    sfRenderWindow_drawSprite(manager->win, player->sprite, NULL);
    return (0);
}
