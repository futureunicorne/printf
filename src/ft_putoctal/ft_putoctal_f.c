/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:35:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/28 11:35:50 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbr_octal_len(int long nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 8;
		i++;
	}
	return (i);
}
void	ft_putoctal(unsigned n)
{
	unsigned nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_f(char *s, va_list *p)
{
	unsigned 	arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	if (ft_check_long(s, 'o'))
	{
		ft_putoctal_maj_f(s, p);
		return (0);
	}
	arg = va_arg(*p, int long);
	nb = ft_nbr_octal_len((int long)arg);
	diff = ft_oct_size(s, check_type);
	ft_handle_oct(s, check_type);
	ft_size_chain_oct(s, nb, diff);
	ft_putoctal(arg);
	ft_size_chain_oct_plus(s, nb, diff);
	return (0);
}
