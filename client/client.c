/*
** client.c for  in /home/maison_f/Epitech/rendu/PSU_2015_minitalk/src
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Mon Feb  1 23:32:34 2016 Maisonnave Florian
** Last update Mon Feb  8 19:23:48 2016 Maisonnave Florian
*/

#include "minitalk.h"

int	receive_bin(int pid, unsigned char c)
{
  int	i;

  i = 0;
  while (i < 8)
    {
      usleep(500);
      if (c % 2 == 0)
	{
	  if ((kill(pid, SIGUSR2)) == -1)
	    {
	      write (2, "Error : Bad PID server.\n", 24);
	      return (1);
	    }
	}
      else
	if ((kill(pid, SIGUSR1)) == -1)
	  {
	    write (2, "Error : Bad PID server.\n", 24);
	    return (1);
	  }
      i++;
      c /= 2;
    }
  return (0);
}

int	send_str(int pid, char *str)
{
  int	i;

  i = 0;
  if (pid < 2)
    {
      write (2, "Error : Bad PID server.\n", 24);
      return (1);
    }
  while (str[i])
    {
      if ((receive_bin(pid, str[i])) == 1)
	return (1);
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  (void)ac;
  if (ac < 3)
    {
      write (2, "Error : Too few arguments.\n", 27);
      return (0);
    }
  if (ac > 3)
    {
      write (2, "Error : Too many arguments.\n", 28);
      return (0);
    }
  if ((send_str(my_getnbr(av[1]), av[2])) == 1)
    return (0);
  return (0);
}
