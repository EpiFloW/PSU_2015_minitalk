##
## Makefile for  in /home/maison_f/Epitech/rendu/PSU_2015_minitalk
## 
## Made by Maisonnave Florian
## Login   <maison_f@epitech.net>
## 
## Started on  Mon Feb  1 23:32:01 2016 Maisonnave Florian
## Last update Sun Feb 21 21:53:28 2016 Maisonnave Florian
##

SRCS	=	src/fonctions.c \
		src/my_getnbr.c \

SRCS_S	=	server/server.c \

SRCS_C	=	client/client.c \

OBJS	=	$(SRCS:.c=.o)

OBJS_S	=	$(SRCS_S:.c=.o)

OBJS_C	=	$(SRCS_C:.c=.o)

CFLAGS	=	-W -Wall -Wextra -ansi -pedantic

HEAD	=	-Iinclude

CC	=	gcc $(CFLAGS) $(HEAD)

RM	=	rm -f

NAME_S	=	server/server

NAME_C	=	client/client

all:		$(NAME_S) $(NAME_C)

$(NAME_S):	$(OBJS) $(OBJS_S)
		$(CC) -o $(NAME_S) $(OBJS_S) $(OBJS)

$(NAME_C):	$(OBJS) $(OBJS_C)
		$(CC) -o $(NAME_C) $(OBJS_C) $(OBJS)

clean:
		$(RM) $(OBJS_S) $(OBJS_C) $(OBJS)

fclean:		clean
		$(RM) $(NAME_S) $(NAME_C)

re:		fclean all
