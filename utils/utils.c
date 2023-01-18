/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:27:57 by darakely          #+#    #+#             */
/*   Updated: 2022/12/22 17:01:57 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (!str)
		return (0);
	while (str[++i])
		;
	return (i);
}

void	my_free(char **str)
{
	free(*str);
	*str = 0;
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		i;

	if (!str)
		return (0);
	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_strcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned const char	*c1;
	unsigned const char	*c2;
	size_t				i;

	c1 = (unsigned const char *)s1;
	c2 = (unsigned const char *)s2;
	i = 0;
	if (!s1 || !s2)
		return (0);
	while (i < n)
	{
		if ((c1[i] != c2[i] || s1[i] == 0) || s2[i] == 0)
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
