/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 17:19:22 by hel-hadi         ###   ########.fr       */
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

void	ft_putnbr_maj_less(long long n)
{

	long long nb;
	nb = n;
	if ((long long)nb < -9223372036854775807)
		ft_putstr("9223372036854775808");
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * (-1);
		}
		if (nb >= 0 && nb <= 9)
			ft_putchar(nb + 48);
		if (nb > 9)
		{
			ft_putnbr_maj_less(nb / 10);
			ft_putchar((nb % 10) + 48);
		}
	}
}

void	ft_putnbr_maj(long long n)
{

	long long nb;
	nb = n;
	if ((long long)nb < -9223372036854775807)
		ft_putstr("-9223372036854775808");
	else
	{
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
}

void	ft_putnbr_short(short int n)
{
	short int nb;

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
		ft_putnbr_short(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_max(intmax_t n)
{
	intmax_t nb;

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
		ft_putnbr_max(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putnbr_size(size_t n)
{
	size_t nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr_size(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int	ft_putnbr_maj_f(char *s, va_list *p)
{
	long long arg;
	int nb;
	int val;
	int diff;

	diff = 0;
	arg = va_arg(*p, long long);
	nb = ft_count_nb_long((ssize_t)arg);
	diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis_maj(s, arg))
	{
		nb = ft_count_num_2(arg);
		val = ft_size_chain_nbr_less(s, nb, diff, (size_t)arg);
		ft_putnbr_maj_less(arg);
	}
	else
	{
		nb = ft_count_num(arg);
		val = ft_size_chain_nbr(s, nb, diff, (size_t)arg);
		ft_putnbr_maj(arg);
	}
	val += ft_size_chain_nbr_plus(s, nb, diff);
	val += nb;
	return (val + nb);
}

int	ft_putnbr_j(char *s, va_list *p)
{
	intmax_t arg;
	int nb;
	int val;
	int diff;

	diff = 0;
	arg = va_arg(*p, intmax_t);
	diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		nb = ft_count_num_2(arg);
		val = ft_size_chain_nbr_less(s, nb, diff, (size_t)arg);
		ft_putnbr_less(arg);
	}
	else
	{
		nb = ft_count_num(arg);
		val = ft_size_chain_nbr(s, nb, diff, (size_t)arg);
		ft_putnbr_max(arg);
	}
	val += ft_size_chain_nbr_plus(s, nb, diff);
	val += nb;
	return (val + nb);
}

int	ft_putnbr_z(char *s, va_list *p)
{
	size_t arg;
	int nb;
	int val;
	int diff;

	diff = 0;
	arg = va_arg(*p, size_t);
	diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		nb = ft_count_num_2(arg);
		val = ft_size_chain_nbr_less(s, nb, diff, (size_t)arg);
		ft_putnbr_less(arg);
	}
	else
	{
		nb = ft_count_num(arg);
		val = ft_size_chain_nbr(s, nb, diff, (size_t)arg);
		ft_putnbr_size(arg);
	}
	val += ft_size_chain_nbr_plus(s, nb, diff);
	val += nb;
	return (val + nb);
}

int	ft_putnbr_h(char *s, va_list *p)
{
	short arg;
	int nb;
	int val;
	int diff;

	diff = 0;
	arg = va_arg(*p, int);
	diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		nb = ft_count_num_2(arg);
		val = ft_size_chain_nbr_less(s, nb, diff, (size_t)arg);
		ft_putnbr_less(arg);
	}
	else
	{
		nb = ft_count_num(arg);
		val = ft_size_chain_nbr(s, nb, diff, (size_t)arg);
		ft_putnbr_short(arg);
	}
	val += ft_size_chain_nbr_plus(s, nb, diff);
	val += nb;
	return (val + nb);
}


int	ft_putnbr_f(char *s, va_list *p)
{
	int arg;
	int nb;
	int val;
	int diff;

	diff = 0;
	val = 0;
	if (ft_check_long(s))
	{
		if (ft_check_long(s))
		{
			if (ft_check_long(s) == 'l')
				ft_putnbr_maj_f(s, p);
			else if (ft_check_long(s) == 'h')
				ft_putnbr_h(s, p);
			else if (ft_check_long(s) == 'j')
				ft_putnbr_j(s, p);
			else if (ft_check_long(s) == 'z')
				ft_putnbr_z(s, p);
			return (0);
		}
	}
	arg = va_arg(*p, int);
	diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		nb = ft_count_num_2(arg);
		if (arg == 0)
		{
			nb = 1;
			diff =  diff - 1;
		}
		val = ft_size_chain_nbr_less(s, nb, diff, (size_t)arg);
		printf("oui\n");

		if (arg != 0)
			ft_putnbr_less(arg);
	}
	else
	{
		nb = ft_count_num(arg);
		if (arg == 0)
		{
			nb = 1;
			diff =  diff - 1;
		}
		val = ft_size_chain_nbr(s, nb, diff, (size_t)arg);
		if (arg != 0)
			ft_putnbr(arg);
	}
	val += ft_size_chain_nbr_plus(s, nb, diff);
	val += nb;
	return (val);
}
