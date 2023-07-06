/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:53:14 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 14:13:22 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	if (dstsize == 0 || ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	count = ft_strlen(dst) + ft_strlen(src);
	dstsize = dstsize - ft_strlen(dst);
	while (*dst)
		dst++;
	while (dstsize-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (count);
}
