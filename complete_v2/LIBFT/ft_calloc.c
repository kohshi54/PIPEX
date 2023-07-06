/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:49:39 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 13:07:25 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	overflow_checker(size_t count, size_t size)
{
	if ((SIZE_MAX / size) < count)
		return (1);
	return (0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	if (!count || !size)
		count = 0;
	else if (overflow_checker(count, size))
		return (NULL);
	p = malloc(count * size);
	if (!p)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_bzero(p, count * size);
	return (p);
}
