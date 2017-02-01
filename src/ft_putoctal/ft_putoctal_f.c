/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:35:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 19:54:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbr_octal_len(size_t nb)
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

void	ft_putoctal_max(intmax_t n)
{
	intmax_t nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

void	ft_putoctal_size(size_t n)
{
	size_t nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

void	ft_putoctal_short(short int n)
{
	short int nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_j(char *s, va_list *p)
{
	intmax_t 	arg;
	int			nb;
	int			val;
	int			diff;
	int			check_type;

	check_type = 1;
	val = 0;
	arg = va_arg(*p, intmax_t);
	nb = ft_nbr_octal_len(arg);
	diff = ft_oct_size(s, check_type);
	if (arg == 0)
	{
		diff = 0;
		nb = 1;
	}
	ft_handle_oct(s, check_type);
	val =  val  + ft_size_chain_oct(s, nb, diff, arg);
	ft_putoctal_max(arg);
	val =  val  + ft_size_chain_oct_plus(s, nb, diff);
	return (val + nb);
}

int	ft_putoctal_z(char *s, va_list *p)
{
	size_t 		arg;
	int			val;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	val = 0;
	arg = va_arg(*p, size_t);
	nb = ft_nbr_octal_len(arg);
	diff = ft_oct_size(s, check_type);
	if (arg == 0)
	{
		diff = 0;
		nb = 1;
	}
	ft_handle_oct(s, check_type);
	val =  val  + ft_size_chain_oct(s, nb, diff, arg);
	ft_putoctal_size(arg);
	val =  val  + ft_size_chain_oct_plus(s, nb, diff);
	return (val + nb);
}

int	ft_putoctal_h(char *s, va_list *p)
{
	short int 	arg;
	int			nb;
	int			val;
	int			diff;
	int			check_type;

	check_type = 1;
	val  = 0;
	arg = va_arg(*p, int);
	nb = ft_nbr_octal_len(arg);
	diff = ft_oct_size(s, check_type);
	if (arg == 0)
	{
		diff = 0;
		nb = 1;
	}
	ft_handle_oct(s, check_type);
	val =  val  + ft_size_chain_oct(s, nb, diff, arg);
	ft_putoctal_short(arg);
	val =  val  + ft_size_chain_oct_plus(s, nb, diff);
	return (val + nb);
}

int	ft_putoctal_f(char *s, va_list *p)
{
	unsigned 	arg;
	int			nb;
	int			diff;
	int			val;
	int			flag;
	int			check_type;

	check_type = 1;
	val = 0;
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			ft_putoctal_maj_f(s, p);
		else if (ft_check_long(s) == 'h')
			ft_putoctal_h(s, p);
		else if (ft_check_long(s) == 'j')
			ft_putoctal_j(s, p);
		else if (ft_check_long(s) == 'z')
			ft_putoctal_z(s, p);
		return (0);
	}
	flag = 0;
	arg = va_arg(*p, int long);
	nb = ft_nbr_octal_len(arg);
	diff = ft_oct_size(s, check_type);
	if (arg == 0)
	{
		if (!ft_check_point(s))
			nb = 1;
		else
		{
			nb = 0;
			flag = 1;
		}
		if (diff)
			diff = diff -1;
	}
	ft_handle_oct(s, check_type);
	val =  val  + ft_size_chain_oct(s, nb, diff, arg);
	if (flag == 0)
		ft_putoctal(arg);
	val =  val  + ft_size_chain_oct_plus(s, nb, diff);
	return (val + nb);
}
