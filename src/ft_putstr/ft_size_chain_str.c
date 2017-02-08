/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:05:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 16:55:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_size_chain_str_bis1(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_zero(s) == 1)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	if (!siz->nbr && siz->nbr_prec)
	{
		siz->len = 0;
		if (siz->nbr_prec < t_arg)
			siz->ecart = siz->nbr_prec;
	}
	else if (!siz->nbr_prec && siz->nbr)
	{
		siz->len = siz->nbr - t_arg;
		if (ft_check_point(s))
			siz->len = siz->nbr;
		siz->ecart = 0;
	}
}

int		ft_size_chain_str_bis(t_siz *siz, char *arg, int t_arg, int diff)
{
	if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr > siz->nbr_prec)
		{
			siz->len = siz->nbr - (ft_strlen(arg));
			siz->ecart = siz->nbr_prec;
			if (siz->nbr_prec <= t_arg)
				siz->len = siz->nbr - siz->nbr_prec;
		}
		else if (siz->nbr < siz->nbr_prec)
		{
			siz->ecart = siz->nbr_prec;
			if (t_arg >= siz->nbr)
				siz->len = 0;
			if (t_arg < siz->nbr)
				siz->len = siz->nbr - t_arg;
		}
	}
	return (0);
}

void	ft_size_chain_str_bis2(t_siz *siz, char *arg, int t_arg, int diff)
{
	if (siz->nbr == siz->nbr_prec)
	{
		siz->ecart = siz->nbr_prec;
		if (siz->nbr_prec > t_arg)
			siz->len = siz->nbr - t_arg;
		if (siz->nbr <= t_arg)
			siz->len = 0;
	}
}

int		ft_size_chain_str(char *s, int t_arg, int diff, char *arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	siz.d = ' ';
	if (ft_check_less(s))
		return (0);
	ft_size_chain_str_bis1(&siz, s, t_arg, diff);
	ft_size_chain_str_bis(&siz, arg, t_arg, diff);
	ft_size_chain_str_bis2(&siz, arg, t_arg, diff);
	while (siz.i < siz.len)
	{
		ft_putchar(siz.d);
		siz.i++;
		siz.val++;
	}
	if (ft_check_point(s) && arg != NULL && siz.ecart)
		siz.val = siz.val + ft_putnstr(arg, siz.ecart);
	else if (ft_check_point(s) && arg != NULL && !siz.nbr_prec && arg[0] != '%')
		return (siz.val);
	else
		siz.val = siz.val + ft_putstr1(arg);
	return (siz.val);
}

int		ft_size_chain_str_plus(char *s, int t_arg, int diff, char *arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	siz.d = ' ';
	if (!ft_check_less(s))
		return (0);
	ft_size_chain_str_bis1(&siz, arg, t_arg, diff);
	ft_size_chain_str_bis(&siz, arg, t_arg, diff);
	if (ft_check_point(s))
		siz.val = siz.val + ft_putnstr(arg, siz.ecart);
	else
		siz.val = siz.val + ft_putstr(arg);
	while (siz.i < siz.len)
	{
		ft_putchar(siz.d);
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}
