/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamaguc <kyamaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:02:25 by kyamaguc          #+#    #+#             */
/*   Updated: 2023/01/29 12:56:19 by kyamaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(long n)
{
	size_t	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*int_min_gen(void)
{
	char	*num;

	num = malloc(sizeof(char) * (11 + 1));
	if (!num)
		return (NULL);
	ft_strlcpy(num, "-2147483648", 12);
	return (num);
}

char	*ft_itoa(int n)
{
	char	*num;
	size_t	count;

	if (n == INT_MIN)
		return (int_min_gen());
	count = count_digit(n);
	num = malloc(sizeof(char) * (count + 1));
	if (!num)
		return (NULL);
	if (n < 0)
	{
		num[0] = '-';
		n *= -1;
	}
	num[count--] = '\0';
	while (n > 9)
	{
		num[count--] = (n % 10) + '0';
		n /= 10;
	}
	num[count] = (n % 10) + '0';
	return (num);
}
