/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** create a list of object from game_runner_t struct
*/

#include <stdlib.h>
#include <stdio.h>
#include "my_gras.h"
#include "my_runner.h"

static void process_data(game_runner_t *data, scenne_entity_t *scene, char c,
        sfVector2f pos)
{
    char const *tmp;

    if (c == 'b')
        tmp = data->block;
    else if (c == 's')
        tmp = data->spike;
    else
        return;
    pos.x *= 53;
    pos.y *= 60;
    if (c == 's') {
        pos.x -= 30;
        pos.y -= 21;
    }
    create_picture(scene, tmp, pos, o_update_game_block);
}

int create_map_obj_from(game_runner_t *data, scenne_entity_t *scene)
{
    FILE *fd = fopen(data->map_txt, "r");
    char *lineptr = NULL;
    size_t size_line = 0;
    sfVector2f pos = {0, 0};

    if (fd == NULL)
        return (0);
    for (int i = 0; getline(&lineptr, &size_line, fd) != -1; i++) {
        for (int j = 0; lineptr[j] != '\0'; j++) {
            pos.y = i;
            pos.x = j;
            process_data(data, scene, lineptr[j], pos);
        }
        free(lineptr);
        size_line = 0;
    }
    return (1);
}
