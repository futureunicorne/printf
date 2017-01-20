/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:30:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/20 16:02:26 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_nbr_add_len(int long nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_putadd(int long nb)
{
	char *tab = "0123456789abcdef";
	if (nb >= 0 && nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_putadd(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

int	ft_putadd_f(char *s, va_list *p)
{
	int long	arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	arg = va_arg(*p, int long);
	nb = ft_nbr_add_len(&arg) + 2;
	diff = ft_flag_size(s, (void*)arg, check_type);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain_add(s, nb, diff);
	ft_putadd(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
