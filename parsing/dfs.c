/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:20:35 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:31:00 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validcheck(t_game *game, int y, int x)
{
	if (game->map.valid[y][x] == 1)
		return (1);
	if (game->map.two_d[y][x] == '1')
		return (1);
	return (0);
}

void	dfs(t_game *game, int y, int x)
{
	game->map.valid[y][x] = 1;
	if (game->map.two_d[y][x] == 'C')
		game->map.is_coin++;
	if (game->map.two_d[y][x] == 'E')
		game->map.is_exit++;
	if (validcheck(game, y - 1, x) == 0)
		dfs(game, y - 1, x);
	if (validcheck(game, y, x + 1) == 0)
		dfs(game, y, x + 1);
	if (validcheck(game, y + 1, x) == 0)
		dfs(game, y + 1, x);
	if (validcheck(game, y, x - 1) == 0)
		dfs(game, y, x - 1);
}

void	player_finder(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.two_d[y])
	{
		x = 0;
		while (game->map.two_d[y][x])
		{
			if (game->map.two_d[y][x] == 'P')
			{
				game->map.x = x;
				game->map.y = y;
			}
			x++;
		}
		y++;
	}
	dfs(game, game->map.y, game->map.x);
}

void	validboy(t_game *game)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	game->map.is_exit = 0;
	game->map.is_coin = 0;
	while (a <= game->map.nline)
	{
		while (b <= game->map.len)
		{
			game->map.valid[a][b] = 0;
			b++;
		}
		b = 0;
		a++;
	}
	player_finder(game);
	if (game->map.is_coin != game->map.coins || game->map.is_exit != 1)
	{
		ft_printf("Error\nThere is no valid path\n");
		freedom(game);
	}
}
