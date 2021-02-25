/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** load_file
*/

#include "../include/my_runner.h"

char *load_file(char *path)
{
    int fd = open(path, O_RDONLY);
    char *buffer = malloc(sizeof(char) * (1000 + 1));

    if (fd == -1)
        return "";
    buffer[read(fd, buffer, 1000)] = '\0';
    return (buffer);
}
