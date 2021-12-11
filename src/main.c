/*
** EPITECH PROJECT, 2021
** ...
** File description:
** the main entry point for the project
*/

#include "my_gras.h"
#include "my_runner.h"
#include "my_puts.h"

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    window_controler_t *manager = create(&w_create_runner, &w_destroy_runner);

    create_scenne(manager, &s_create_intro, &s_update_intro, &s_destroy_intro);
    create_scenne(manager, &s_create_menu, &s_update_menu, &s_destroy_menu);
    return (start(manager, "Geometry Dash", mode, sfResize));
}
