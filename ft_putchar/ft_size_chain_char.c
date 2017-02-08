/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:51:10 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 20:30:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_char(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	if (ft_check_less(s) == 1)
		return (0);
	siz.d = ' ';
	if (ft_check_zero(s) == 1)
		siz.d = '0';
	if (ft_check_zero(s) == 0)
		siz.d = ' ';
	siz.nbr = ft_record_chain(s);
	siz.i = 0;
	siz.len = siz.nbr - t_arg - diff;
	while (siz.i < siz.len)
	{
		ft_putchar(siz.d);
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}

int	ft_size_chain_char_plus(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	if (ft_check_less(s) == 0)
		return (0);
	siz.nbr = ft_record_chain(s);
	siz.len = siz.nbr - t_arg - diff;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}
