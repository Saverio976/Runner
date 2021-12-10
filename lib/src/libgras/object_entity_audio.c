/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** all elements for an object entity of audio type
*/

#include <SFML/Audio.h>
#include <stdlib.h>
#include "my_gras.h"

static object_entity_t *create_music_create(char const *path, int play,
        void (*update_ptr)(object_entity_t *, scenne_entity_t *,
            window_controler_t *))
{
    object_entity_t *new = malloc(sizeof(object_entity_t));

    if (new == NULL)
        return (NULL);
    new->type = MUSIC;
    new->music = sfMusic_createFromFile(path);
    if (new->music == NULL) {
        free(new);
        return (NULL);
    }
    new->music_is_looping = 0;
    new->music_is_playing = play;
    if (play)
        sfMusic_play(new->music);
    new->update = update_ptr;
    return (new);
}

int create_music(scenne_entity_t *scene, char const *path,
        int playing_now,
        void (*update_ptr)(object_entity_t *, scenne_entity_t *,
            window_controler_t *))
{
    object_entity_t *cursor = scene->objects;
    object_entity_t *new = create_music_create(path, playing_now, update_ptr);

    if (new == NULL)
        return (0);
    if (cursor == NULL) {
        scene->objects = new;
        new->next = NULL;
        return (1);
    }
    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = new;
    return (1);
}

int destroy_music(scenne_entity_t *scene, object_entity_t *obj)
{
    object_entity_t *last = scene->objects;

    if (obj->type != MUSIC || last == NULL)
        return (0);
    while (last != NULL && last->next != obj)
        last = last->next;
    if (last == NULL)
        return (0);
    last->next = obj->next;
    if (sfMusic_getStatus(obj->music) != sfStopped) {
        sfMusic_setLoop(obj->music, sfFalse);
        sfMusic_stop(obj->music);
    }
    sfMusic_destroy(obj->music);
    free(obj);
    return (1);
}
