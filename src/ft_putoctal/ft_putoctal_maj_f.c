/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_maj_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:10:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 17:09:08 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putoctal_0(char *s, int arg)
{
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.nb = 1;
	ptr.diff = ft_nbr_size(s, arg);
	if (ft_check_point(s))
	{
		ptr.diff = ptr.diff - 1;
		ptr.flag = 1;
	}
	ptr.val = ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	if (!ptr.flag && !ft_check_dieses(s))
	{
		ft_putchar('0');
		ptr.val++;
	}
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val);
}

int	ft_putoctal_j(char *s, va_list *p)
{
	intmax_t	arg;
	t_ptr		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, intmax_t);
	if (arg == 0)
		return (ft_putoctal_0(s, arg));
	ptr.nb = ft_nbr_octal_len((intmax_t)arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_max(arg);
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_maj_f(char *s, va_list *p)
{
	unsigned long long	arg;
	t_ptr				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			return (ft_putoctal_l(s, p));
		else if (ft_check_long(s) == 'h')
			return (ft_putoctal_h(s, p));
		else if (ft_check_long(s) == 'j')
			return (ft_putoctal_j(s, p));
		else if (ft_check_long(s) == 'z')
			return (ft_putoctal_z(s, p));
	}
	arg = va_arg(*p, unsigned long long);
	if (arg == 0)
		return (ft_putoctal_0(s, arg));
	ptr.nb = ft_nbr_octal_len_maj((unsigned long long)arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_long(arg);
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
