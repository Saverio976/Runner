/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** show the time passed
*/

#include "my_gras.h"
#include "my_runner.h"

char *transform_to_str(float time)
{
    static char buff[15] = "time : 00.00";
    int nb = ((int) (time * 100)) % 10000;

    buff[11] = (nb % 10) + '0';
    nb /= 10;
    buff[10] = (nb % 10) + '0';
    nb /= 10;
    buff[8] = (nb % 10) + '0';
    nb /= 10;
    buff[7] = (nb % 10) + '0';
    return (buff);
}

int o_update_game_time(object_entity_t *obj,
        scenne_entity_t *scene,
        window_controler_t *manager)
{
    float time = sfTime_asSeconds(sfClock_getElapsedTime(scene->clock));

    sfText_setString(obj->text, transform_to_str(time));
    sfText_setCharacterSize(obj->text, 28);
    sfText_setFillColor(obj->text, sfGreen);
    sfRenderWindow_drawText(manager->win, obj->text, NULL);
    return (0);
}
