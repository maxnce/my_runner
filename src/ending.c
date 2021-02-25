/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** ending
*/

#include "../include/my_runner.h"

void create_death(texture_t *txtr)
{
    txtr->death = sfSprite_create();
    txtr->tdeath = sfTexture_createFromFile("assets/death.jpg", NULL);
    sfSprite_setTexture(txtr->death, txtr->tdeath, sfFalse);
}

void victory(sfRenderWindow *w, texture_t *txtr, misc_t *misc)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(w) && misc->context == 3) {
        while (sfRenderWindow_pollEvent(w, &evt)) {
            if (evt.type == sfEvtClosed || (evt.type == sfEvtKeyPressed
            && evt.key.code == sfKeyEscape))
                sfRenderWindow_close(w);
        }
        sfRenderWindow_clear(w, sfBlack);
        sfRenderWindow_drawSprite(w, txtr->win, NULL);
        sfRenderWindow_drawSprite(w, txtr->quit, NULL);
        sfRenderWindow_display(w);
    }
}

void defeat(sfRenderWindow *w, texture_t *txtr, misc_t *misc)
{
    sfEvent evt;
    while (sfRenderWindow_isOpen(w) && misc->context != 3) {
        while (sfRenderWindow_pollEvent(w, &evt)) {
            if (evt.type == sfEvtClosed || (evt.type == sfEvtKeyPressed
            && evt.key.code == sfKeyEscape))
                sfRenderWindow_close(w);
        }
        sfRenderWindow_clear(w, sfBlack);
        sfRenderWindow_drawSprite(w, txtr->death, NULL);
        sfRenderWindow_drawSprite(w, txtr->quit, NULL);
        sfRenderWindow_display(w);
    }
}

void ending(sfRenderWindow *w, texture_t *txtr, misc_t *misc)
{
    if (misc->context == 3)
        victory(w, txtr, misc);
    else
        defeat(w, txtr, misc);
}