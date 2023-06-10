/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:50:54 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 14:55:40 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (len == 0 && (!haystack || !needle))
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (ft_strlen(needle) > len)
			return (NULL);
		if (*haystack == *needle)
			if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
