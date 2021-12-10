/*
** EPITECH PROJECT, 2021
** LIBMY
** File description:
** the internal function and structure for printf
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdarg.h>

struct specifier_struct {
    char prefix;
    int (*fptr)(va_list);
};
typedef struct specifier_struct specifier_t;

// print char
int print_c(va_list);

// print int
int print_d(va_list);

// print uint
int print_u(va_list);

// print uint in octal
int print_o(va_list);

// print uint in binary
int print_b(va_list);

// print uint in hexa low
int print_x_low(va_list);

// print uint in hexa up
int print_x_up(va_list);

// print str
int print_s(va_list);

// print %
int print_mod(va_list);

#endif
