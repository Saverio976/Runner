/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** update the game scene
*/

#include "my_gras.h"
#include "my_runner.h"

static int colision_between(game_player_t *player,
        object_entity_t *obj, window_controler_t *manager)
{
    int passed = 0;
    sfFloatRect pl_bounds = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect bounds = sfSprite_getGlobalBounds(obj->sprite);

    if (obj->data != NULL)
        return (pass_game_to_menu(manager));
    player->buffer_gravity = 0;
    while (player->on_ground == 0 &&
            (check_point_in(bounds.left + bounds.width, bounds.top,
                &pl_bounds) ||
            check_point_in(bounds.left, bounds.top, &pl_bounds))) {
        passed = 1;
        player->pos.y -= 1;
        pl_bounds.top -= 1;
        sfSprite_setPosition(player->sprite, player->pos);
    }
    player->pos.y += 2;
    sfSprite_setPosition(player->sprite, player->pos);
    player->on_ground = passed;
    return (1);
}

static int update_pos_player(game_player_t *player, object_entity_t *objs,
        window_controler_t *manager)
{
    sfFloatRect bounds;
    sfFloatRect pl_bounds = sfSprite_getGlobalBounds(player->sprite);
    int game_continue = 1;

    for (objs = objs; game_continue && objs != NULL; objs = objs->next) {
        if (objs->type != SPRITE)
            continue;
        bounds = sfSprite_getGlobalBounds(objs->sprite);
        if (check_point_in(bounds.left, bounds.top, &pl_bounds) ||
                check_point_in(bounds.left + bounds.width,
                    bounds.top + bounds.height, &pl_bounds) ||
                check_point_in(bounds.left, bounds.top + bounds.height,
                    &pl_bounds) ||
                check_point_in(bounds.left + bounds.width, bounds.top,
                    &pl_bounds))
            game_continue = colision_between(player, objs, manager);
    }
    return (game_continue);
}

static void check_loose_player(window_controler_t *manager,
        game_player_t *player, object_entity_t *bg)
{
    sfFloatRect bounds_bg;
    sfFloatRect bounds_pl = sfSprite_getGlobalBounds(player->sprite);

    if (bg->type != SPRITE)
        return;
    bounds_bg = sfSprite_getGlobalBounds(bg->sprite);
    if (!check_point_in(bounds_pl.left, bounds_pl.top, &bounds_bg) ||
            !check_point_in(bounds_pl.left, bounds_pl.top + bounds_pl.height,
                &bounds_bg)) {
        pass_game_to_menu(manager);
    }
}

static void update_gravity(game_player_t *player)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(player->clock)) < 1.0 / 20.0)
        return;
    if (sfKeyboard_isKeyPressed(sfKeySpace) && player->on_ground == 1) {
        player->buffer_gravity -= player->gravity * 5;
        player->pos.y -= 5;
        player->on_ground = 0;
        sfSprite_setPosition(player->sprite, player->pos);
    }
    player->buffer_gravity += player->gravity;
    sfClock_restart(player->clock);
}

int s_update_game(scenne_entity_t *scene,
        window_controler_t *manager)
{
    game_player_t *player = (game_player_t *) scene->data;
    object_entity_t *objs = scene->objects;

    update_gravity(player);
    if (!update_pos_player(player, objs, manager)) {
        manager->current_zindex = 1;
        return (0);
    }
    player->pos.y += player->buffer_gravity;
    sfSprite_setPosition(player->sprite, player->pos);
    check_loose_player(manager, player, objs);
    sfRenderWindow_drawSprite(manager->win, player->sprite, NULL);
    return (0);
}
