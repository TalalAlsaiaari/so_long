/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:40:11 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:31:24 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	duplicate_checker(t_game *game, int y)
{
	char	*p;
	char	*e;
	char	*c;

	p = ft_strchr(game->map.one_d, 'P');
	e = ft_strchr(game->map.one_d, 'E');
	c = ft_strchr(game->map.one_d, 'C');
	if (p == 0 || e == 0 || c == 0)
	{
		ft_printf("Error\nEihter P, E or C is missing\n");
		freedom(game);
	}
	if ((game->map.one_d[y] == 'P'
			&& &game->map.one_d[y] != p)
		|| (game->map.one_d[y] == 'E'
			&& &game->map.one_d[y] != e))
	{
		ft_printf("Error\nDuplicate P or E\n");
		freedom(game);
	}
	return (0);
}

int	extra_line_checker(t_game *game, int y)
{
	if ((game->map.one_d[y] == '\n' && game->map.one_d[y + 1] == '\n'))
	{
		ft_printf("Error\nExtra lines\n");
		freedom(game);
	}
	return (0);
}

int	character_checker(t_game *game)
{
	int	y;

	y = 0;
	game->map.coins = 0;
	while (game->map.one_d[y])
	{
		if (game->map.one_d[y] != '1' && game->map.one_d[y] != '0'
			&& game->map.one_d[y] != 'C' && game->map.one_d[y] != 'E'
			&& game->map.one_d[y] != 'P' && game->map.one_d[y] != '\n')
		{
			ft_printf("Error\nInvalid character\n");
			freedom(game);
		}
		duplicate_checker(game, y);
		if (game->map.one_d[y] == 'C')
			game->map.coins++;
		extra_line_checker(game, y);
		y++;
	}
	if (game->map.one_d[y - 1] == '\n')
	{
		ft_printf("Error\nExtra line in the end\n");
		freedom(game);
	}
	return (0);
}
