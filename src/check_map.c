/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:28:23 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 21:06:11 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_correct_data(t_data *data, int i)
{
	data->parsing->y = 0;
	while (data->parsing->full_map[i])
	{
		i++;
		data->parsing->y++;
	}
	data->parsing->y--;
}

void	check_walls(t_data *data, int i)
{
	int	row;
	int	col;

	row = 0;
	while (data->parsing->full_map[i] && row < data->parsing->y)
	{
		col = 0;
		if (row == 0 || (row == data->parsing->y - 1))
		{
			while (data->parsing->full_map[i][col])
			{
				if (data->parsing->full_map[i][col] != '1' && \
				data->parsing->full_map[i][col] != ' ' && \
				data->parsing->full_map[i][col] != '\t')
					print_error(data, "Invalid map!", 1);
				col++;
			}
		}
		continue_check_walls(data, i);
		i++;
		row++;
	}
}

void	check_map_3(t_data *data, int i, int j, int k)
{
	while (data->parsing->full_map[++i])
	{
		j = -1;
		while (data->parsing->full_map[i][++j])
			if (data->parsing->full_map[i][j] != ' ' && \
			data->parsing->full_map[i][j] != '\t')
				k = 1;
		if (k == 1)
			break ;
	}
	data->parsing->index_map = i;
	get_correct_data(data, i);
	check_walls(data, i);
	check_characters(data, i);
	check_count_player(data, i);
	check_all_spaces(data, i);
	data->game->index = i;
}

void	check_map_2(t_data *data, int i, int j, int k)
{
	k = i;
	while (data->parsing->map[i])
	{
		i++;
		j++;
	}
	data->parsing->full_map = (char **)malloc(sizeof(char *) * (j + 1));
	data->parsing->full_map[j] = 0;
	j = 0;
	while (data->parsing->map[k])
	{
		data->parsing->full_map[j] = ft_strdup(data->parsing->map[k]);
		j++;
		k++;
	}
	check_map_3(data, -1, 0, 0);
}

void	check_map(t_data *data, int i, int j, int count)
{
	int	len;

	data->parsing->count = 0;
	while (data->parsing->map[++i])
	{
		j = 0;
		len = ft_strlen(data->parsing->map[i]);
		while (j < len && (data->parsing->map[i][j] == ' ' || data->parsing->map[i][j] == '\t'))
			j++;
		if (data->parsing->map[i][j] != '\0' && data->parsing->map[i][j] >= 'A' \
		&& data->parsing->map[i][j] <= 'Z')
			count++;
		data->parsing->count++;
		if (count == 6)
		{
			i++;
			check_map_2(data, i, 0, 0);
			break ;
		}
	}
	if (count != 6)
		print_error(data, "Invalid argument(s) in map!", 1);
	add_map_arg_in_struct(data, 0);
	check_arg_map(data, i);
	last_check_colors(data);
}
