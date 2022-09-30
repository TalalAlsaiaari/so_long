/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_refs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:26:37 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:36:10 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	images_refs(t_game *game)
{
	game->wall = my_wall(game->mlx);
	game->bkgrnd = my_bkgrnd(game->mlx);
	game->clct = my_clct(game->mlx);
	game->exit_x = my_exit_x(game->mlx);
	game->exit = my_exit(game->mlx);
	game->player = my_player(game->mlx);
}
