/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_maj_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:10:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 15:01:32 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putoctal_maj(long long n)
{
	int long nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 1)
	{
		ft_putoctal_maj(nb / 8);
		ft_putchar((nb % 8) + 48);
	}
}

int	ft_putoctal_maj_f(char *s ,va_list *p)
{
	long long	arg;
	int			nb;
	int			diff;

	arg = va_arg(*p, long long);
	nb = ft_count_num((int long)arg);
	diff = ft_flag_size(s, (void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, (void*)arg);
	ft_putoctal_maj(arg);
	return (0);
}
