/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:32:36 by darakely          #+#    #+#             */
/*   Updated: 2022/12/24 18:39:07 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_add_arg(t_data *data, char *str, int i, int j)
{
	char	*delim;

	delim = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && (str[i] >= 'A' && str[i] <= 'Z'))
	{
		delim[j] = str[i];
		i++;
		j++;
	}
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	delim[j] = '\0';
	if (str[i] == '\0')
	{
		my_free(&delim);
		print_error(data, "Invalid argument(s) in map!", 1);
	}
	norm_get_add_arg(data, delim, i, str);
	my_free(&delim);
}

void	add_map_arg_in_struct(t_data *data, int j)
{
	while (data->parsing->count >= 0)
	{
		j = -1;
		while (data->parsing->map[data->parsing->count][++j])
		{
			if (data->parsing->map[data->parsing->count][j] && \
				data->parsing->map[data->parsing->count][j] != ' ' && \
				data->parsing->map[data->parsing->count][j] != '\t')
			{
				get_add_arg(data, \
				data->parsing->map[data->parsing->count], 0, 0);
				break ;
			}
		}
		data->parsing->count--;
	}
}

int	continue_check_arg(char **check, char *str)
{
	int	len;
	int	i;

	i = 0;
	while (i < 6)
	{
		len = check_size_str(str, check[i]);
		if (ft_strncmp(check[i], str, len) == 0)
			return (0);
		++i;
	}
	return (-1);
}

void	check_left_and_right_walls(t_data *data, char *str, int i, \
									int index_str)
{
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	if ((i > 0 && str[i - 1] != ' ' && str[i - 1] != '\t' && \
		str[i - 1] != '1') || (str[i + 1] && str[i + 1] != ' ' && \
		str[i + 1] != '\t' && str[i + 1] != '1'))
		print_error(data, "Invalid map!", 1);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] && str[i] != '1')
		print_error(data, "Invalid map!", 1);
	check_down_and_up_spaces(data, str, 0, index_str);
}

void	check_all_spaces(t_data *data, int i)
{
	int	j;

	while (data->parsing->full_map[i])
	{
		j = 0;
		while (data->parsing->full_map[i][j] && \
				(data->parsing->full_map[i][j] == ' ' \
				|| data->parsing->full_map[i][j] == '\t'))
				j++;
		while (data->parsing->full_map[i][j])
		{
			if (data->parsing->full_map[i][j] == ' ' || \
				data->parsing->full_map[i][j] == '\t')
				check_left_and_right_walls(data, data->parsing->full_map[i], \
				0, i);
			j++;
		}
		check_down_and_up_walls(data, data->parsing->full_map[i], 0, i);
		i++;
	}
}
