/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_oct2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:31:54 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 17:31:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_nbr_octal_len_maj(unsigned long long nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 8;
		i++;
	}
	return (i);
}

int		ft_nbr_octal_len(size_t nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 8;
		i++;
	}
	return (i);
}

void	ft_putoctal(unsigned n)
{
	unsigned nb;

	nb = n;
	if (nb <= 7)
		ft_putchar(nb + 48);
	if (nb > 7)
	{
		ft_putoctal(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int		ft_size_chain_oct_plus(char *s, int t_arg, int diff)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	if (!ft_check_less(s))
		return (0);
	if (siz.nbr_prec)
		siz.len = siz.nbr - siz.nbr_prec - diff;
	else
		siz.len = siz.nbr - t_arg - diff;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.i++;
		siz.val++;
	}
	return (siz.val);
}
