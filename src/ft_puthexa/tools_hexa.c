/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:51:14 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 16:43:47 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_puthexa_long(unsigned long long nb)
{
	char *tab = "0123456789abcdef";
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
	char *tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_size(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_short(int nb)
{
	char *tab = "0123456789abcdef";
	if (nb > 32767)
		nb = nb * (-1);
	if (nb <= 15)
	{
		if (nb <= 32767)
			ft_putchar(tab[nb]);
	}
	if (nb >= 16)
	{
		ft_puthexa_short(nb / 16);
		if (nb <= 32767)
			ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_max(size_t nb)
{
	char *tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_max(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa(unsigned nb)
{
	char *tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}
