/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 20:38:16 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_maj(int long n)
{

	long long nb;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_maj(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int	ft_putnbr_maj_f(va_list *p)
{
	ft_putnbr_maj(va_arg(*p, int long));
	return (0);
}

int	ft_putnbr_f(va_list *p)
{
	ft_putnbr(va_arg(*p, int));
	return (0);
}
