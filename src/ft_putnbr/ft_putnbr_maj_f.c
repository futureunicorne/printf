/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/05 23:16:57 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_ll(char *s, va_list *p)
{
	ssize_t arg;
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, int long long);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		if (arg < -9223372036854775807)
			ptr.nb = ft_count_num(arg);
		else
			ptr.nb = ft_count_num_2(arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_long2(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num(arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_long2(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_maj_f(char *s, va_list *p)
{
	ssize_t arg;
	t_ptr ptr;

	if (ft_check_letter(s, 'l'))
	{
		ptr.val = ft_putnbr_ll(s, p);
		return (ptr.val);
	}
	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, long);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.nb = ft_count_num_2(arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_long(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num(arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_long(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_j(char *s, va_list *p)
{
	intmax_t arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, intmax_t);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		if (arg < -9223372036854775807)
			ptr.nb = ft_count_num(arg);
		else
			ptr.nb = ft_count_num_2(arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_max(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num(arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_max(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_z(char *s, va_list *p)
{
	ssize_t arg;
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, size_t);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.nb = ft_count_num_2(arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_size(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num(arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_size(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_hh(char *s, va_list *p)
{
	signed char arg;
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, signed);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.nb = ft_count_num_2((signed char)arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short2(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num((signed char)arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short2(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_h(char *s, va_list *p)
{
	int short arg;
	t_ptr ptr;

	if (ft_check_letter(s, 'h'))
	{
		ptr.val = ft_putnbr_hh(s, p);
		return (ptr.val);
	}
	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, int);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.nb = ft_count_num_2((int short)arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num((int short)arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_0(char *s, int arg)
{
	t_ptr ptr;
	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.nb = 1;
	ptr.diff = ft_nbr_size(s, arg);
	if (ft_record_chain(s) || ft_record_prec(s))
	{
		ptr.diff = ptr.diff - 1;
		ptr.flag = 1;
	}
	ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
	if ((ptr.flag && ft_record_prec(s)) || ft_check_more(s))
	{
		ft_putchar('0');
		ptr.val++;
	}
	ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	return (ptr.val);
}

int	ft_putnbr_f(char *s, va_list *p)
{
	int		arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_long(s))
	{
		if (ft_check_long(s) == 'l')
			ptr.val = ft_putnbr_maj_f(s, p);
		else if (ft_check_long(s) == 'h')
			ptr.val = ft_putnbr_h(s, p);
		else if (ft_check_long(s) == 'j')
			ptr.val = ft_putnbr_j(s, p);
		else if (ft_check_long(s) == 'z')
			ptr.val = ft_putnbr_z(s, p);
		return (ptr.val);
	}
	arg = va_arg(*p, int);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.diff++;
		ptr.nb = ft_count_num_2((int)arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr1(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num((int)arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr1(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}
