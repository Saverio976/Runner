/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** update the game scene
*/

#include "my_gras.h"
#include "my_runner.h"

static int check_point_in(float px, float py, sfFloatRect *rect)
{
    if (rect->left <= px && px <= rect->left + rect->width &&
            rect->top <= py && py <= rect->top + rect->height)
        return (1);
    return (0);
}

static int colision_between(game_player_t *player,
        __attribute((unused)) object_entity_t *obj, sfFloatRect *bounds,
        sfFloatRect *pl_bounds)
{
    int passed = 0;

    player->buffer_gravity = 0;
    while (player->on_ground == 0 &&
            (check_point_in(bounds->left + bounds->width, bounds->top,
                pl_bounds) ||
            check_point_in(bounds->left, bounds->top, pl_bounds))) {
        passed = 1;
        player->pos.y -= 1;
        pl_bounds->top -= 1;
        sfSprite_setPosition(player->sprite, player->pos);
    }
    player->pos.y += 1;
    sfSprite_setPosition(player->sprite, player->pos);
    player->on_ground = passed;
    return (1);
}

static int update_pos_player(game_player_t *player, object_entity_t *objs)
{
    sfFloatRect bounds;
    sfFloatRect pl_bounds = sfSprite_getGlobalBounds(player->sprite);
    int game_continue = 1;

    for (objs = objs->next; game_continue && objs != NULL; objs = objs->next) {
        if (objs->type != SPRITE) {
            continue;
        }
        bounds = sfSprite_getGlobalBounds(objs->sprite);
        if (bounds.width == 800)
            continue;
        if (check_point_in(bounds.left, bounds.top, &pl_bounds) ||
                check_point_in(bounds.left + bounds.width,
                    bounds.top + bounds.height, &pl_bounds) ||
                check_point_in(bounds.left, bounds.top + bounds.height,
                    &pl_bounds) ||
                check_point_in(bounds.left + bounds.width, bounds.top,
                    &pl_bounds))
            game_continue = colision_between(player, objs, &bounds, &pl_bounds);
    }
    return (game_continue);
}

static void check_loose_player(window_controler_t *manager,
        game_player_t *player, object_entity_t *bg)
{
    sfFloatRect bounds_bg = sfSprite_getGlobalBounds(bg->sprite);
    sfFloatRect bounds_pl = sfSprite_getGlobalBounds(player->sprite);

    if (!check_point_in(bounds_pl.left, bounds_pl.top, &bounds_bg) ||
            !check_point_in(bounds_pl.left, bounds_pl.top + bounds_pl.height,
                &bounds_bg)) {
        manager->current_zindex = 1;
    }
}

int s_update_game(scenne_entity_t *scene,
        window_controler_t *manager)
{
    game_player_t *player = (game_player_t *) scene->data;
    object_entity_t *objs = scene->objects;

    if (sfKeyboard_isKeyPressed(sfKeySpace) && player->on_ground == 1) {
        player->buffer_gravity -= player->gravity * 8;
        player->pos.y -= 10;
        player->on_ground = 0;
    }
    player->buffer_gravity += player->gravity;
    if (!update_pos_player(player, objs)) {
        manager->current_zindex = 1;
        return (0);
    }
    player->pos.y += player->buffer_gravity;
    sfSprite_setPosition(player->sprite, player->pos);
    check_loose_player(manager, player, objs);
    sfRenderWindow_drawSprite(manager->win, player->sprite, NULL);
    return (0);
}
