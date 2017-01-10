/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_big_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:21:49 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 13:22:24 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putuns(unsigned long long n)
{
	unsigned long long nb;

	nb = n;
	if ((long int)nb < 0)
		ft_putchar('-');
		nb = nb * (-1);
	}
	if ((int)nb >= 0 && (int)nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}
