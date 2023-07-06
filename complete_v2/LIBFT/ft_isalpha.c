/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:03:50 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/27 12:04:00 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	return (0);
}

static int	ft_islower(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}
