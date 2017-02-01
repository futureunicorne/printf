/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_maj_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:10:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 10:07:18 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbr_octal_len_maj(unsigned long long nb)
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

void	ft_putoctal_maj(unsigned long long n)
{
	unsigned long long nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb >= 7)
	{
		ft_putoctal_maj(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_maj_f(char *s ,va_list *p)
{
	unsigned long long	arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	arg = va_arg(*p, unsigned long long);
	nb = ft_nbr_octal_len_maj((int long)arg);
	diff = ft_oct_size(s, check_type);
	ft_handle_oct(s, check_type);
	ft_size_chain_oct(s, nb, diff, arg);
	ft_putoctal_maj(arg);
	ft_size_chain_oct_plus(s, nb, diff);
	return (0);
}
