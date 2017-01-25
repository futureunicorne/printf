/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/25 11:21:24 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strhlen(int nb)
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

void	ft_puthexa(unsigned nb)
{
	char *tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

int	ft_puthexa_f(char *s, va_list *p)
{
	int			arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	arg = va_arg(*p, unsigned);
	nb = ft_strhlen((int)arg);
	diff = ft_hexa_size(s, arg, check_type);
	ft_handle_hexa(s, arg, check_type);
	ft_size_chain_hexa(s, nb, diff);
	ft_puthexa(arg);
	ft_size_chain_hexa_plus(s, nb, diff);
	return (0);
}
