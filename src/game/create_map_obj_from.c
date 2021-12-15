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

static void process_data(game_runner_t *data, scene_entity_t *scene, char c,
        sfVector2f pos)
{
    object_entity_t *obj;
    char const *tmp;

    if (c != 'b' && c != 's' && c != 'f')
        return;
    if (c == 'b')
        tmp = data->settings.block_img;
    if (c == 's')
        tmp = data->settings.spike_img;
    if (c == 'f')
        tmp = data->settings.end_img;
    pos.x *= 53;
    pos.y *= 60;
    create_picture(scene, tmp, pos, o_update_game_block);
    for (obj = scene->objects; obj->next != NULL; obj = obj->next);
    if (c == 's')
        obj->data = (void *) 1;
    else if (c == 'f')
        obj->data = (void *) 2;
    else
        obj->data = NULL;
}

int create_map_obj_from(game_runner_t *data, scene_entity_t *scene)
{
    FILE *fd = fopen(data->settings.map_path, "r");
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
    free(lineptr);
    return (1);
}
