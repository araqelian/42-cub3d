/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:24:08 by darakely          #+#    #+#             */
/*   Updated: 2022/12/24 20:29:15 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_name_map(t_data *data, char *name_map)
{
	if (ft_strlen(name_map) <= 4 || name_map[ft_strlen(name_map) - 1] != 'b' \
	|| name_map[ft_strlen(name_map) - 2] != 'u' || \
	name_map[ft_strlen(name_map) - 3] != 'c' || \
	name_map[ft_strlen(name_map) - 4] != '.')
		print_error(data, "Non correct name of map!", 1);
}

void	continue_read_map(t_data *data, char *map)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error(data, strerror(errno), 1);
	data->parsing->map = malloc(sizeof(char *) * (data->parsing->y + 1));
	data->parsing->map[data->parsing->y] = 0;
	while (get_next_line(fd, &data->parsing->map[i]))
		i++;
	close(fd);
}

void	read_map(t_data *data, char *line, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_error(data, strerror(errno), 1);
	while (get_next_line(fd, &line))
	{
		data->parsing->y++;
		my_free(&line);
	}
	data->parsing->y++;
	my_free(&line);
	close(fd);
	continue_read_map(data, map);
}

void	get_map(char **argv, t_data *data)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error(data, strerror(errno), 1);
	close(fd);
	check_name_map(data, argv[1]);
	read_map(data, 0, argv[1]);
	check_map(data, -1, 0, 0);
	check_arg_in_map(data);
	check_arg_colors(data, 0, 0, 0);
}
