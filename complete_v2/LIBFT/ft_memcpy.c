/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:58:22 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 14:29:21 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*head;

	if (!dst && !src)
		return (NULL);
	head = dst;
	while (n--)
		*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (head);
}
