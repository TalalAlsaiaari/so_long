/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_img_to_win.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:11:59 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:36:31 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_clct_to_win(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
		game->wall_p.x, game->wall_p.y);
	mlx_put_image_to_window(game->mlx, game->win.win, game->clct.img,
		game->wall_p.x, game->wall_p.y);
}

void	my_exit_x_to_win(t_game *game)
{
	game->exit_x_p.y = game->map.j * game->wall.size.y;
	game->exit_x_p.x = game->map.i * game->wall.size.x;
	mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
		game->wall_p.x, game->wall_p.y);
	mlx_put_image_to_window(game->mlx, game->win.win, game->exit_x.img,
		game->wall_p.x, game->wall_p.y);
}

void	my_player_to_win(t_game *game)
{
	game->player_p.y = game->map.j * game->wall.size.y;
	game->player_p.x = game->map.i * game->wall.size.x;
	mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
		game->wall_p.x, game->wall_p.y);
	mlx_put_image_to_window(game->mlx, game->win.win, game->player.img,
		game->wall_p.x, game->wall_p.y);
}

void	placing_imgs(t_game *game)
{
	game->map.i = 0;
	while (game->map.two_d[game->map.j][game->map.i])
	{
		if (game->map.two_d[game->map.j][game->map.i] == '1')
			mlx_put_image_to_window(game->mlx, game->win.win, game->wall.img,
				game->wall_p.x, game->wall_p.y);
		if (game->map.two_d[game->map.j][game->map.i] == '0')
			mlx_put_image_to_window(game->mlx, game->win.win, game->bkgrnd.img,
				game->wall_p.x, game->wall_p.y);
		if (game->map.two_d[game->map.j][game->map.i] == 'C')
			my_clct_to_win(game);
		if (game->map.two_d[game->map.j][game->map.i] == 'E')
			my_exit_x_to_win(game);
		if (game->map.two_d[game->map.j][game->map.i] == 'P')
			my_player_to_win(game);
		game->wall_p.x += game->wall.size.x;
		game->map.i++;
	}
	game->wall_p.x = 0;
}

void	my_img_to_win(t_game *game)
{
	game->map.j = 0;
	game->wall_p.y = 0;
	game->wall_p.x = 0;
	while (game->map.two_d[game->map.j])
	{
		placing_imgs(game);
		game->wall_p.y += game->wall.size.y;
		game->map.j++;
	}
	game->map.i = game->player_p.x / game->player.size.x;
	game->map.j = game->player_p.y / game->player.size.y;
}
