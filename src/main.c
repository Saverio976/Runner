/*
** EPITECH PROJECT, 2021
** MYRUNNNER
** File description:
** the main entry point for the project
*/

#include "my_gras.h"
#include "my_runner.h"
#include "my_puts.h"

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    window_controller_t *manager = create(w_create_runner, w_destroy_runner);

    if (manager == NULL)
        return (84);
    create_scene(manager, s_create_intro, s_update_intro, s_destroy_intro);
    create_scene(manager, s_create_menu, s_update_menu, s_destroy_menu);
    create_scene(manager, s_create_settings, s_update_settings,
            s_destroy_settings);
    create_scene(manager, s_create_game, s_update_game, s_destroy_game);
    return (start(manager, "Geometry Dash", mode, sfResize));
}
