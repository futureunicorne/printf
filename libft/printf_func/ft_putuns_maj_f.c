/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_big_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:21:49 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 20:45:40 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putuns_maj(unsigned long long n)
{
	unsigned long long nb;

	nb = n;
	if ((long int)nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if ((int)nb >= 0 && (int)nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns_maj(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int ft_putuns_maj_f(va_list *p)
{
	ft_putuns_maj(va_arg(*p, unsigned long long));
	return (0);
}