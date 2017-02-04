/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 20:34:40 by hel-hadi         ###   ########.fr       */
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

int	ft_puthexa_l(char *s, va_list *p)
{
	unsigned long long	arg;
	t_ptr 				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned long long);
	ptr.nb = ft_strhlen((unsigned long long)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	if (arg == 0)
	{
		ptr.nb = 1;
		ptr.diff =  ptr.diff - 1;
	}
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_long(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_puthexa_hh(char *s, va_list *p)
{
	unsigned	arg;
	t_ptr 		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	ptr.nb = ft_strhlen((int)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	if (arg == 0)
	{
		ptr.nb = 1;
		ptr.diff =  ptr.diff - 1;
	}
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_short2(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_puthexa_h(char *s, va_list *p)
{
	unsigned		arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	ptr.nb = ft_strhlen((unsigned)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	if (arg == 0)
	{
		ptr.nb = 1;
		ptr.diff =  ptr.diff - 1;
	}
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_short(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_puthexa_j(char *s, va_list *p)
{
	intmax_t	arg;
	t_ptr 		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, intmax_t);
	ptr.nb = ft_strhlen((intmax_t)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	if (arg == 0)
	{
		ptr.nb = 1;
		ptr.diff =  ptr.diff - 1;
	}
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_max(arg);

	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_puthexa_z(char *s, va_list *p)
{
	size_t	arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, size_t);
	ptr.nb = ft_strhlen((int)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	if (arg == 0)
	{
		ptr.nb = 1;
		ptr.diff =  ptr.diff - 1;
	}
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_size(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_puthexa_f(char *s, va_list *p)
{
	int		arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			ptr.val = ft_puthexa_l(s, p);
		else if (ft_check_long(s) == 'h')
			ptr.val = ft_puthexa_h(s, p);
		else if (ft_check_long(s) == 'j')
			ptr.val = ft_puthexa_j(s, p);
		else if (ft_check_long(s) == 'z')
			ptr.val = ft_puthexa_z(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	ptr.nb = ft_strhlen((unsigned)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	if (arg == 0)
	{
		if (!ft_check_point(s))
			ptr.nb = 1;
		else
		{
			ptr.nb = 0;
			ptr.flag = 1;
		}
		if (ptr.diff)
			ptr.diff = ptr.diff -1 ;
	}
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	if (ptr.flag == 0)
		ft_puthexa(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
