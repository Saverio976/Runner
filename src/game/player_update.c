/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** update the game scene
*/

#include "my_gras.h"
#include "my_runner.h"

static int check_end_game(game_player_t *player, scene_entity_t *scene)
{
    sfFloatRect bounds_pl = sfSprite_getGlobalBounds(player->sprite);
    object_entity_t *cursor = scene->objects;
    int ret = 0;

    if (bounds_pl.top + bounds_pl.height > 600)
        return (1);
    for (; cursor != NULL; cursor = cursor->next) {
        if (cursor->type != SPRITE || collision_between(player, cursor) == 0)
            continue;
        if (cursor->data == NULL || cursor->data == (void *) 98 ||
                cursor->data == (void *) 106)
            continue;
        if (cursor->data == (void *) 115)
            ret = 1;
        if (cursor->data == (void *) 102)
            ret = 2;
    }
    return (ret);
}

static int jump_player(game_player_t *player)
{
    if ((sfKeyboard_isKeyPressed(sfKeySpace) ||
                sfKeyboard_isKeyPressed(sfKeyUp)) && player->on_ground == 1) {
        player->buffer_gravity -= player->gravity * 5;
        player->pos.y -= 5;
        player->on_ground = 0;
        sfSprite_setPosition(player->sprite, player->pos);
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(player->clock)) < 1.0 / 20.0)
        return (0);
    if (player->on_ground == 0) {
        player->buffer_gravity += player->gravity;
        sfSprite_rotate(player->sprite, 25);
    } else {
        sfSprite_setRotation(player->sprite, 0);
    }
    sfClock_restart(player->clock);
    return (0);
}

static void do_update_buffer_gravity(sfFloatRect b, object_entity_t *c,
        game_player_t *player, int *on_ground)
{
    if (b.top + b.height > c->pos.y + 10 && c->data == (void *) 106) {
        player->buffer_gravity -= player->gravity * 6;
        player->pos.y -= 60;
        player->on_ground = 0;
        return;
    }
    *on_ground = 1;
    sfSprite_setRotation(player->sprite, 0);
    b = sfSprite_getGlobalBounds(player->sprite);
    while (b.top + b.height < c->pos.y) {
        b.top += 1;
        player->pos.y += 1;
        player->buffer_gravity = 0;
    }
    while (b.top + b.height > c->pos.y) {
        b.top -= 1;
        player->pos.y -= 1;
        player->buffer_gravity = 0;
    }
    player->pos.y += 3;
}

static int update_buffer_gravity_player(game_player_t *player,
        scene_entity_t *scene)
{
    sfFloatRect b = sfSprite_getGlobalBounds(player->sprite);
    object_entity_t *cursor = scene->objects;
    sfFloatRect bounds;
    int on_ground = 0;

    for (; cursor != NULL; cursor = cursor->next) {
        if (cursor->type != SPRITE || collision_between(player, cursor) == 0 ||
                (cursor->data != (void *) 98 && cursor->data != (void *) 106))
            continue;
        bounds = sfSprite_getGlobalBounds(cursor->sprite);
        if (bounds.width > 500)
            continue;
        if (b.top + b.height > cursor->pos.y + 40 &&
                cursor->data == (void *) 98)
            return (1);
        do_update_buffer_gravity(b, cursor, player, &on_ground);
    }
    player->on_ground = on_ground;
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
    end = update_buffer_gravity_player(player, scene);
    if (end == 1)
        return (pass_game_to_menu(manager, 0));
    jump_player(player);
    player->pos.y += player->buffer_gravity;
    sfSprite_setPosition(player->sprite, player->pos);
    sfRenderWindow_drawSprite(manager->win, player->sprite, NULL);
    return (0);
}
