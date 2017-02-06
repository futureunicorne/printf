/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 13:58:30 by hel-hadi         ###   ########.fr       */
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
	if (arg == 0)
		return (ft_puthexa_0(s, arg));
	ptr.nb = ft_strhlen((unsigned long long)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
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
	if (arg == 0)
		return (ft_puthexa_0(s, arg));
	ptr.nb = ft_strhlen((unsigned char)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
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
	if (ft_check_letter(s, 'h'))
	{
		ptr.val = ft_puthexa_hh(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	if (arg == 0)
		return (ft_puthexa_0(s, arg));
	ptr.nb = ft_strhlen((unsigned)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
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
	if (arg == 0)
		return (ft_puthexa_0(s, arg));
	ptr.nb = ft_strhlen((intmax_t)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
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
	if (arg == 0)
		return (ft_puthexa_0(s, arg));
	ptr.nb = ft_strhlen((size_t)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_size(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_puthexa_0(char *s, int arg)
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
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	if (!ptr.flag)
	{
		ft_putchar('0');
		ptr.val++;
	}
	ptr.val =  ptr.val  + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val);
}

int	ft_puthexa_f(char *s, va_list *p)
{
	unsigned		arg;
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
	if (arg == 0)
		return (ft_puthexa_0(s, arg));
	ptr.nb = ft_strhlen((unsigned)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	ptr.val = ft_size_chain_hexa(s, ptr.nb, ptr.diff, arg);
	ft_puthexa(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
