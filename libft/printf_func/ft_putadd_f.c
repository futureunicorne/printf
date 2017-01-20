/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:30:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 18:48:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putadd(int long n)
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
		ft_putadd(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 87);
		na = 0;
	}
}

int	ft_putadd_f(char *s, va_list *p)
{
	int long	arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 0;
	arg = va_arg(*p, int long);
	nb = ft_count_num((int long)arg);
	diff = ft_flag_size(s, (void*)arg);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain(s, nb, diff);
	ft_putstr("0x");
	ft_putadd(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
