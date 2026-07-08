# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: criredon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/08 18:38:38 by criredon          #+#    #+#              #
#    Updated: 2026/07/08 18:38:41 by criredon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a
CC 		= 	cc
CFLAGS 	= 	-Wall -Wextra -Werror -c
AR 		= 	ar
ARFLAG 	= 	rcs
RM 		= 	rm -rf

SOURCES = 	ft_printf.c \
		  	ft_putchar.c \
		  	ft_putnbr.c \
		  	ft_putstr.c \
		  	ft_putunsigned.c \
		  	ft_puthex.c \
		  	ft_putptr.c

OBJECTS =	$(SOURCES:.c=.o)
all: 		$(NAME)
%.o: 		%.c
			$(CC) $(CFLAGS) $< -o $@


main: $(NAME)
make: $(NAME)
make fclean: clean
$(NAME): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)
	$(AR) $(ARFLAG) $(NAME) *.o
clean:
	$(RM) *.o
fclean: clean
	$(RM) $(NAME)
