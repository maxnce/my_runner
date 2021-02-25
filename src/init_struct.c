/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** init_struct
*/

#include "../include/my_runner.h"

void load_parameters(texture_t *t)
{
    sfSprite_setTexture(t->finn, t->tfinn, sfFalse);
    sfSprite_setTexture(t->bg, t->tbg, sfFalse);
    sfSprite_setTextureRect(t->finn, t->rect);
    sfSprite_setTexture(t->stars1, t->tstars1, sfFalse);
    sfSprite_setTexture(t->clouds1, t->tclouds1, sfFalse);
    sfSprite_setTexture(t->clouds2, t->tclouds2, sfFalse);
    sfSprite_setTexture(t->clouds3, t->tclouds3, sfFalse);
    sfSprite_setTexture(t->stars2, t->tstars2, sfFalse);
    sfSprite_setTexture(t->stars3, t->tstars3, sfFalse);
    sfSprite_setTexture(t->smell, t->tsmell, sfFalse);
    sfSprite_setTexture(t->castle, t->tcastle, sfFalse);
    sfSprite_setTexture(t->advtime, t->tadvtime, sfFalse);
    sfSprite_setTexture(t->rnstyle, t->trnstyle, sfFalse);
    sfSprite_setTexture(t->clds, t->tclds, sfFalse);
    sfSprite_setTexture(t->space, t->tspace, sfFalse);
    sfSprite_setTexture(t->quit, t->tquit, sfFalse);
    sfSprite_setPosition(t->advtime, t->advtimepos);
    sfSprite_setPosition(t->rnstyle, t->rnstylepos);
    sfSprite_setPosition(t->space, t->spacepos);
    sfSprite_setPosition(t->quit, t->quitpos);
    sfSprite_setRotation(t->rnstyle, -20.0);
}

void init_pos(texture_t *txture)
{
    txture->clouds1pos = (sfVector2f){0, 0};
    txture->clouds2pos = (sfVector2f){0, 0};
    txture->clouds3pos = (sfVector2f){0, 0};
    txture->stars1pos = (sfVector2f){0, 0};
    txture->castlepos = (sfVector2f){0, 0};
    txture->stars2pos = (sfVector2f){0, 0};
    txture->stars3pos = (sfVector2f){0, 0};
    txture->smellpos = (sfVector2f){0, 0};
    txture->advtimepos = (sfVector2f){400, 50};
    txture->rnstylepos = (sfVector2f){1100, 500};
    txture->spacepos = (sfVector2f){700, 600};
    txture->quitpos = (sfVector2f){700, 700};
    txture->pos = (sfVector2f){30, 900};
}

void init_textures(texture_t *txture)
{
    txture->tfinn = sfTexture_createFromFile("assets/finn.png", NULL);
    txture->tbg = sfTexture_createFromFile("assets/bg.png", NULL);
    txture->tclouds1 = sfTexture_createFromFile("assets/clouds1.png", NULL);
    txture->tclouds2 = sfTexture_createFromFile("assets/clouds2.png", NULL);
    txture->tclouds3 = sfTexture_createFromFile("assets/clouds3.png", NULL);
    txture->tstars1 = sfTexture_createFromFile("assets/stars1.png", NULL);
    txture->tstars2 = sfTexture_createFromFile("assets/stars2.png", NULL);
    txture->tstars3 = sfTexture_createFromFile("assets/stars3.png", NULL);
    txture->tcastle = sfTexture_createFromFile("assets/castle.png", NULL);
    txture->tsmell = sfTexture_createFromFile("assets/smell.png", NULL);
    txture->tadvtime =
    sfTexture_createFromFile("assets/adventure_time.png", NULL);
    txture->trnstyle = sfTexture_createFromFile("assets/rnnstyle.png", NULL);
    txture->tclds = sfTexture_createFromFile("assets/clouds_ss.jpg", NULL);
    txture->tspace = sfTexture_createFromFile("assets/space.png", NULL);
    txture->tquit = sfTexture_createFromFile("assets/quit.png", NULL);
}

void init_sprites(texture_t *txture)
{
    txture->finn = sfSprite_create();
    txture->bg = sfSprite_create();
    txture->clouds1 = sfSprite_create();
    txture->clouds2 = sfSprite_create();
    txture->clouds3 = sfSprite_create();
    txture->stars1 = sfSprite_create();
    txture->smell = sfSprite_create();
    txture->castle = sfSprite_create();
    txture->stars2 = sfSprite_create();
    txture->stars3 = sfSprite_create();
    txture->advtime = sfSprite_create();
    txture->rnstyle = sfSprite_create();
    txture->clds = sfSprite_create();
    txture->space = sfSprite_create();
    txture->quit = sfSprite_create();
}

texture_t init_texture(char *file)
{
    texture_t txture;

    init_sprites(&txture);
    init_textures(&txture);
    init_pos(&txture);
    txture.rect = load_rect(32, 224, 0, 32);
    txture.font = sfFont_createFromFile("assets/AmericanCaptain.ttf");
    txture.text = sfText_create();
    txture.score = set_score();
    txture.nbopp = calculate_enemies(file);
    txture.win = sfSprite_create();
    txture.twin = sfTexture_createFromFile("assets/win.png", NULL);
    load_parameters(&txture);
    sfSprite_setTexture(txture.win, txture.twin, sfFalse);
    sfSprite_setPosition(txture.win, (sfVector2f){850, 200});
    sfText_setFont(txture.text, txture.font);
    sfText_setScale(txture.text, (sfVector2f){2.0, 2.0});
    sfText_setPosition(txture.text, (sfVector2f){1750, 0});
    create_death(&txture);
    return (txture);
}