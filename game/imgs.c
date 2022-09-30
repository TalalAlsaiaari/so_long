/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:35:35 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 00:36:17 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_img	my_player(void	*mlx)
{
	t_img	player;

	player.img = mlx_xpm_file_to_image(mlx, "imgs/player.xpm", &player.size.x,
			&player.size.y);
	player.addr = mlx_get_data_addr(player.img, &player.bpp, &player.llen,
			&player.endian);
	return (player);
}

t_img	my_wall(void *mlx)
{
	t_img	wall;

	wall.img = mlx_xpm_file_to_image(mlx, "imgs/wall.xpm", &wall.size.x,
			&wall.size.y);
	wall.addr = mlx_get_data_addr(wall.img, &wall.bpp, &wall.llen,
			&wall.endian);
	return (wall);
}

t_img	my_bkgrnd(void *mlx)
{
	t_img	bkgrnd;

	bkgrnd.img = mlx_xpm_file_to_image(mlx, "imgs/bkgrnd.xpm", &bkgrnd.size.x,
			&bkgrnd.size.y);
	bkgrnd.addr = mlx_get_data_addr(mlx, &bkgrnd.bpp, &bkgrnd.llen,
			&bkgrnd.endian);
	return (bkgrnd);
}

t_img	my_clct(void *mlx)
{
	t_img	clct;

	clct.img = mlx_xpm_file_to_image(mlx, "imgs/clct.xpm", &clct.size.x,
			&clct.size.y);
	clct.addr = mlx_get_data_addr(clct.img, &clct.bpp, &clct.llen,
			&clct.endian);
	return (clct);
}

t_img	my_exit_x(void *mlx)
{
	t_img	exit_x;

	exit_x.img = mlx_xpm_file_to_image(mlx, "imgs/exit_x.xpm", &exit_x.size.x,
			&exit_x.size.y);
	exit_x.addr = mlx_get_data_addr(exit_x.img, &exit_x.bpp, &exit_x.llen,
			&exit_x.endian);
	return (exit_x);
}
