/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:51:21 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 15:05:09 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (n-- && (*tmp1 || *tmp2))
	{
		if (*tmp1 || *tmp2)
			if (*tmp1 != *tmp2)
				return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
	}
	return (0);
}
