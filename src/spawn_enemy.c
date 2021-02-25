/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** spawn_enemy
*/

#include "../include/my_runner.h"

sfSprite **create_marcelines(char *file, int nb)
{
    sfSprite **tab_sprite = malloc(sizeof(sfSprite *) * nb);
    sfTexture *marceline = sfTexture_createFromFile("assets/marceline.png",
    NULL);
    float x = 1920;
    int j = 0;

    for (int i = 0; i < nb; i++) {
        tab_sprite[i] = sfSprite_create();
        sfSprite_setTexture(tab_sprite[i], marceline, sfFalse);
    }
    for (int i = 0; file[i] != '\0'; i++, x += 100) {
        if (file[i] == 'e') {
            sfSprite_setPosition(tab_sprite[j], (sfVector2f){x, 870.0});
            j++;
        }
    }
    return (tab_sprite);
}

int calculate_enemies(char *file)
{
    int count = 0;

    for (int i = 0; file[i]; i++)
        count += (file[i] == 'e') ? 1 : 0;
    return (count);
}