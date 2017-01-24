/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_nbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:59:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:38:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_nbr(char *s, int t_arg, int diff)
{
	int nbr;
	int nbr_prec;
	int i;
	int len;
	int flag;
	int ecart;
	char d;

	nbr = ft_record_chain(s);
	nbr_prec =  ft_record_prec(s);
	flag  = 0;
	i = 0;
	if (ft_check_space(s) == 1 && nbr && ft_check_more(s) == 0 && ft_check_less(s) == 1)
		ft_putchar(' ');
	if ((ft_check_less(s) == 1 || ft_check_zero(s, nbr) == 1) && ft_check_more(s) == 1)
	{
		ft_putchar('+');
		flag = 1;
	}
	if (ft_check_less(s) == 1)
		return (0);
	if (ft_check_zero(s, nbr) == 1)
		d = '0';
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	if (!nbr_prec)
		len = nbr - t_arg - diff;
	else if (!nbr)
		len = nbr_prec - t_arg - diff;
	else if (nbr && nbr_prec)
	{
		len = nbr - t_arg - diff;
		ecart =  nbr - nbr_prec;
		d = '0';
	}
	while (i < len)
	{
		if (i < ecart)
			ft_putchar(' ');
		else
			ft_putchar(d);
		i++;
	}
	if (flag == 0 && ft_check_more(s) == 1)
		ft_putchar('+');
	return (i);
}


int	ft_size_chain_nbr_plus(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;

	if (ft_check_less(s) == 0)
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
