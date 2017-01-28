/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:02:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/28 12:11:13 by hel-hadi         ###   ########.fr       */
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
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int		ft_putuns_f(char *s, va_list *p)
{
	unsigned	arg;
	int			nb;
	int			diff;
	int			check_type;


	nb = 0;
	diff = 0;
	check_type = 1;
	if (ft_check_long(s, 'u'))
	{
		ft_putuns_maj_f(s, p);
		return (0);
	}
	arg = va_arg(*p, unsigned);
	nb = ft_count_num((int long)arg);
	diff = ft_uns_size(s, check_type);
	ft_handle_uns(s, check_type);
	ft_size_chain_uns(s, nb, diff);
	ft_putuns(arg);
	ft_size_chain_uns_plus(s, nb, diff);
	return (0);
}
