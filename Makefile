# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 13:51:12 by talsaiaa          #+#    #+#              #
#    Updated: 2022/09/30 15:25:33 by talsaiaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

SRCS			=	main.c utils/ft_strnstr.c utils/ft_split.c utils/ft_substr.c \
					parsing/saving_map.c parsing/character_checker.c parsing/wall_checker.c \
					parsing/shape_checker.c parsing/dfs.c \
					gnl/get_next_line.c gnl/get_next_line_utils.c \
					game/freedom.c game/images_refs.c game/imgs.c game/my_img_to_win.c \
					game/hooks.c game/movement.c game/window.c

OBJS			=	$(SRCS:.c=.o)

FT_PRINTF		=	cd ft_printf && make

MINI_MLX		= 	cd mlx && make

LIB				=	ft_printf/libftprintf.a

INCLUDE			=	-I mlx

LINUX_INCLUDE	= -I/usr/include -Imlx_linux -Iutils -O3

LINKS			=	-L mlx -l mlx -framework OpenGL -framework AppKit

LINUX_LINKS 	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

GCC				=	gcc

FLAGS			=	-g -Wall -Werror -Wextra

all: comp_start $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(FLAGS) $(OBJS) $(LINKS) $(LIB) -o $(NAME)

comp_start:
	$(MINI_MLX)
	$(FT_PRINTF)

.c.o:
	${GCC} ${FLAGS} $(INCLUDE) -c $< -o ${<:.c=.o}

clean:
	rm -rf $(OBJS)
	cd ft_printf && make clean
	cd mlx && make clean

fclean:	clean
	rm -rf $(NAME)
	cd ft_printf && make fclean
	cd mlx && make clean

re:	fclean all