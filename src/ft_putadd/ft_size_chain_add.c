/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_add.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:33:46 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 20:39:01 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_size_chain_add_plus(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_less(s) == 0 || siz.nbr_prec > t_arg)
		return (0);
	siz.i = 0;
	siz.len = siz.nbr - t_arg - diff - 2;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}

void	ft_size_chain_add_bis1(t_siz *siz, char *arg, int t_arg, int diff)
{
	if (!siz->nbr && siz->nbr_prec)
	{
		siz->len = 0;
		if (siz->nbr_prec > t_arg)
			siz->ecart = siz->nbr_prec - t_arg;
	}
	else if (!siz->nbr_prec && siz->nbr)
	{
		siz->len = siz->nbr - t_arg -2;
		siz->ecart = 0;
	}
}

int		ft_size_chain_add_bis(t_siz *siz, char *arg, int t_arg, int diff)
{
	siz->ecart = siz->nbr_prec - t_arg;
	if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr > siz->nbr_prec)
		{
			siz->len = siz->nbr - t_arg;
			if (siz->nbr_prec < t_arg)
				siz->len = siz->nbr - t_arg - 2;
			if (siz->nbr_prec > t_arg)
				siz->len = siz->nbr - siz->nbr_prec - 2;
		}
		else if (siz->nbr < siz->nbr_prec)
		{
			if (t_arg > siz->nbr)
				siz->len = siz->nbr - t_arg;
			if (t_arg < siz->nbr)
				siz->len = 0;
		}
		else if (siz->nbr == siz->nbr_prec)
		{
			if (siz->nbr > t_arg || siz->nbr_prec > t_arg)
				siz->len = 0;
		}
	}
	return (0);
}
void	ft_size_chain_add_bis2(t_siz *siz)
{
	while (siz->i < siz->len)
	{
		ft_putchar(' ');
		siz->i++;
		siz->val++;
	}
	if (!siz->flag)
	{
		ft_putstr("0x");
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
int		ft_size_chain_add(char *s, int t_arg, int diff)
{
	t_siz	siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_space(s) && (siz.nbr <= t_arg || siz.nbr_prec > t_arg))
	{
		ft_putchar(' ');
		siz.val++;
	}
	if (siz.nbr <= t_arg && siz.nbr_prec <= t_arg)
	{
		ft_putstr("0x");
		siz.flag = 1;
		siz.val = siz.val + 2;
	}
	if (ft_check_less(s) && siz.nbr_prec <= t_arg)
	{
		if (!siz.flag)
		{
			ft_putstr("0x");
			siz.val = siz.val + 2;
		}
		return (siz.val);
	}
	ft_size_chain_add_bis1(&siz, s, t_arg, diff);
	ft_size_chain_add_bis(&siz, s, t_arg, diff);
	ft_size_chain_add_bis2(&siz);
	return (siz.val);
}
