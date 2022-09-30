/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:36:49 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 15:33:51 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_map
{
	int		fd;
	int		x;
	int		y;
	int		valid[256][256];
	int		nline;
	int		len;
	int		coins;
	int		is_exit;
	int		is_coin;
	int		i;
	int		j;
	char	*a;
	char	*one_d;
	char	**two_d;
}				t_map;

typedef struct s_vec
{
	int	x;
	int	y;
}				t_vec;

typedef struct s_win
{
	void	*win;
	t_vec	size;
}				t_win;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
	t_vec	size;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	t_win	win;
	t_map	map;
	t_img	player;
	t_img	wall;
	t_img	bkgrnd;
	t_img	clct;
	t_img	exit;
	t_img	exit_x;
	t_vec	player_p;
	t_vec	wall_p;
	t_vec	bkgrnd_p;
	t_vec	clct_p;
	t_vec	exit_x_p;
}				t_game;

char	**ft_split(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		character_checker(t_game *game);
int		wall_checker(t_game *game);
int		shape_checker(t_game *game);
void	validboy(t_game *game);
int		saving_map(t_game *game);
void	freedom(t_game *game);
void	images_refs(t_game *game);
t_img	my_player(void	*mlx);
t_img	my_wall(void *mlx);
t_img	my_bkgrnd(void *mlx);
t_img	my_clct(void *mlx);
t_img	my_exit_x(void *mlx);
t_img	my_exit(void *mlx);
t_win	my_mlx_new_window(void *mlx, int x, int y, char *name);
void	my_img_to_win(t_game *game);
void	my_clct_to_win(t_game *game);
void	my_exit_x_to_win(t_game *game);
void	my_player_to_win(t_game *game);
void	placing_imgs(t_game *game);
int		my_hooker(int key, t_game *game);
int		moving_up(t_game *game, int counter);
int		moving_down(t_game *game, int counter);
int		moving_left(t_game *game, int counter);
int		moving_right(t_game *game, int counter);
int		window_close(t_game	*game);

#endif