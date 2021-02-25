/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** reproduce the behavior of strcmpfnctn
*/

int my_strcmp(char const *s1, char const *s2)
{
    int index = 0;

    while (s1[index] == s2[index] &&
    s1[index] != '\0' &&
    s2[index] != '\0') {
        index++;
    }
    if (s1[index] == s2[index]) {
        return (0);
    } else {
        if (s1[index] > s2[index]) {
            return (1);
        }
        if (s1[index] < s2[index]) {
            return (-1);
        }
    }
    return (84);
}