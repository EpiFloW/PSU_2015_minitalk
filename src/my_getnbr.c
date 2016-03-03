/*
** my_getnbr.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minitalk/src
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Mon Feb  1 23:33:02 2016 Maisonnave Florian
** Last update Tue Feb  2 15:25:16 2016 Maisonnave Florian
*/

#include "minitalk.h"

int	my_neg(char *str)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	c++;
      i++;
    }
  if (c % 2 != 0)
    return (1);
  else
    return (0);
}

int	my_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int	my_getnbr(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (my_num(str[i]) == 0)
    i++;
  while (my_num(str[i]) == 1)
    {
      nb = ((nb * 10) + (str[i] - 48));
      i++;
    }
  if (my_neg(str) == 1)
    nb = -nb;
  return (nb);
}
