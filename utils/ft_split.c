/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:03:17 by darakely          #+#    #+#             */
/*   Updated: 2022/12/24 19:05:35 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			len2;
	size_t			len3;
	unsigned int	i;

	if (!s)
		return (NULL);
	len2 = ft_strlen(s);
	len3 = ft_strlen(s + start);
	if (len3 < len)
		len = len3;
	str = malloc(len + 1);
	i = 0;
	while (i < len && start + i < (unsigned int)len2)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	wordlen(char const *s, char c)
{
	size_t	index;

	index = 0;
	while (*s)
	{
		index++;
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			index--;
		while (*s && *s != c)
			s++;
	}
	return (index);
}

static char	**fill_string(char **store, char *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			store[i++] = ft_substr(s - len, 0, len);
		}
		else
			s++;
	}
	store[i] = 0;
	return (store);
}

char	**ft_split(char *s, char c)
{
	char	**split_string;
	size_t	len_words;

	if (!s)
		return (NULL);
	len_words = wordlen(s, c);
	split_string = malloc(sizeof(char *) * (len_words + 1));
	if (!split_string)
		return (NULL);
	split_string = fill_string(split_string, s, c);
	return (split_string);
}
