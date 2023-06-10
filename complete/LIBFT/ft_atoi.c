/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:37:11 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 12:31:26 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	overflow_min_checker(long num, const char *str)
{
	if (num > (LONG_MIN / 10) * -1)
		return (1);
	else if (num == ((LONG_MIN / 10) * -1) \
				&& (*str - '0') > ((LONG_MIN % 10) * -1))
		return (1);
	return (0);
}

static bool	overflow_max_checker(long num, const char *str)
{
	if (num > (LONG_MAX / 10))
		return (1);
	else if (num == (LONG_MAX / 10) && (*str - '0') > (LONG_MAX % 10))
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') \
					|| (c == '\f') || (c == '\r') || (c == ' '))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	neg_flg;
	long	num;

	neg_flg = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg_flg = -1;
	while (ft_isdigit(*str))
	{
		if (neg_flg == -1)
		{
			if (overflow_min_checker(num, str))
				return ((int)LONG_MIN);
		}
		else
		{
			if (overflow_max_checker(num, str))
				return ((int)LONG_MAX);
		}
		num = (num * 10) + (*str++ - '0');
	}
	return ((int)(num * neg_flg));
}
