/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_big_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:10:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 20:43:38 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putoctal_maj(long long n)
{
	int long nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 1)
	{
		ft_putoctal_maj(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_maj_f(va_list *p)
{
	ft_putoctal_maj(va_arg(*p, long long));
	return (0);
}
