/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** start_game
*/

#include "../include/my_runner.h"

void start_game(sfEvent evt, int *context)
{
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeySpace)
        *context = 1;
    if ((evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape) ||
        evt.type == sfEvtClosed)
        *context = 2;
}

void start_screen(sfRenderWindow *w, texture_t *txtr, int *context, sfEvent evt)
{
    while (sfRenderWindow_isOpen(w) && *context == 0) {
        while (sfRenderWindow_pollEvent(w, &evt))
            start_game(evt, context);
        sfRenderWindow_clear(w, sfBlack);
        sfRenderWindow_drawSprite(w, txtr->clds, NULL);
        sfRenderWindow_drawSprite(w, txtr->advtime, NULL);
        sfRenderWindow_drawSprite(w, txtr->rnstyle, NULL);
        sfRenderWindow_drawSprite(w, txtr->space, NULL);
        sfRenderWindow_drawSprite(w, txtr->quit, NULL);
        sfRenderWindow_display(w);
    }
}