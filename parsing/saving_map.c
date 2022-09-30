/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saving_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:25:25 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:31:52 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	saving_map(t_game *game)
{
	game->map.len = 0;
	game->map.nline = 1;
	game->map.a = get_next_line(game->map.fd);
	if (game->map.a == 0)
		exit (1);
	game->map.one_d = ft_strdup(game->map.a);
	free (game->map.a);
	game->map.len = ft_strlen(game->map.one_d) - 2;
	while (game->map.a)
	{
		game->map.a = get_next_line(game->map.fd);
		if (game->map.a == 0)
			break ;
		game->map.one_d = ft_strjoin(game->map.one_d, game->map.a);
		free (game->map.a);
		game->map.nline++;
	}
	game->map.two_d = ft_split(game->map.one_d, '\n');
	return (0);
}
