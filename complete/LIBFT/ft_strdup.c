/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:54:28 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 14:02:06 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;

	p = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!p)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strlcpy(p, s1, ft_strlen(s1) + 1);
	return (p);
}
