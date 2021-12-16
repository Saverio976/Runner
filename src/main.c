/*
** EPITECH PROJECT, 2021
** MYRUNNNER
** File description:
** the main entry point for the project
*/

#include "my_gras.h"
#include "my_runner.h"
#include <unistd.h>
#include <fcntl.h>



static int check_file_path(char **av)
{
    int fd = open(av[1], O_RDONLY);

    if (fd < 0)
        return (0);
    close(fd);
    return (1);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {800, 600, 32};
    window_controller_t *manager;

    if (ac < 2)
        return (print_error(av[0], ": need one args; retry with -h\n"));
    if (len_calc(av[1]) == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return (print_help(av[0]));
    if (check_file_path(av) == 0)
        return (print_error(av[0], ": provide a map available (map/42.txt)\n"));
    manager = create(w_create_runner, w_destroy_runner);
    if (manager == NULL)
        return (84);
    ((game_runner_t *) manager->data)->settings.map_path = av[1];
    create_scene(manager, s_create_intro, s_update_intro, s_destroy_intro);
    create_scene(manager, s_create_menu, s_update_menu, s_destroy_menu);
    create_scene(manager, s_create_settings, s_update_settings,
            s_destroy_settings);
    create_scene(manager, s_create_game, s_update_game, s_destroy_game);
    return (start(manager, "Geometry Dash", mode, sfResize));
}
