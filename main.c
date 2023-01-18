/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:54:30 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 13:36:36 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_error(&data, "More or less arguments!", 0);
	init_structs(&data);
	get_map(argv, &data);
	add_new_map(&data);
	data.game->mlx = mlx_init();
	data.game->win = mlx_new_window(data.game->mlx, WIDTH, \
	HEIGHT, "42 Yerevan");
	ft_mlx_xpm(&data);
	init_win(&data);
	mlx_hook(data.game->win, 17, 1L << 0, close_game, &data);
	mlx_hook(data.game->win, 2, 1L << 0, key_manager, &data);
	mlx_loop(data.game->mlx);
	return (0);
}
