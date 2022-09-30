/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:33:21 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:36:23 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	moving_up(t_game *game, int counter)
{
	if (game->map.two_d[game->map.j][game->map.i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win.win, game->exit_x.img,
			game->player_p.x, game->player_p.y);
	else
		mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
			game->player_p.x, game->player_p.y);
	game->player_p.y -= game->player.size.y;
	game->map.j = game->player_p.y / game->player.size.y;
	mlx_put_image_to_window(game->mlx, game->win.win, game->player.img,
		game->player_p.x, game->player_p.y);
	ft_printf("Number of steps: %d\n", ++counter);
	return (1);
}

int	moving_down(t_game *game, int counter)
{
	if (game->map.two_d[game->map.j][game->map.i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win.win, game->exit_x.img,
			game->player_p.x, game->player_p.y);
	else
		mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
			game->player_p.x, game->player_p.y);
	game->player_p.y += game->player.size.y;
	game->map.j = game->player_p.y / game->player.size.y;
	mlx_put_image_to_window(game->mlx, game->win.win, game->player.img,
		game->player_p.x, game->player_p.y);
	ft_printf("Number of steps: %d\n", ++counter);
	return (1);
}

int	moving_left(t_game *game, int counter)
{
	if (game->map.two_d[game->map.j][game->map.i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win.win, game->exit_x.img,
			game->player_p.x, game->player_p.y);
	else
		mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
			game->player_p.x, game->player_p.y);
	game->player_p.x -= game->player.size.x;
	game->map.i = game->player_p.x / game->player.size.x;
	mlx_put_image_to_window(game->mlx, game->win.win, game->player.img,
		game->player_p.x, game->player_p.y);
	ft_printf("Number of steps: %d\n", ++counter);
	return (1);
}

int	moving_right(t_game *game, int counter)
{
	if (game->map.two_d[game->map.j][game->map.i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win.win, game->exit_x.img,
			game->player_p.x, game->player_p.y);
	else
		mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
			game->player_p.x, game->player_p.y);
	game->player_p.x += game->player.size.x;
	game->map.i = game->player_p.x / game->player.size.x;
	mlx_put_image_to_window(game->mlx, game->win.win, game->player.img,
		game->player_p.x, game->player_p.y);
	ft_printf("Number of steps: %d\n", ++counter);
	return (1);
}
