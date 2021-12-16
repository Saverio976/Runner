/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** check if a point is in a suqare
*/

#include "my_gras.h"
#include "my_runner.h"

int collision_between(game_player_t *player, object_entity_t *obj)
{
    sfFloatRect bounds_pl = sfSprite_getGlobalBounds(player->sprite);
    sfFloatRect bounds_ob = sfSprite_getGlobalBounds(obj->sprite);

    if (bounds_ob.top + bounds_ob.height < bounds_pl.top ||
            bounds_ob.top > bounds_pl.top + bounds_pl.height ||
            bounds_ob.left + bounds_ob.width < bounds_pl.left ||
            bounds_ob.left > bounds_pl.left + bounds_pl.width)
        return (0);
    return (1);
}

int check_point_in(float px, float py, sfFloatRect *rect)
{
    if (rect->left <= px && px <= rect->left + rect->width &&
            rect->top <= py && py <= rect->top + rect->height)
        return (1);
    return (0);
}
