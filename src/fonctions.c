/*
** fonctions.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minitalk/src
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Mon Feb  1 23:33:18 2016 Maisonnave Florian
** Last update Tue Feb  2 15:25:27 2016 Maisonnave Florian
*/

#include "minitalk.h"

void	my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_putnbr(int nb)
{
  int	i;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  i = nb % 10;
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(i + 48);
}
