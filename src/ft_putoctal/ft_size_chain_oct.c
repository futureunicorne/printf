/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_oct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:02:24 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:38:44 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_oct(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;
	int flag;
	char d;

	nbr = ft_record_chain(s);
	i = 0;
	flag = 0;
	if ((ft_check_less(s) == 1 || ft_check_zero(s, nbr) == 1) && ft_check_dieses(s) == 1)
	{
		ft_putstr("0");
		flag = 1;
	}
	if (ft_check_less(s) == 1)
		return (0);
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_less(s) == 1)
		return (0);
	if (ft_check_zero(s, nbr) == 1)
	{
		len = len;
		d = '0';
	}
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	if (flag == 0 && ft_check_dieses(s) == 1)
	{
		ft_putstr("0");
	}
	return (i);
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
