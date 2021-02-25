/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** upsate_positions
*/

#include "../include/my_runner.h"

void update_positions(texture_t *txtr)
{
    txtr->clouds1pos.x += (txtr->clouds1pos.x >= -1920) ? -5 : +1915;
    txtr->clouds2pos.x += (txtr->clouds2pos.x >= -1920) ? -4.4 : 1915.6;
    txtr->clouds3pos.x += (txtr->clouds3pos.x >= -1920) ? -4 : +1916;
    txtr->smellpos.x += (txtr->smellpos.x >= -1920) ? -3.7 : +1916.3;
    txtr->stars1pos.x += (txtr->stars1pos.x >= -1920) ? -3 : +1917;
    txtr->stars2pos.x += (txtr->stars2pos.x >= -1920) ? -2 : +1918;
    txtr->stars3pos.x += (txtr->stars3pos.x >= -1920) ? -1 : +1919;
    txtr->castlepos.x += (txtr->castlepos.x >= -1920) ? -3.2 : +1916.8;
}