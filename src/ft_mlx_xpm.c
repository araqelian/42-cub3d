/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:51:10 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 20:21:19 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_mlx_xpm(t_data *data)
{
	data->game->no = mlx_xpm_file_to_image(data->game->mlx, \
	data->parsing->arg_no, &data->img[1].width, &data->img[1].height);
	data->game->so = mlx_xpm_file_to_image(data->game->mlx, \
	data->parsing->arg_so, &data->img[2].width, &data->img[2].height);
	data->game->ea = mlx_xpm_file_to_image(data->game->mlx, \
	data->parsing->arg_ea, &data->img[3].width, &data->img[3].height);
	data->game->we = mlx_xpm_file_to_image(data->game->mlx, \
	data->parsing->arg_we, &data->img[4].width, &data->img[4].height);
	if (!data->game->no || !data->game->so || !data->game->ea || \
		!data->game->we)
		print_error(data, "Invalid xpm path in map!", 0);
}
