/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/02 18:09:51 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr_ll(char *s, va_list *p)
{
	ssize_t arg;
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, long long);
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
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

	if (ft_check_letter(s))
	{
		ptr.val = ft_putnbr_ll(s, p);
		return (ptr.val);
	}
	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, long);
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
	ssize_t arg;
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, intmax_t);
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
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
	arg = va_arg(*p, ssize_t);
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.nb = ft_count_num_2(arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short2(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num(arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short2(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_h(char *s, va_list *p)
{
	short arg;
	t_ptr ptr;

	if (ft_check_letter(s))
	{
		ptr.val = ft_putnbr_hh(s, p);
		return (ptr.val);
	}
	printf("oui\n");
	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, signed);
	ptr.diff = ft_nbr_size(s, arg);
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.nb = ft_count_num_2(arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num(arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr_short(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}

int	ft_putnbr_f(char *s, va_list *p)
{
	ssize_t arg;
	t_ptr ptr;

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
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr.nb = ft_count_num_2(arg);
		ptr.val = ft_size_chain_nbr_less(s, ptr.nb, ptr.diff, arg);
		ft_putnbr1(arg);
		ptr.val += ft_size_chain_nbr_plus_bis(s, ptr.nb, ptr.diff);
	}
	else
	{
		ptr.nb = ft_count_num(arg);
		ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
		ft_putnbr1(arg);
		ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	}
	ptr.val += ptr.nb;
	return (ptr.val);
}
