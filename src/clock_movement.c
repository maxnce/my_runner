/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** clock_movement
*/

#include "../include/my_runner.h"

void clock_movement(texture_t *txtr, misc_t *misc)
{
    sfText_setString(txtr->text, txtr->score);
    if (sfClock_getElapsedTime(misc->jumptimer).microseconds > 2000) {
            jump(&txtr->pos, misc);
            sfClock_restart(misc->jumptimer);
            update_positions(txtr);
        }
        if (sfClock_getElapsedTime(misc->clock).microseconds > 75000) {
            move_rect(&txtr->rect, 224, 448);
            sfClock_restart(misc->clock);
        }
}