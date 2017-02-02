/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:02:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/02 21:22:23 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putuns(unsigned n)
{
	unsigned nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putuns_short(unsigned short n)
{
	unsigned short nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putuns_max(intmax_t n)
{
 	intmax_t nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

void	ft_putuns_size(size_t n)
{
 	size_t nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int		ft_putuns_h(char *s, va_list *p)
{
	unsigned short	arg;
	int				nb;
	int				val;
	int				diff;
	int				check_type;


	nb = 0;
	diff = 0;
	val = 0;
	check_type = 1;

	arg = va_arg(*p, unsigned);
	nb = ft_count_num(arg);
	diff = ft_uns_size(s, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = val + ft_size_chain_uns(s, nb, diff);
	ft_putuns_short(arg);
	val = val + ft_size_chain_uns_plus(s, nb, diff);
	return (val + nb);
}

int		ft_putuns_j(char *s, va_list *p)
{
	intmax_t	arg;
	int			nb;
	int			val;
	int			diff;
	int			check_type;


	nb = 0;
	diff = 0;
	check_type = 1;
	arg = va_arg(*p, intmax_t);
	nb = ft_count_num(arg);
	diff = ft_uns_size(s, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = val + ft_size_chain_uns(s, nb, diff);
	ft_putuns_max(arg);
	val = val + ft_size_chain_uns_plus(s, nb, diff);
	return (val + nb);
}

int		ft_putuns_z(char *s, va_list *p)
{
	size_t		arg;
	int			nb;
	int			val;
	int			diff;
	int			check_type;


	nb = 0;
	diff = 0;
	val = 0;
	check_type = 1;

	arg = va_arg(*p, size_t);
	nb = ft_count_num(arg);
	diff = ft_uns_size(s, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = val + ft_size_chain_uns(s, nb, diff);
	ft_putuns_size(arg);
	val = val + ft_size_chain_uns_plus(s, nb, diff);
	return (val + nb);
}

int		ft_putuns_f(char *s, va_list *p)
{
	unsigned	arg;
	int			nb;
	int			val;
	int			diff;
	int			check_type;


	nb = 0;
	diff = 0;
	val = 0;
	check_type = 1;
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			val = ft_putuns_maj_f(s, p);
		else if (ft_check_long(s) == 'h')
			val = ft_putuns_h(s, p);
		else if (ft_check_long(s) == 'j')
			val = ft_putuns_j(s, p);
		else if (ft_check_long(s) == 'z')
			val = ft_putuns_z(s, p);
		return (val);
	}
	arg = va_arg(*p, unsigned);
	nb = ft_count_num(arg);
	diff = ft_uns_size(s, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = val + ft_size_chain_uns(s, nb, diff);
	ft_putuns(arg);
	val = val + ft_size_chain_uns_plus(s, nb, diff);
	return (val + nb);
}
