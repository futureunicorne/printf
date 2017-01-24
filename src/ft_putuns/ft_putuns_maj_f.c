/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:21:49 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:37:48 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putuns_maj(unsigned long long n)
{
	unsigned long long nb;

	nb = n;
	if ((unsigned long long)nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if ((unsigned long long)nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns_maj(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int ft_putuns_maj_f(char *s, va_list *p)
{
	unsigned long long	arg;
	int					nb;
	int					diff;
	int				check_type;


	nb = 0;
	diff = 0;
	check_type = 1;
	arg = va_arg(*p, unsigned long long);
	nb = ft_count_num((int long)arg);
	diff = ft_uns_size(s, (void*)arg, check_type);
	ft_handle_uns(s, (void*)arg, check_type);
	ft_size_chain_uns(s, nb, diff);
	ft_putuns_maj(arg);
	ft_size_chain_uns_plus(s, nb, diff);
	return (0);
}
