/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuns_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:02:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/05 23:13:18 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putuns_hh(char *s, va_list *p)
{
	unsigned char 	arg;
	t_ptr 			ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	if (arg == 0)
		return (ft_putuns_0(s, arg));
	ptr.nb = ft_count_num((unsigned char)arg);
	ptr.diff = ft_uns_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_uns(s, ptr.nb, ptr.diff);
	ft_putuns_short2(arg);
	ptr.val = ptr.val + ft_size_chain_uns_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int		ft_putuns_h(char *s, va_list *p)
{
	unsigned short	arg;
	t_ptr 			ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	if (ft_check_letter(s, 'h'))
	{
		ptr.val = ft_putuns_hh(s, p);
		return (ptr.val);
	}
	arg = va_arg(*p, unsigned);
	if (arg == 0)
		return (ft_putuns_0(s, arg));
	ptr.nb = ft_count_num((unsigned short)arg);
	ptr.diff = ft_uns_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_uns(s, ptr.nb, ptr.diff);
	ft_putuns_short(arg);
	ptr.val = ptr.val + ft_size_chain_uns_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int		ft_putuns_j(char *s, va_list *p)
{
	intmax_t	arg;
	t_ptr 		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, intmax_t);
	if (arg == 0)
		return (ft_putuns_0(s, arg));
	ptr.nb = ft_count_num(arg);
	ptr.diff = ft_uns_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_uns(s, ptr.nb, ptr.diff);
	ft_putuns_max(arg);
	ptr.val = ptr.val + ft_size_chain_uns_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int		ft_putuns_z(char *s, va_list *p)
{
	size_t		arg;
	t_ptr 		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, size_t);
	if (arg == 0)
		return (ft_putuns_0(s, arg));
	ptr.nb = ft_count_num(arg);
	ptr.diff = ft_uns_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_uns(s, ptr.nb, ptr.diff);
	ft_putuns_size(arg);
	ptr.val = ptr.val + ft_size_chain_uns_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putuns_0(char *s, int arg)
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
	ptr.val = ft_size_chain_uns(s, ptr.nb, ptr.diff);
	if (!ptr.flag)
	{
		ft_putchar('0');
		ptr.val++;
	}
	ptr.val =  ptr.val  + ft_size_chain_uns_plus(s, ptr.nb, ptr.diff);
	return (ptr.val);
}

int		ft_putuns_f(char *s, va_list *p)
{
	unsigned	arg;
	t_ptr 		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			ptr.val = ft_putuns_maj_f(s, p);
		else if (ft_check_long(s) == 'h')
			ptr.val = ft_putuns_h(s, p);
		else if (ft_check_long(s) == 'j')
			ptr.val = ft_putuns_j(s, p);
		else if (ft_check_long(s) == 'z')
			ptr.val = ft_putuns_z(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	if (arg == 0)
		return (ft_putuns_0(s, arg));
	ptr.nb = ft_count_num((unsigned)arg);
	ptr.diff = ft_uns_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_uns(s, ptr.nb, ptr.diff);
	ft_putuns(arg);
	ptr.val = ptr.val + ft_size_chain_uns_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
