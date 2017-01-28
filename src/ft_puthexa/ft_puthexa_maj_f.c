/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:26 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/28 11:14:11 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

int	ft_puthexa_maj_long_f(char *s, va_list *p)
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
	ft_handle_hexa(s, arg, check_type);
	ft_size_chain_hexa(s, nb, diff);
	ft_puthexa_maj_long(arg);
	ft_size_chain_hexa_plus(s, nb, diff);
	return (0);
}

int	ft_puthexa_maj_f(char *s, va_list *p)
{
	int 		arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	if (ft_check_long(s, 'X'))
	{
		ft_puthexa_maj_long_f(s, p);
		return (0);
	}
	arg = va_arg(*p, int long);
	nb = ft_strhlen((int long)arg);
	diff = ft_hexa_size(s, arg, check_type);
	ft_handle_hexa(s, arg, check_type);
	ft_size_chain_hexa_maj(s, nb, diff);
	ft_puthexa_maj(arg);
	ft_size_chain_hexa_plus(s, nb, diff);
	return (0);
}
