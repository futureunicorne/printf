/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_maj_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:10:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 19:00:23 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putoctal_j(char *s, va_list *p)
{
	intmax_t 	arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, intmax_t);
	ptr.nb = ft_nbr_octal_len(arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	if (arg == 0)
	{
		ptr.diff = 0;
		ptr.nb = 1;
	}
	ptr.val =  ptr.val  + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_max(arg);
	ptr.val =  ptr.val  + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_maj_f(char *s ,va_list *p)
{
	unsigned 	arg;
	t_ptr		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			ptr.val = ft_putoctal_l(s, p);
		else if (ft_check_long(s) == 'h')
			ptr.val = ft_putoctal_h(s, p);
		else if (ft_check_long(s) == 'j')
			ptr.val = ft_putoctal_j(s, p);
		else if (ft_check_long(s) == 'z')
			ptr.val = ft_putoctal_z(s, p);
		return (ptr.val);
	}
	arg = va_arg(*p, unsigned);
	ptr.nb = ft_nbr_octal_len_maj((int long)arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	if (arg == 0)
	{
		ptr.diff = 0;
		ptr.nb = 1;
	}
	ptr.val =  ptr.val  + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal(arg);
	ptr.val =  ptr.val  + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
