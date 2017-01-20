/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoctal_maj_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:10:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/20 18:32:20 by hel-hadi         ###   ########.fr       */
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
	int			check_type;

	check_type = 1;
	arg = va_arg(*p, long long);
	nb = ft_count_num((int long)arg);
	diff = ft_flag_size(s, (void*)arg, check_type);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain_oct(s, nb, diff);
	ft_putoctal_maj(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
