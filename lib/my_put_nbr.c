/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** write an integer  passed as parameter using my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int reste;
    if (nb == -2147483648) {
        my_putchar('-');
        my_putchar('2');
        nb = 147483648;
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9){
        my_put_nbr(nb/10);
    }
    reste = nb % 10 + 48;
    my_putchar(reste);
    return (0);
}
