/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/27 09:56:02 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_less(int n)
{
	int long nb;

	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_maj(int long n)
{

	long long nb;
	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_maj(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int	ft_putnbr_maj_f(char *s, va_list *p)
{
	int long 	arg;
	int 		nb;
	int			val;
	int			diff;
	int			len;
	int			check_type;

	check_type = 0;
	arg = va_arg(*p, int long);
	nb = ft_count_num((int long)arg);
	diff = ft_nbr_size_maj(s, arg, check_type);
	ft_handle_nbr_maj(s, arg, check_type);
	val = ft_size_chain_nbr(s, nb, diff, arg);
	ft_putnbr_maj(arg);
	val += ft_size_chain_nbr_plus(s, nb, diff);
	return (0);
}

int	ft_putnbr_f(char *s, va_list *p)
{
	int arg;
	int nb;
	int val;
	int diff;

	diff = 0;
	arg = va_arg(*p, int);
	nb = ft_count_num((int long)arg);
	diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		nb = nb;
		val = ft_size_chain_nbr_less(s, nb, diff, (size_t)arg);
		ft_putnbr_less(arg);
	}
	else
	{
		val = ft_size_chain_nbr(s, nb, diff, (size_t)arg);
		ft_putnbr(arg);
	}
	val += ft_size_chain_nbr_plus(s, nb, diff);
	val += nb;
	return (val);
}
