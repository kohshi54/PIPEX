/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:19:30 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/02/05 16:25:08 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert_base(unsigned long long num, const size_t base, char format)
{
	size_t	len;

	len = 0;
	if (num >= base)
	{
		len += ft_convert_base(num / base, base, format);
		len += ft_convert_base(num % base, base, format);
	}
	else
	{
		if (num < 10)
		{
			len += ft_putchar(num + '0');
		}
		else
		{
			if (format == 'p' || format == 'x')
				len += ft_putchar((num - 10) + 'a');
			else if (format == 'X')
				len += ft_putchar((num - 10) + 'A');
		}
	}
	return (len);
}
