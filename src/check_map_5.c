/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:47:39 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 21:07:55 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	continue_norm_get_add_arg(char *str, int i, char *ptr, int *j)
{
	if (str[i] != ' ' && str[i] != '\t')
	{
		ptr[*j] = str[i];
		(*j)++;
	}
}

void	norm_continue_get_add_arg(t_data *data, char *ptr, char *delim)
{
	int	len;

	len = check_size_str(delim, "WE");
	if ((ft_strncmp(delim, "WE", len) == 0) && (data->index->index_we == 0))
	{
		data->parsing->arg_we = ft_strdup(ptr);
		data->index->index_we = 1;
	}
	len = check_size_str(delim, "F");
	if ((ft_strncmp(delim, "F", len) == 0) && (data->index->index_f == 0))
	{
		data->parsing->arg_f = ft_strdup(ptr);
		data->index->index_f = 1;
	}
	len = check_size_str(delim, "C");
	if ((ft_strncmp(delim, "C", len) == 0) && (data->index->index_c == 0))
	{
		data->parsing->arg_c = ft_strdup(ptr);
		data->index->index_c = 1;
	}
}

void	check_arg_in_map(t_data *data)
{
	if (data->index->index_no == 0 || data->index->index_so == 0 || \
		data->index->index_ea == 0 || data->index->index_we == 0 || \
		data->index->index_f == 0 || data->index->index_c == 0)
		print_error(data, "Invalid argument(s) in map!", 1);
}

void	continue_check_arg_colors(t_data *data, int i, char *str, char **check)
{
	char	**for_split;

	check = ft_split(data->parsing->arg_f, ',');
	if (!check || !check[0] || !check[1] || !check[2] || check[3])
		print_error(data, "Invalid argument for color floor!", 1);
	while (check && check[i])
	{
		str = my_strjoin(str, check[i]);
		str = my_strjoin(str, ",");
		i++;
	}
	for_split = ft_split(str, ',');
	my_free(&str);
	if (!for_split || !for_split[0] || !for_split[1] || !for_split[2] || \
		ft_atoi(for_split[0]) < 0 || ft_atoi(for_split[0]) > 255 || \
		ft_atoi(for_split[1]) < 0 || ft_atoi(for_split[1]) > 255 || \
		ft_atoi(for_split[2]) < 0 || ft_atoi(for_split[2]) > 255)
	{
		free_array(&check);
		free_array(&for_split);
		print_error(data, "Invalid argument for color floor!", 1);
	}
	free_array(&check);
	free_array(&for_split);
}

void	check_arg_colors(t_data *data, int i, char *str, char **check)
{
	char	**for_split;

	check = ft_split(data->parsing->arg_c, ',');
	if (!check || !check[0] || !check[1] || !check[2] || check[3])
		print_error(data, "Invalid argument for color ceilling!", 1);
	while (check && check[i])
	{
		str = my_strjoin(str, check[i]);
		str = my_strjoin(str, ",");
		i++;
	}
	for_split = ft_split(str, ',');
	my_free(&str);
	if (!for_split || !for_split[0] || !for_split[1] || !for_split[2] || \
		ft_atoi(for_split[0]) < 0 || ft_atoi(for_split[0]) > 255 || \
		ft_atoi(for_split[1]) < 0 || ft_atoi(for_split[1]) > 255 || \
		ft_atoi(for_split[2]) < 0 || ft_atoi(for_split[2]) > 255)
	{
		free_array(&check);
		free_array(&for_split);
		print_error(data, "Invalid argument for color ceilling!", 1);
	}
	free_array(&check);
	free_array(&for_split);
	continue_check_arg_colors(data, 0, 0, 0);
}
