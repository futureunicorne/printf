/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:26 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 18:08:48 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_puthexa_size_maj(size_t nb)
{
	char *tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_size_maj(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_short_maj(int nb)
{
	char *tab = "0123456789ABCDEF";
	if (nb > 32767)
		nb = nb * (-1);
	if (nb <= 15)
	{
		if (nb <= 32767)
			ft_putchar(tab[nb]);
	}
	if (nb >= 16)
	{
		ft_puthexa_short_maj(nb / 16);
		if (nb <= 32767)
			ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_max_maj(size_t nb)
{
	char *tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_max_maj(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_puthexa_maj_long(unsigned long long n)
{
	unsigned long long nb;
	unsigned long long na;

	nb = n;
	na = 0;
	char *tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_maj_long(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 55);
		na = 0;
	}
}

void	ft_puthexa_maj(unsigned int n)
{
	unsigned int nb;
	unsigned int na;

	nb = n;
	na = 0;
	char *tab = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_maj(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 55);
		na = 0;
	}
}

int	ft_puthexa_maj_h(char *s, va_list *p)
{
	int					arg;
	int					val;
	int					nb;
	int					base;
	int					diff;
	int					check_type;
	check_type = 1;

	arg = va_arg(*p, int);
	nb = ft_strhlen((int)arg);
	diff = ft_hexa_size(s, arg, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = ft_size_chain_hexa_maj(s, nb, diff, arg);
	ft_puthexa_short_maj(arg);
	val = val + ft_size_chain_hexa_plus_maj(s, nb, diff);
	return (val + nb);
}

int	ft_puthexa_maj_j(char *s, va_list *p)
{
	intmax_t			arg;
	int					val;
	int					nb;
	int					base;
	int					diff;
	int					check_type;
	check_type = 1;

	arg = va_arg(*p, intmax_t);
	nb = ft_strhlen((intmax_t)arg);
	diff = ft_hexa_size(s, arg, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = ft_size_chain_hexa_maj(s, nb, diff, arg);
	ft_puthexa_max_maj(arg);

	val = val + ft_size_chain_hexa_plus_maj(s, nb, diff);
	return (val + nb);
}

int	ft_puthexa_maj_z(char *s, va_list *p)
{
	size_t				arg;
	int					val;
	int					nb;
	int					base;
	int					diff;
	int					check_type;

	check_type = 1;
	arg = va_arg(*p, size_t);
	nb = ft_strhlen((int)arg);
	diff = ft_hexa_size(s, arg, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = ft_size_chain_hexa_maj(s, nb, diff, arg);
	ft_puthexa_size_maj(arg);
	val = val + ft_size_chain_hexa_plus_maj(s, nb, diff);
	return (val + nb);
}

int	ft_puthexa_maj_l(char *s, va_list *p)
{
	unsigned long long	arg;
	int					val;
	int					nb;
	int					base;
	int					diff;
	int					check_type;
	check_type = 1;

	arg = va_arg(*p, unsigned long long);
	nb = ft_strhlen((int)arg);
	diff = ft_hexa_size(s, arg, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = ft_size_chain_hexa_maj(s, nb, diff, arg);
	ft_puthexa_maj_long(arg);
	val = val + ft_size_chain_hexa_plus_maj(s, nb, diff);
	return (val + nb);
}

int	ft_puthexa_maj_f(char *s, va_list *p)
{
	int 		arg;
	int			val;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			val = ft_puthexa_maj_l(s, p);
		else if (ft_check_long(s) == 'h')
			val = ft_puthexa_maj_h(s, p);
		else if (ft_check_long(s) == 'j')
			val = ft_puthexa_maj_j(s, p);
		else if (ft_check_long(s) == 'z')
			val = ft_puthexa_maj_z(s, p);
		return (val);
	}
	arg = va_arg(*p, int long);
	nb = ft_strhlen((unsigned)arg);
	diff = ft_hexa_size(s, arg, check_type);
	if (arg == 0)
	{
		nb = 1;
		diff =  diff - 1;
	}
	val = ft_size_chain_hexa_maj(s, nb, diff, arg);
	ft_puthexa_maj(arg);
	val = val + ft_size_chain_hexa_plus_maj(s, nb, diff);
	return (val + nb);
}
