/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:22:42 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/02/05 16:24:48 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

size_t	ft_putchar(const char c);
size_t	ft_putstr(const char *s);
int		ft_printf(const char *str, ...);
size_t	ft_putnbr(int nbr);
size_t	ft_convert_base(unsigned long long num, const size_t base, char format);
#endif