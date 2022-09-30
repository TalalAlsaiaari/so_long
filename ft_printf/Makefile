# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talsaiaa <talal_alsaiaary@yahoo.comr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 00:42:19 by talsaiaa          #+#    #+#              #
#    Updated: 2021/11/02 23:53:17 by talsaiaa         ###   ########.AD        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf_d.c ft_printf_s.c ft_printf_ux.c ft_printf_p.c ft_printf_u.c ft_printf.c ft_printf_c.c ft_printf_x.c ft_putchar.c

INCLUDES = printf.h

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcsv ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re:		fclean all
