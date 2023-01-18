/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:18:40 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 17:33:05 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_array(char ***str)
{
	int	i;

	i = 0;
	if (*str)
	{
		while ((*str)[i])
		{
			free((*str)[i]);
			(*str)[i] = 0;
			i++;
		}
		free(*str);
		*str = 0;
	}
}

void	free_struct_parsing(t_data *data)
{
	free_array(&data->parsing->split_arg_c);
	free_array(&data->parsing->split_arg_f);
	free_array(&data->parsing->norm_map);
	free_array(&data->parsing->full_map);
	free_array(&data->parsing->map);
	my_free(&data->parsing->hex_arg_c);
	my_free(&data->parsing->hex_arg_f);
	my_free(&data->parsing->arg_no);
	my_free(&data->parsing->arg_so);
	my_free(&data->parsing->arg_we);
	my_free(&data->parsing->arg_ea);
	my_free(&data->parsing->arg_c);
	my_free(&data->parsing->arg_f);
	free(data->parsing);
}

void	free_all(t_data *data)
{
	free_struct_parsing(data);
	free(data->rcasting);
	free(data->index);
	free(data->game);
	free(data->img);
}
