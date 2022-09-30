/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:50:11 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/09/30 15:32:44 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

void	args_checker(int ac, char **av)
{
	int		x;
	int		len;
	char	*ber;

	x = 0;
	len = 0;
	ber = ".ber";
	if (ac != 2)
	{
		ft_printf("Error\ninvalid number of arguments\n");
		exit (1);
	}
	while (av[1][x] != '.' && av[1][x])
		x++;
	while (av[1][x])
	{
		len++;
		x++;
	}
	if ((len != 4 && ft_strnstr(av[1], ber, 5) == 0)
		|| open(av[1], O_DIRECTORY) > 0)
	{
		ft_printf("Error\nmap type is invalid\n");
		exit (1);
	}
}

void	so_long(t_game *game, char **av)
{
	game->map.fd = open(av[1], O_RDONLY);
	if (game->map.fd < 0)
	{
		ft_printf("Error\nmap does not exist\n");
		exit (1);
	}
	saving_map(game);
	character_checker(game);
	wall_checker(game);
	shape_checker(game);
	validboy(game);
}

int	main(int ac, char **av)
{
	t_game		game;

	args_checker(ac, av);
	so_long(&game, av);
	game.mlx = mlx_init();
	images_refs(&game);
	game.win = my_mlx_new_window(game.mlx,
			((game.map.len + 1) * game.wall.size.x),
			(game.map.nline * game.wall.size.y), "So_Long");
	my_img_to_win(&game);
	mlx_key_hook(game.win.win, my_hooker, &game);
	mlx_hook(game.win.win, 17, 0, window_close, &game);
	mlx_loop(game.mlx);
	freedom(&game);
	return (0);
}
