/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_runner
*/

#include "../include/my_runner.h"

sfRenderWindow *create_window(unsigned int x, unsigned int y,
unsigned int bpp, char *title)
{
    sfVideoMode video_mode = {x, y, bpp};

    return (sfRenderWindow_create(video_mode, title, sfDefaultStyle, NULL));
}

sfIntRect load_rect(int height, int left, int top, int width)
{
    sfIntRect rect;

    rect.height = height;
    rect.left = left;
    rect.top = top;
    rect.width = width;
    return (rect);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left < max_value - 32) {
        rect->left += 32;
    } else {
        rect->left = offset;
    }
}

void my_runner(char *av)
{
    char *file = load_file(av);
    texture_t txtr = init_texture(file);
    misc_t misc = init_misc();
    sfRenderWindow *w = create_window(1920, 1080, 32, "Adventure Time!");
    sfEvent evt;
    sfSprite **marcelines = create_marcelines(file, txtr.nbopp);

    game_launch(w, evt, &txtr, &misc);
    while (sfRenderWindow_isOpen(w) && misc.context == 1) {
        while (sfRenderWindow_pollEvent(w, &evt)) {
            event_window(evt, w, &txtr, &misc);
        }
        game_events(w, &txtr, &misc, marcelines);
    }
    ending(w, &txtr, &misc);
    free_all(txtr, misc, marcelines);
    sfRenderWindow_destroy(w);
}