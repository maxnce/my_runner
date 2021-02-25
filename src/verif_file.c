/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** verif_file
*/

#include "../include/my_runner.h"

int verif_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return (84);
    else
        return (0);
}