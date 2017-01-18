/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:02:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 15:13:08 by hel-hadi         ###   ########.fr       */
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
	unsigned	arg;
	int			nb;
	int			diff;

	nb = 0;
	diff = 0;
	arg = va_arg(*p, unsigned);
	nb = ft_count_num((int long)arg);
	diff = ft_flag_size(s, (void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, (void*)arg);
	ft_putuns(arg);
	return (0);
}
