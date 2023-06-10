/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:59:11 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 14:46:38 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	target;

	src = (unsigned char *)s;
	target = (unsigned char)c;
	while (n--)
	{
		if (*src == target)
			return ((void *)src);
		src++;
	}
	return (NULL);
}
