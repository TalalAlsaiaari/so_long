/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:46:34 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 15:33:57 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	window_close(t_game	*game)
{
	freedom(game);
	return (0);
}

t_win	my_mlx_new_window(void *mlx, int x, int y, char *name)
{
	t_win	win;

	win.win = mlx_new_window(mlx, x, y, name);
	win.size.x = x;
	win.size.y = y;
	return (win);
}

t_img	my_exit(void *mlx)
{
	t_img	exit;

	exit.img = mlx_xpm_file_to_image(mlx, "imgs/exit.xpm", &exit.size.x,
			&exit.size.y);
	exit.addr = mlx_get_data_addr(exit.img, &exit.bpp, &exit.llen,
			&exit.endian);
	return (exit);
}
