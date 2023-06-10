/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:48:42 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 12:39:00 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check(char s1, char const *set)
{
	while (*set)
		if (s1 == *set++)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*p;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (check(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (check(s1[j], set) && (i < j))
		j--;
	p = malloc(sizeof(char) * (j - i + 2));
	if (!p)
		return (NULL);
	ft_strlcpy(p, &s1[i], (j - i + 2));
	return (p);
}
