/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_hexa_maj.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 17:46:13 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 18:13:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_size_chain_hexa_maj_bis2(t_siz *siz, char *arg, int t_arg, int diff)
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

int	ft_size_chain_hexa_maj_bis(t_siz *siz, char *arg, int t_arg, int diff)
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

void	ft_size_chain_hexa_maj_bis1(t_siz *siz, char *s, ssize_t arg)
{
	if (ft_check_zero(s) == 1)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	while (siz->i < siz->len)
	{
		ft_putchar(siz->d);
		siz->i++;
		siz->val++;
	}
	if (ft_check_dieses(s) && arg != 0 && (siz->nbr > siz->nbr_prec)
	&& !siz->flag && siz->nbr_prec)
	{
		ft_putstr("0X");
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

int	ft_size_chain_hexa_maj(char *s, int t_arg, int diff, ssize_t arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (ft_check_dieses(s) == 1 && arg != 0 && ((!(siz.nbr > siz.nbr_prec)) ||
	(ft_check_zero(s) && siz.nbr && (!siz.nbr_prec))))
	{
		ft_putstr("0X");
		siz.flag = 1;
		siz.val = siz.val + 2;
	}
	if (ft_check_less(s) && siz.nbr_prec <= t_arg && arg != 0)
	{
		if (ft_check_dieses(s) && !siz.flag)
		{
			ft_putstr("0X");
			siz.val = siz.val + 2;
		}
		return (0);
	}
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_hexa_maj_bis2(&siz, s, t_arg, diff);
	ft_size_chain_hexa_maj_bis(&siz, s, t_arg, diff);
	ft_size_chain_hexa_maj_bis1(&siz, s, arg);
	if (!siz.flag && ft_check_dieses(s) && arg != 0)
	{
		ft_putstr("0X");
		siz.val = siz.val + 2;
	}
	return (siz.val);
}

int	ft_size_chain_hexa_plus_maj(char *s, int t_arg, int diff)
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
