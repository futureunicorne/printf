/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/28 11:27:56 by hel-hadi         ###   ########.fr       */
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
/*
int		ft_strhlen_long(unsigned long long nb)
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
*/
void	ft_puthexa_long(unsigned long long nb)
{
	char *tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_long(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
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

int	ft_puthexa_long_f(char *s, va_list *p)
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
	ft_puthexa_long(arg);
	ft_size_chain_hexa_plus(s, nb, diff);
	return (0);
}

int	ft_puthexa_f(char *s, va_list *p)
{
	int			arg;

	int			nb;
	int			diff;
	int			check_type;

	if (ft_check_long(s, 'x'))
	{
		ft_puthexa_long_f(s, p);
		return (0);
	}
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
