/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** pass the game status to menu scene
*/

#include "my_gras.h"
#include "my_runner.h"

void explode_sprite(sfSprite *sprite, window_controller_t *manager,
        game_player_t *player)
{
    float i = 0;
    sfIntRect rect = {0, 0, 100, 100};
    float seconds = 0;
    sfVector2f pos = {player->pos.x - 50, player->pos.y - 50};

    sfSprite_setPosition(sprite, pos);
    sfClock_restart(manager->clock);
    seconds = sfTime_asSeconds(sfClock_getElapsedTime(manager->clock));
    sfRenderWindow_clear(manager->win, sfBlack);
    while (rect.left < 1000) {
        if (seconds > 1.0 / 15.0 + i) {
            sfRenderWindow_clear(manager->win, sfBlack);
            sfSprite_setTextureRect(sprite, rect);
            rect.left += 100;
            sfRenderWindow_drawSprite(manager->win, sprite, NULL);
            i += 0.1;
        }
        sfRenderWindow_display(manager->win);
        seconds = sfTime_asSeconds(sfClock_getElapsedTime(manager->clock));
    }
}

sfSound *create_the_music(void)
{
    sfSoundBuffer *sound_buffer = sfSoundBuffer_createFromFile(DEATH_SOUND);
    sfSound *sound = NULL;

    if (!sound_buffer)
        return (NULL);
    sound = sfSound_create();
    if (!sound)
        return (NULL);
    sfSound_setBuffer(sound, sound_buffer);
    sfSound_play(sound);
    return (sound);
}

void destroy_this(sfTexture *texture, sfSprite *sprite, sfSound *sound)
{
    sfSoundBuffer const *buff;

    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    if (sound) {
        buff = sfSound_getBuffer(sound);
        sfSound_stop(sound);
        sfSound_destroy(sound);
        sfSoundBuffer_destroy((sfSoundBuffer *) buff);
    }
}

void do_icon_explode(window_controller_t *manager, int is_win,
        scene_entity_t *scene)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfSound *sound = NULL;

    if (is_win)
        return;
    sound = create_the_music();
    texture = sfTexture_createFromFile(ICON_EXPLODE, NULL);
    if (!texture)
        return;
    sprite = sfSprite_create();
    if (!sprite) {
        sfTexture_destroy(texture);
        return;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    explode_sprite(sprite, manager, scene->data);
    destroy_this(texture, sprite, sound);
}

int pass_game_to_menu(window_controller_t *manager, int is_win)
{
    game_runner_t *data = (game_runner_t *) manager->data;
    scene_entity_t *scene = get_current_scene_entity(manager);

    if (data->settings.global_sound) {
        sfMusic_stop(data->music);
        sfMusic_play(data->music);
        data->is_playing = 1;
    }
    data->is_win = is_win;
    destroy_all_scene_obj(scene);
    manager->current_zindex = 1;
    do_icon_explode(manager, is_win, scene);
    return (0);
}
