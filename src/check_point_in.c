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

    if (sfFloatRect_intersects(&bounds_pl, &bounds_ob, NULL))
        return (1);
    return (0);
}

int check_point_in(float px, float py, sfFloatRect *rect)
{
    if (rect->left <= px && px <= rect->left + rect->width &&
            rect->top <= py && py <= rect->top + rect->height)
        return (1);
    return (0);
}
