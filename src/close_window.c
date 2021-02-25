/*
** EPITECH PROJECT, 2020
** B-MUL-100-LYN-1-1-myhunter-maxence.pellouin
** File description:
** close_window
*/

#include "../include/my_runner.h"

void draw_sprites(sfRenderWindow *w, texture_t *txtr, sfSprite **sp)
{
    sfVector2f pos;
    sfRenderWindow_drawSprite(w, txtr->stars2, NULL);
    sfRenderWindow_drawSprite(w, txtr->stars1, NULL);
    sfRenderWindow_drawSprite(w, txtr->castle, NULL);
    sfRenderWindow_drawSprite(w, txtr->smell, NULL);
    sfRenderWindow_drawSprite(w, txtr->clouds3, NULL);
    sfRenderWindow_drawSprite(w, txtr->clouds2, NULL);
    sfRenderWindow_drawSprite(w, txtr->clouds1, NULL);
    sfRenderWindow_drawSprite(w, txtr->finn, NULL);
    for (int i = 0; i < txtr->nbopp; i++) {
        pos = sfSprite_getPosition(sp[i]);
        pos.x -= 5;
        sfSprite_setPosition(sp[i], pos);
        sfRenderWindow_drawSprite(w, sp[i], NULL);
    }
    sfRenderWindow_display(w);
}

void update_window(sfRenderWindow *w, texture_t *txtr, sfText *text,
                                            sfSprite **sp)
{
    sfRenderWindow_clear(w, sfBlack);
    sfSprite_setTextureRect(txtr->finn, txtr->rect);
    sfSprite_setPosition(txtr->clouds1, txtr->clouds1pos);
    sfSprite_setPosition(txtr->clouds2, txtr->clouds2pos);
    sfSprite_setPosition(txtr->clouds3, txtr->clouds3pos);
    sfSprite_setPosition(txtr->stars1, txtr->stars1pos);
    sfSprite_setPosition(txtr->finn, txtr->pos);
    sfSprite_setPosition(txtr->stars2, txtr->stars2pos);
    sfSprite_setPosition(txtr->stars3, txtr->stars3pos);
    sfSprite_setPosition(txtr->smell, txtr->smellpos);
    sfSprite_setPosition(txtr->castle, txtr->castlepos);
    sfSprite_setScale(txtr->finn, (sfVector2f){5.0, 5.0});
    sfRenderWindow_drawSprite(w, txtr->bg, NULL);
    sfRenderWindow_drawSprite(w, txtr->stars3, NULL);
    sfRenderWindow_drawText(w, text, NULL);
    draw_sprites(w, txtr, sp);
}

void jump(sfVector2f *pos, misc_t *misc)
{
    if (pos->y >= 550 && misc->jumping == 1) {
        pos->y -= ((pos->y / 100) * (20 * pos->y / 1000)) / 15;
        if (pos->y <= 550)
            misc->jumping = -1;
        sfMusic_stop(misc->jump);
    }
    if (pos->y <= 900 && misc->jumping == -1)
        pos->y += ((pos->y / 100) * (20 * pos->y / 1000)) / 15;
    if (pos->y >= 900 && misc->jumping == -1) {
        pos->y = 900;
        misc->jumping = 0;
    }

}

void event_window(sfEvent event, sfRenderWindow *window, texture_t *txtr,
                                misc_t *misc)
{
    misc->jump = sfMusic_createFromFile("assets/jump.ogg");
    sfMusic_setVolume(misc->jump, 5);
    if (event.type == sfEvtClosed || (event.type == sfEvtKeyPressed
        && event.key.code == sfKeyEscape))
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        if (txtr->pos.x > 4)
            txtr->pos.x -= 7;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        if (txtr->pos.x + 64 < 800)
            txtr->pos.x += 10;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace
    && misc->jumping == 0) {
        misc->jumping = 1;
        sfMusic_play(misc->jump);
    }
}