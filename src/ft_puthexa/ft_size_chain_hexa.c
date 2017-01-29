/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:56:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/29 10:30:02 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_hexa_bis(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_zero(s) == 1)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	if (!siz->nbr_prec && siz->nbr)
	{
		siz->len = siz->nbr - t_arg - diff;
	}
	else if (!siz->nbr && siz->nbr_prec)
		siz->len = siz->nbr_prec - t_arg;
	else if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr == siz->nbr_prec)
			siz->len = siz->nbr - t_arg;
		else if (siz->nbr < siz->nbr_prec)
			siz->len = siz->nbr_prec - t_arg;
		siz->ecart =  siz->nbr - siz->nbr_prec -  diff;
		siz->d = '0';
		siz->e = ' ';
	}
	return (0);
}

int	ft_size_chain_hexa(char *s, int t_arg, int diff, char *base)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	siz.d = '0';
	if (ft_check_dieses(s) == 1 &&
	((!(siz.nbr > siz.nbr_prec)) || (ft_check_zero(s) && siz.nbr && (!siz.nbr_prec))))
	{
		ft_putstr(base);
		siz.flag = 1;
	}
	if (ft_check_less(s) && !ft_check_point(s))
	{
		if (ft_check_dieses(s) && !siz.flag)
			ft_putstr(base);
		return (0);
	}
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_hexa_bis(&siz, s, t_arg, diff);
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
				ft_putstr(base);
				siz.flag = 1;
			}
			siz .val++;
			ft_putchar(siz.d);
		}
		siz.i++;
	}
	if (!siz.flag && ft_check_dieses(s))
	{
		ft_putstr(base);
		siz.val++;
	}
	return (siz.i);
}

int	ft_size_chain_hexa_plus(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;

	if (ft_check_less(s) == 0 || ft_check_point(s))
		return (0);

	nbr = ft_record_chain(s);
	i = 0;
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
