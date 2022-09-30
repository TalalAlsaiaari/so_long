/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:42:55 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:32:04 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	wall_errors(t_game *game, int y)
{
	int	x;

	x = 0;
	while (game->map.two_d[y][x])
	{
		if (y == 0 || y == game->map.nline - 1)
		{
			if (game->map.two_d[y][x] != '1')
			{
				ft_printf("Error\nEither upper or lower edge is incorrect\n");
				freedom(game);
			}
		}
		else if (game->map.two_d[y][0] != '1'
			|| game->map.two_d[y][ft_strlen(game->map.two_d[y]) - 1] != '1')
		{
			ft_printf("Error\nEither left or right edge is incorrect\n");
			freedom(game);
		}
		x++;
	}
	return (0);
}

int	wall_checker(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.two_d[y])
	{
		wall_errors(game, y);
		y++;
	}
	return (0);
}
