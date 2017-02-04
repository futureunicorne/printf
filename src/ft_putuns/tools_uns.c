/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:10:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 17:15:57 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putuns(unsigned n)
{
	unsigned nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putuns_short(unsigned short n)
{
	unsigned short nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns_short(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putuns_short2(unsigned char n)
{
	unsigned char nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns_short2(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putuns_max(intmax_t n)
{
 	size_t nb;

	nb = n;

	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns_max(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putuns_size(size_t n)
{
 	size_t nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns_size(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}
