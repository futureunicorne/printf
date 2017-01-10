/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:35:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 17:23:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putoctal(int long n)
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
		ft_putoctal(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_f(va_list *p)
{
	ft_putoctal(va_arg(*p, int long));
	return (0);
}
