/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_bin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 23:56:46 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 15:32:21 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_bin_bis(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_zero(s) == 1)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	if (!siz->nbr_prec && siz->nbr)
		siz->len = siz->nbr - t_arg - diff;
	else if (!siz->nbr && siz->nbr_prec)
	{
		siz->len = siz->nbr_prec - t_arg;
		siz->d = '0';
	}
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
	if (siz->ecart && (!siz->len))
		siz->len = siz->ecart;
	return (0);
}

int	ft_size_chain_bin(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_less(s) && siz.nbr_prec <= t_arg)
		return (siz.val);
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_bin_bis(&siz, s, t_arg, diff);
	while (siz.i < siz.len)
	{
		if (siz.i < siz.ecart)
		{
			ft_putchar(siz.e);
			siz.val++;
		}
		else if (siz.i >= siz.ecart)
		{
			siz .val++;
			ft_putchar(siz.d);
		}
		siz.i++;
	}
	return (siz.val);
}

int	ft_size_chain_bin_plus(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_less(s) == 0)
		return (siz.val);
	siz.len = siz.nbr - t_arg - diff;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}
