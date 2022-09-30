/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:20:22 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 14:28:48 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	my_hooker(int key, t_game *game)
{
	static int	counter;

	if (key == 53)
		freedom(game);
	if (key == 13 && game->map.two_d[game->map.j - 1][game->map.i] != '1')
		counter += moving_up(game, counter);
	else if (key == 1 && game->map.two_d[game->map.j + 1][game->map.i] != '1')
		counter += moving_down(game, counter);
	else if (key == 0 && game->map.two_d[game->map.j][game->map.i - 1] != '1')
		counter += moving_left(game, counter);
	else if (key == 2 && game->map.two_d[game->map.j][game->map.i + 1] != '1')
		counter += moving_right(game, counter);
	if (game->map.two_d[game->map.j][game->map.i] == 'C')
	{
		game->map.coins--;
		game->map.two_d[game->map.j][game->map.i] = '0';
	}
	if (game->map.coins == 0)
		mlx_put_image_to_window(game->mlx, game->win.win, game->exit.img,
			game->exit_x_p.x, game->exit_x_p.y);
	if (game->map.coins == 0 && game->player_p.x == game->exit_x_p.x
		&& game->player_p.y == game->exit_x_p.y)
		freedom(game);
	return (0);
}
