/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:02:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/17 16:32:50 by hel-hadi         ###   ########.fr       */
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

int		ft_putuns_f(char *s, va_list *p)
{
	unsigned arg;

	arg = va_arg(*p, unsigned);
	ft_handle_flag(s, (void*)arg);
	ft_putuns(arg);
	return (0);
}
