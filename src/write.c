/*
** EPITECH PROJECT, 2021
** MYRUNNER
** File description:
** write something
*/

#include <unistd.h>

int len_calc(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int print_error(char const *exe, char const *str)
{
    write(2, exe, len_calc(exe));
    write(2, str, len_calc(str));
    return (84);
}

int print_msg(char const *msg)
{
    write(1, msg, len_calc(msg));
    return (0);
}

int print_help(char const *exe)
{
    print_msg("Finite runner created with CSFML\n\n"
            "USAGE\n\t");
    print_msg(exe);
    print_msg(" map.txt [flag]\n\n"
            "DESCRIPTION\n"
            "\tmap.txt\tthe map to load (for example : map/42.txt)\n"
            "\tflag\t-f\tto force the fullscreen [use it if you dare]\n\n"
            "OPTIONS\n"
            "\t-h\tprint the usage\n\n"
            "USER INTERACTIONS\n"
            "\tSpace\tjump in the game / start the game\n"
            "\tEscape\tquit the window\n"
            "\tPause\tpause the game / resume it\n");
    return (0);
}
