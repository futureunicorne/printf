/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:35:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 17:05:44 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putoctal_z(char *s, va_list *p)
{
	size_t	arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, size_t);
	if (arg == 0)
		return (ft_putoctal_0(s, arg));
	ptr.nb = ft_nbr_octal_len(arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_size(arg);
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_hh(char *s, va_list *p)
{
	unsigned char		arg;
	t_ptr				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_letter_o(s))
	{
		ptr.val = ft_putoctal_l(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	if (arg == 0)
		return (ft_putoctal_0(s, arg));
	ptr.nb = ft_nbr_octal_len((unsigned char)arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_short2(arg);
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_h(char *s, va_list *p)
{
	unsigned short	arg;
	t_ptr			ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_letter(s, 'h'))
	{
		ptr.val = ft_putoctal_hh(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	if (arg == 0)
		return (ft_putoctal_0(s, arg));
	ptr.nb = ft_nbr_octal_len((unsigned short)arg);
	if (arg == 65535)
		ptr.nb = 6;
	ptr.diff = ft_oct_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_short(arg);
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_l(char *s, va_list *p)
{
	unsigned long long	arg;
	t_ptr				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned long long);
	if (arg == 0)
		return (ft_putoctal_0(s, arg));
	ptr.nb = ft_nbr_octal_len((unsigned long long)arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	ptr.val = ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_long(arg);
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_f(char *s, va_list *p)
{
	unsigned	arg;
	t_ptr		ptr;

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
	arg = va_arg(*p, unsigned);
	if (arg == 0)
		return (ft_putoctal_0(s, arg));
	ptr.nb = ft_nbr_octal_len((unsigned)arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal(arg);
	ptr.val = ptr.val + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
