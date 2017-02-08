/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hexa4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 19:38:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/07 23:25:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_puthexa_maj_0(char *s, int arg)
{
	t_ptr ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.nb = 1;
	ptr.diff = ft_nbr_size(s, arg);
	if (ft_check_point(s) && ft_check_point(s))
	{
		ptr.nb = 0;
		ptr.flag = 1;
	}
	ptr.val = ft_size_chain_hexa_maj(s, ptr.nb, ptr.diff, arg);
	if (!ptr.flag && !ft_check_dieses(s))
	{
		ft_putchar('0');
		ptr.val++;
	}
	ptr.val = ptr.val + ft_size_chain_hexa_plus_maj(s, ptr.nb, ptr.diff);
	if (ft_check_dieses(s) && ((ft_record_chain(s) && !ft_check_point(s))
	|| (!ft_record_chain(s) && !ft_record_prec(s))))
	{
		ft_putchar('0');
		ptr.val++;
	}
	return (ptr.val);
}

int		ft_puthexa_maj_z(char *s, va_list *p)
{
	size_t	arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, size_t);
	if (arg == 0)
		return (ft_puthexa_maj_0(s, arg));
	ptr.nb = ft_strhlen((size_t)arg);
	ptr.diff = ft_hexa_size(s, arg, ptr.check_type);
	ptr.val = ft_size_chain_hexa_maj(s, ptr.nb, ptr.diff, arg);
	ft_puthexa_size_maj(arg);
	ptr.val = ptr.val + ft_size_chain_hexa_plus_maj(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}

int		ft_size_chain_hexa_plus_maj(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_less(s) == 0 || siz.nbr_prec > t_arg)
		return (0);
	siz.i = 0;
	siz.len = siz.nbr - t_arg - diff;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}

int		ft_size_chain_hexa_plus(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_less(s) == 0 || siz.nbr_prec > t_arg)
		return (0);
	siz.i = 0;
	siz.len = siz.nbr - t_arg - diff;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}
