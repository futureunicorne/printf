/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/07 11:17:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_j2(char *s, intmax_t arg, t_ptr *ptr)
{
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr->nb = ft_count_num_2(arg);
		ptr->val = ft_size_chain_nbr_less(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_max(arg);
		ptr->val += ft_size_chain_nbr_plus_bis(s, ptr->nb, ptr->diff);
	}
	else
	{
		ptr->nb = ft_count_num(arg);
		ptr->val = ft_size_chain_nbr(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_max(arg);
		ptr->val += ft_size_chain_nbr_plus(s, ptr->nb, ptr->diff);
	}
}

int		ft_putnbr_j(char *s, va_list *p)
{
	intmax_t	arg;
	t_ptr		ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, intmax_t);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	ft_putnbr_j2(s, arg, &ptr);
	return (ptr.val + ptr.nb);
}

int		ft_putnbr_z(char *s, va_list *p)
{
	ssize_t	arg;
	t_ptr	ptr;

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
	return (ptr.val + ptr.nb);
}

int		ft_putnbr_hh(char *s, va_list *p)
{
	signed char	arg;
	t_ptr		ptr;

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
	return (ptr.val + ptr.nb);
}
