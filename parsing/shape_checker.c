/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:00:29 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:31:57 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	shape_checker(t_game *game)
{
	int	y;

	y = 0;
	while (game->map.two_d[y])
	{
		if (ft_strlen(game->map.two_d[y]) - 1 != game->map.len)
		{
			ft_printf("Error\nmap is not rectangular\n");
			freedom(game);
		}
		y++;
	}
	return (0);
}
