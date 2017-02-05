/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:21:49 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/05 22:38:31 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putuns_maj(unsigned long long n)
{
	unsigned long long nb;

	nb = n;
	if (nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putuns_maj(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int ft_putuns_maj_f(char *s, va_list *p)
{
	unsigned long long	arg;
	t_ptr 				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned long long);
	if (arg == 0)
		return (ft_putuns_0(s, arg));
	ptr.nb = ft_count_num(arg);
	ptr.diff = ft_uns_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_uns(s, ptr.nb, ptr.diff);
	ft_putuns_maj(arg);
	ptr.val = ptr.val + ft_size_chain_uns_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
