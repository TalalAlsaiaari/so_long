/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:17:06 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 15:33:13 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	freedom(t_game *game)
{
	int	y;

	y = 0;
	free(game->map.a);
	free(game->map.one_d);
	while (game->map.two_d[y])
	{
		free (game->map.two_d[y]);
		y++;
	}
	free (game->map.two_d);
	exit (1);
}
