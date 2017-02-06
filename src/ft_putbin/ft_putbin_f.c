/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 23:56:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 12:43:28 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbr_bin(unsigned long long nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{

	}
}

void	ft_puthexa(unsigned nb)
{
	char *tab = "0111111111";
	if (nb < 2)
		ft_putchar(tab[nb]);
	if (nb > 1)
	{
		ft_puthexa(nb / 2);
		ft_putchar(tab[nb % 2]);
	}
}

void	ft_putbin(unsigned long long nb)
{
	char *tab = "0123456789abcdef";
	if (nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_putbin(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

int	ft_putbin_f(char *s, va_list *p)
{
   unsigned		arg;
   t_ptr 		ptr;

   ft_memset(&ptr, 0, sizeof(t_ptr));
   ptr.check_type = 1;
   arg = va_arg(*p, unsigned);
   ptr.nb = ft_nbr_bin((unsigned)arg);
   ptr.diff = ft_bin_size(s, arg, ptr.check_type);
   ptr.val = ft_size_chain_bin(s, ptr.nb, ptr.diff, arg);
   ft_putbin(arg);
   ptr.val = ptr.val + ft_size_chain_bin_plus(s, ptr.nb, ptr.diff);
   return (ptr.val + ptr.nb);
}

