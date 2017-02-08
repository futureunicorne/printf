/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 18:07:52 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/08 11:46:35 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr_h2(char *s, int short arg, t_ptr *ptr)
{
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr->nb = ft_count_num_2((int short)arg);
		ptr->val = ft_size_chain_nbr_less(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_short(arg);
		ptr->val += ft_size_chain_nbr_plus_bis(s, ptr->nb, ptr->diff);
	}
	else
	{
		ptr->nb = ft_count_num((int short)arg);
		ptr->val = ft_size_chain_nbr(s, ptr->nb, ptr->diff, arg);
		ft_putnbr_short(arg);
		ptr->val += ft_size_chain_nbr_plus(s, ptr->nb, ptr->diff);
	}
}

int		ft_putnbr_h(char *s, va_list *p)
{
	int short	arg;
	t_ptr		ptr;

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
	ft_putnbr_h2(s, arg, &ptr);
	return (ptr.val + ptr.nb);
}

void	ft_putnbr_f2(char *s, int arg, t_ptr *ptr)
{
	if (!ft_putplus_nbr_bis(s, arg))
	{
		ptr->diff++;
		ptr->nb = ft_count_num_2((int)arg);
		ptr->val = ft_size_chain_nbr_less(s, ptr->nb, ptr->diff, arg);
		ft_putnbr1(arg);
		ptr->val += ft_size_chain_nbr_plus_bis(s, ptr->nb, ptr->diff);
	}
	else
	{
		ptr->nb = ft_count_num((int)arg);
		ptr->val = ft_size_chain_nbr(s, ptr->nb, ptr->diff, arg);
		ft_putnbr1(arg);
		ptr->val += ft_size_chain_nbr_plus(s, ptr->nb, ptr->diff);
	}
}

int		ft_putnbr_f(char *s, va_list *p)
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
	ft_putnbr_f2(s, arg, &ptr);
	return (ptr.val + ptr.nb);
}
