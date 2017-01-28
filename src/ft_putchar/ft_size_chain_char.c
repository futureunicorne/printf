/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:51:10 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/28 19:13:45 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_char(char *s, int t_arg, int diff)
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
	if (ft_check_zero(s) == 1)
		d = '0';
	if (ft_check_zero(s) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	return (i);
}

int	ft_size_chain_char_plus(char *s, int t_arg, int diff)
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
