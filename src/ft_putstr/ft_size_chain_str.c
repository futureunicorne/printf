/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:05:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:38:13 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_str_plus(char *s, int t_arg, int diff)
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

int	ft_size_chain_str(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;
	char d;


	if (ft_check_less(s) == 1)
		return (0);

	nbr = ft_record_chain(s);
	i = 0;
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_zero(s, nbr) == 1)
		d = '0';
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	return (i);
}