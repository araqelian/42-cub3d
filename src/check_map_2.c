/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 15:08:45 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 17:20:23 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_arg(t_data *data, int i, int j)
{
	char	**check;
	char	*str;
	int		len;

	check = (char **)malloc(sizeof(char *) * 7);
	check[0] = ft_strdup("NO");
	check[1] = ft_strdup("SO");
	check[2] = ft_strdup("EA");
	check[3] = ft_strdup("WE");
	check[4] = ft_strdup("F");
	check[5] = ft_strdup("C");
	check[6] = 0;
	str = my_strdup(&data->parsing->map[i][j]);
	len = continue_check_arg(check, str);
	my_free(&str);
	free_array(&check);
	if (len == -1)
		print_error(data, "Invalid map!", 1);
}

void	check_arg_map(t_data *data, int i)
{
	int	j;

	i--;
	while (i >= 0)
	{
		j = 0;
		while (data->parsing->map[i][j] && (data->parsing->map[i][j] == ' ' \
			|| data->parsing->map[i][j] == '\t'))
			j++;
		if (data->parsing->map[i][j] != '\0')
			check_arg(data, i, j);
		i--;
	}
}

void	check_count_player(t_data *data, int i)
{
	int	count;
	int	j;

	count = 0;
	while (data->parsing->full_map[i])
	{
		j = -1;
		while (data->parsing->full_map[i][++j])
		{
			if (data->parsing->full_map[i][j] == 'N' || \
				data->parsing->full_map[i][j] == 'W' || \
				data->parsing->full_map[i][j] == 'S' || \
				data->parsing->full_map[i][j] == 'E')
				count++;
		}
		i++;
	}
	if (count != 1)
		print_error(data, "Invalid map: count of \'NWSE\' \
chars in map must be 1!", 1);
}

void	check_characters(t_data *data, int i)
{
	int	j;

	while (data->parsing->full_map[i])
	{
		j = -1;
		while (data->parsing->full_map[i][++j])
		{
			if (data->parsing->full_map[i][j] != '1' && \
				data->parsing->full_map[i][j] != '0' && \
				data->parsing->full_map[i][j] != ' ' && \
				data->parsing->full_map[i][j] != '\t' && \
				data->parsing->full_map[i][j] != 'N' && \
				data->parsing->full_map[i][j] != 'W' && \
				data->parsing->full_map[i][j] != 'S' && \
				data->parsing->full_map[i][j] != 'E')
				print_error(data, "Invalid map!", 1);
		}
		i++;
	}
}

void	continue_check_walls(t_data *data, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(data->parsing->full_map[i]);
	while (data->parsing->full_map[i][j] && \
	(data->parsing->full_map[i][j] == ' ' || \
	data->parsing->full_map[i][j] == '\t'))
		j++;
	len--;
	while (len > 0 && (data->parsing->full_map[i][len] == ' ' || \
	data->parsing->full_map[i][len] == '\t'))
	{
		data->parsing->full_map[i][len] = '\0';
		len--;
	}
	if (data->parsing->full_map[i][j] != '1' || \
	data->parsing->full_map[i][len] != '1')
		print_error(data, "Invalid map!", 1);
}
