/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:02:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/11 11:42:27 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putuns(unsigned n)
{
	unsigned nb;

	nb = n;
	if (!(unsigned)nb)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if ((unsigned)nb && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int		ft_putuns_f(va_list *p)
{
	ft_putuns(va_arg(*p, unsigned));
	return (0);
}
