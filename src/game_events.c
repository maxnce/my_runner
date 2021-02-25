/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** game_events
*/

#include "../include/my_runner.h"

void game_events(sfRenderWindow *w, texture_t *txtr, misc_t *misc,
                                        sfSprite **sp)
{
    if (sfClock_getElapsedTime(misc->clock).microseconds >= 70000)
            upgrade_score(txtr->score);
        clock_movement(txtr, misc);
        update_window(w, txtr, txtr->text, sp);
        misc->context = (sfSprite_getPosition(sp[txtr->nbopp - 1]).x <
        -500) ? 3 : misc->context;
        for (int i = 0; i < txtr->nbopp; i++) {
            if ((txtr->pos.x >= sfSprite_getPosition(sp[i]).x &&
            txtr->pos.x <= sfSprite_getPosition(sp[i]).x + 100 &&
            txtr->pos.y >= sfSprite_getPosition(sp[i]).y) || (txtr->pos.x + 100
            >= sfSprite_getPosition(sp[i]).x &&
            txtr->pos.x + 100 <= sfSprite_getPosition(sp[i]).x + 100 &&
            txtr->pos.y >= sfSprite_getPosition(sp[i]).y))
                misc->context = 4;
        }
}