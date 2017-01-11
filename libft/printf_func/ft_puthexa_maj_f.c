/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:26 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/11 11:41:24 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthexa_maj(int long n)
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
	if (nb >= 1)
	{
		ft_puthexa_maj(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 55);
		na = 0;
	}
}

int	ft_puthexa_maj_f(va_list *p)
{
	ft_puthexa_maj(va_arg(*p, int long));
	return (0);
}
