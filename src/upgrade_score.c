/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** my_nbrtostr
*/

#include "../include/my_runner.h"

void upgrade_score(char *score)
{
    int i = 5;

    score[i]++;
    for (; i > 0; i--)
        if (score[i] == 58) {
            score[i] = '0';
            score[i - 1]++;
            i = -1;
        }
}

char *set_score(void)
{
    char *score = malloc(sizeof(char) * 7);

    score[0] = '0';
    score[1] = '0';
    score[2] = '0';
    score[3] = '0';
    score[4] = '0';
    score[5] = '0';
    score[6] = '\0';
    return (score);
}