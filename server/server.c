/*
** server.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minitalk/src
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Mon Feb  1 23:32:43 2016 Maisonnave Florian
** Last update Mon Feb  8 19:11:07 2016 Maisonnave Florian
*/

#include "minitalk.h"

void			one_or_zero(unsigned int b)
{
  static unsigned char	c = 0;
  static unsigned int	i = 0;
  static int		x = 0;

  c += b << i;
  i++;
  if (c == '=')
    x = 1;
  if (i == 8)
    {
      if (x == 1)
	my_putchar(61);
      my_putchar(c);
      c = 0;
      i = 0;
      x = 0;
    }
}

void	handler(int i)
{
  if (i == SIGUSR1)
    one_or_zero(1);
  if (i == SIGUSR2)
    one_or_zero(0);
}

int	main()
{
  pid_t	pid;

  pid = getpid();
  my_putnbr(pid);
  my_putchar('\n');
  if ((signal(SIGUSR1, handler)) == SIG_ERR)
    write(2, "Error signal\n", 13);
  if ((signal(SIGUSR2, handler)) == SIG_ERR)
    write(2, "Error signal\n", 13);
  while (42);
  return (0);
}
