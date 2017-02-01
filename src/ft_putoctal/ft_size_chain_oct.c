/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_oct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:55:12 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 10:07:16 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_size_chain_oct_bis(t_siz *siz, char *arg, int t_arg, int diff)
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

int	ft_size_chain_oct_bis1(t_siz *siz, char *arg, int t_arg, int diff)
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

void	ft_size_chain_oct_bis2(t_siz *siz, char *s)
{
	while (siz->i < siz->len)
	{
		ft_putchar(' ');
		siz->i++;
	}
	if (ft_check_dieses(s) && (siz->nbr > siz->nbr_prec)
	&& !siz->flag && siz->nbr_prec)
	{
		ft_putchar('0');
		siz->flag = 1;
	}
	siz->i = 0;
	while (siz->i < siz->ecart)
	{
		ft_putchar('0');
		siz->i++;
	}
}

int	ft_size_chain_oct(char *s, int t_arg, int diff, int arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_dieses(s) == 1 && arg != 0 && ((!(siz.nbr > siz.nbr_prec)) ||
	(ft_check_zero(s) && siz.nbr && (!siz.nbr_prec))))
	{
		ft_putchar('0');
		siz.flag = 1;
	}
	if (ft_check_less(s) && siz.nbr_prec <= t_arg)
	{
		if (ft_check_dieses(s) && !siz.flag && arg != 0)
			ft_putchar('0');
		return (0);
	}
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_oct_bis(&siz, s, t_arg, diff);
	ft_size_chain_oct_bis1(&siz, s, t_arg, diff);
	ft_size_chain_oct_bis2(&siz, s);
	if (!siz.flag && ft_check_dieses(s) && arg != 0)
	{
		ft_putchar('0');
		siz.val++;
	}
	return (siz.i);
}

int	ft_size_chain_oct_plus(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;

	if (ft_check_less(s) == 0)
		return (0);
	nbr = ft_record_chain(s);
	i = 0;

	len = nbr - t_arg - diff;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
