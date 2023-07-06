/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:18:58 by kohshi54          #+#    #+#             */
/*   Updated: 2023/01/29 13:55:09 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_element(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	start;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i == start)
		{
			i++;
			continue ;
		}
		count++;
		if (s[i] == '\0')
			return (count);
		i++;
	}	
	return (count);
}

static void	*free_all(char **p, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(p[i++]);
	free(p);
	return (NULL);
}

char	**my_split(const char *s, char c, char **p, size_t start)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i == start)
		{
			i++;
			continue ;
		}
		p[count] = malloc(sizeof(char) * (i - start + 1));
		if (!p)
			return (free_all(p, count));
		ft_strlcpy(p[count], &s[start], (i - start + 1));
		count++;
		if (s[i++] == '\0')
			break ;
	}
	p[count] = NULL;
	return (&p[0]);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	size_t	start;

	start = 0;
	if (!s)
		return (NULL);
	p = malloc(sizeof(char *) * (count_element(s, c) + 1));
	if (!p)
		return (NULL);
	p = my_split(s, c, p, start);
	if (!p)
		return (NULL);
	return (p);
}
