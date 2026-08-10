# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: criredon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/22 16:41:08 by criredon          #+#    #+#              #
#    Updated: 2026/06/22 16:41:10 by criredon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
AR		=	ar
ARFLAGS	=	rcs
RM		=	rm -rf

SOURCES	= 	ft_strlen.c

OBJECTS	=	$(SOURCES:.c=.o)
all:		$(NAME)
$(NAME):	$(OBJECTS)
				$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)
%.o:		%.c libft.h
				$(CC) $(CFLAGS) -c $< -o $@
clean:
				$(RM) $(OBJECTS)
fclean:		clean
				$(RM) $(NAME)
re:			fclean all
.PHONY:		all clean fclean re
