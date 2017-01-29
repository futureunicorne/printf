/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_oct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:02:24 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/29 10:59:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_oct_bis(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_zero(s) == 1)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	if (!siz->nbr_prec && siz->nbr)
		siz->len = siz->nbr - t_arg - diff;
	else if (!siz->nbr && siz->nbr_prec)
	{
		if (ft_check_dieses(s))
			siz->len = siz->nbr_prec - t_arg - diff;
		else
			siz->len = siz->nbr_prec - t_arg;
		siz->d = '0';
	}
	else if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr == siz->nbr_prec)
			siz->len = siz->nbr - t_arg;
		else if (siz->nbr < siz->nbr_prec)
			siz->len = siz->nbr_prec - t_arg;
		if (ft_check_dieses(s))
		{
			siz->len = siz->nbr_prec - t_arg - diff;
			siz->ecart =  siz->nbr - siz->nbr_prec;
		}
		else
			siz->ecart =  siz->nbr - siz->nbr_prec -  diff;
		siz->d = '0';
		siz->e = ' ';
	}
	if (siz->ecart && (!siz->len))
		siz->len = siz->ecart;
	return (0);
}

int	ft_size_chain_oct(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	siz.d = '0';
	if (ft_check_dieses(s) == 1 &&
	((!(siz.nbr > siz.nbr_prec)) || (ft_check_zero(s) && siz.nbr && (!siz.nbr_prec))))
	{
		ft_putchar('0');
		siz.flag = 1;
	}
	if (ft_check_less(s))
	{
		if (ft_check_dieses(s) && !siz.flag)
			ft_putchar('0');
		return (0);
	}
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_oct_bis(&siz, s, t_arg, diff);
	while (siz.i < siz.len)
	{
		if (siz.i < siz.ecart)
		{
			ft_putchar(siz.e);
			siz.val++;
		}
		else if (siz.i >= siz.ecart)
		{
			if (ft_check_dieses(s) && (siz.nbr > siz.nbr_prec)
			&& !siz.flag && siz.nbr_prec)
			{
				ft_putchar('0');
				siz.flag = 1;
			}
			siz .val++;
			ft_putchar(siz.d);
		}
		siz.i++;
	}
	if (!siz.flag && ft_check_dieses(s))
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
