/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:59:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/25 18:10:02 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


int	ft_size_chain_nbr_bis(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_space(s) == 1 && siz->nbr && ft_check_more(s) == 0
	&& siz->nbr < siz->nbr_prec)
		ft_putchar(' ');
	if (ft_check_more(s) == 1 && ft_check_point(s) == 0 && siz->flag_plus == 1
	&& (t_arg > siz->nbr || ft_check_zero(s, siz->nbr) == 1 || ft_check_less(s) == 1))
	{
		ft_putchar('+');
		siz->flag = 1;
	}
	if (ft_check_less(s) == 1 && ft_check_point(s) == 0)
		return (0);
	if (ft_check_zero(s, siz->nbr) == 1)
		siz->d = '0';
	if (ft_check_zero(s, siz->nbr) == 0)
		siz->d = ' ';
	if (!siz->nbr_prec)
		siz->len = siz->nbr - t_arg - diff;
	else if (!siz->nbr)
		siz->len = siz->nbr_prec - t_arg;
	else if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr > siz->nbr_prec)
			siz->len = siz->nbr - t_arg - diff;
		else if (siz->nbr < siz->nbr_prec)
			siz->len = siz->nbr_prec - t_arg;
		siz->ecart =  siz->nbr - siz->nbr_prec -  diff;
		siz->d = '0';
	}
	return (0);
}

int		ft_size_chain_nbr(char *s, int t_arg, int diff, int arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec =  ft_record_prec(s);
	ft_size_chain_nbr_bis(&siz, s, t_arg, diff);
	if (ft_check_space(s) == 1 && !ft_check_more(s))
		ft_putchar(' ');
	if (ft_putplus_nbr(s, arg) == 1)
		siz.flag_plus = 1;
	while (siz.i < siz.ecart)
	{
		ft_putchar(' ');
		siz.i++;
	}
	if (siz.flag == 0 && ft_check_more(s) == 1 && ft_check_point(s) == 1
	&& siz.flag_plus == 1)
	{
		ft_putchar('+');
		siz.flag = 1;
	}
	while (siz.i < siz.len)
	{
		ft_putchar(siz.d);
		siz.i++;
	}
	if (siz.flag == 0 && ft_check_more(s) == 1 && siz.flag_plus == 1)
	{
		ft_putchar('+');
		siz.flag = 1;
	}
	return (siz.i);
}


int	ft_size_chain_nbr_plus(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;

	if (ft_check_less(s) == 0 || ft_check_point(s) == 1)
		return (0);
	nbr = ft_record_chain(s);
	i = 0;
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_space(s) == 1 && nbr && ft_check_more(s) == 0)
		len -= 1;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
