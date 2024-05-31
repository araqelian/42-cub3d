/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:22:58 by darakely          #+#    #+#             */
/*   Updated: 2022/12/21 17:42:15 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*ptr;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ptr)
		return (0);
	if (s1)
		ft_strcpy(ptr, s1, len_s1);
	ft_strcpy(ptr + (len_s1), s2, len_s2);
	free(s1);
	return (ptr);
}

char	*copy_str(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*new_str_malloc(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	ptr = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!ptr)
		return (0);
	i++;
	j = 0;
	while (str[i])
	{
		ptr[j] = str[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	free(str);
	return (ptr);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[FOPEN_MAX];
	char		*buffer;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_size = 1;
	while (((ft_strchr(str[fd])) == 0) && (read_size != 0))
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[read_size] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	free(buffer);
	*line = copy_str(str[fd]);
	str[fd] = new_str_malloc(str[fd]);
	if (read_size == 0)
		return (0);
	return (1);
}
