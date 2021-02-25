/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** free_all
*/

#include "../include/my_runner.h"

void destroy_sprites(texture_t txtr)
{
    sfSprite_destroy(txtr.finn);
    sfSprite_destroy(txtr.bg);
    sfSprite_destroy(txtr.clouds1);
    sfSprite_destroy(txtr.clouds2);
    sfSprite_destroy(txtr.clouds3);
    sfSprite_destroy(txtr.stars1);
    sfSprite_destroy(txtr.smell);
    sfSprite_destroy(txtr.castle);
    sfSprite_destroy(txtr.stars2);
    sfSprite_destroy(txtr.stars3);
    sfSprite_destroy(txtr.advtime);
    sfSprite_destroy(txtr.rnstyle);
    sfSprite_destroy(txtr.clds);
    sfSprite_destroy(txtr.space);
    sfSprite_destroy(txtr.quit);
    sfSprite_destroy(txtr.win);
    sfSprite_destroy(txtr.death);
}

void destroy_textures(texture_t txtr)
{
    sfTexture_destroy(txtr.tfinn);
    sfTexture_destroy(txtr.tbg);
    sfTexture_destroy(txtr.tclouds1);
    sfTexture_destroy(txtr.tclouds2);
    sfTexture_destroy(txtr.tclouds3);
    sfTexture_destroy(txtr.tstars1);
    sfTexture_destroy(txtr.tsmell);
    sfTexture_destroy(txtr.tcastle);
    sfTexture_destroy(txtr.tstars2);
    sfTexture_destroy(txtr.tstars3);
    sfTexture_destroy(txtr.tadvtime);
    sfTexture_destroy(txtr.trnstyle);
    sfTexture_destroy(txtr.tclds);
    sfTexture_destroy(txtr.tspace);
    sfTexture_destroy(txtr.tquit);
    sfTexture_destroy(txtr.twin);
    sfTexture_destroy(txtr.tdeath);
}

void destroy_misc(texture_t txtr, misc_t misc)
{
    sfText_destroy(txtr.text);
    sfFont_destroy(txtr.font);
    free(txtr.score);
    sfClock_destroy(misc.clock);
    sfClock_destroy(misc.jumptimer);
}

void free_all(texture_t txtr, misc_t misc, sfSprite **sp)
{
    destroy_sprites(txtr);
    destroy_textures(txtr);
    destroy_misc(txtr, misc);
    for (int i = 0; i < txtr.nbopp; i++)
        sfSprite_destroy(sp[i]);
    free(sp);
}