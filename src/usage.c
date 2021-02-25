/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** usage
*/

#include "../include/my_runner.h"

int bad_argument(int ac)
{
    write(1, "./my_runner: bad arguments: ", 29);
    my_put_nbr(ac - 1);
    write(1, " given but 1 is required\nretry with -h\n", 40);
    return (84);
}

int usage(void)
{
    write(1, "Finite runner created with CSFML.\n\n", 36);
    write(1, "USAGE\n ./my_runner maps/[easy/medium/hard/your_map]\n\n\n", 55);
    write(1, "OPTIONS\n -h\t\tprint the usage and quit.\n\n", 41);
    write(1, "USER INTERACTIONS\n SPACE_KEY\tjump.\n", 37);
    write(1, "LEFT/RIGHT ARROWS\tmove to the left / right.\n", 45);
    write(1, "ESCAPE\tleave game.\n", 20);
    return (0);
}