/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hexa3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:59:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/07 23:20:27 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strhlen(size_t nb)
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

int		ft_puthexa_0(char *s, int arg)
{
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.nb = 1;
	ptr.diff = ft_nbr_size(s, arg);
	if (ft_check_point(s) && ft_check_point(s))
	{
		ptr.nb = 0;
		ptr.flag = 1;
	}
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	if (!ptr.flag && !ft_check_dieses(s))
	{
		ft_putchar('0');
		ptr.val++;
	}
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	if (ft_check_dieses(s) && ((ft_record_chain(s) && !ft_check_point(s))
	|| (!ft_record_chain(s) && !ft_record_prec(s))))
	{
		ft_putchar('0');
		ptr.val++;
	}
	return (ptr.val);
}

int		ft_puthexa_z(char *s, va_list *p)
{
	size_t	arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, size_t);
	if (arg == 0)
		return (ft_puthexa_0(s, arg));
	ptr.nb = ft_strhlen((size_t)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_size(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

void	ft_puthexa_maj(unsigned int n)
{
	unsigned int	nb;
	unsigned int	na;
	char			*tab;

	tab = "0123456789ABCDEF";
	nb = n;
	na = 0;
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

void	ft_puthexa(unsigned nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}
