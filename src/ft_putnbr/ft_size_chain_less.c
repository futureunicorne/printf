/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_less.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:59:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/07 10:20:39 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_size_chain_nbr_less_bis(t_siz *siz, char *arg, int t_arg, int diff)
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

int		ft_size_chain_nbr_less_bis1(t_siz *siz, char *arg, int t_arg, int diff)
{
	siz->ecart = siz->nbr_prec - t_arg;
	if (siz->nbr && siz->nbr_prec)
	{
		if (siz->nbr > siz->nbr_prec)
		{
			siz->len = siz->nbr - t_arg - diff;
			if (siz->nbr_prec < t_arg)
				siz->len = siz->nbr - t_arg - diff;
			if (siz->nbr_prec > t_arg)
				siz->len = siz->nbr - siz->nbr_prec - diff;
		}
		else if (siz->nbr < siz->nbr_prec)
		{
			if (t_arg > siz->nbr)
				siz->len = siz->nbr - t_arg - diff;
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

void	ft_size_chain_nbr_less_bis2(t_siz *siz, char *s, ssize_t arg)
{
	if (ft_check_zero(s) == 1 && siz->ecart <= 0)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	while (siz->i < siz->len)
	{
		ft_putchar(siz->d);
		siz->i++;
		siz->val++;
	}
	if (!siz->flag && (!ft_putplus_nbr_bis(s, arg))
	&& siz->nbr_prec < siz->nbr && siz->nbr_prec)
	{
		ft_putchar('-');
		siz->val++;
		siz->flag = 1;
	}
	siz->i = 0;
	while (siz->i < siz->ecart)
	{
		ft_putchar('0');
		siz->i++;
		siz->val++;
	}
}

int		ft_size_chain_nbr_less_bis0(t_siz *siz, char *s, int t_arg, ssize_t arg)
{
	if ((!ft_check_point(s)) && !ft_putplus_nbr_bis(s, arg)
	&& (t_arg > siz->nbr || ft_check_zero(s)))
	{
		ft_putchar('-');
		siz->val++;
		siz->flag = 1;
	}
	if (siz->nbr_prec
	&& (siz->nbr_prec > siz->nbr || siz->nbr_prec == siz->nbr))
	{
		ft_putchar('-');
		siz->val++;
		siz->flag = 1;
	}
	if (ft_check_less(s) &&
	((siz->nbr_prec <= t_arg && arg != 0) || (siz->nbr && !ft_check_point(s))))
	{
		if (siz->flag == 0)
		{
			ft_putchar('-');
			siz->val++;
		}
		return (1);
	}
	return (0);
}

int		ft_size_chain_nbr_less(char *s, int t_arg, int diff, ssize_t arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	siz.res = ft_size_chain_nbr_less_bis0(&siz, s, t_arg, arg);
	if (siz.res)
		return (siz.val);
	if (ft_check_less(s) && siz.nbr_prec > t_arg && siz.nbr > siz.nbr_prec)
		siz.nbr = 0;
	ft_size_chain_nbr_less_bis(&siz, s, t_arg, diff);
	ft_size_chain_nbr_less_bis1(&siz, s, t_arg, diff);
	ft_size_chain_nbr_less_bis2(&siz, s, arg);
	if (!siz.flag && (!ft_putplus_nbr_bis(s, arg)))
	{
		ft_putchar('-');
		siz.val++;
		siz.flag = 1;
	}
	return (siz.val);
}
