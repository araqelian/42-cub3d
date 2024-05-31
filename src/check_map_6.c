/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:44:44 by darakely          #+#    #+#             */
/*   Updated: 2023/01/17 19:05:44 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	get_correct_args(t_data *data)
{
	char	*new_arg_c;
	char	*new_arg_f;
	
	new_arg_c = get_correct_arg(data->parsing->arg_c);
	new_arg_f = get_correct_arg(data->parsing->arg_f);
	data->parsing->split_arg_c = ft_split(new_arg_c, ',');
	data->parsing->split_arg_f = ft_split(new_arg_f, ',');
	data->parsing->dec_arg_c = create_rgb \
	(ft_atoi(data->parsing->split_arg_c[0]), \
	ft_atoi(data->parsing->split_arg_c[1]), \
	ft_atoi(data->parsing->split_arg_c[2]));
	data->parsing->dec_arg_f = create_rgb \
	(ft_atoi(data->parsing->split_arg_f[0]), \
	ft_atoi(data->parsing->split_arg_f[1]), \
	ft_atoi(data->parsing->split_arg_f[2]));
	free_array(&data->parsing->split_arg_c);
	free_array(&data->parsing->split_arg_f);
	my_free(&new_arg_c);
	my_free(&new_arg_f);
}

void	last_check_colors(t_data *data)
{
	int	i;

	i = -1;
	while (data->parsing->arg_c && data->parsing->arg_c[++i])
	{
		if (!(data->parsing->arg_c[i] >= '0' && data->parsing->arg_c[i] <= '9') \
			&& !(data->parsing->arg_c[i] == ' ' || \
			data->parsing->arg_c[i] == '\t') && \
			!(data->parsing->arg_c[i] == ','))
			print_error(data, "Invalid argument for color ceilling!", 1);
	}
	i = -1;
	while (data->parsing->arg_f && data->parsing->arg_f[++i])
	{
		if (!(data->parsing->arg_f[i] >= '0' && data->parsing->arg_f[i] <= '9') \
			&& !(data->parsing->arg_f[i] == ' ' || \
			data->parsing->arg_f[i] == '\t') && \
			!(data->parsing->arg_f[i] == ','))
			print_error(data, "Invalid argument for color floor!", 1);
	}
}

void	add_new_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->game->index;
	while (data->parsing->full_map && \
		data->parsing->full_map[data->game->index])
	{
		i++;
		data->game->index++;
	}
	i++;
	data->parsing->norm_map = malloc(sizeof(char *) * i);
	i = 0;
	while (data->parsing->full_map && data->parsing->full_map[j])
	{
		data->parsing->norm_map[i] = ft_strdup(data->parsing->full_map[j]);
		j++;
		i++;
	}
	data->parsing->norm_map[i] = 0;
	free_array(&data->parsing->full_map);
	get_correct_args(data);
}
