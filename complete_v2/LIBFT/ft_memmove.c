/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:57:18 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 14:29:52 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*head;

	if (!dst && !src)
		return (NULL);
	head = dst;
	if (src >= dst)
	{
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	}
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*(unsigned char *)dst-- = *(unsigned char *)src--;
	}
	return (head);
}
