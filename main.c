/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** main
*/

#include "include/my_runner.h"

int main(int ac, char **av)
{
    if (ac == 1 || ac > 2)
        return (bad_argument(ac));
    if (my_strcmp("-h", av[1]) == 0)
        return (usage());
    ac = verif_file(av[1]);
    if (ac == 84)
        return (84);
    else
        my_runner(av[1]);
    return (0);
}