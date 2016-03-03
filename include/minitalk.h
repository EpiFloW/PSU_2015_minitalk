/*
** minitalk.h for  in /home/maison_f/Epitech/rendu/PSU_2015_minitalk/include
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Mon Feb  1 23:33:30 2016 Maisonnave Florian
** Last update Mon Feb  8 19:11:29 2016 Maisonnave Florian
*/

#ifndef MINITALK_H
# define MINITALK_H
# define _BSD_SOURCE
# define _POSIX_SOURCE

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void	my_putchar(char);
void	my_putstr(char *);
void	my_putnbr(int);
int	my_neg(char *);
int	my_num(char);
int	my_getnbr(char *);
int	receiver_bin(int, unsigned char);
int	send_str(int, char *);
void	one_or_zero(unsigned int);
void	handler(int);

#endif /* !MINITALK_H */
