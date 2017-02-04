/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:35:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 18:02:02 by hel-hadi         ###   ########.fr       */
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
	ptr.nb = ft_nbr_octal_len(arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	if (arg == 0)
	{
		ptr.diff = 0;
		ptr.nb = 1;
	}
	ptr.val =  ptr.val  + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_size(arg);
	ptr.val =  ptr.val  + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_hh(char *s, va_list *p)
{
 	unsigned			arg;
	t_ptr				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned);
	ptr.nb = ft_nbr_octal_len((unsigned char)arg);
	if (arg == 65535)
		ptr.nb = 6;
	ptr.diff = ft_oct_size(s, ptr.check_type);
	if (arg == 0)
	{
		ptr.diff = 0;
		ptr.nb = 1;
	}
	ptr.val =  ptr.val  + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_short2(arg);
	ptr.val =  ptr.val  + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_h(char *s, va_list *p)
{
 	unsigned 			arg;
	t_ptr				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_letter(s, 'h'))
	{
		ptr.val = ft_putoctal_hh(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, int);
	ptr.nb = ft_nbr_octal_len((unsigned short)arg);
	if (arg == 65535)
		ptr.nb = 6;
	ptr.diff = ft_oct_size(s, ptr.check_type);
	if (arg == 0)
	{
		ptr.diff = 0;
		ptr.nb = 1;
	}
	ptr.val =  ptr.val  + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_short(arg);
	ptr.val =  ptr.val  + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int	ft_putoctal_l(char *s, va_list *p)
{
	unsigned long long	arg;
	t_ptr				ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, unsigned long long);
	ptr.nb = ft_nbr_octal_len(arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	if (arg == 0)
	{
		ptr.diff = 0;
		ptr.nb = 1;
	}
	ptr.val = ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	ft_putoctal_long(arg);
	ptr.val =  ptr.val  + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);

	return (ptr.val + ptr.nb);
}

int	ft_putoctal_f(char *s, va_list *p)
{
	unsigned 	arg;
	t_ptr 		ptr;

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
	arg = va_arg(*p, int long);
	ptr.nb = ft_nbr_octal_len(arg);
	ptr.diff = ft_oct_size(s, ptr.check_type);
	if (arg == 0)
	{
		if (!ft_check_point(s))
		{
			ptr.nb = 0;
			ptr.flag = 1;
		}
		if (ptr.diff)
			ptr.diff = ptr.diff -1;
	}
	ptr.val =  ptr.val  + ft_size_chain_oct(s, ptr.nb, ptr.diff, arg);
	if (ptr.flag == 0)
		ft_putoctal(arg);
	ptr.val =  ptr.val  + ft_size_chain_oct_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
