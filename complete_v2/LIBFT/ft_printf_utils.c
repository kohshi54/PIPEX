/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:19:40 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/02/05 16:21:26 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

size_t	ft_putchar(const char c)
{
	return (write(1, &c, sizeof(c)));
}

size_t	ft_putstr(const char *s)
{
	if (!s)
		return (ft_putstr("(null)"));
	return (write(1, s, ft_strlen(s)));
}

size_t	ft_putnbr(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	else
	{
		len += ft_putchar(nbr + '0');
	}
	return (len);
}
