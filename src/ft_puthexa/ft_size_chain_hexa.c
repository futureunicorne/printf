/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:56:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 11:29:37 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_size_chain_hexa_bis2(t_siz *siz, char *arg, int t_arg, int diff)
{
	if (!siz->nbr && siz->nbr_prec)
	{
		siz->len = 0;
		if (siz->nbr_prec > t_arg)
			siz->ecart = siz->nbr_prec - t_arg;
	}
	else if (!siz->nbr_prec && siz->nbr)
	{
		siz->len = siz->nbr - t_arg - diff;
		siz->ecart = 0;
	}
}

int	ft_size_chain_hexa_bis(t_siz *siz, char *arg, int t_arg, int diff)
{
	siz->ecart =  siz->nbr_prec - t_arg;
	if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr > siz->nbr_prec)
		{
			siz->len = siz->nbr - t_arg - diff;
			if (siz->nbr_prec < t_arg)
				siz->len = siz->nbr - t_arg - diff;
			if (siz->nbr_prec > t_arg)
				siz->len = siz->nbr - siz->nbr_prec- diff;
		}
		else if (siz->nbr < siz->nbr_prec)
		{
			if (t_arg > siz->nbr)
				siz->len = siz->nbr - t_arg - diff;
			if (t_arg < siz->nbr)
				siz->len =  0;
			}
		else if (siz->nbr == siz->nbr_prec)
		{
			if (siz->nbr > t_arg || siz->nbr_prec > t_arg)
				siz->len = 0;
		}
	}
	return (0);
}

void	ft_size_chain_hexa_bis1(t_siz *siz, char *s, char *base)
{
	while (siz->i < siz->len)
	{
		ft_putchar(' ');
		siz->i++;
		siz->val++;
	}
	if (ft_check_dieses(s) && (siz->nbr > siz->nbr_prec)
	&& !siz->flag && siz->nbr_prec)
	{
		ft_putstr(base);
		siz->flag = 1;
		siz->val = siz->val + 2;
	}
	siz->i = 0;
	while (siz->i < siz->ecart)
	{
		ft_putchar('0');
		siz->i++;
		siz->val++;
	}
}

int	ft_size_chain_hexa(char *s, int t_arg, int diff, char *base)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_dieses(s) == 1 && ((!(siz.nbr > siz.nbr_prec)) ||
	(ft_check_zero(s) && siz.nbr && (!siz.nbr_prec))))
	{
		ft_putstr(base);
		siz.flag = 1;
		siz.val = siz.val + 2;
	}
	if (ft_check_less(s) && siz.nbr_prec <= t_arg)
	{
		if (ft_check_dieses(s) && !siz.flag)
		{
			ft_putstr(base);
			siz.val = siz.val + 2;
		}
		return (0);
	}
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_hexa_bis2(&siz, s, t_arg, diff);
	ft_size_chain_hexa_bis(&siz, s, t_arg, diff);
	ft_size_chain_hexa_bis1(&siz, s, base);
	if (!siz.flag && ft_check_dieses(s))
	{
		ft_putstr(base);
		siz.val = siz.val + 2;
	}
	return (siz.val);
}

int	ft_size_chain_hexa_plus(char *s, int t_arg, int diff)
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
