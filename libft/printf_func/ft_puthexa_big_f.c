/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_big_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:26 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 16:54:54 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthexa_big(int long n)
{
	int long nb;
	int long na;

	nb = n;
	na = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb > 1)
	{
		ft_puthexa_big(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 55);
		na = 0;
	}
}

int	ft_putadd_f(va_list *p)
{
	ft_putstr("0x");
	ft_puthexa(va_arg(*p, int long));
	return (0);
}

int	ft_puthexa_big_f(va_list *p)
{
	ft_puthexa_big(va_arg(*p, int long));
	return (0);
}
