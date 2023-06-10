/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:51:59 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 14:54:11 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	char	*head;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	p = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	head = p;
	while (s[i])
	{
		*p++ = (*f)(i, s[i]);
		i++;
	}
	*p = '\0';
	return (head);
}
