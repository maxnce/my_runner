/*
** EPITECH PROJECT, 2020
** my_runner
** File description:
** my_runner
*/

#ifndef MY_RUNNER_H_
#define MY_RUNNER_H_

//Includes
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Window/Event.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/RenderTexture.h>
#include <SFML/System/Time.h>
#include <SFML/System/Clock.h>
#include <SFML/Graphics/Text.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio.h>
#include <SFML/Audio/Types.h>
#include <SFML/Audio/Export.h>
#include <SFML/Config.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Listener.h>
#include <SFML/Audio/SoundStream.h>
#include <SFML/System.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <SFML/System/InputStream.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics/Font.h>

//structures

typedef struct textures {
    sfSprite *finn;
    sfSprite *bg;
    sfSprite *clouds1;
    sfSprite *clouds2;
    sfSprite *clouds3;
    sfSprite *stars1;
    sfSprite *smell;
    sfSprite *castle;
    sfSprite *stars2;
    sfSprite *stars3;
    sfSprite *advtime;
    sfSprite *rnstyle;
    sfSprite *clds;
    sfSprite *space;
    sfSprite *quit;
    sfVector2f clouds1pos;
    sfVector2f clouds2pos;
    sfVector2f clouds3pos;
    sfVector2f stars1pos;
    sfVector2f castlepos;
    sfVector2f stars2pos;
    sfVector2f stars3pos;
    sfVector2f smellpos;
    sfVector2f advtimepos;
    sfVector2f rnstylepos;
    sfVector2f spacepos;
    sfVector2f quitpos;
    sfVector2f pos;
    sfTexture *tfinn;
    sfTexture *tbg;
    sfTexture *tclouds1;
    sfTexture *tclouds2;
    sfTexture *tclouds3;
    sfTexture *tstars1;
    sfTexture *tstars2;
    sfTexture *tstars3;
    sfTexture *tcastle;
    sfTexture *tsmell;
    sfTexture *tadvtime;
    sfTexture *trnstyle;
    sfTexture *tclds;
    sfTexture *tspace;
    sfTexture *tquit;
    sfIntRect rect;
    int nbopp;
    sfFont *font;
    sfText *text;
    char *score;
    sfSprite *win;
    sfTexture *twin;
    sfSprite *death;
    sfTexture *tdeath;
} texture_t;

typedef struct miscelanneous {
    char *file;
    sfClock *clock;
    sfClock *jumptimer;
    int jumping;
    int context;
    sfMusic *intro;
    sfMusic *main;
    sfMusic *jump;
} misc_t;

//lib
int my_strcmp(char const *s1, char const *s2);
void my_putchar(char c);
int my_put_nbr(int nb);

//usage
int usage(void);
int bad_argument(int ac);

//src
void event_window(sfEvent event, sfRenderWindow *window, texture_t *txtr,
                                misc_t *misc);
int verif_file(char *filepath);
void my_runner(char *av);
void jump(sfVector2f *pos, misc_t *misc);
void start_game(sfEvent evt, int *context);
char *load_file(char *path);
sfIntRect load_rect(int height, int left, int top, int width);
misc_t init_misc(void);
texture_t init_texture(char *file);
void start_screen(sfRenderWindow *w, texture_t *txtr, int *context,
sfEvent evt);
void update_positions(texture_t *txtr);
void update_window(sfRenderWindow *w, texture_t *txtr, sfText *text,
sfSprite **sp);
void move_rect(sfIntRect *rect, int offset, int max_value);
void clock_movement(texture_t *txtr, misc_t *misc);
void game_launch(sfRenderWindow *w, sfEvent evt, texture_t *txtr, misc_t *misc);
char *set_score(void);
void upgrade_score(char *score);
sfSprite **create_marcelines(char *file, int nb);
int calculate_enemies(char *file);
void defeat(sfRenderWindow *w, texture_t *txtr, misc_t *misc);
void ending(sfRenderWindow *w, texture_t *txtr, misc_t *misc);
void game_events(sfRenderWindow *w, texture_t *txtr, misc_t *misc,
                                        sfSprite **sp);
void create_death(texture_t *txtr);
void free_all(texture_t txtr, misc_t misc, sfSprite **sp);

#endif /* !MY_RUNNER_H_ */