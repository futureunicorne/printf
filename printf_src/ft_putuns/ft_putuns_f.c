/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:02:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 07:06:45 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putuns(unsigned n)
{
	unsigned nb;

	nb = n;
	if ((unsigned)nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if ((unsigned)nb >= 0 && nb <= 9)
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
	arg = va_arg(*p, unsigned);
	nb = ft_count_num((int long)arg);
	diff = ft_uns_size(s, (void*)arg, check_type);
	ft_handle_uns(s, (void*)arg, check_type);
	ft_size_chain(s, nb, diff);
	ft_putuns(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
