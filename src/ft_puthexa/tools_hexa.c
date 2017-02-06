/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:51:14 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 19:45:21 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_puthexa_long(unsigned long long nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_long(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_size(size_t nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_size(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_short(unsigned short nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_short(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_short2(unsigned char nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_short2(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_max(size_t nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_max(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}
