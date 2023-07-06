/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:19:45 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/02/05 16:27:50 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	format_checker(va_list *ap, const char **format)
{
	(*format)++;
	if (**format == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (**format == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (**format == 'p')
		return (ft_putstr("0x") \
			+ ft_convert_base(va_arg(*ap, uintptr_t), 16, **format));
	if (**format == 'd' || **format == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (**format == 'u')
		return (ft_convert_base(va_arg(*ap, unsigned int), 10, **format));
	if (**format == 'x' || **format == 'X')
		return (ft_convert_base(va_arg(*ap, unsigned int), 16, **format));
	if (**format == '%')
		return (ft_putchar('%'));
	(*format)--;
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			len += format_checker(&ap, &format);
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (len);
}
