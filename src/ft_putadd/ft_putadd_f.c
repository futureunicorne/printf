/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 10:30:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 15:36:48 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbr_add_len(size_t nb)
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

void	ft_putadd(int long nb)
{
	char *tab = "0123456789abcdef";
	if (nb >= 0 && nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_putadd(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

int	ft_putadd_f(char *s, va_list *p)
{
	int long		arg;
	t_ptr 			ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_long(s))
	{
		ft_putstr("0x");
		ptr.val = ptr.val + ft_puthexa_l(s, p);
		return (ptr.val + 2);
	}
	arg = va_arg(*p, int long);
	ptr.nb = ft_nbr_add_len((int long)&arg);
	if (arg == 0)
		ptr.nb = 1;
	ptr.diff = ft_add_size(s, arg, ptr.check_type);
	ft_handle_add(s, arg, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_add(s, ptr.nb, ptr.diff);
	ft_putadd(arg);
	ptr.val = ptr.val + ft_size_chain_add_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
