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

sfMusic *create_the_music(void)
{
    sfMusic *music = sfMusic_createFromFile(DEATH_SOUND);

    if (!music)
        return (NULL);
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    return (music);
}

void destroy_this(sfTexture *texture, sfSprite *sprite, sfMusic *music)
{
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    if (music) {
        sfMusic_stop(music);
        sfMusic_destroy(music);
    }
}

void do_icon_explode(window_controller_t *manager, int is_win,
        scene_entity_t *scene)
{
    sfTexture *texture;
    sfSprite *sprite;
    sfMusic *music = NULL;

    if (is_win)
        return;
    music = create_the_music();
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
    destroy_this(texture, sprite, music);
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
