/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 14:42:24 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/27 16:41:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_num(ssize_t n)
{
	int count;

	count = 0;
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_count_nb_long(long long n)
{
	int count;

	count = 0;
	if (n < -9223372036854775807)
		return (20);
	if (n >= 0 && n <= 9)
		return (1);
	if (n < 0)
	{
		n = n * (-1);
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
