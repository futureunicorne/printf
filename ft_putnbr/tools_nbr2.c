/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_nbr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:18:51 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 19:25:31 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr1(int n)
{
	int long nb;

	nb = n;
	if (nb < 0)
		nb = nb * (-1);
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int		ft_putnbr_0(char *s, int arg)
{
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.nb = 1;
	ptr.diff = ft_nbr_size(s, arg);
	if (ft_record_chain(s) || ft_record_prec(s))
	{
		ptr.diff = ptr.diff - 1;
		ptr.flag = 1;
	}
	ptr.val = ft_size_chain_nbr(s, ptr.nb, ptr.diff, arg);
	if ((ptr.flag && ft_record_prec(s)) || ft_check_more(s))
	{
		ft_putchar('0');
		ptr.val++;
	}
	ptr.val += ft_size_chain_nbr_plus(s, ptr.nb, ptr.diff);
	return (ptr.val);
}

void	ft_putnbr_long2(long long n)
{
	long long nb;

	nb = n;
	if (nb < -9223372036854775807)
		ft_putstr("9223372036854775808");
	else
	{
		if (nb < 0)
			nb = nb * (-1);
		if (nb >= 0 && nb <= 9)
			ft_putchar(nb + 48);
		if (nb > 9)
		{
			ft_putnbr_long2(nb / 10);
			ft_putchar((nb % 10) + 48);
		}
	}
}

int		ft_size_chain_nbr_plus(char *s, int t_arg, int diff)
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
	if (ft_check_space(s) == 1 && siz.nbr && ft_check_more(s) == 0)
		siz.len -= 1;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.val++;
		siz.i++;
	}
	return (siz.val);
}

int		ft_size_chain_nbr_plus_bis(char *s, int t_arg, int diff)
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
	if (ft_check_space(s) == 1 && siz.nbr && ft_check_more(s) == 0)
		siz.len -= 1;
	while (siz.i < siz.len)
	{
		ft_putchar(' ');
		siz.val++;
		siz.i++;
	}
	return (siz.val);
}
