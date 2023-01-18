/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 17:10:39 by darakely          #+#    #+#             */
/*   Updated: 2022/12/24 20:49:32 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_down_and_up_spaces(t_data *data, char *str, int len, \
								int index_str)
{
	int	i;
	int	len_str;

	i = 0;
	len = ft_strlen(data->parsing->full_map[index_str - 1]);
	len_str = ft_strlen(data->parsing->full_map[index_str + 1]);
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
	{
		if (i <= len && (data->parsing->full_map[index_str - 1][i] && \
			data->parsing->full_map[index_str - 1][i] != '1' && \
			data->parsing->full_map[index_str - 1][i] != ' ' && \
			data->parsing->full_map[index_str - 1][i] != '\t'))
			print_error(data, "Invalid map!", 1);
		if (i <= len_str && (data->parsing->full_map[index_str + 1] && \
			(data->parsing->full_map[index_str + 1][i] && \
			data->parsing->full_map[index_str + 1][i] != '1' && \
			data->parsing->full_map[index_str + 1][i] != ' ' && \
			data->parsing->full_map[index_str + 1][i] != '\t')))
			print_error(data, "Invalid map!", 1);
		i++;
	}
}

void	continue_check(t_data *data, int index_str, int len_str)
{
	while (data->parsing->full_map[index_str - 1][len_str])
	{
		if (data->parsing->full_map[index_str - 1][len_str] != '1' && \
			data->parsing->full_map[index_str - 1][len_str] != ' ' && \
			data->parsing->full_map[index_str - 1][len_str] != '\t')
			print_error(data, "Invalid map!", 1);
		len_str++;
	}
}

void	check_down_and_up_walls(t_data *data, char *str, int len, int index_str)
{
	int	len_str;

	len_str = ft_strlen(str);
	len = ft_strlen(data->parsing->full_map[index_str - 1]);
	if (len_str != len)
	{
		if (len_str > len)
		{
			while (data->parsing->full_map[index_str][len])
			{
				if (data->parsing->full_map[index_str][len] != '1' && \
					data->parsing->full_map[index_str][len] != ' ' && \
					data->parsing->full_map[index_str][len] != '\t')
					print_error(data, "Invalid map!", 1);
				len++;
			}
		}
		else
			continue_check(data, index_str, len_str);
	}
}

void	continue_get_add_arg(t_data *data, char *ptr, char *delim)
{
	int	len;

	len = check_size_str(delim, "NO");
	if ((ft_strncmp(delim, "NO", len) == 0) && (data->index->index_no == 0))
	{
		data->parsing->arg_no = ft_strdup(ptr);
		data->index->index_no = 1;
	}
	len = check_size_str(delim, "SO");
	if ((ft_strncmp(delim, "SO", len) == 0) && (data->index->index_so == 0))
	{
		data->parsing->arg_so = ft_strdup(ptr);
		data->index->index_so = 1;
	}
	len = check_size_str(delim, "EA");
	if ((ft_strncmp(delim, "EA", len) == 0) && (data->index->index_ea == 0))
	{
		data->parsing->arg_ea = ft_strdup(ptr);
		data->index->index_ea = 1;
	}
	norm_continue_get_add_arg(data, ptr, delim);
}

void	norm_get_add_arg(t_data *data, char *delim, int i, char *str)
{
	char	*ptr;
	int		j;
	int		flag;

	flag = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	j = 0;
	if (ft_strlen(delim) == 2)
		flag = 1;
	while (str[i])
	{
		if (flag == 1)
			continue_norm_get_add_arg(str, i, ptr, &j);
		else
		{
			ptr[j] = str[i];
			j++;
		}
		i++;
	}
	ptr[j] = '\0';
	continue_get_add_arg(data, ptr, delim);
	my_free(&ptr);
}
