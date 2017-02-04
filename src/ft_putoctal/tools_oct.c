/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:28:54 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 15:32:13 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putoctal_long(unsigned long long n)
{
	unsigned long long  nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal_long(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

void	ft_putoctal_max(intmax_t n)
{
	intmax_t nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal_max(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

void	ft_putoctal_size(size_t n)
{
	size_t nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal_size(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_short2(unsigned char n)
{
  	unsigned char nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal_short2(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
	return (0);
}


int	ft_putoctal_short(unsigned n)
{
  	short unsigned nb;

	nb = n;
	if (n == 65535)
	{
		ft_putstr("177777");
		return (0);
	}
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal_short(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
	return (0);
}
