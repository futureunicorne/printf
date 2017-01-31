/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:51:10 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/31 00:24:00 by hel-hadi         ###   ########.fr       */
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
	d = ' ';
	nbr = ft_record_chain(s);
	i = 0;
	len = nbr - t_arg - diff;
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
	len = nbr - t_arg - diff;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
