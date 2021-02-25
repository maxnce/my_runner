/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** init_misc
*/

#include "../include/my_runner.h"

misc_t init_misc(void)
{
    misc_t misc;
    misc.clock = sfClock_create();
    misc.jumptimer = sfClock_create();
    misc.jumping = 0;
    misc.context = 0;
    misc.intro = sfMusic_createFromFile("assets/intro.ogg");
    misc.main = sfMusic_createFromFile("assets/main.ogg");
    sfMusic_play(misc.intro);
    sfMusic_setLoop(misc.intro, sfTrue);
    return (misc);
}