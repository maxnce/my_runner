/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game_launch
*/

#include "../include/my_runner.h"

void game_launch(sfRenderWindow *w, sfEvent evt, texture_t *txtr, misc_t *misc)
{
    sfRenderWindow_setFramerateLimit(w, 120);
    start_screen(w, txtr, &misc->context, evt);
    sfMusic_stop(misc->intro);
    sfMusic_destroy(misc->intro);
    sfMusic_play(misc->main);
    sfMusic_setLoop(misc->main, sfTrue);
    if (misc->context == 2)
        sfRenderWindow_close(w);
}