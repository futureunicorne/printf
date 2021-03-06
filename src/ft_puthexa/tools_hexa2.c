/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hexa2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:52:21 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 19:43:58 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_puthexa_size_maj(size_t nb)
{
	char *tab;

	tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_size_maj(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_short_maj(unsigned short nb)
{
	char *tab;

	tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_short_maj(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_short_maj2(unsigned char nb)
{
	char *tab;

	tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_short_maj2(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_max_maj(size_t nb)
{
	char *tab;

	tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_max_maj(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_maj_long(unsigned long long n)
{
	unsigned long long	nb;
	unsigned long long	na;
	char				*tab;

	tab = "0123456789ABCDEF";
	nb = n;
	na = 0;
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_maj_long(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 55);
		na = 0;
	}
}
