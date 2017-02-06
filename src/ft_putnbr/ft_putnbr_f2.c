/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_f2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:23:39 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 18:56:10 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_ll2(char *s, int long long arg, t_ptr *ptr)
{
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr->nb = ft_count_num_2(arg);
		ptr->val = ft_size_chain_nbr_less(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_long2(arg);
		ptr->val += ft_size_chain_nbr_plus_bis(s, ptr->nb, ptr->diff);
	}
	else
	{
		ptr->nb = ft_count_num(arg);
		ptr->val = ft_size_chain_nbr(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_long2(arg);
		ptr->val += ft_size_chain_nbr_plus(s, ptr->nb, ptr->diff);
	}
}

int		ft_putnbr_ll(char *s, va_list *p)
{
	ssize_t	arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, int long long);
	if (arg == 0 && ft_check_point(s))
		return (ft_putnbr_0(s, arg));
	ptr.diff = ft_nbr_size(s, arg);
	ft_putnbr_ll2(s, arg, &ptr);
	return (ptr.val + ptr.nb);
}

void	ft_putnbr_maj_f2(char *s, int long arg, t_ptr *ptr)
{
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr->nb = ft_count_num_2(arg);
		ptr->val = ft_size_chain_nbr_less(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_long(arg);
		ptr->val += ft_size_chain_nbr_plus_bis(s, ptr->nb, ptr->diff);
	}
	else
	{
		ptr->nb = ft_count_num(arg);
		ptr->val = ft_size_chain_nbr(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_long(arg);
		ptr->val += ft_size_chain_nbr_plus(s, ptr->nb, ptr->diff);
	}
}

int		ft_putnbr_maj_f(char *s, va_list *p)
{
	ssize_t	arg;
	t_ptr	ptr;

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
	ft_putnbr_maj_f2(s, arg, &ptr);
	return (ptr.val + ptr.nb);
}
