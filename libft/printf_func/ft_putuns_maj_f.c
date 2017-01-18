/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:21:49 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 15:13:57 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putuns_maj(unsigned long long n)
{
	unsigned long long nb;

	nb = n;
	if (!(unsigned long long)nb)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if ((unsigned long long)nb && nb <= 9)
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

	nb = 0;
	diff = 0;
	arg = va_arg(*p, unsigned long long);
	nb = ft_count_num((int long)arg);
	diff = ft_flag_size(s, (void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, (void*)arg);
	ft_putuns_maj(arg);
	return (0);
}
