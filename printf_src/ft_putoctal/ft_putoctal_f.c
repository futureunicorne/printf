/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:35:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 13:48:33 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

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
void	ft_putoctal(int long n)
{
	int long nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_f(char *s, va_list *p)
{
	int long	arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	arg = va_arg(*p, int long);
	nb = ft_nbr_octal_len((int long)arg);
	diff = ft_oct_size(s, (void*)arg, check_type);
	ft_handle_oct(s, (void*)arg, check_type);
	ft_size_chain_oct(s, nb, diff);
	ft_putoctal(arg);
	ft_size_chain_oct_plus(s, nb, diff);
	return (0);
}
